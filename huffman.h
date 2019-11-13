#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declarión de las estructuras de arbol binario y lista.

struct Arbol
{
  char caracter;
  int frecuencia;
  struct nodoHoja *hijoIzquierdo;
  struct nodoHoja *hijoDerecho;
};

struct Lista
{
  char caracter;
  int frecuencia;
  char codificacion[8];
  struct Lista *siguiente;
  struct Lista *anterior;
  struct Arbol *arbol;
};

//Posibles cabeceras de las funciones que seran implementadas.
struct Lista *crearNodo (char, int , struct Arbol *);
struct Lista *altaInicio (struct Lista *, char , int ,
			  struct Arbol *);
struct Lista *altaPosicion (struct Lista *, int , int,
			    char , struct Arbol *);
struct Lista *altaFinal (struct Lista *, char , int ,
			 struct Arbol *);
struct Lista *bajaInicio (struct Lista *);
struct Lista *bajaPosicion ();
struct Lista *bajaFinal (struct Lista *);
struct Lista *generarListadeFrecuencias (char *);
struct Lista *ordenarLista (struct Lista *);
struct Arbol *crearNodoHoja (char , int );
void Mostrar (struct Lista *);
void generarArbol (struct Lista *, struct Lista *,
		   struct Arbol **);
void mostrarArbolPreOrden (struct Arbol *);
void generarListaArbolPreOrden (struct Arbol *, struct Lista **);
void crearArchivodelArbol (struct Arbol *, struct Lista *);
void conseguirCodificacion (struct Arbol *, char ,
			    struct Lista **, int );
void mostrarCodigos (struct Lista *);
void conseguirCodigoBinario (struct Lista *, char ,
			     char , char );
void crearArchivodeCodigo (char );
int Tamano (struct Lista *);
struct Lista *conseguirArbolPreOrden ();
struct Arbol *altoArbol (struct Lista **, struct Arbol *);
struct Arbol *generarArbolPreOrden (struct Arbol *,
				    struct Lista **);
void leerArchivoCodificado (char );
void conseguirBinarioLeido (unsigned char ,
			    unsigned char );
void conseguirMensaje (char ,
		       struct Lista *, char );
#endif
