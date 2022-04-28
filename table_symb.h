#ifndef _INTERFACE_H
#define _INTERFACE_H
//#define TAILLE 103
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define BUFFER_SIZE 200

int pos;

typedef enum { INT_, VOID_, STRUCT_,  EXTERN_INT_, EXTERN_VOID_, EXTERN_STRUCT_} type_t;

typedef enum { FONCTION_, VARIABLE_, STRUCTURE_} ts_type;

typedef struct _param_t {
    type_t type;
    char *nom;
} param_t;

typedef struct _symbole_t{
    char *nom;
    bool isPtr;
    type_t type;
    int taille;
    int position;
    ts_type ts;
    struct _param_list_t * param_list; // Dans le cas où c'est une fonction on sauvegarde ses paramètres
    struct _symbole_t *suivant;
}symbole_t;

typedef struct _table_t {
    symbole_t *symbole;
    struct _table_t *preced;
}table_t;

typedef struct _param_list_t {
    symbole_t *symbole;
    struct _param_list_t *suivant;
}param_list_t;

param_list_t * param_list_stack;
table_t *pile;

void addParam(param_list_t ** st, symbole_t * s);
param_list_t * copyParamList(param_list_t * stack); // fait une copy de la liste de parametre courante
void clean_param_list_stack();
void displayParam(param_list_t * p);

table_t *nouvelle_table();
void push(table_t * t);

table_t ** top();
symbole_t *rechercher(symbole_t * list, char * name);
symbole_t *ajouter(symbole_t ** list, char *nom);
symbole_t * rechercher_global(table_t * t, char * nom);

table_t * pop();
void detruire_table(table_t ** list);
void print_table();
void print_complete_table();
#endif