#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

void aloca(float **p, int tam);

// Trapézios

float calculaH(float minimo, float maximo, int nroDivisoes);
void valoresx(float *fx, float h, float maximo, float minimo, int nroDivisoes, int grau, float *coef);
void valoresfx(float *x, float *fx, float *coef, float maximo, float minimo, int grau, int nroDivisoes);
float calculaIt(float h, float minimo, float maximo);

float descobriU(float *x, float *y, float *mu,int qtde, int grau);
float produtoEscalar(float *x, float *y, float *mu,int qtde, int grau);

int main()
{

	setlocale(LC_ALL, "portuguese");

	int i, tam, menu, grau;
	// Trapézios
	int nroDivisoes;
	float *coeficiente = NULL;
	float minimo = 0, maximo = 0, h = 0;
	float *valoresFx = NULL, *valoresX = NULL;

	float *xMMQ=NULL, *yMMQ=NULL, *matrizU=NULL; 
	int qtde, j;

	do
	{
		system("cls");
		printf("----------------------MENU-------------------\n\n");
		printf("[1]Regra dos Trapezios\n[2]Metodos dos Minimos Quadrados\n[3]Saida\n\n");
		scanf("%i", &menu);
		fflush(stdin);

		switch (menu)
		{

		// Regra dos Trapézios
		case 1:
			system("cls");
			printf("---------------- Metodos Numericos Computacionais - Regra dos Trapezios ----------------");

			do
			{
				printf("\n\nDigite o grau da equacao: ");
				scanf("%i", &grau);
				fflush(stdin);
				if (grau < 1 || grau > 10)
					printf("Numero fora do intervalo (1 a 10), digite novamente\n");
			} while (grau < 1 || grau > 10);

			printf("\n\nDigite o intervalo");
			printf("\n\nValor Minimo: ");
			scanf("%f", &minimo);
			fflush(stdin);

			printf("Valor Maximo: ");
			scanf("%f", &maximo);
			fflush(stdin);

			printf("\n\nDigite o numero de divisoes: ");
			scanf("%i", &nroDivisoes);
			fflush(stdin);

			for (i = 0; i <= grau; i++)
			{
				aloca(&coeficiente, i + 1);
				printf("\n\nDigite o valor do coeficiente do x^%i\n", i);
				scanf("%f", coeficiente + i);
				fflush(stdin);
			}

			h = calculaH(minimo, maximo, nroDivisoes);
			printf("\nH = %.2f\n", h);
			valoresx(valoresX, h, maximo, minimo, nroDivisoes, grau, coeficiente);
			printf("\nTESTEEE\n");
			// valoresfx(valoresX, valoresFx, coeficiente, maximo, minimo, grau, nroDivisoes);

			system("pause");
			break;

		// Método dos Mínimos Quadrados
		case 2: // system("cls");
			printf("---------------- Metodos Numericos Computacionais - Mínimos Quadrados ----------------");

			do
			{
				printf("\n\nDigite o grau da equacao: ");
				scanf("%i", &grau);
				fflush(stdin);
				if (grau < 1 || grau > 10)
					printf("Numero fora do intervalo (1 a 10), digite novamente\n");
			} while (grau < 1 || grau > 10);

			printf("\nQuantos valores a matriz vai ter? ");
			scanf("%i", &qtde);

			printf("\nDigite valores de x:\n");
			for(i=0; i<qtde; i++){
					aloca(&xMMQ, i+1);
					scanf("%f", (xMMQ+i));
			}
			printf("\nDigite valores de y:\n");
			for(i=0; i<qtde; i++){
					aloca(&yMMQ, i+1);
					scanf("%f", (yMMQ+i));
			}
		//	descobriU(xMMQ, yMMQ, matrizU, qtde, grau);



			break;

		} // switch
	} while (menu != 3);

	system("cls");
	return 0;
} // main

void aloca(float **p, int tam)
{
	if ((*p = (float *)realloc(*p, tam * sizeof(float))) == NULL)
	{
		printf("Erro!");
		exit(1);
	}
} // aloca

// Trapézios
float calculaH(float minimo, float maximo, int nroDivisoes)
{
	float h;
	h = (maximo - minimo) / nroDivisoes;
	return h;
}

/*float calculaIt (flcalcula oat h, float minimo, float maximo )
{
	float it = (h/2)*()
}*/
//		lista de valores de x, o passo entre as divisões, e o valor, int nroDivisoes máximo e mínimo

void valoresx(float *fx, float h, float maximo, float minimo, int nroDivisoes, int grau, float *coef)
{
	int i, j;
	int total = nroDivisoes; // tirar maximo
	float valorF = 0;
	float x;
	// printf("\nX[%i] = %.2f", 0, minimo);
	for (i = 0; i < total; i++)
	{
		aloca(&fx, i + 1);
		x = 0;
		valorF = 0;
		x = (minimo + (h * (i + 1)));
		for (j = 0; j <= grau; j++)
		{
			if (i == 0)
				valorF = (*(coef + j)) * (pow(minimo, j));
			else if (i == nroDivisoes)
				valorF += (*(coef + j)) * (pow(maximo, j));
			else
				valorF += (*(coef + j)) * (pow(x, j));
		}
		printf("\nFx[%i] = %.2f", i + 1, *(fx + i));
	}
	// printf("\nX[%i] = %.2f\n\n", nroDivisoes, maximo);
} // valoresx
  /*
  void valoresfx(float *x, float *fx, float *coef, float maximo, float minimo, int grau, int nroDivisoes)
  {
	  int i, j;
	  float valorF = 0, teste = 2;
  
	  for (i = 0; i < nroDivisoes; i++)
	  { // i relaciona com x
		  valorF = 0;
		  for (j = 0; j <= grau; j++) // j relaciona com o polinomio
		  {
			  if (i == 0)
				  valorF = ( *(coef + j)) * (pow(minimo, j));
			  else if (i == nroDivisoes)
				  valorF += (*(coef + j)) * (pow(minimo, j));
			   else
				  valorF+=(*(coef+j))*(pow(*(x+i),j));
			  printf("\nvalor F = %.2f", &valorF);
		  } // j
		  aloca(&fx, i + 1);
		  *(fx + i) = valorF;
		  printf("\n valor de f: %f", *(fx + i));
		  // printf("\nF(%.2f)= %.2f", *(fx), *(fx + i));
	  } // i
  } // valoresfx
  */
  /*
  void calculaFx(float *fx, float *x, int grau){
	  int i;
	  float valorF = 0;
	  for(i=0; i<=grau; i++){
		  valorF +=(*(coef+i))*(pow(*(x+i),i));
	  }
	  return valorFa;
  }
  */

/*
float calculaFx ()
{
	printf("alo");
}

float calculaPolinomioIntervalo()
{
	printf("alo");
}*/

/*
float descobriU(float *x, float *y, float *mu,int qtde, int grau){
	int l, c;
	
	for(l=0;l<=qtde;l++)
	{
		aloca(&mu, l+1);
	    for(c=0;c<=grau;c++)
	    {
			*(mu+l*grau+c) = pow((x+l), grau);	// endereço de cada elemento
	    }
	}
}

float produtoEscalar(float *x, float *y, float *mu, float *m,int qtde, int grau){
	int l, c;
	
	for(l=0;l<=qtde;l++)
	{
		aloca(&m, l+1);
	    for(c=0;c<=qtde;c++)
	    {
			(*(m+l*coluna+c))*(*(m+l*coluna+c))			
			
	    }
	}
}

*(m+l*coluna+c)=()
*/