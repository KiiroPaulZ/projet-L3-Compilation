#include "table_symb.h"
#include <stdarg.h>

typedef struct node_ { // Représentation d'un noeud
        char * name;
        bool isConst; // Constante ou non
        struct nodes_list_ * children; // Ses enfants, si c'est null c'est qu'il s'agit d'une feuille
        ts_type ts_t; // Nature du symbole qui lui sera associé
        type_t type;
        symbole_t * symb; // Symbole associé
} node_t;

typedef struct nodes_list_ { // Liste de noeuds freres
        struct node_ * first;
        struct nodes_list_ * next;
} nodes_list_t;

node_t * create_node(char * name, nodes_list_t * nodesList); // Création d'un noeud
nodes_list_t * mergeNodes(int nbPara, ...); // Encapsulation d'un nombre arbitraire de noeuds dans une liste
nodes_list_t * pushNode(nodes_list_t * t, node_t * n); // Un noeud est ajouter à la fin de la liste de noeuds freres
void print_node(node_t * n); // Affichage des infos d'un noeud
void print_tree(nodes_list_t * n, char * space); // On affiche l'arbre construit
nodes_list_t * concatNodes(nodes_list_t * n1, nodes_list_t * n2); // Deux listes de noeuds freres deviennent freres entre eux