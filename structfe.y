%{
        #include "nodes.h"
        #include <math.h>
        #define BUFFER_SIZE 200
        #define MAX_STRING_SIZE 40
        #define RED "\033[0;31m"
        #define WHITE "\033[0;37m"
        #define PURPLE "\033[0;35m"
        #define ERROR RED"ERROR: "WHITE
        #define WARNING PURPLE"WARNING: "WHITE
        int yylex();
        int yylineno;
        int yyerror(char *);
        table_t *pile;
        //param_list_stack_t * param_list_stack;
        //int pos;
        void print_table();
        void semanticAnalysis(nodes_list_t * n);
        int paramMatching(param_list_t * a, param_list_t * b);
%}

%union{
    char *nom; // represente nom des variables, fonctions, structures
    char* val;
    type_t type; // int ou void (variable ou fonction)
    // Une fonction prend 0 OU N parametre(s)
    param_t param; //
    param_list_t * param_list;
    //liste_t *liste; // liste de parametres
    node_t * node;
    nodes_list_t * node_list;
    symbole_t * symb;
}

%type<node> expression primary_expression postfix_expression unary_expression program 
%type<node> multiplicative_expression additive_expression relational_expression equality_expression
%type<node> logical_and_expression logical_or_expression declaration struct_specifier
%type<node> struct_declaration
%type<node> ACCOO ACCOF expression_statement selection_statement iteration_statement jump_statement external_declaration function_definition
%type<type> declaration_specifiers type_specifier 
%type<nom> declarator direct_declarator unary_operator
%type<node_list> argument_expression_list struct_declaration_list declaration_list statement_list compound_statement statement
%type<symb> parameter_list parameter_declaration function_init

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
                        s = rechercher_global(stack_head, $1);
                        n = create_node($1, NULL);
                        n->symb = s;
                        $$ = n;
                      }
        | CONSTANT { node_t * n = NULL; n = create_node($1, NULL); /*n->type = INT_;*/ $$ = n; }
        | '(' expression ')' { $$ = $2; }
        ;

postfix_expression
        : primary_expression { $$ = $1; }
        | postfix_expression '(' ')' { 
                if($1->symb != NULL && $1->symb->ts == FONCTION_ && (paramLength(param_list_stack) == paramLength($1->symb->param_list))){
                        $$ = $1;
                } else {
                        clean_param_list_stack();
                        printf("%sLigne %d, ceci n'est pas une fonction anonyme!\n",ERROR, yylineno);
                        exit(1);
                }
        }
        | postfix_expression '(' argument_expression_list ')' {
                // S'il s'agit d'une fonction, qu'il a un symbole associé et que la liste des parametres correspond à la liste de parametres définie initialement
                //displayParam(param_list_stack);
                //displayParam($1->symb->param_list);
                //printf("%d <--\n", paramLength(param_list_stack));
                //printf("1: %d, 2: %d\n", paramLength(param_list_stack), paramLength($1->symb->param_list));
                if($1->symb != NULL && $1->symb->ts == FONCTION_ && (paramLength(param_list_stack) == paramLength($1->symb->param_list))){
                        clean_param_list_stack(); // Après chaque utilisation il faut penser à clean la pile de parametre globale
                        //print_node($1);
                        $$ = $1;
                } else {
                        //printf("%d - %d\n", paramLength(param_list_stack), paramLength($1->symb->param_list));
                        clean_param_list_stack();
                        printf("%sLigne %d, la fonction n'est pas déclaré et/ou le nombre de paramètres n'est pas valide!\n",ERROR, yylineno);
                        exit(1);
                }
        }
        | postfix_expression '.' IDENTIFIER { 
                                                node_t * n = NULL; 
                                                n = create_node(".", mergeNodes(2, $1, create_node($3, NULL))); 
                                                $$ = n;
                                            }
        | postfix_expression PTR_OP IDENTIFIER { 
                                                node_t * n = NULL; 
                                                n = create_node("->", mergeNodes(2, $1, create_node($3, NULL))); 
                                                $$ = n; 
                                               }
        ;

argument_expression_list
        : expression {
                if($1->symb == NULL){
                        symbole_t * s = malloc(sizeof(symbole_t));
                        s->nom = $1->name;
                        $1->symb = s;
                }
                //displayParam(param_list_stack);
                //printf("=========%d-1========\n", yylineno);
                addParam(&param_list_stack, $1->symb);
                //displayParam(param_list_stack);
                //printf("=================\n");
        }
        | argument_expression_list ',' expression{
                if($3->symb == NULL){ // Si le noeud n'a pas de symbole c'est qu'il s'agit d'une opération, donc on lui creer un symbole "vide"
                        symbole_t * s = malloc(sizeof(symbole_t));
                        s->nom = $3->name;
                        $3->symb = s;
                }
                //displayParam(param_list_stack);
                //printf("=========%d-2========\n", yylineno);
                addParam(&param_list_stack, $3->symb);
                //displayParam(param_list_stack);
                //printf("=================\n");
        }
        ;

unary_expression
        : postfix_expression {$$ = $1;}
        | unary_operator unary_expression { 
                                                node_t * n = NULL;
                                                n = create_node($1, mergeNodes(1,$2));
                                                //n->type = $2->type;
                                                $$ = n;
                                          }
        | SIZEOF unary_expression
        ;

unary_operator
        : '&' {$$="&";}
        | '*' {$$="*";}
        | '-' {$$="-";}
        ;

multiplicative_expression
        : unary_expression {$$ = $1;}
        | multiplicative_expression '*' unary_expression {$$ = create_node("*", mergeNodes(2,$1,$3));}
        | multiplicative_expression '/' unary_expression {$$ = create_node("/", mergeNodes(2,$1,$3));}
        ;

additive_expression
        : multiplicative_expression {$$ = $1;}
        | additive_expression '+' multiplicative_expression {$$ = create_node("+", mergeNodes(2,$1,$3));}
        | additive_expression '-' multiplicative_expression {$$ = create_node("-", mergeNodes(2,$1,$3));}
        ;

relational_expression
        : additive_expression {$$ = $1;}
        | relational_expression '<' additive_expression {$$ = create_node("<", mergeNodes(2,$1,$3));}
        | relational_expression '>' additive_expression {$$ = create_node(">", mergeNodes(2,$1,$3));}
        | relational_expression LE_OP additive_expression {$$ = create_node("<=", mergeNodes(2,$1,$3));}
        | relational_expression GE_OP additive_expression {$$ = create_node(">=", mergeNodes(2,$1,$3));}
        ;

equality_expression
        : relational_expression {$$ = $1;}
        | equality_expression EQ_OP relational_expression {$$ = create_node("==", mergeNodes(2,$1,$3));}
        | equality_expression NE_OP relational_expression {$$ = create_node("!=", mergeNodes(2,$1,$3));}
        ;

logical_and_expression
        : equality_expression {$$ = $1;}
        | logical_and_expression AND_OP equality_expression {$$ = create_node("&&", mergeNodes(2,$1,$3));}
        ;

logical_or_expression
        : logical_and_expression {$$ = $1;}
        | logical_or_expression OR_OP logical_and_expression {$$ = create_node("||", mergeNodes(2,$1,$3));}
        ;

expression
        : logical_or_expression {$$ = $1;}
        | unary_expression '=' expression {
                $$ = create_node("=", mergeNodes(2,$1,$3));
        }
        ;

declaration
        : declaration_specifiers declarator ';' {       
                                                        
                                                        //print_table();
                                                        //print_complete_table();
                                                        if($1 == VOID_){
                                                                printf("%sLigne %d, vous ne pouvez pas déclarer une variable de type void.\n", ERROR, yylineno);
                                                                exit(1);
                                                        }
                                                        symbole_t *s = NULL;
                                                        table_t * stack_head = pile;
                                                        if(stack_head == NULL){
                                                                table_t *table = nouvelle_table(); push(table); // Si la pile est vide on l'initialise
                                                        }
                                                        table_t * current = stack_head;

                                                        if(current != NULL)
                                                                s = rechercher(current->symbole, $2);

                                                        //print_table();
                                                        symbole_t * s2 = NULL;
                                                        if(stack_head != NULL)
                                                                s2 = rechercherStack((getSymbole(stack_head->preced->symbole,-1))->param_list, $2); // Je vérifie aussi s'il existe dans les parametres des symboles de la fonction

                                                        if(s != NULL){
                                                                printf("%sLigne %d, la variable '%s' a déjà été déclarée.\n", ERROR, yylineno, $2);
                                                                print_table();
                                                                exit(1);
                                                        } else if (s2 != NULL) {
                                                                print_complete_table();
                                                                printf("%sLigne %d, vous ne pouvez pas déclarer %s car elle est défini en parametre de fonction.\n", ERROR, yylineno, $2);
                                                                exit(1);
                                                         }else {
                                                                while(current != NULL){ // je vérifie si la variable a deja été declaré
                                                                        if(current ->symbole != NULL){
                                                                                s = rechercher(current->symbole, $2);
                                                                                if(s != NULL)
                                                                                        break;
                                                                        }
                                                                        current  = current ->preced;
                                                                }
                                                                if(s != NULL)
                                                                        printf("%sLigne %d, la variable '%s' en masque une autre\n", WARNING, yylineno, $2);
                                                                table_t * t = *top(); // Le symbole n'existe pas, il faut le définir
                                                                s = ajouter(&(t->symbole), $2);
                                                                if($1 == EXTERN_INT_ || $1 == EXTERN_VOID_ || $1 == EXTERN_STRUCT_){ // Ici on gere les extern
                                                                        s->ts = FONCTION_; //EXTERN_FONCTION_;
                                                                        if(param_list_stack != NULL){ // S'il a des paramètres, on les sauvegardes
                                                                                s->param_list = copyParamList(param_list_stack);
                                                                                //displayParam(s->param_list);
                                                                                clean_param_list_stack();
                                                                        }
                                                                        switch($1){
                                                                                case EXTERN_INT_: s->type = INT_; break;
                                                                                case EXTERN_VOID_ : s->type = VOID_; break;
                                                                                default : s->type = STRUCT_;
                                                                        }
                                                                } else {
                                                                        s->type = $1;
                                                                        s->ts = VARIABLE_;
                                                                }
                                                                s->taille = sizeof($1);
                                                                s->position = pos;
                                                                s->suivant = NULL;
                                                                pos += s->taille;
                                                        }
                                                        //print_table();
                                                        //print_complete_table();
                                                }
        | struct_specifier ';'
        ;

declaration_specifiers
        : EXTERN type_specifier {       
                                        switch($2){
                                                case INT_: $$ = EXTERN_INT_; break;
                                                case VOID_: $$ = EXTERN_VOID_; break;
                                                default: $$ = EXTERN_STRUCT_;
                                        }
                                }
        | type_specifier {$$ = $1;}
        ;

type_specifier
        : VOID { $$ = VOID_ ;}
        | INT { $$ = INT_ ;}
        | struct_specifier {$$ = STRUCT_ ;}
        ;

struct_specifier
        : STRUCT IDENTIFIER '{' struct_declaration_list '}'
        | STRUCT '{' struct_declaration_list '}'
        | STRUCT IDENTIFIER
        ;

struct_declaration_list
        : struct_declaration
        | struct_declaration_list struct_declaration
        ;

struct_declaration
        : type_specifier declarator ';'
        ;

declarator
        : '*' direct_declarator { 
                char p[strlen($2)+2]; 
                sprintf(p, "*%s", $2); 
                //printf("p : %s\n",p);
                $$ = strdup(p);
        }
        | direct_declarator { $$ = $1; }
        ;

direct_declarator
        : IDENTIFIER {$$ = $1;}
        | '(' declarator ')' {$$ = $2;}
        | direct_declarator '(' parameter_list ')' {
                //clean_param_list_stack();
                $$ = $1;
        }
        | direct_declarator '(' ')' {$$ = $1;}
        ;

parameter_list
        : parameter_declaration {
                addParam(&param_list_stack, $1);
                //displayParam(param_list_stack);
        }
        | parameter_list ',' parameter_declaration {
                addParam(&param_list_stack, $3);
                //displayParam(param_list_stack);
        }
        ;

parameter_declaration
        : declaration_specifiers declarator {
                char * nom = $2; // Je sauvegarde les informations
                symbole_t * s;
                s = malloc(sizeof(symbole_t));
                s->type = $1;
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
        : compound_statement {$$ = mergeNodes(1, $1);}
        | expression_statement {$$ = mergeNodes(1, $1);}
        | selection_statement {$$ = mergeNodes(1, $1);}
        | iteration_statement {$$ = mergeNodes(1, $1);}
        | jump_statement {$$ = mergeNodes(1, $1);}
        ;

compound_statement
        : ACCOO ACCOF {$$ = NULL;}
        | ACCOO statement_list ACCOF {$$ = $2;}
        | ACCOO declaration_list ACCOF {$$ = NULL;}
        | ACCOO declaration_list statement_list ACCOF {$$ = $3;}
        ;

ACCOO : '{' {table_t *table = nouvelle_table(); push(table);}
ACCOF : '}' {
                /*table_t *table = pop(); 
                detruire_table(&table);
                if((*top()) != NULL){ // autrement dit si la pile est vide    
                    //print_table();
                } else {
                    printf("[]\n");
                }*/
            }

declaration_list
        : declaration
        | declaration_list declaration
        ;

statement_list
        : statement { $$ = $1;}
        | statement_list statement {$$ = pushNode($1, $2->first);}
        ;

expression_statement
        : ';'
        | expression ';' {$$ = $1;}
        ;

selection_statement
        : IF '(' expression ')' statement %prec ELSE_PRIORITY
        | IF '(' expression ')' statement ELSE statement %prec ELSE
        ;

iteration_statement
        : WHILE '(' expression ')' statement
        | FOR '(' expression_statement expression_statement expression ')' statement
        ;

jump_statement
        : RETURN ';' 
        | RETURN expression ';' {$$ = $2; /*$$ = create_node("jump_statement", mergeNodes(3,create_node("return", NULL), $2, create_node(";", NULL)));*/}
        ;

program_start: program {
                                table_t *table = pop(); 
                                detruire_table(&table);
                                if((*top()) != NULL){ // autrement dit si la pile est vide    
                                        //print_table();
                                } else {
                                        printf("[]\n");
                                }
                        };

program
        : external_declaration {
                nodes_list_t * arbre = NULL;
                if($1 != NULL){
                        $$ = create_node("prog", mergeNodes(1, $1)); 
                        arbre = mergeNodes(1, $1);
                        
                        print_tree(arbre, "");
                }
        }
        | program external_declaration {
                nodes_list_t * arbre = NULL;
                if($2 != NULL){
                        $$ = create_node("prog", mergeNodes(1, $2));
                        arbre = mergeNodes(1, $2);
                        
                        print_tree(arbre, "");
                }
        }
        ;

external_declaration
        : function_definition { $$ = $1;}
        | declaration { $$ = NULL;}
        ;

function_init
        : declaration_specifiers declarator {
                
                symbole_t *s = NULL;
                table_t * stack_head = pile;
                if(stack_head == NULL){
                        table_t *table = nouvelle_table(); push(table); // Si la pile est vide on l'initialise
                }
                while(stack_head != NULL){
                        if(stack_head->symbole != NULL){
                        s = rechercher(stack_head->symbole, $2);
                        if(s != NULL)
                                break;
                        }
                        stack_head = stack_head->preced;
                }
                if(s == NULL) {
                        if(s != NULL)
                                printf("%sLigne %d, la fonction '%s' en masque une autre\n", WARNING, yylineno, $2);
                        table_t * t = *top();
                        s = ajouter(&(t->symbole), $2);
                        s->type = $1;
                        s->ts = FONCTION_;
                        s->taille = sizeof($1);
                        s->position = pos;
                        s->suivant = NULL;
                        pos += s->taille;
                        //displayParam(param_list_stack);  
                }
                //print_table();
                //print_complete_table();
                if(($2)[0] == '*')
                        $2++;
                
                s->param_list = copyParamList(param_list_stack);
                $$ = s;
                displayParam(s->param_list);
                clean_param_list_stack();
                print_table();
        }

function_definition
        :  function_init compound_statement {   
                                                printf("affichage du compound:\n");
                                                print_tree($2, "");
                                                clean_param_list_stack();              
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

        table_t ** top() {
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

        symbole_t * rechercher_global(table_t * t, char * nom){
                if(t != NULL){
                        table_t * table = t;
                        while(table != NULL){
                                symbole_t * s = NULL;
                                s = rechercher(table->symbole, nom);
                                if(s != NULL)
                                        return s;
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
                                printf("        NAME: %-22s | isPTR: %d | type: %2d | TAILLE: %3d | POSITION: %3d | TS NATURE: %2d\n", stack->symbole->nom, stack->symbole->isPtr, stack->symbole->type, stack->symbole->taille, stack->symbole->position, stack->symbole->ts);
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

                if(nbPara == 1)
                        return n;

                n->next = malloc(sizeof(nodes_list_t));

                nodes_list_t * temp = n->next;

                for(int j = 1; j < nbPara; j++){
                        node_t * current = va_arg(ap, node_t *);
                        temp->first = current;
                        if(j != nbPara -1){
                                temp->next = malloc(sizeof(nodes_list_t));
                                temp = temp->next;
                        }
                }
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
                //current = n->children;
                nodes_list_t * current = n->first->children;
                char * newspace = "     ";
                //char ntarget[strlen(space) + strlen(newspace) + 1];
                while(current != NULL){ // Tant que le pere a des enfants
                    //strcpy(ntarget, space);
                    printf("%s     |___> ", space);
                    //strcat(ntarget, newspace);
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
                if(stack == NULL){
                        return NULL;
                }
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
                //param_list_t * current = *stack;
                while (*stack != NULL)
                {       
                        //current = NULL;
                        *stack = (*stack)->suivant;
                }
                /*printf("=========%d-3========\n", yylineno);
                
                displayParam(param_list_stack);
                printf("=================\n");*/
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

        int main(){
                while(1){
                        yyparse();
                }
        }