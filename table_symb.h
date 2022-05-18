#ifndef _INTERFACE_H

#define _INTERFACE_H
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum { INT_, VOID_, STRUCT_,  EXTERN_INT_, EXTERN_VOID_, EXTERN_STRUCT_} type_t;

typedef enum { FONCTION_, VARIABLE_, STRUCTURE_} ts_type; // "Nature" des symboles

typedef struct _param_t { // un parametre a un type et un nom
    type_t type;
    char *nom;
} param_t;

typedef struct _symbole_t{ // Structure d'un symbole
    char *nom;
    bool isPtr; // S'il s'agit d'un pointeur
    bool is_function_def; // S'il s'agit d'une définition de fonction
    char * marker; // connaitre le scope de la déclaration
    type_t type;
    int taille; // Sa taille en mémoire
    int position;
    ts_type ts; // "Nature" du symbole 
    struct _param_list_t * param_list; // Dans le cas où c'est une fonction on sauvegarde ses paramètres
    struct _field_list_t * field_list; // Dans le cas où c'est une fonction on sauvegarde ses paramètres
    struct _symbole_t *suivant; // On chaine les symboles
} symbole_t;

typedef struct _table_t { // La TS est une pile de listes de symboles
    symbole_t *symbole; 
    struct _table_t *preced;
} table_t;

typedef struct _param_list_t { // Liste des parametres de fonction courant
    symbole_t *symbole;
    struct _param_list_t *suivant;
} param_list_t;

typedef struct _field_list_t { // Liste des champs de structure courant
    symbole_t *symbole;
    struct _field_list_t *suivant;
} field_list_t;

typedef struct _code_info { // Encapsulation textuelle pour sa représentation dans le backend
    char * code;
    char * val;
} code_info;

/* Variables globales */
int pos; // Pointeur sur une case disponible en mémoire
param_list_t * param_list_stack; 
field_list_t * field_list_stack; 
table_t *pile; // TS


// Primitives pour la pile de parametres
void addParam(param_list_t ** st, symbole_t * s); // Ajouter un parametre à la liste 
param_list_t * copyParamList(param_list_t * stack); // Fait une copie de la liste de parametres
void clean_param_list_stack(); // Le pointeur de la liste est redirigé
void displayParam(param_list_t * p); // Afficher la liste des paramètres
int paramLength(param_list_t * p); // Longueur de la liste
symbole_t * rechercherStack(param_list_t * p, char * nom); // Chercher un symbole dans la liste en fonction de son nom

// Primitives pour la pile des champs de structures
void addField(field_list_t ** ft, symbole_t * s); // Ajouter un champs à la liste 
field_list_t * copyFieldList(field_list_t * stack); // fait une copie de la liste de champs
void clean_field_list_stack(); // Le pointeur de la liste est redirigé sur null
void displayField(field_list_t * p); // Afficher la liste des paramètres
int fieldLength(field_list_t * p); // Longueur de la liste
symbole_t * rechercherFieldStack(field_list_t * p, char * nom); // Chercher un symbole dans la liste en fonction de son nom

// Primitives pour la TS
table_t *nouvelle_table(); // Initialisation d'une table
void push(table_t * t); // Ajouter la table à la TS
table_t ** top(); // Pointeur sur le sommet de la pile
symbole_t *rechercher(symbole_t * list, char * name); // Rechercher un symbole dans une liste de symbole
symbole_t *ajouter(symbole_t ** list, char *nom);
symbole_t * rechercher_global(table_t * t, char * nom, int n, char * mark); // Recherche global à un niveau de la pile jusqu'en bas, par defaut mettre n à 0 et mark à ""
table_t * pop(); // Enlever le premier element de la pile
void detruire_table(table_t ** list); // détruire le contenue d'une table et celle-ci
void print_table(); // Affichage rudimentaire de la table
void print_complete_table(); // Affichage plus complet de la table
symbole_t * getSymbole(symbole_t * list, int n); // Recuperer un symbole à une position n, si -1 on récupere le dernier element
symbole_t * getSymboleList(table_t * t, int n); // getSymbole() appliqué globalement

#endif