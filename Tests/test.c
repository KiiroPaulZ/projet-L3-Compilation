#include "../nodes.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

/*int main(){
    int i;
    int j;
    int k;
    i = 1;
    j = 1;
    k = i + j;
}*/
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

        void print_tree(nodes_list_t * n, char * space){
                printf("%s\n", n->first->name);
                //current = n->children;
                nodes_list_t * current = n->first->children;
                while(current != NULL){ // Tant que le pere a des enfants
                    printf("%s|___> ", space);
                    printf("%s \n", current->first->name);
                    nodes_list_t * depth_current = current->first->children;
                    while(depth_current != NULL){ //tant que j'ai pas vu tout les enfants
                        char * newspace = "     ";
                        char target[strlen(space) + strlen(newspace) + 1];
                        strcpy(target, space);
                        strcat(target, newspace);
                        printf("%s|___> ", target);
                        print_tree(depth_current, target);
                        depth_current = depth_current->next;
                        printf("\n");
                    }
                    current = current->next;
                }
        };

        node_t * create_node(char * name, nodes_list_t * nodesList){
                node_t * n = malloc(sizeof(node_t));
                assert(n != NULL);
                n->name = name;
                n->children = nodesList;
                //print_node(n);
                return n;
        };

/*void outputTree(node_t * treePtr, int spaces){ 
    int loop; // loop counter
    // while not the end of tree
    while ( treePtr != NULL ) { 
            // recursive call with right subtree
            outputTree(treePtr->childrenR, spaces + 5 );
            
            // loop and output spaces
            for ( loop = 1; loop <= spaces; ++loop ) { printf( "%s", " "); } // end for 
            printf( "%s\n", treePtr->name);
            
            // set pointer to left subtree and make recursive call
            outputTree( treePtr->childrenL, spaces + 5 );
            treePtr = NULL;
    } // end while
}; // end function outputTree*/




int main(){
    node_t * a = create_node("a", NULL);
    node_t * b = create_node("b", NULL);
    node_t * c = create_node("c", mergeNodes(2, a, b));

    node_t * d = create_node("d", NULL);
    node_t * e = create_node("e", mergeNodes(1,d));
    node_t * f = create_node("f", mergeNodes(2, c, e));

    /*print_node(f);
    printf("=================\n");
    print_node(c);*/

    print_tree(mergeNodes(1,f),"");
    /*outputTree(create_node("a", 
        create_node("b", 
            create_node("d", NULL, NULL), create_node("e", NULL, NULL)), 
        create_node("c", NULL, NULL)), 0);*/

    return(0);
}


