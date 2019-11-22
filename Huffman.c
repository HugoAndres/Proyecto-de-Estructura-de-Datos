#include "Huffman.h"

struct Lista *
crearNodo (char dato, int frecuencia, struct Arbol *arbol)
{
  struct Lista *nuevo = NULL;
  nuevo = (struct Lista *) malloc (sizeof (struct Lista));
  nuevo->caracter = dato;
  nuevo->frecuencia = frecuencia;
  nuevo->siguiente = NULL;
  nuevo->anterior = NULL;
  nuevo->arbol = arbol;
};

struct Lista *
creaLista (struct Lista *inicio, char dato, int frecuencia,
	    struct Arbol *arbol)
{
  struct Lista *nuevo = NULL;
  nuevo = crearNodo (dato, frecuencia, arbol);
  if (inicio == NULL)
    {
      inicio = nuevo;
    }
  else
    {
      nuevo->siguiente = inicio;
      inicio->anterior = nuevo;
      inicio = nuevo;
    }
  return inicio;
};

struct Lista *
posicionPadre (struct Lista *inicio, int posicion, int frecuencia,
	      char dato, struct Arbol *arbol)
{
  struct Lista *nuevo = NULL;
  struct Lista *recorre = NULL;
  int tamano = 0;
  int i = 1;
  tamano = Tamano (inicio);
  if (inicio != NULL)
    {
      if (posicion > tamano + 1)
	{
	  printf ("%d\n", posicion);
	  printf ("Posición invalida.\n");
	}
      else if (posicion == 1)
	{
	  inicio = creaLista (inicio, dato, frecuencia, arbol);
	}
      else if (posicion == tamano + 2)
	{
	  inicio = recorreInicio (inicio, dato, frecuencia, arbol);
	}
      else
	{
	  nuevo = crearNodo (dato, frecuencia, arbol);
	  recorre = inicio;
	  while (i != posicion)
	    {
	      i++;
	      recorre = recorre->siguiente;
	    }
	  nuevo->anterior = recorre->anterior;
	  nuevo->siguiente = recorre;
	  recorre->anterior->siguiente = nuevo;
	  recorre->anterior = nuevo;
	}
    }
  return inicio;
};

struct Lista *
recorreInicio (struct Lista *inicio, char dato, int frecuencia,
	   struct Arbol *arbol)
{
  struct Lista *nuevo = NULL;
  struct Lista *recorre = NULL;
  nuevo = crearNodo (dato, frecuencia, arbol);
  if (inicio == NULL)
    {
      inicio = nuevo;
    }
  else
    {
      recorre = inicio;
      while (recorre->siguiente != NULL)
	{
	  recorre = recorre->siguiente;
	}
      recorre->siguiente = nuevo;
      nuevo->anterior = recorre;
    }
  return inicio;
};

void
Mostrar (struct Lista *inicio)
{
  int contador = 0;
  if (inicio == NULL)
    {
      printf ("Lista vacia.\n");
    }
  else
    {
      printf ("Caracter:\tFrecuencia:\n\n");
      while (inicio != NULL)
	{
	  printf ("%c\t\t%d\n", inicio->caracter, inicio->frecuencia);
	  contador++;
	  inicio = inicio->siguiente;
	}
    }
};

int
Tamano (struct Lista *inicio)
{
  int contador = 0;
  if (inicio == NULL)
    {
      printf ("Lista vacia.\n");
    }
  else
    {
      while (inicio->siguiente != NULL)
	{
	  contador++;
	  inicio = inicio->siguiente;
	}
    }
  return contador;
};

struct Lista *
generaListadeFrecuencia (char *frase)
{
  struct Lista *listaGenerada = NULL;
  struct Lista *recorre = NULL;
  int i = 0;
  int flag = 0;
  while (frase[i] != '\0')
    {
      if (listaGenerada == NULL)
	{
	  listaGenerada = creaLista (listaGenerada, frase[i], 1,NULL);
	}
      else
	{
	  recorre = listaGenerada;
	  if (recorre->caracter == frase[i])
	    {
	      recorre->frecuencia++;
	      flag = 1;
	    }
	  while (recorre->siguiente != NULL && flag == 0)
	    {
	      if (recorre->caracter == frase[i])
		{
		  recorre->frecuencia++;
		  flag = 1;
		}
	      else
		{
		  recorre = recorre->siguiente;
		  flag = 0;
		}
	      if (recorre->caracter == frase[i])
		{
		  recorre->frecuencia++;
		  flag = 1;
		}
	    }
	  if (flag == 0)
	    {
	     listaGenerada = recorreInicio (listaGenerada, frase[i], 1, NULL);
	    }
	  flag = 0;
	}
      i++;
    }
  Mostrar (listaGenerada);
  system ("read -p '' var");
  return listaGenerada;
};

struct Lista *
ordenarLista (struct Lista *inicio)
{
  struct Lista *aux1 = NULL;
  struct Lista *aux2 = NULL;
  struct Lista *aux3 = NULL;

  aux1 = inicio;
  aux2 = inicio;
  aux3 = inicio;
  struct Lista *K;
  K = crearNodo ('K', 1, NULL);
  aux2 = inicio->siguiente;
  while (aux2 != NULL)
    {
      K->caracter = aux2->caracter;
      K->frecuencia = aux2->frecuencia;
      aux1 = aux2->anterior;
      while (aux1 != NULL && K->frecuencia < aux1->frecuencia)
	{
	  aux3 = aux1->siguiente;
	  aux3->frecuencia = aux1->frecuencia;
	  aux3->caracter = aux1->caracter;
	  aux1->caracter = K->caracter;
	  aux1->frecuencia = K->frecuencia;
	  aux1 = aux1->anterior;
	}
      aux2 = aux2->siguiente;
    }
  return inicio;
};

void
generarArbol (struct Lista *inicio, struct Lista *inicioOriginal,
	      struct Arbol **raiz)
{
  struct Arbol *hijoIzquierdo=NULL;
  struct Arbol *hijoDerecho=NULL;
  struct Arbol *padre=NULL;

  int auxfrecuencia = 0;
  char caracterImpro = '*';
  int tamano = 0;

  struct Lista *recorre;
  recorre = inicioOriginal;
  int i = 1;
  int selector = 0;

  if (inicio == NULL)
    {
      while (recorre->siguiente != NULL)
	{
	  recorre = recorre->siguiente;
	}
      *raiz = recorre->arbol;
    }
  else
    {
      if (inicio->arbol != NULL)
	{
	  hijoIzquierdo = inicio->arbol;
	}
      else
	{
	  hijoIzquierdo =
	    crearNodoHoja (inicio->caracter, inicio->frecuencia);
	}
      inicio = inicio->siguiente;
      if (inicio->arbol != NULL)
	{
	  hijoDerecho = inicio->arbol;
	}
      else
	{
	  hijoDerecho = crearNodoHoja (inicio->caracter, inicio->frecuencia);
	}
      inicio = inicio->siguiente;
      auxfrecuencia = hijoIzquierdo->frecuencia + hijoDerecho->frecuencia;
      padre = crearNodoHoja (caracterImpro, auxfrecuencia);
      padre->Izquierdo = hijoIzquierdo;
      padre->Derecho = hijoDerecho;

      while (recorre != NULL && selector == 0)
	{
	  if ((padre->frecuencia + 1) <= recorre->frecuencia)
	    {
	      selector = 1;
	    }
	  else
	    {
	      i++;
	    }
	  recorre = recorre->siguiente;
	}
      tamano = Tamano (inicioOriginal) + 1;
//        printf ("Tamaño: %d\n", tamano+1);
//        printf ("Posicion: %d\n", i);
      if (tamano >= i)
	{
	  inicioOriginal =
	    posicionPadre (inicioOriginal, i, padre->frecuencia,
			  padre->caracter, padre);
	}
      else
	{
	  inicioOriginal =
	    recorreInicio (inicioOriginal, padre->caracter, padre->frecuencia,
		       padre);

	}
//        Mostrar (inicioOriginal);
//        system ("read -p '' var");
      generarArbol (inicio, inicioOriginal, &(*raiz));
    }

};

struct Arbol *
crearNodoHoja (char caracter, int frecuencia)
{
  struct Arbol *nuevo = NULL;
  nuevo = (struct Arbol *) malloc (sizeof (struct Arbol));
  nuevo->caracter = caracter;
  nuevo->frecuencia = frecuencia;
  nuevo->Izquierdo = NULL;
  nuevo->Derecho = NULL;
};

void
mostrarArbolPreOrden (struct Arbol *raiz)
{
  if (raiz != NULL)
    {
      printf ("%c\t%d\n", raiz->caracter, raiz->frecuencia);
      if (raiz->Izquierdo != NULL)
	{
	  mostrarArbolPreOrden (raiz->Izquierdo);
	}
      if (raiz->Derecho != NULL)
	{
	  mostrarArbolPreOrden (raiz->Derecho);
	}
    }
};

void
generarListaArbolPreOrden (struct Arbol *raiz, struct Lista **inicio)
{
  if (raiz != NULL)
    {
      *inicio = recorreInicio (*inicio, raiz->caracter, raiz->frecuencia, NULL);
      if (raiz->Izquierdo != NULL)
	{
	  generarListaArbolPreOrden (raiz->Izquierdo, &*inicio);
	  if (raiz->Derecho != NULL)
	    {
	      generarListaArbolPreOrden (raiz->Derecho, &*inicio);
	    }
	}
    }
};

void
conseguirCodificacion (struct Arbol *raiz, char codigoCaracter[],
		       struct Lista **inicio, int i)
{
  struct Lista *recorre = NULL;
  if (raiz != NULL)
    {
      if (raiz->Izquierdo != NULL)
	{
	  codigoCaracter[i] = '0';
	  conseguirCodificacion (raiz->Izquierdo, codigoCaracter, &*inicio,
				 i + 1);
	}
      if (raiz->Derecho != NULL)
	{
	  codigoCaracter[i] = '1';
	  conseguirCodificacion (raiz->Derecho, codigoCaracter, &*inicio,
				 i + 1);
	}
      if (raiz->caracter != '<')
	{
	  codigoCaracter[i] = '\0';
	  *inicio = recorreInicio (*inicio, raiz->caracter, 0, NULL);
	  recorre = *inicio;
	  while (recorre->siguiente != NULL)
	    {
	      recorre = recorre->siguiente;
	    }
	  strcpy (recorre->codificacion, codigoCaracter);
	}
    }
};

void
conseguirCodigoBinario (struct Lista *codigos, char oracion[],
			char codificacionB[], char codificacionC[])
{
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  char aux;
  int caracteresDec[500];
  struct Lista *recorre = NULL;
  while (oracion[i] != '\0')
    {
      aux = toupper (oracion[i]);
      recorre = codigos;
      while (recorre->caracter != aux)
	{
	  recorre = recorre->siguiente;
	}
      j = 0;
      while (recorre->codificacion[j] != '\0')
	{
	  codificacionB[k] = recorre->codificacion[j];
	  j++;
	  k++;
	}
      i++;
    }
  codificacionB[k] = '\0';
  i = 0;
//  printf ("%ld\n\n", strlen (oracion));
//  printf ("%ld\n\n", strlen (codificacionB));
  while (codificacionB[i] != '\0')
    {
      printf ("%c", codificacionB[i]);
      i++;
    }

  k = 0;
  while (caracteresDec[k] != '\0')
    {
      codificacionC[k] = caracteresDec[k];
      k++;
    }
  codificacionC[l] = '\0';
printf("\n");
};

void
MostrarCodigos (struct Lista *inicio)
{
  struct Lista *recorre = NULL;
  recorre = inicio;
  if (inicio != NULL)
    {
      printf ("Caracter\tCodigo\n\n");
      while (recorre != NULL)
	{
	  if (recorre->caracter != '*')
	    {
	      printf ("%c\t\t%s\n", recorre->caracter, recorre->codificacion);
	    }
	  recorre = recorre->siguiente;
	}
    }
};
