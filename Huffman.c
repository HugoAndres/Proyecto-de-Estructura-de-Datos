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
struct Lista *crearNodo (char dato, int frecuencia, struct Arbol *arbol);
struct Lista *altaInicio (struct Lista *inicio, char dato, int fracuencia,
			  struct Arbol *arbol);
struct Lista *altaPosicion (struct Lista *inicio, int posicion, int fecuencia,
			    char dato, struct Arbol *arbol);
struct Lista *altaFinal (struct Lista *inicio, char dato, int frecuencia,
			 struct Arbol *arbol);
struct Lista *bajaInicio (struct Lista *inicio);
struct Lista *bajaPosicion ();
struct Lista *bajaFinal (struct Lista *inicio);
struct Lista *generarListadeFrecuencias (char *frase);
struct Lista *ordenarLista (struct Lista *inicio);
struct Arbol *crearNodoHoja (char caracter, int frecuencia);
void Mostrar (struct Lista *inicio);
void generarArbol (struct Lista *inicio, struct Lista *inicioOriginal,
		   struct Arbol **raiz);
void mostrarArbolPreOrden (struct Arbol *raiz);
void generarListaArbolPreOrden (struct Arbol *raiz, struct Lista **inicio);
void crearArchivodelArbol (struct Arbol *raiz, struct Lista *inicio);
void conseguirCodificacion (struct Arbol *raiz, char codigoCaracter[],
			    struct Lista **inicio, int i);
void mostrarCodigos (struct Lista *inicio);
void conseguirCodigoBinario (struct Lista *codigos, char oracion[],
			     char codificacionB[], char codificacionC[]);
void crearArchivodeCodigo (char codificacionC[]);
int Tamano (struct Lista *inicio);
struct Lista *conseguirArbolPreOrden ();
struct Arbol *altoArbol (struct Lista **inicio, struct Arbol *arbol);
struct Arbol *generarArbolPreOrden (struct Arbol *raiz,
				    struct Lista **inicio);
void leerArchivoCodificado (char frase[]);
void conseguirBinarioLeido (unsigned char codificado[],
			    unsigned char codificadoBinario[]);
void conseguirMensaje (char codificadoLeidoB[],
		       struct Lista *codigosConstruidos, char mensaje[]);
