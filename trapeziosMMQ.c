#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

void aloca(float **p, int tam);

// Trapézios

float calculaH(float minimo, float maximo, int nroDivisoes);
void valoresx(float *fx, float h, float maximo, float minimo, int nroDivisoes, int grau, float *coef, float *x);
//void valoresfx(float *x, float *fx, float *coef, float maximo, float minimo, int grau, int nroDivisoes);
void calculaIt(float *fx, float h, int nroDivisoes);

//MMQ
void vetores(float *fx, float *x, float *u0, float *u1, float *u2, int qtde, int grau);
//void descobriU(float *x, float *y, float *mu,int qtde, int grau);
//void produtoEscalar(float *x, float *y, float *mu,int qtde, int grau);

int main()
{

	setlocale(LC_ALL, "portuguese");

	int i, tam, menu, grau;
	// Trapézios
	int nroDivisoes, op;
	float *coeficiente = NULL;
	float minimo = 0, maximo = 0, h = 0;
	float *valoresFx = NULL, *valoresX = NULL;

	float *xMMQ=NULL, *yMMQ=NULL, *matrizU=NULL; 
	int qtde, j;

	int operador;
	float *u0=NULL, *u1 = NULL, *u2 = NULL;

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

			for (i = 0; i <= grau; i++)
			{
				aloca(&coeficiente, i + 1);
				printf("\n\nDigite o valor do coeficiente do x^%i\n", i);
				scanf("%f", coeficiente + i);
				fflush(stdin);
			}

			do{

				printf("\n\nDigite o numero de divisoes: ");
				scanf("%i", &nroDivisoes);
				fflush(stdin);

				h = calculaH(minimo, maximo, nroDivisoes);
				printf("\nH = %.2f\n", h);
				valoresx(valoresFx, h, maximo, minimo, nroDivisoes, grau, coeficiente, valoresX);  //calcula x fx e it
				printf("\n\n");
				system("pause");
				printf("\nDeseja calcular novamente com outro numero de trapezios? 1(sim) ou 2(nao)");
				scanf("%i", &op);
			}while(op==1);

		
			break;

		// Método dos Mínimos Quadrados
		case 2: system("cls");
			printf("---------------- Metodos Numericos Computacionais - Mínimos Quadrados ----------------");

			printf("\n\nQuantos valores de x e y possui? ");
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

			do{
				printf("\nDigite uma opcao: 1 - reta ou 2 - parabola: ");
				scanf("%i", &operador);
				fflush(stdin);
			}while(operador!=1 && operador!=2);

		//vetores(yMMQ, xMMQ, u0, u1, u2, qtde, operador);
	



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


void valoresx(float *fx, float h, float maximo, float minimo, int nroDivisoes, int grau, float *coef, float *x)
{
	int i, j;
	int total = nroDivisoes; // tirar maximo
	float valorF = 0;
	
	for (i = 0; i <= total; i++)
	{
		aloca(&fx, i + 1);
		aloca(&x, i + 1);
		valorF = 0;
		if(i!=0 && i!=nroDivisoes)
			*(x+i) = (minimo + (h * (i)));   //calcula x

		for (j = 0; j <= grau; j++)
		{
			if (i == 0)
				valorF += (*(coef + j)) * (pow(minimo, j));
			else if (i == nroDivisoes)
				valorF += (*(coef + j)) * (pow(maximo, j));
			else
				valorF += (*(coef + j)) * (pow((*(x+i)), j));
		}
		*(fx+i)=valorF;
		
	}

	//mostrar valores de X e Fx
	for(i=0; i<=nroDivisoes; i++){
		if(i==0)
			printf("\nX[%i] = %.2f", i, minimo);
		else if(i==nroDivisoes)
			printf("\nX[%i] = %.2f", i, maximo);
		else
			printf("\nX[%i] = %.2f", i, *(x+i));
	}
	printf("\n");
	for(i=0; i<=nroDivisoes; i++)
		printf("\nFx[%i] = %.2f", i, *(fx+i));
	printf("\n");

	calculaIt(fx, h, nroDivisoes);

} // valoresx

void calculaIt(float *fx, float h, int nroDivisoes){
	int i;
	float soma=0, calculo=0, maximo, minimo;
	for(i=0; i<=nroDivisoes; i++){
		if(i==0)
			minimo=*(fx+i);
		else if(i==nroDivisoes)
			maximo=*(fx+i);
		else
			soma+=*(fx+i);
	}
	calculo=(h/2)*((minimo + maximo)+(2*soma));  //calculo da integral
	printf("\n%ITR = %.4f\n", calculo);

}///calculaIt

/*
void vetores(float *fx, float *x, float *u0, float *u1, float *u2, int qtde, int grau){
	
	int i, j;
	if(grau<=2){  
		for(i=0; i<=qtde; i++){  //qtde de x 
			aloca(&u0, i+1);
				*(u0+j)=pow(*(x+i), 0);
			aloca(&u1, i+1);
				*(u0+j)=pow(*(x+i), 1);
			if(grau==2){
				aloca(&u2, i+1);
				*(u2+j)=pow(*(x+i), 2);
			}
		}
	}
	/*else if(grau==2){  
		for(i=0; i<=qtde; i++){  //qtde de x 
			aloca(&u0, i+1);
				*(u0+j)=pow(*(x+i), 0);
			aloca(&u1, i+1);
				*(u1+j)=pow(*(x+i), 1);
			aloca(&u2, i+1);
				*(u2+j)=pow(*(x+i), 2);
		}

	
	//mostrar vetores
	if(grau==1){
		printf("\n  Y  \t  U0  \t  U1  \t");
		for(i=0; i<=qtde; i++){
			printf("\n%.2f\t%.2f\t%.2f\t", *(fx+i), *(u0+i), *(u1+i));
		}
	}
	if(grau==2){
		printf("\n  Y  \t  U0  \t  U1  \t  U2  \t");
		for(i=0; i<=qtde; i++){
			printf("\n%.2f\t%.2f\t%.2f\t%.2f\t", *(fx+i), *(u0+i), *(u1+i), *(u2+i));
		}
	}
	
			
}

  */

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