#include "table_symb.h"
#include <stdarg.h>

typedef struct node_ {
        char * name;
        bool isConst;
        struct nodes_list_ * children;
        ts_type ts_t;
        type_t type;
        symbole_t * symb;
        char * code;
        char * val;
} node_t;

typedef struct nodes_list_ {
        struct node_ * first;
        struct nodes_list_ * next;
}nodes_list_t;

node_t * create_node(char * name, nodes_list_t * nodesList);
nodes_list_t * mergeNodes(int nbPara, ...);
nodes_list_t * pushNode(nodes_list_t * t, node_t * n);
void print_node(node_t * n);
void print_tree(nodes_list_t * n, char * space);
nodes_list_t * concatNodes(nodes_list_t * n1, nodes_list_t * n2); // deux noeuds deviennent freres