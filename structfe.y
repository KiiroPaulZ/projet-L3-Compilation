%{
        #include "nodes.h"
        #include <math.h>

        /* Variables globales */
        int pos; // Pointeur sur une case disponible en mémoire
        param_list_t * param_list_stack; 
        field_list_t * field_list_stack; 
        table_t *pile; // TS
        
        #define RED "\033[0;31m"
        #define WHITE "\033[0;37m"
        #define PURPLE "\033[0;35m"
        #define ERROR RED"ERROR: "WHITE
        #define WARNING PURPLE"WARNING: "WHITE

        extern int yylex();
        extern int yylineno;
        int yyerror(char *);

        char * marker = "prog"; // Marque par défaut, pour verifier si une variable globale est redefinie

        char * type_check(nodes_list_t * a); // Partie finale de l'analyse sémantique, on vérifie le typage et si les opérations sont correctes sur la représentation intermédiaire
        int verifyParamIntegrity(param_list_t * pls); // Vérifie si chaque déclaration est bien formée (présence des paramètres dans ts)
        code_info * generation (node_t * a); // après l'analyse sémantique, génération du code en partant de la racine
%}

%union{
        char *nom; // represente nom des variables, fonctions, structures
        char* val;

        /*type_t type; // int ou void (variable ou fonction)
        param_t param; 
        param_list_t * param_list;*/

        node_t * node;
        nodes_list_t * node_list;
        symbole_t * symb;
}

%type<node> expression primary_expression postfix_expression unary_expression program type_specifier declaration_specifiers
%type<node> multiplicative_expression additive_expression relational_expression equality_expression program_start
%type<node> logical_and_expression logical_or_expression declaration struct_specifier declarator direct_declarator 
%type<node> ACCOO ACCOF expression_statement selection_statement iteration_statement jump_statement external_declaration function_definition
%type<nom>  unary_operator
%type<node_list> argument_expression_list declaration_list statement_list compound_statement statement
%type<symb> parameter_list parameter_declaration function_init struct_declaration struct_declaration_list

%token<nom> IDENTIFIER 
%token<val> CONSTANT SIZEOF
%token PTR_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP
%token EXTERN
%token INT VOID
%token STRUCT 
%token IF ELSE WHILE FOR RETURN
%left '+' '-'
%left '*' '/'
%nonassoc ELSE_PRIORITY
%nonassoc ELSE

%start program_start
%%

primary_expression
        : IDENTIFIER  { 
                        symbole_t * s = NULL;
                        node_t * n = NULL;
                        table_t * stack_head = pile;
                        s = rechercher_global(stack_head, $1,0, ""); // Recherche de s dans dans la table
                        n = create_node(strdup($1), NULL); // On crée un noeud auquel on associe le symbole
                        n->symb = s;
                        $$ = n;
                      }
        | CONSTANT { node_t * n = NULL; n = create_node(strdup($1), NULL); n->isConst = true; $$ = n; }
        | '(' expression ')' { $$ = $2; }
        ;

postfix_expression
        : primary_expression { $$ = $1; }
        | postfix_expression '(' ')' { // appel de fonction anonyme
                if($1->symb != NULL && $1->symb->ts == FONCTION_ && (paramLength(param_list_stack) == paramLength($1->symb->param_list))){ // Verification s'il s'agit bien d'un appel de fonction et si son nombre de paramètre correspond
                        $$ = $1;
                } else {
                        clean_param_list_stack();
                        printf("%sLigne %d, ceci n'est pas une fonction anonyme!\n",ERROR, yylineno);
                        exit(1);
                }
        }
        | postfix_expression '(' argument_expression_list ')' { // appel de fonction
                // S'il s'agit d'une fonction, qu'il a un symbole associé et que la liste des parametres correspond à la liste de parametres définie initialement
                if($1->symb != NULL && $1->symb->ts == FONCTION_ && (paramLength(param_list_stack) == paramLength($1->symb->param_list)) && verifyParamIntegrity(param_list_stack) == 1){
                        if($1->symb->is_function_def){
                                clean_param_list_stack(); // Après chaque utilisation il faut penser à clean la pile de parametre globale
                                $$ = $1;
                        } else {
                                printf("%sLigne %d, La fonction '%s' existe, mais il n'y a aucune reference.\n", ERROR, yylineno, $1->name);
                                exit(1);
                        }
                } else if($1->symb != NULL && $1->symb->ts == FONCTION_) { // peut-etre existe-il une "surcharge" de cette fonction
                        int n = 1;
                        symbole_t * sy = NULL;
                        while(sy == NULL){ // Tant qu'il y a des occurences de la fonction, on regarde "ses surcharges"
                                sy = rechercher_global(pile, $1->symb->nom, n, "");
                                if(sy == NULL)
                                        break;
                                if(sy->ts == FONCTION_ && (paramLength(param_list_stack) == paramLength(sy->param_list)) && verifyParamIntegrity(param_list_stack) == 1){
                                        if(sy->is_function_def) {
                                                clean_param_list_stack(); // Après chaque utilisation il faut penser à clean la pile de parametre globale
                                                $$ = $1;
                                        } else {
                                                printf("%sLigne %d, La fonction '%s' existe, mais il n'y a aucune reference.\n", ERROR, yylineno, $1->name);
                                                exit(1);
                                        }
                                } else { // Une occurence a été trouvé mais pas le bon nb de params
                                        
                                }

                                n++;
                        }
                        if(sy == NULL){
                                clean_param_list_stack();
                                printf("%sLigne %d, la fonction n'est pas déclaré et/ou le nombre de paramètres n'est pas valide!\n",ERROR, yylineno);
                                exit(1);
                        }
                } else  {
                                clean_param_list_stack();
                                printf("%sLigne %d, la fonction n'est pas déclaré et/ou le nombre de paramètres n'est pas valide!\n",ERROR, yylineno);
                                exit(1);
                        }
        }
        | postfix_expression '.' IDENTIFIER {
                                                node_t * n = NULL; 
                                                n = create_node(".", mergeNodes(2, $1, create_node(strdup($3), NULL))); 
                                                $$ = n;
                                            }
        | postfix_expression PTR_OP IDENTIFIER  { 
                                                        node_t * n = NULL; 
                                                        n = create_node("->", mergeNodes(2, $1, create_node(strdup($3), NULL))); 
                                                        $$ = n; 
                                                }
        ;

argument_expression_list
        : expression    {
                                // On sauvegarde des informations pour le paramètre dans la TS et on l'ajoute à la pile des paramètres courants
                                if($1->symb == NULL){
                                        symbole_t * s = malloc(sizeof(symbole_t));
                                        s->nom = $1->name;
                                        $1->symb = s;
                                }
                                addParam(&param_list_stack, $1->symb);
                        }
        | argument_expression_list ',' expression       {

                                                                if($3->symb == NULL){ // Si le noeud n'a pas de symbole c'est qu'il s'agit d'une opération, donc on lui creer un symbole "vide"
                                                                        symbole_t * s = malloc(sizeof(symbole_t));
                                                                        s->nom = $3->name;
                                                                        $3->symb = s;
                                                                }
                                                                addParam(&param_list_stack, $3->symb);
                                                        }
        ;

unary_expression
        : postfix_expression { $$ = $1; }
        | unary_operator unary_expression {
                                                node_t * n = NULL;
                                                n = create_node(strdup($1), mergeNodes(1,$2));
                                                $$ = n;
                                          }
        | SIZEOF unary_expression { $$ = create_node("SIZEOF", mergeNodes(1,$2)); }
        ;

unary_operator
        : '&' { $$="&"; }
        | '*' { $$="*"; }
        | '-' { $$="-"; }
        ;

multiplicative_expression
        : unary_expression { $$ = $1; }
        | multiplicative_expression '*' unary_expression { $$ = create_node("*", mergeNodes(2,$1,$3)); }
        | multiplicative_expression '/' unary_expression { $$ = create_node("/", mergeNodes(2,$1,$3)); }
        ;

additive_expression
        : multiplicative_expression { $$ = $1; }
        | additive_expression '+' multiplicative_expression { $$ = create_node("+", mergeNodes(2,$1,$3)); }
        | additive_expression '-' multiplicative_expression { $$ = create_node("-", mergeNodes(2,$1,$3)); }
        ;

relational_expression
        : additive_expression { $$ = $1; }
        | relational_expression '<' additive_expression { $$ = create_node("<", mergeNodes(2,$1,$3)); }
        | relational_expression '>' additive_expression { $$ = create_node(">", mergeNodes(2,$1,$3)); }
        | relational_expression LE_OP additive_expression { $$ = create_node("<=", mergeNodes(2,$1,$3)); }
        | relational_expression GE_OP additive_expression { $$ = create_node(">=", mergeNodes(2,$1,$3)); }
        ;

equality_expression
        : relational_expression { $$ = $1; }
        | equality_expression EQ_OP relational_expression { $$ = create_node("==", mergeNodes(2,$1,$3)); }
        | equality_expression NE_OP relational_expression { $$ = create_node("!=", mergeNodes(2,$1,$3)); }
        ;

logical_and_expression
        : equality_expression { $$ = $1; }
        | logical_and_expression AND_OP equality_expression { $$ = create_node("&&", mergeNodes(2,$1,$3)); }
        ;

logical_or_expression
        : logical_and_expression { $$ = $1; }
        | logical_or_expression OR_OP logical_and_expression { $$ = create_node("||", mergeNodes(2,$1,$3)); }
        ;

expression
        : logical_or_expression { $$ = $1; }
        | unary_expression '=' expression { $$ = create_node("=", mergeNodes(2,$1,$3)); }
        ;

declaration
        : declaration_specifiers declarator ';' {       
                                                        if($1->type == VOID_){
                                                                printf("%sLigne %d, vous ne pouvez pas déclarer une variable de type void.\n", ERROR, yylineno);
                                                                exit(1);
                                                        }
                                                        
                                                        symbole_t *s = NULL;
                                                        table_t * stack_head = pile;
                                                        
                                                        if(stack_head == NULL){
                                                                table_t *table = nouvelle_table(); // Si la pile est vide on l'initialise
                                                                push(table); 
                                                        }
                                                        
                                                        table_t * current = stack_head;

                                                        if($1->type == STRUCT_){
                                                                symbole_t * s = rechercher_global(current->preced, $1->children->first->name, 0, ""); 

                                                                if(s == NULL){
                                                                        printf("%sLigne %d, cette structure n'est pas définie.\n",ERROR, yylineno);
                                                                        exit(1);
                                                                }
                                                        }
                                                        
                                                        if(current != NULL)
                                                                s = rechercher(current->symbole, $2->name);
                                                        
                                                        symbole_t * s2 = NULL;

                                                        if(stack_head != NULL && stack_head->preced != NULL && stack_head->preced->symbole != NULL)
                                                                s2 = rechercherStack((getSymbole(stack_head->preced->symbole,-1))->param_list, $2->name); // Je vérifie aussi si ce que je déclare n'a pas le meme nom qu'un parametre dans la définition de fonction courante
                                                       
                                                        if(s != NULL && s->ts != FONCTION_ && strcmp(s->marker, marker) == 0 || ((rechercher_global(pile, $2->name, 0, "prog")) != NULL && strcmp((rechercher_global(pile, $2->name, 0, "prog"))->marker, marker) == 0) && (rechercher_global(pile, $2->name, 0, "prog"))->ts != FONCTION_ ){
                                                                printf("%sLigne %d, la variable '%s' a déjà été déclarée.\n", ERROR, yylineno, $2->name);
                                                                exit(1);
                                                        } else if (s2 != NULL) {
                                                                printf("%sLigne %d, vous ne pouvez pas déclarer %s car elle est défini en parametre de fonction.\n", ERROR, yylineno, $2->name);
                                                                exit(1);
                                                         }else if (s != NULL && s->ts == FONCTION_){ 
                                                                s->param_list = copyParamList(param_list_stack);
                                                                clean_param_list_stack();
                                                         }else {
                                                                while(current != NULL){ // je vérifie si la variable a deja été declaré
                                                                        if(current ->symbole != NULL){
                                                                                s = rechercher(current->symbole, $2->name);
                                                                                if(s != NULL)
                                                                                        break;
                                                                        }
                                                                        current  = current ->preced;
                                                                }

                                                                if(((rechercher_global(pile, $2->name, 0, "prog")) != NULL && strcmp((rechercher_global(pile, $2->name, 0, "prog"))->marker, "prog") == 0) && (rechercher_global(pile, $2->name, 0, "prog"))->ts != FONCTION_ ) // le -1 pour regarde les déclarations globales
                                                                        printf("%sLigne %d, la variable '%s' en masque une autre.\n", WARNING, yylineno, $2->name);
                                                                table_t * t = *top(); // Le symbole n'existe pas, il faut le définir
                                                                s = ajouter(&(t->symbole), $2->name);
                                                                if($1->type == EXTERN_INT_ || $1->type == EXTERN_VOID_ || $1->type == EXTERN_STRUCT_){ // Ici on gere les extern
                                                                        s->ts = FONCTION_; //EXTERN_FONCTION_;
                                                                        s->is_function_def = true;
                                                                        switch($1->type){
                                                                                case EXTERN_INT_: s->type = INT_; break;
                                                                                case EXTERN_VOID_ : s->type = VOID_; break;
                                                                                default : s->type = STRUCT_;
                                                                        }
                                                                } 
                                                                s->ts = $2->ts_t;
                                                                if(param_list_stack != NULL){ // S'il a des paramètres, on les sauvegardes
                                                                        s->param_list = copyParamList(param_list_stack);
                                                                        clean_param_list_stack();
                                                                }
                                                                s->marker = marker;
                                                                s->taille = sizeof($1->type);
                                                                s->position = pos;
                                                                s->suivant = NULL;
                                                                pos += s->taille;
                                                        }
                                                }
        | struct_specifier ';' {
                symbole_t *s = NULL;
                table_t * stack_head = pile;
                table_t * current = stack_head;
                
                if(stack_head == NULL){
                        table_t *table = nouvelle_table(); push(table); // Si la pile est vide on l'initialise
                }

                if(current != NULL)
                        s = rechercher(current->symbole, $1->name);

                if(s != NULL && s->field_list != NULL){
                        printf("%sLigne %d, la structure '%s' a déjà été déclarée.\n", ERROR, yylineno, $1->name);
                        exit(1);
                } else {
                        table_t * t = *top(); // Le symbole n'existe pas, il faut le définir
                        s = ajouter(&(t->symbole), $1->name);
                        s->type = STRUCT_;
                        s->ts = STRUCTURE_;
                        s->taille = sizeof(STRUCT_);
                        s->position = pos;
                        s->suivant = NULL;
                        s->marker = marker;
                        pos += s->taille;
                        if ($$->symb != NULL)
                                s->field_list = $$->symb->field_list;
                }
        }
        ;

declaration_specifiers
        : EXTERN type_specifier {
                                        switch($2->type){
                                                case INT_:      { 
                                                                        node_t * n = create_node("type_EXTERN_INT", NULL);
                                                                        n->type = EXTERN_INT_;
                                                                        n->ts_t = FONCTION_;
                                                                        $$ = n;
                                                                        break;
                                                                }
                                                case VOID_:     {
                                                                        node_t * n = create_node("type_EXTERN_VOID", NULL);
                                                                        n->type = EXTERN_VOID_;
                                                                        n->ts_t = FONCTION_;
                                                                        $$ = n;
                                                                        break;
                                                                }
                                                default:        {
                                                                        node_t * n = create_node("type_EXTERN_STRUCT", NULL);
                                                                        n->type = EXTERN_STRUCT_;
                                                                        n->ts_t = FONCTION_;
                                                                        $$ = n;
                                                                        break;
                                                                }
                                        }
                                }
        | type_specifier { $$ = $1; }
        ;

type_specifier
        : VOID { node_t * n = create_node("type_VOID", NULL); n->type = VOID_; $$ = n; }
        | INT { node_t * n = create_node("type_INT", NULL); n->type = INT_; $$ = n; }
        | struct_specifier { node_t * n = create_node("type_STRUCT", mergeNodes(1, $1)); n->type = STRUCT_; n->ts_t = STRUCTURE_ ; $$ = n; } // un noeud de type struct avec pour enfant le nom de la structure
        ;

struct_specifier
        : STRUCT IDENTIFIER '{' struct_declaration_list '}'     { 
                                                                        node_t * n = create_node(strdup($2), NULL);
                                                                        symbole_t * s = malloc(sizeof(symbole_t));
                                                                        s->field_list = field_list_stack;
                                                                        clean_field_list_stack();
                                                                        n->symb = s;
                                                                        $$ = n;
                                                                }
        | STRUCT '{' struct_declaration_list '}' { printf("%sLigne %d, les structures anonymes ne sont pas autorisées.\n",ERROR, yylineno); exit(1); }
        | STRUCT IDENTIFIER { $$ = create_node(strdup($2), NULL); }
        ;

struct_declaration_list
        : struct_declaration { addField(&field_list_stack, $1); $$ = NULL; }
        | struct_declaration_list struct_declaration { addField(&field_list_stack, $2); $$ = NULL; }
        ;

struct_declaration
        : type_specifier declarator ';'         {
                                                        char * nom = $2->name; // Je sauvegarde les informations
                                                        symbole_t * s;
                                                        s = malloc(sizeof(symbole_t));
                                                        s->type = $1->type;
                                                        if(nom[0] == '*'){
                                                                s->isPtr = true;
                                                                nom++; // on retire le premier caractere
                                                        } else {
                                                                s->isPtr = false;
                                                        }
                                                        s->nom = nom;
                                                        $$ = s;
                                                }
        ;

declarator
        : '*' direct_declarator         {
                                                char p[strlen($2->name)+2]; 
                                                sprintf(p, "*%s", $2->name);
                                                $2->name = strdup(p);
                                                $$ = $2;
                                        }
        | direct_declarator { $$ = $1; }
        ;

direct_declarator
        : IDENTIFIER { node_t * n = create_node(strdup($1), NULL); n->ts_t = VARIABLE_; $$ = n; }
        | '(' declarator ')' { $$ = $2; }
        | direct_declarator '(' parameter_list ')' { node_t * n = $1; n->ts_t = FONCTION_; $$ = n; }
        | direct_declarator '(' ')' { node_t * n = $1; n->ts_t = FONCTION_; $$ = n; }
        ;

parameter_list
        : parameter_declaration { addParam(&param_list_stack, $1); }
        | parameter_list ',' parameter_declaration { addParam(&param_list_stack, $3); }
        ;

parameter_declaration
        : declaration_specifiers declarator {
                char * nom = strdup($2->name); // Je sauvegarde les informations
                symbole_t * s;
                s = malloc(sizeof(symbole_t));
                s->type = $1->type;
                if(nom[0] == '*'){
                        s->isPtr = true;
                        nom++; // on retire le premier caractere
                } else {
                        s->isPtr = false;
                }
                s->nom = nom;
                $$ = s;
        }
        ;

statement
        : compound_statement {$$ = $1;}
        | expression_statement {$$ = mergeNodes(1, $1);}
        | selection_statement {$$ = mergeNodes(1, $1);}
        | iteration_statement {$$ = mergeNodes(1, $1);}
        | jump_statement {$$ = mergeNodes(1, $1);}
        ;

compound_statement
        : '{' '}' {$$ = NULL;}
        | ACCOO statement_list ACCOF {$$ = $2;}
        | ACCOO declaration_list ACCOF {$$ = NULL;}
        | ACCOO declaration_list statement_list ACCOF {$$ = $3;}
        ;

ACCOO : '{' { table_t *table = nouvelle_table(); push(table);}
ACCOF : '}' {   /* NE PAS TOUCHER */

                marker = "prog";
                
                /*table_t *table = pop(); 
                detruire_table(&table);
                if((*top()) != NULL){ // autrement dit si la pile est vide    
                    //print_table();
                } else {
                    printf("[]\n");
                }*/

                /* ************* */
            }

declaration_list
        : declaration { $$ = NULL; }
        | declaration_list declaration { $$ = NULL; }
        ;

statement_list
        : statement {$$ = $1;}
        | statement_list statement {$$ = concatNodes($1, $2); }
        ;

expression_statement
        : ';' { $$ = NULL; }
        | expression ';' {$$ = $1;}
        ;

selection_statement
        : IF '(' expression ')' statement %prec ELSE_PRIORITY {$$ = create_node("IF", concatNodes(mergeNodes(1, $3), $5));}
        | IF '(' expression ')' statement ELSE statement %prec ELSE {$$ = create_node("IF-ELSE", concatNodes(mergeNodes(1, $3), concatNodes($5, $7)));}
        ;

iteration_statement
        : WHILE '(' expression ')' statement {$$ = create_node("WHILE", concatNodes(mergeNodes(1, $3), $5)); }
        | FOR '(' expression_statement expression_statement expression ')' statement { $$ = create_node("FOR", concatNodes( mergeNodes(3, $3, $4, $5), $7)); }
        ;

jump_statement
        : RETURN ';' { $$ = create_node("RETURN", NULL);}
        | RETURN expression ';' {$$ = create_node("RETURN", mergeNodes(1, $2)); }
        ;

program_start: program  {       //Obliger de séparer le start du program car on affiche chaque AST des fonctions, donc on ne veux pas un arret prématuré
                                printf("FIN ANALYSE!\n");
                                print_tree(mergeNodes(1,$$), "");
                                
                                /* Il faudrait normalement vider la table */
                                // ...
                        }
                ;

program
        : external_declaration {
                                        print_complete_table();
                                        nodes_list_t * arbre = NULL;
                                        if($1 != NULL){
                                                arbre = mergeNodes(1, $1);
                                                print_tree(arbre, "");
                                                // Il faut verifier chacune de ses branches
                                                nodes_list_t * current = arbre->first->children;
                                                int i = 0;
                                                while(current->next != NULL){ // je ne gere pas le return pour le moment
                                                        type_check(current);
                                                        current = current->next;
                                                        i++;
                                                }
                                                i++;
                                                switch(arbre->first->symb->type){
                                                        case INT_ :{
                                                                if(strcmp(type_check(current), "int") == 0 &&  arbre->first->symb->isPtr == true || (strcmp(type_check(current), "int *") == 0 && arbre->first->symb->isPtr == false) || (strcmp(type_check(current), "int") != 0 && strcmp(type_check(current), "int *") != 0)){
                                                                        printf("%sLe type de retour '%s' est different de celui de la fonction!\n", ERROR, type_check(current));
                                                                        exit(1);
                                                                }
                                                                break;
                                                        }

                                                        case VOID_ : {
                                                                if(strcmp(type_check(current), "void") == 0 &&  arbre->first->symb->isPtr == true || (strcmp(type_check(current), "void *") == 0 && arbre->first->symb->isPtr == false) || (strcmp(type_check(current), "void") != 0 && strcmp(type_check(current), "void *") != 0)){
                                                                        printf("%sLe type de retour '%s' est different de celui de la fonction!\n", ERROR, type_check(current));
                                                                        exit(1);
                                                                }
                                                                break;
                                                        }

                                                        default : { // STRUCT_
                                                                if(strcmp(type_check(current), "struct") != 0){
                                                                        printf("%sLe type de retour '%s' est different de celui de la fonction!\n", ERROR, type_check(current));
                                                                        exit(1);
                                                                }
                                                                break;
                                                        }             
                                                }
                                                printf("%s\n", generation(arbre->first)->code);
                                                printf("TYPECHECK ==> OK\n");
                                        }
                                        $$ = create_node("prog", mergeNodes(1, $1));
                                }
        | program external_declaration {
                                                print_complete_table();
                                                nodes_list_t * arbre = NULL;
                                                if($2 != NULL){
                                                        arbre = mergeNodes(1, $2);
                                                        print_tree(arbre, "");
                                                        nodes_list_t * current = arbre->first->children;
                                                        int i = 0;
                                                        while(current->next != NULL){ // je ne gere pas le return pour le moment
                                                                type_check(current);
                                                                current = current->next;
                                                                i++;
                                                        }
                                                        i++;

                                                        if(strcmp(current->first->name, "RETURN") != 0 && arbre->first->symb->type != VOID_){
                                                                printf("%sIl n'y a pas de fonction de retour alors que la fonction n'est pas de type void.\n", ERROR);
                                                                exit(1);
                                                        } else if (strcmp(current->first->name, "RETURN") != 0 && arbre->first->symb->type == VOID_ && arbre->first->symb->isPtr == false){
                                                                /* il n'y a rien a faire */
                                                        } else {
                                                                switch(arbre->first->symb->type){
                                                                        case INT_ :{
                                                                                if(strcmp(type_check(current), "int") == 0 &&  arbre->first->symb->isPtr == true || (strcmp(type_check(current), "int *") == 0 && arbre->first->symb->isPtr == false) || (strcmp(type_check(current), "int") != 0 && strcmp(type_check(current), "int *") != 0)){
                                                                                        printf("%sLe type de retour '%s' est different de celui de la fonction!\n", ERROR, type_check(current));
                                                                                        exit(1);
                                                                                }
                                                                                break;
                                                                        }

                                                                        case VOID_ : {
                                                                                if(strcmp(type_check(current), "void") == 0 &&  arbre->first->symb->isPtr == true || (strcmp(type_check(current), "void *") == 0 && arbre->first->symb->isPtr == false) || (strcmp(type_check(current), "void") != 0 && strcmp(type_check(current), "void *") != 0)){
                                                                                        printf("%sLe type de retour '%s' est different de celui de la fonction!\n", ERROR, type_check(current));
                                                                                        exit(1);
                                                                                }
                                                                                break;
                                                                        }

                                                                        default : { // STRUCT_
                                                                                if(strcmp(type_check(current), "struct") != 0){
                                                                                        printf("%sLe type de retour '%s' est different de celui de la fonction!\n", ERROR, type_check(current));
                                                                                        exit(1);
                                                                                }
                                                                                break;
                                                                        }             
                                                                }
                                                        }
                                                        printf("TYPECHECK ==> OK\n");    
                                                }
                                                $$ = create_node("prog", mergeNodes(1, $2));
                                        }
        ;

external_declaration
        : function_definition { $$ = $1;}
        | declaration { $$ = NULL;}
        ;

function_init
        : declaration_specifiers declarator     { /* Nouvelle regle syntaxique */
                                                        // Il fallait pouvoir agir sur la declaration des fonctions indépendamment des paramètres de celle-ci
                                                        marker = strdup($2->name);
                                                        symbole_t *s = NULL;
                                                        table_t * stack_head = pile;

                                                        if(stack_head == NULL){
                                                                table_t *table = nouvelle_table(); push(table); // Si la pile est vide on l'initialise
                                                        }

                                                        while(stack_head != NULL){
                                                                if(stack_head->symbole != NULL){
                                                                        s = rechercher(stack_head->symbole, $2->name);
                                                                        if(s != NULL)
                                                                                break;
                                                                }
                                                                stack_head = stack_head->preced;
                                                        }
                                                        if(s != NULL && s->is_function_def == true && paramLength(s->param_list) == paramLength(param_list_stack)){
                                                                printf("%sLigne %d, la fonction '%s' est déjà déclarée.\n", ERROR, yylineno, $2->name);
                                                                exit(1);
                                                        } else {
                                                                int n = 0;
                                                                symbole_t * sy = NULL;

                                                                while(sy == NULL){ // Tant qu'il y a des occurences de la fonction, on regarde ses surcharges
                                                                        sy = rechercher_global(stack_head, $2->name, n, "");
                                                                        if(sy == NULL){
                                                                                if (s != NULL && s->is_function_def != true){
                                                                                        s->param_list = copyParamList(param_list_stack);
                                                                                        s->ts = FONCTION_;
                                                                                        s->is_function_def = true;
                                                                                        clean_param_list_stack();
                                                                                        $$ = s;
                                                                                        break;
                                                                                } else {
                                                                                        table_t * t = *top();
                                                                                        sy = ajouter(&(t->symbole), $2->name);
                                                                                        sy->type = $1->type;
                                                                                        sy->ts = FONCTION_;
                                                                                        sy->taille = sizeof($1->type);
                                                                                        sy->position = pos;
                                                                                        sy->suivant = NULL;
                                                                                        pos += sy->taille;
                                                                                        if(($2->name)[0] == '*')
                                                                                                $2->name++;
                                                                                        sy->is_function_def = true; 
                                                                                        sy->param_list = copyParamList(param_list_stack);
                                                                                        clean_param_list_stack();
                                                                                        $$ = sy;
                                                                                        break; 
                                                                                }
                                                                        }
                                                                                
                                                                        if(sy != NULL && sy->ts == FONCTION_ && (paramLength(param_list_stack) == paramLength(sy->param_list)) && sy->is_function_def){
                                                                                printf("%sLigne %d, La fonction '%s' est déjà définie.\n", ERROR, yylineno, $2->name);
                                                                                exit(1);
                                                                        } else if (sy != NULL && sy->ts == FONCTION_ && sy->is_function_def ) {
                                                                                sy = NULL;
                                                                        } else {
                                                                                sy = NULL;
                                                                        }
                                                                        
                                                                        n++;
                                                                }
                                                        }
                                                }

function_definition
        :  function_init compound_statement     {
                                                        clean_param_list_stack(); // On nettoie la pile des paramètres par précaution
                                                        node_t * n  = create_node(getSymbole($1,-1)->nom,$2);
                                                        n->symb = $1;
                                                        $$ = n;
                                                }
        ;
%%
        int yyerror(char *s){ // fonction pour détecter une erreur
                fprintf(stderr, "%s\n", s);
                exit(1);
        }

        int pos = 0;
        table_t * pile = NULL;

        table_t ** top(){
                return &pile;
        }

        table_t * nouvelle_table(){
                table_t * t = malloc(sizeof(table_t));
                assert(t != NULL);
                t->symbole = NULL;
                t->preced = NULL;
                return t;
        }

        void push(table_t * table){
                table_t ** stack = top();
                table->preced = *stack;
                *stack = table;
        }

        symbole_t * rechercher(symbole_t * list, char * nom){
                if(list != NULL){
                        symbole_t *last = list;
                        while(strcmp(last->nom, nom) != 0){
                                if (last->suivant == NULL){
                                        return NULL;
                                }
                                last = last->suivant;           
                        }
                        return last;
                }else{
                        return NULL;
                }
        }

        symbole_t * rechercher_global(table_t * t, char * nom, int n, char * mark){
                if(t != NULL){
                        table_t * table = t;
                        while(table != NULL){
                                symbole_t * s = NULL;
                                symbole_t * depthS = NULL;
                                depthS = table->symbole;
                                while(1){
                                        s = rechercher(depthS, nom);
                                        
                                        if(s == NULL)
                                                break;
                                        

                                        if(s != NULL && (s->marker != NULL && strcmp(s->marker, mark) == 0 || strcmp("", mark) == 0) && n == 0) // "" pour faire une recherche classique
                                                return s;
                                        
                                        if(s != NULL && (s->marker != NULL && strcmp(s->marker, mark) == 0 || strcmp("", mark) == 0))
                                                n--;

                                        depthS = depthS->suivant;
                                }
                                table = table->preced;
                        }
                }
                return NULL;
        }

        symbole_t * ajouter(symbole_t ** list_s, char *nom){
                symbole_t *s = malloc(sizeof(symbole_t));
                assert(s != NULL);
                if(nom[0] == '*'){
                        s->isPtr = true;
                        nom++; // on retire le premier caractere
                } else {
                        s->isPtr = false;
                }
                s->nom = strdup(nom);
                if((*list_s) != NULL){
                        symbole_t *last = (*list_s);
                        while(last->suivant != NULL){
                                last = last->suivant;
                        }
                        last->suivant = s;
                }else{
                        *list_s = s;
                }
                return s;
        }

        void print_table(){
                table_t * stack = malloc(sizeof (table_t));
                assert(stack != NULL);

                if(*top() != NULL){
                        stack->symbole = (*top())->symbole;
                        stack->preced = (*top())->preced;
                }
                
                printf("[");
                while(stack != NULL){
                        printf("{ ");
                        while(stack->symbole != NULL){
                                printf("%s -> ", stack->symbole->nom);
                                stack->symbole = stack->symbole->suivant;
                        }
                        printf("NULL }");

                        if(stack->preced != NULL){
                                stack->symbole = stack->preced->symbole;
                                stack->preced = stack->preced->preced;
                        } else {
                                break;
                        }
                }
                printf("]\n");
                free(stack);
        }

        void print_complete_table(){
                table_t * stack = malloc(sizeof (table_t));
                assert(stack != NULL);

                if(*top() != NULL){
                        stack->symbole = (*top())->symbole;
                        stack->preced = (*top())->preced;
                }
                printf("================================\n");
                while(stack != NULL){
                        printf("{\n");
                        while(stack->symbole != NULL){
                                if(stack->symbole->marker != NULL){
                                        printf("        NAME: %-22s | isPTR: %d | type: %2d | TAILLE: %3d | POSITION: %3d | TS NATURE: %2d | PARAM_LENGTH: %2d | FUN def?:%d | MARKER: %s\n", stack->symbole->nom, stack->symbole->isPtr, stack->symbole->type, stack->symbole->taille, stack->symbole->position, stack->symbole->ts, paramLength(stack->symbole->param_list), stack->symbole->is_function_def, stack->symbole->marker);
                                } else {
                                        printf("        NAME: %-22s | isPTR: %d | type: %2d | TAILLE: %3d | POSITION: %3d | TS NATURE: %2d | PARAM_LENGTH: %2d | FUN def?:%d | MARKER: NONE\n", stack->symbole->nom, stack->symbole->isPtr, stack->symbole->type, stack->symbole->taille, stack->symbole->position, stack->symbole->ts, paramLength(stack->symbole->param_list), stack->symbole->is_function_def);
                                }
                                stack->symbole = stack->symbole->suivant;
                        }
                        printf("}\n");

                        if(stack->preced != NULL){
                                stack->symbole = stack->preced->symbole;
                                stack->preced = stack->preced->preced;
                        } else {
                                break;
                        }
                }
                printf("\n================================\n");
                free(stack);
        }

        table_t * pop(){
                table_t ** stack_header = top();
                table_t * first = *top();
                *stack_header = first->preced;
                return first;
        }

        void detruire_table(table_t ** t){
                symbole_t *tmp;
                while((*t)->symbole != NULL){
                        tmp = (*t)->symbole;
                        (*t)->symbole = (*t)->symbole->suivant;
                        free(tmp->nom); // A cause du strdup
                        free(tmp);
                }
                //t = NULL;
                free(*t);
        }

        // function for nodes 
        nodes_list_t * mergeNodes(int nbPara, ...){
                if(nbPara == 0)
                        return NULL;

                va_list ap;    
                va_start(ap, nbPara);
                nodes_list_t * n = malloc(sizeof(nodes_list_t));
                n->first = va_arg(ap, node_t *);

                if(nbPara == 1){
                        n->next = NULL;
                        return n;
                }

                n->next = malloc(sizeof(nodes_list_t));

                nodes_list_t * temp = n->next;
                
                for(int j = 1; j < nbPara; j++){
                        node_t * current = va_arg(ap, node_t *);
                        temp->first = current;
                        if(j != nbPara -1) {
                                temp->next = malloc(sizeof(nodes_list_t));
                                temp = temp->next;
                        }
                }
                temp->next = NULL;
                va_end(ap);
                return n;
        };

        void print_node(node_t * n){
                printf("nom : %s\n", n->name);
                nodes_list_t * current = n->children; //malloc(sizeof(nodes_list_t));
                //current = n->children;
                printf("mes fils sont: ");
                while(current != NULL){
                        printf("%s -> ", current->first->name);
                        current = current->next;
                }
                printf("NULL\n");
        };

        node_t * create_node(char * name, nodes_list_t * nodesList){
                node_t * n = malloc(sizeof(node_t));
                assert(n != NULL);
                n->name = name;
                n->children = nodesList;
                //print_node(n);
                return n;
        };

        void print_tree(nodes_list_t * n, char * space){
                printf("%s\n", n->first->name);
                nodes_list_t * current = n->first->children;
                char * newspace = "     ";
                while(current != NULL){ // Tant que le pere a des enfants
                    printf("%s     |___> ", space);
                    printf("%s \n", current->first->name);
                    
                    nodes_list_t * depth_current = current->first->children;
                    
                    while(depth_current != NULL){ //tant que j'ai pas vu tout les enfants
                        char target[strlen(space) + strlen(newspace) + 1];
                        strcpy(target, space);
                        strcat(target, newspace);
                        printf("%s     |___> ", target);
                        
                        char ntarget[strlen(target) + strlen(newspace) + 1];
                        strcpy(ntarget, target);
                        strcat(ntarget, newspace);
                        print_tree(depth_current, ntarget);

                        depth_current = depth_current->next;
                        
                        printf("\n");
                        
                    }
                    
                    current = current->next;
                }
        };

        nodes_list_t * pushNode(nodes_list_t * t, node_t * n){
                nodes_list_t * copy = t;
                nodes_list_t * current = copy;
                while(current->next != NULL){
                        current = current->next;
                }
                current->next = mergeNodes(1, n);
                return copy;
        };

        void addParam(param_list_t ** stack, symbole_t * s){
                param_list_t * p = malloc(sizeof(param_list_t));
                p->symbole = s;
                param_list_t * st = *stack;

                if(*stack == NULL){
                        *stack = p;
                } else {
                        while(st->suivant != NULL){
                                st = st->suivant;
                        }
                        st->suivant = p;
                }
        }   

        param_list_t * copyParamList(param_list_t * stack){
                if(stack == NULL)
                        return NULL;
                
                param_list_t * p = malloc(sizeof(param_list_t));
                p->symbole = malloc(sizeof(symbole_t));
                p->symbole->type = stack->symbole->type;
                p->symbole->isPtr = stack->symbole->isPtr;
                p->symbole->nom = strdup(stack->symbole->nom);
                p->suivant = copyParamList(stack->suivant);
                return p;
        }

        symbole_t * rechercherStack(param_list_t * st, char * nom){
                param_list_t * p = st;
                while(p != NULL){
                        if(strcmp(nom, p->symbole->nom) == 0)
                                return p->symbole;
                        p = p->suivant;
                }
                return NULL;
        }

        void displayParam(param_list_t * p){
                printf("Liste courante des paramètres:\n");
                while(p != NULL){
                        printf("+ %s, est de type %d et isPtr vaut %d\n",p->symbole->nom, p->symbole->type ,p->symbole->isPtr);
                        p = p->suivant;
                }
        }

        void clean_param_list_stack(){
                param_list_t ** stack = &param_list_stack;
                while (*stack != NULL){
                        *stack = (*stack)->suivant;
                }
        }

        int paramLength(param_list_t * p){
                param_list_t * current;
                int count;
                current = p;
                count = 0;
                while(current != NULL){
                        count++;
                        current = current->suivant;
                }
                return count;
        }

        symbole_t * getSymbole(symbole_t * s, int n){
                symbole_t * current = s;
                if(n < 0){
                        while(current->suivant != NULL){
                                current = current->suivant;
                        }
                        return current;
                } else{
                        int count = 0;
                        while(count < n){
                        if(current == NULL){
                                printf("getSymbole : out of range\n");
                                exit(1);
                        }
                        current = current->suivant;
                        }
                }
                if(current == NULL){
                        printf("getSymbole : out of range\n");
                        exit(1);
                }
                return current;
        }

        symbole_t * getSymboleList(table_t * t, int n){
                table_t * current = t;
                if(n < 0){
                        while(current->preced != NULL){
                                current = current->preced;
                        }
                        return current->symbole;
                } else{
                        int count = 0;
                        while(count < n){
                                if(current == NULL){
                                        printf("getSymbole : out of range\n");
                                        exit(1);
                                }
                                current = current->preced;
                        }
                }
                if(current == NULL){
                        printf("getSymbole : out of range\n");
                        exit(1);
                }
                return current->symbole;
        }

        nodes_list_t * concatNodes(nodes_list_t * n1, nodes_list_t * n2){
                nodes_list_t * copy = n1;
                nodes_list_t * current = copy;
                while(current->next != NULL){
                        current = current->next;
                }
                current->next = n2;
                return copy;
        }

        void addField(field_list_t ** stack, symbole_t * s){
                field_list_t * p = malloc(sizeof(field_list_t));
                p->symbole = s;
                field_list_t * st = *stack;

                if(*stack == NULL){
                        *stack = p;
                } else {
                        while(st->suivant != NULL){
                                st = st->suivant;
                        }
                        st->suivant = p;
                }
        }

        field_list_t * copyFieldList(field_list_t * stack){
                if(stack == NULL)
                        return NULL;

                field_list_t * p = malloc(sizeof(field_list_t));
                p->symbole = malloc(sizeof(symbole_t));
                p->symbole->type = stack->symbole->type;
                p->symbole->isPtr = stack->symbole->isPtr;
                p->symbole->nom = strdup(stack->symbole->nom);
                p->suivant = copyFieldList(stack->suivant);
                return p;
        }

        symbole_t * rechercherFieldStack(field_list_t * st, char * nom){
                field_list_t * p = st;
                while(p != NULL){
                        if(strcmp(nom, p->symbole->nom) == 0)
                                return p->symbole;
                        p = p->suivant;
                }
                return NULL;
        }

        void displayField(field_list_t * p){
                printf("Liste courante des paramètres:\n");
                while(p != NULL){
                        printf("+ %s, est de type %d et isPtr vaut %d\n",p->symbole->nom, p->symbole->type ,p->symbole->isPtr);
                        p = p->suivant;
                }
        }

        void clean_field_list_stack(){
                field_list_t ** stack = &field_list_stack;
                while (*stack != NULL){
                        *stack = (*stack)->suivant;
                }
        }

        int fieldLength(field_list_t * p){
                field_list_t * current;
                int count;
                current = p;
                count = 0;
                while(current != NULL){
                        count++;
                        current = current->suivant;
                }
                return count;
        }

        int verifyParamIntegrity(param_list_t * pls){
                param_list_t * current = pls;
                table_t * stack_head = pile;
                while(current != NULL){
                        if(rechercher_global(stack_head, current->symbole->nom,0,marker) == NULL && rechercher_global(stack_head, current->symbole->nom,0,"prog") == NULL){ // Si un parametre n'existe pas alors il y  a un probleme
                                return 0;
                        }
                        current = current->suivant;
                }
                return 1;
        }

        char * type_check(nodes_list_t * a){
                if(strcmp(a->first->name, "=") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if(strcmp(fg, fd) == 0)
                                return fg; 
                        printf("%sTYPECHECK: '=' attendait un type %s mais a reçu un type %s OU il s'agit d'un probleme de pointeurs.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "+") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0)){
                                return "int"; 
                        } else if (((strcmp(fg, "int *") == 0 && strcmp(fd, "int") == 0)) || ((strcmp(fg, "int") == 0 && strcmp(fd, "int *") == 0)) || ((strcmp(fg, "int *") == 0 && strcmp(fd, "int *") == 0))){
                                return "int *";
                        }
                        printf("%sTYPECHECK: '+' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "-") == 0){ // Il faut aussi verifier s'il s'agit d'une opération unaire
                        if(a->first->children->next != NULL){ // S'il ne s'agit pas de l'operation unaire
                                char * fg = type_check(a->first->children);
                                char * fd = type_check(a->first->children->next);

                                if((strcmp(fg, "int *") == 0 && strcmp(fd, "int *") == 0) || (strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                        return "int"; 
                                
                                printf("%sTYPECHECK: '-' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                                exit(1);
                        } else {
                                char * fils = type_check(a->first->children);
                                if(strcmp(fils, "int") == 0)
                                        return "int";
                                printf("%sTYPECHECK: '-' (UNAIRE) attendait un type int mais a reçu un type %s.\n", ERROR, fils);
                                exit(1);
                        }
                } else if (strcmp(a->first->name, "*") == 0){ // Il faut aussi vérifier s'il s'agit d'un pointeur
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                              
                        printf("%sTYPECHECK: '*' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "/") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                              
                        printf("%sTYPECHECK: '/' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, ">") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                        
                        printf("%sTYPECHECK: '>' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "<") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                
                        printf("%sTYPECHECK: '<' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, ">=") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                             
                        printf("%sTYPECHECK: '>=' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "<=") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                                
                        printf("%sTYPECHECK: '<=' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "==") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                         
                        printf("%sTYPECHECK: '==' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "!=") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                               
                        printf("%sTYPECHECK: '!=' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "&&") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                                
                        printf("%sTYPECHECK: '&&' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "||") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if((strcmp(fg, "int") == 0 && strcmp(fd, "int") == 0))
                                return "int"; 
                               
                        printf("%sTYPECHECK: '||' attendait un type int mais a reçu un type %s et %s.\n", ERROR, fg, fd);
                        exit(1);
                } else if (strcmp(a->first->name, "&") == 0){
                        char * fils = type_check(a->first->children);
                        if(strcmp(fils, "int") == 0){
                                return "int *"; 
                        } else if (a->first->children->first->symb->ts == FONCTION_){
                                switch(a->first->children->first->symb->type){
                                        case INT_ : return "int *"; break;
                                        case VOID_: return "void *"; break;
                                        default : return "struct"; break;
                                }
                        }        
                        printf("%sTYPECHECK: '&' (UNAIRE) attendait un type int ou une fonction mais a reçu un type %s et/ou n'est pas une fonction.\n", ERROR, fils);
                        exit(1);
                } else if (strcmp(a->first->name, "->") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if(strcmp(fg, "struct") == 0 && a->first->children->first->symb->isPtr == true)
                                return fd; 
                              
                        printf("%sTYPECHECK: '->' attendait un type struct mais a reçu un type %s (peut-etre pas un pointeur?) .\n", ERROR, fg);
                        exit(1);
                } else if (strcmp(a->first->name, ".") == 0){
                        char * fg = type_check(a->first->children);
                        char * fd = type_check(a->first->children->next);
                        if(strcmp(fg, "struct") == 0 && a->first->children->first->symb->isPtr == false)
                                return fd; 
                                
                        printf("%sTYPECHECK: '.' attendait un type struct mais a reçu un type %s (peut-etre un pointeur?) .\n", ERROR, fg);
                        exit(1);
                } else if (strcmp(a->first->name, "RETURN") == 0){
                        if(a->first->children != NULL){
                                char * fils = type_check(a->first->children);
                                return fils;
                        } else {
                                return "void";
                        }
                        
                } else { // Si on entre ici, soit on a pas implémenté un opérateur, soit il faut faire remonter un type
                        //JE RECHERCHE DANS LA TS L'ELEMENT COURANT
                        
                        table_t * stack_head = pile;
                        symbole_t * s = NULL;

                        if(a->first->isConst == true){ // c'est qu'il s'agit d'une constante
                                return "int";
                        }
                        
                        s = rechercher_global(stack_head, a->first->name, 0, "");

                        if (s != NULL) {
                                type_t res;
                                res = s->type;
                                switch(res){
                                        case INT_ :{
                                                if(s->isPtr)
                                                        return "int *";
                                                return "int";
                                                break;}
                                        case VOID_ :{
                                                if(s->isPtr)
                                                        return "void *";
                                                return "void";
                                                break;}
                                        default :
                                                return "struct";
                                }
                        }
                        
                        printf("%sTYPECHECK: %s n'est pas géré semble-t-il OU n'existe pas.\n", ERROR, a->first->name);
                        exit(1);
                }
        }

        int lengthChildren(node_t * a) {
                nodes_list_t * children;
                children = a->children;
                int acc = 0;
                while(children != NULL){
                        acc++;
                        children = children->next;
                }
                return acc;
        }

        char * concatener(int nbPara, ...){
                char * res = strdup("");
                if(nbPara == 0)
                        return NULL;
                        
                va_list ap;    
                va_start(ap, nbPara);
                                
                for(int j = 0; j < nbPara; j++){
                        char * current = va_arg(ap, char *);
                        strcat(res, " ");
                        strcat(res, current);
                }
                                
                va_end(ap);
                return res;
        }

        code_info * generation (node_t * a){
                // Init
                nodes_list_t * arbre = a->children; // Premier fils
                int length_children = lengthChildren(a); // Nb de ses enfants
                code_info * codes[length_children];
                int i = 0;

                // Je recupere dans un premier temps le code des enfants du noeud courant
                while(arbre != NULL && length_children > 0){
                        codes[i] = generation(arbre->first);
                        i++;
                        arbre = arbre->next;
                }

                // Je peux maintenant traiter le code du noeud en parametre
                if(strcmp(a->name, "=") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        if(infos->val == NULL){
                                infos->code = strdup(concatener(4, codes[0]->code, "=", codes[1]->code, ";\n"));
                        } else {
                                char * tmp = codes[1]->code;
                                infos->code = concatener(4, tmp, codes[0]->code, "=", codes[1]->val);
                        }
                        return infos;
                } else if (strcmp(a->name, "+") == 0) {
                         // ^ il faudra introduire le nombre de var temp créées
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        if(infos->val == NULL){
                                infos->code = strdup(concatener(4, codes[0]->code, "+", codes[1]->code, ";\n"));
                        }else{
                                char * tmp = codes[1]->code;
                                infos->code = concatener(4, tmp, codes[0]->code, "+", codes[1]->val);
                        }
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "-") == 0){ // Il faut aussi verifier s'il s'agit d'une opération unaire
                       code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "-", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "*") == 0){ // Il faut aussi vérifier s'il s'agit d'un pointeur
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "*", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "/") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "/", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, ">") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, ">", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "<") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "<", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, ">=") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, ">=", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                        
                } else if (strcmp(a->name, "<=") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "<=", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "==") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "==", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "!=") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "!=", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "&&") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "&&", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } else if (strcmp(a->name, "||") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        infos->code = strdup(concatener(5, "_t=", codes[0]->code, "||", codes[1]->code, ";\n"));
                        infos->val = strdup("_t");
                        return infos;
                } /* else if (strcmp(a->name, "&") == 0){
                        
                } else if (strcmp(a->name, "->") == 0){
                        
                } else if (strcmp(a->name, ".") == 0){

                }*/ else if (strcmp(a->name, "RETURN") == 0){
                        code_info * infos = malloc(sizeof(code_info));
                        assert(infos != NULL);
                        
                        if (infos->val == NULL){
                                infos->code = strdup(concatener(3, "return", codes[0]->code, ";\n"));
                        } else {
                                char * tmp = codes[1]->code;
                                infos->code = concatener(4, tmp, codes[0]->code, "return", codes[1]->val);
                        }
                        return infos;
                } else if (strcmp (a->name, "main") == 0){ 
                        int i = 0;
                        if(length_children == 0)
                                return codes[0];

                        while(i < length_children - 1){
                                if(length_children == 1)
                                        break;
                                strcat(codes[0]->code, codes[i+1]->code);
                                i++;
                        }
                        return codes[0];
                } else { // Soit le cas n'est pas implémenté, soit il s'agit d'une variable ou une constante
                        if(a->name != NULL){
                                  code_info * infos = malloc(sizeof(code_info));
                                  assert(infos != NULL);
                                  infos->code = a->name;
                                return infos;
                        }
                                
                        printf("ERREUR: il y a un pb d'implémentation ... \n");
                        exit(1);
                }
        }

        int main(){
                while(1){
                        yyparse();
                }
        }