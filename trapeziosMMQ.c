#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

void aloca(float **p, int tam);

// Trapézios

float calculaH(float minimo, float maximo, int nroDivisoes);
void valoresx(float *x, float h, float maximo, float minimo, int nroDivisoes);
void valoresfx(float *x, float *fx, float *coef, float maximo, float minimo, int grau, int nroDivisoes);
float calculaIt(float h, float minimo, float maximo);

int main()
{

	setlocale(LC_ALL, "portuguese");

	int i, tam, menu, grau;
	// Trapézios
	int nroDivisoes;
	float *coeficiente = NULL;
	float minimo = 0, maximo = 0, h = 0;
	float *valoresFx = NULL, *valoresX = NULL;

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
			valoresx(valoresX, h, maximo, minimo, nroDivisoes);
			printf("\nTESTEEE\n"); 
			valoresfx(valoresX, valoresFx, coeficiente, maximo, minimo, grau, nroDivisoes);

			system("pause");
			break;

		// Método dos Mínimos Quadrados
		case 2: // system("cls");
			printf("---------------- Metodos Numericos Computacionais - Mínimos Quadrados ----------------");

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

void valoresx(float *x, float h, float maximo, float minimo, int nroDivisoes)
{
	int i;
	int total = nroDivisoes - 1; // tirar maximo
	printf("\nX[%i] = %.2f", 0, minimo);
	for (i = 0; i < total; i++)
	{
		aloca(&x, i + 1);
		*(x + i) = (minimo + (h * (i + 1)));
		printf("\nX[%i] = %.2f", i + 1, *(x + i));
	}
	printf("\nX[%i] = %.2f\n\n", nroDivisoes, maximo);
} // valoresx

void valoresfx(float *x, float *fx, float *coef, float maximo, float minimo, int grau, int nroDivisoes)
{
	int i, j;
	float valorF = 0, teste=2;

for(i=0; i<nroDivisoes; i++){  //i relaciona com x
		valorF=0;
		for (j=0; j<=grau; j++)  //j relaciona com o polinomio
		{
			if(i==0)
				valorF = (*(coef+j))*(pow(minimo,j));
			else if(i==nroDivisoes)
				valorF+= (*(coef+j))*(pow(minimo,j));
			else
				valorF+=(*(coef+j))*(pow(*(x+i),j));

		} // j
		aloca(&fx, i+1);
		*(fx+i) = valorF;
		printf("\nF(%.2f)= %.2f", *(x + i), *(fx + i));
}//i
} // valoresfx

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