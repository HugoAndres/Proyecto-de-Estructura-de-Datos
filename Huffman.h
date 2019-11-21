#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Arbol
{
  char caracter;
  int frecuencia;
  struct Arbol *Izquierdo;
  struct Arbol *Derecho;
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

struct Lista *crearNodo (char, int, struct Arbol *);
struct Lista *altaInicio (struct Lista *, char, int, struct Arbol *);
struct Lista *altaPosicion (struct Lista *, int, int, char, struct Arbol *);
struct Lista *altaFinal (struct Lista *, char, int, struct Arbol *);
int Tamano (struct Lista *);
void Mostrar (struct Lista *);

struct Lista *generaListadeFrecuencia (char *);
struct Lista *ordenarLista (struct Lista *);
void generarArbol (struct Lista *, struct Lista *, struct Arbol **);
void mostrarArbolPreOrden (struct Arbol *);
void generarListaArbolPreOrden (struct Arbol *, struct Lista **);
void crearArchivodeArbol (struct Arbol *, struct Lista *);
void conseguirCodificacion (struct Arbol *, char[], struct Lista **, int);
void conseguirCodigoBinario (struct Lista *, char[], char[], char[]);
void crearArchivodeCodigo (char[]);
struct Arbol *crearNodoHoja (char, int);
void MostrarCodigos (struct Lista *);


struct Lista *conseguirArbolPreOrden ();
struct Arbol *altaArbol (struct Lista **, struct Arbol *);
struct Arbol *generarArbolPreOrden (struct Arbol *, struct Lista **);
void leerArchivoCodificado (unsigned char[]);
void conseguirBinarioLeido (unsigned char[], unsigned char[]);
void conseguirMensaje (unsigned char[], struct Lista *, char[]);
#endif
