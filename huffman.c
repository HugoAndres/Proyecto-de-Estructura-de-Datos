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
