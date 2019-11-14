#include"huffman.h"

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
}

struct Lista *
generaListadeFrecuencia (char *frase)
{
  struct Lista *listaGenerada = NULL;
  struct Lista *recorre = NULL;
  int i = 0;
  int flag = 0;
  printf ("\n%s\n", frase);
  while (frase[i] != '\0')
    {
      if (listaGenerada == NULL)
	{
	  listaGenerada = altaInicio (listaGenerada, frase[i], 1, NULL);
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
	      listaGenerada = altaFinal (listaGenerada, frase[i], 1, NULL);
	    }
	  flag = 0;
	}
      i++;
    }
  Mostrar (listaGenerada);
  system ("PAUSE");
  return listaGenerada;
}

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
	  printf ("%c\t%d\n", inicio->caracter, inicio->frecuencia);
	  contador++;
	  inicio = inicio->siguiente;
	}
    }
}

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
}

void
generarArbol (struct Lista *inicio, struct Lista *inicioOriginal,
	      struct Arbol **raiz)
{
  struct Arbol *hijoIzquierdo;
  struct Arbol *hijoDerecho;
  struct Arbol *padre;

  int auxfrecuencia = 0;
  char caracterImpro = '<';
  int tamano = 0;

  struct Lista *recorre;
  recorre = inicioOriginal;
  int i = 1;
  int selector = 0;

  if (inicio == NULL)
    {
      printf ("Lista vacia de genera arbol\n\n");
      while (recorre->siguiente != NULL)
	{
	  recorre = recorre->siguiente;
	}
      printf ("Me encuentro aqui 1\n\n");
      *raiz = recorre->arbol;
    }
  else
    {
      if (inicio == NULL)
	{
	  while (recorre->siguiente != NULL)
	    {
	      recorre = recorre->siguiente;
	    }
	  printf ("Me encuentro aqui 2\n\n");
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
	      hijoDerecho =
		crearNodoHoja (inicio->caracter, inicio->frecuencia);
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
	  printf ("Tamano: %d\n", tamano);
	  printf ("Posicion: %d\n", i);
	  if (tamano >= i)
	    {
	      inicioOriginal =
		altaPosicion (inicioOriginal, i, padre->frecuencia,
			      padre->caracter, padre);
	    }
	  else
	    {
	      inicioOriginal =
		altaFinal (inicioOriginal, padre->caracter, padre->frecuencia,
			   padre);

	    }
	  Mostrar (inicioOriginal);
	  system ("PAUSE");
	  generarArbol (inicio, inicioOriginal, &(*raiz));
	}
    }
}

struct Arbol *
crearNodoHoja (char caracter, int frecuencia)
{
  struct Arbol *nuevo = NULL;
  nuevo = (struct Arbol *) malloc (sizeof (struct Arbol));
  nuevo->caracter = caracter;
  nuevo->frecuencia = frecuencia;
  nuevo->Izquierdo = NULL;
  nuevo->Derecho = NULL;
}

