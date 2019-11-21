#include "Huffman.h"
int
main (void)
{
  char frase[] = "PROFESOR ESPERO CON ESTE PROYECTO PUEDA PASAR MI RECURSE DE ESTRUCTURA DE DATOS";	//frase para leer
  char codigoCaracter[8];
  char codificacionC[500];	//codificacion caracter
  char codificacionB[500];
  int i = 0;
  struct Lista *inicio = NULL;
  struct Lista *codigos = NULL;
  struct Arbol *arbol = NULL;


  while (frase[i] != '\0')
    {
      if (frase[i] == ' ')
	{
	  frase[i] = '_';
	}
      else
	{
	  frase[i] = toupper (frase[i]);
	}
      i++;
    }
  printf ("\nFRASE A CODIFICAR: %s\n", frase);
  system ("read -p '' var");
  printf ("LISTA DE CONTEO DE FRECUENCIAS\n\n");
  inicio = generaListadeFrecuencia (frase);
  printf ("\nLISTA ORDENADA DE FORMA ASCENDENTE\n\n");
  inicio = ordenarLista (inicio);
  Mostrar (inicio);
  system ("read -p '' var");
  generarArbol (inicio, inicio, &arbol);
  printf ("\nARBOL GENERADO Y MOSTRADO EN PREORDEN\n\n");
  mostrarArbolPreOrden (arbol);
  system ("read -p '' var");
  printf ("CODIGO GENERADO PARA CADA LETRA.\n\n");
  conseguirCodificacion (arbol, codigoCaracter, &codigos, 0);
  MostrarCodigos (codigos);
  system ("read -p '' var");
  printf ("SUSTITUCIÓN DE CARACTERES EN LA FRASE ORIGINAL.\n\n");
  conseguirCodigoBinario (codigos, frase, codificacionB, codificacionC);
  printf ("%s", codificacionC);

  return 0;
}

