/*Examen
Cortez Barbosa Emiliano
2CV3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100

struct Nodo
{
    //Datos
    char nombre[size];
    char nacionalidad[size];
    //Ramas
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

struct Nodo *raizOro = NULL;
struct Nodo *raizPlata = NULL;
struct Nodo *raizBronce = NULL;

struct Nodo *nuevoNodo(char nombre[size],char nacionalidad[size])
{
    // Solicitar memoria
    size_t tamanioNodo = sizeof(struct Nodo);
    struct Nodo *arbol = (struct Nodo *)malloc(tamanioNodo);
    // Asignar datos
    strcpy(arbol->nombre, nombre);
    strcpy(arbol->nacionalidad, nacionalidad);
    arbol->izquierda = arbol->derecha = NULL;
    return arbol;
}

void agregarOro(struct Nodo *arbol, char *nombre, char *nacionalidad)
{

    if (raizOro == NULL)
    {
        raizOro = nuevoNodo(nombre,nacionalidad);
    }else if (strcmp(nombre, arbol->nombre) > 0)
    {
        if (arbol->derecha == NULL)
        {
            arbol->derecha = nuevoNodo(nombre,nacionalidad);
        }
        else
        {
            agregarOro(arbol->derecha, nombre,nacionalidad);
        }
    }
    else
    {
        if (arbol->izquierda == NULL)
        {
            arbol->izquierda = nuevoNodo(nombre,nacionalidad);
        }
        else
        {
            agregarOro(arbol->izquierda,nombre,nacionalidad);
        }
    }
}

void agregarPlata(struct Nodo *arbol, char *nombre, char *nacionalidad)
{

    if (raizPlata == NULL)
    {
        raizPlata = nuevoNodo(nombre,nacionalidad);
    }else if (strcmp(nombre, arbol->nombre) > 0)
    {
        if (arbol->derecha == NULL)
        {
            arbol->derecha = nuevoNodo(nombre,nacionalidad);
        }
        else
        {
            agregarPlata(arbol->derecha, nombre,nacionalidad);
        }
    }
    else
    {
        if (arbol->izquierda == NULL)
        {
            arbol->izquierda = nuevoNodo(nombre,nacionalidad);
        }
        else
        {
            agregarPlata(arbol->izquierda,nombre,nacionalidad);
        }
    }
}

void agregarBronce(struct Nodo *arbol, char *nombre, char *nacionalidad)
{

    if (raizBronce == NULL)
    {
        raizBronce = nuevoNodo(nombre,nacionalidad);
    }else if (strcmp(nombre, arbol->nombre) > 0)
    {
        if (arbol->derecha == NULL)
        {
            arbol->derecha = nuevoNodo(nombre,nacionalidad);
        }
        else
        {
            agregarBronce(arbol->derecha, nombre,nacionalidad);
        }
    }
    else
    {
        if (arbol->izquierda == NULL)
        {
            arbol->izquierda = nuevoNodo(nombre,nacionalidad);
        }
        else
        {
            agregarBronce(arbol->izquierda,nombre,nacionalidad);
        }
    }
}

void preorden(struct Nodo *arbol)
{
    if (arbol != NULL)
    {
        printf("%s %s\n", arbol->nombre,arbol->nacionalidad);
        preorden(arbol->izquierda);
        preorden(arbol->derecha);
    }
}

void inorden(struct Nodo *arbol)
{
    if (arbol != NULL)
    {
        inorden(arbol->izquierda);
        printf("%s %s\n", arbol->nombre,arbol->nacionalidad);
        inorden(arbol->derecha);
    }
}

void postorden(struct Nodo *arbol)
{
    if (arbol != NULL)
    {
        postorden(arbol->izquierda);
        postorden(arbol->derecha);
        printf("%s %s\n", arbol->nombre,arbol->nacionalidad);
    }
}

struct Nodo *buscar(struct Nodo *arbol, char *nombre, char *nacionalidad)
{
    if (arbol == NULL)
    {
        return NULL;
    }
    if (strcmp(nombre,arbol->nombre) == 0 && strcmp(nacionalidad,arbol->nacionalidad) == 0)
    {
        return arbol;
    }
    else if (strcmp(nombre,arbol->nombre) > 0)
    {
        return buscar(arbol->derecha,nombre,nacionalidad);
    }
    else
    {
        return buscar(arbol->izquierda,nombre,nacionalidad);
    }
}

int main(int argc, char const *argv[])
{
    
    int tamano=50;
    int i=0;
    char nom[size];
    char nac[size];
    char medalla[size];
    
    // Agregar datos dede archivo de texto

    for (i=0;i<tamano;i++){

        scanf("%s %s %s",&nom,&nac,&medalla);

        if(strcmp(medalla, "Oro") == 0){

            agregarOro(raizOro,nom,nac);

        }else if(strcmp(medalla, "Plata") == 0){

            agregarPlata(raizPlata,nom,nac);

        }else{

            agregarBronce(raizBronce,nom,nac);

        }

    }
    //Oro
    printf("\n\nPreorden Oro: \n");
    preorden(raizOro);

    printf("\n\nInorden Oro: \n");
    inorden(raizOro);

    printf("\n\nPostorden Oro: \n");
    postorden(raizOro);

    //Plata
    printf("\n\nPreorden Plata: \n");
    preorden(raizPlata);

    printf("\n\nInorden Plata: \n");
    inorden(raizPlata);

    printf("\n\nPostorden Plata: \n");
    postorden(raizPlata);

    //Bronce
    printf("\n\nPreorden Bronce: \n");
    preorden(raizBronce);

    printf("\n\nInorden Bronce: \n");
    inorden(raizBronce);

    printf("\n\nPostorden Bronce: \n");
    postorden(raizBronce);


    printf("\n");

    //Búsqueda
    printf("\nEscriba el nombre y nacionalidad del atleta separados por un espacio:\n Ejemplo:William Italiano\n");
    scanf("%s %s",&nom,&nac);


    struct Nodo *apuntador = buscar(raizOro,nom,nac);
    if (apuntador != NULL)
    {
        printf("%s tiene medalla de oro\n", nom,nac);
    }
    else
    {
        apuntador = buscar(raizPlata,nom,nac);
        
        if (apuntador != NULL)
        {
            printf("%s tiene medalla de plata\n", nom);
        }else{

            apuntador = buscar(raizBronce,nom,nac);

            if (apuntador != NULL)
        {
            printf("%s tiene medalla de Bronce\n", nom);

        }else{

            printf("%s no se encuentra en la lista o tiene otra nacionalidad\n", nom);

        }
    }
    }

    return 0;
}
