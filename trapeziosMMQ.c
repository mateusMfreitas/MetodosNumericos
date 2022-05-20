#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

void aloca(float **p, int tam);

//Trapézios
void definirValoresX(float *x, float h, float maximo, float minimo, int nroDivisoes);
void valoresx(float *x, float h, float maximo, float minimo, int nroDivisoes);
float calculaH (float minimo, float maximo, int nroDivisoes);
float calculaIt (float h, float minimo, float maximo );

int main(){
	

	setlocale(LC_ALL, "portuguese");

	int i, tam, menu, grau;
	//Trapézios
	int nroDivisoes;
	float *coeficiente = NULL;
	float minimo=0, maximo=0, h=0;
	float *valoresFx = NULL, *valoresX = NULL;

	do{
	system("cls");
	printf("----------------------MENU-------------------\n\n");
	printf("[1]Regra dos Trapezios\n[2]Metodos dos Minimos Quadrados\n[3]Saida\n\n");
	scanf("%i", &menu);
    fflush(stdin);
	
	switch (menu){
		
		//Regra dos Trapézios 
		case 1: system("cls");
				printf("---------------- Metodos Numericos Computacionais - Regra dos Trapezios ----------------");
				
				do{
					printf("\n\nDigite o grau da equacao: ");
					scanf("%i", &grau);
					fflush(stdin);
					if(grau<1 || grau>10)
						printf("Numero fora do intervalo (1 a 10), digite novamente\n");
				} while(grau<1 || grau>10);

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
                   
                    for(i=0; i<=grau; i++){
                        aloca(&coeficiente, i+1);
                        printf("\n\nDigite o valor do coeficiente do x^%i\n", i);
                        scanf("%f", coeficiente+i);
                        fflush(stdin);  
                    }
				h=calculaH(minimo, maximo, nroDivisoes);
				printf("\nH = %.2f\n", h);
				valoresx(valoresX, h, maximo, minimo, nroDivisoes);
				
				system("pause");
				break;
		
		
		//Método dos Mínimos Quadrados
		case 2:	//system("cls");
				printf("---------------- Metodos Numericos Computacionais - Mínimos Quadrados ----------------");
				
				break;
				
	}//switch
	}while(menu!=3);		
	
	system("cls");
	return 0;
}//main

void aloca(float **p, int tam)
{
	if( (*p=(float *)realloc(*p,tam*sizeof(float)) )==NULL){
		printf("Erro!");
		exit(1);
	}
}//aloca


//Trapézios	
float calculaH (float minimo, float maximo, int nroDivisoes)
{
	float h;
	h = (maximo - minimo)/nroDivisoes;
	return h;
}

/*float calculaIt (flcalcula oat h, float minimo, float maximo )
{
	float it = (h/2)*()	
}*/
//		lista de valores de x, o passo entre as divisões, e o valor, int nroDivisoes máximo e mínimo
void valoresx(float *x, float h, float maximo, float minimo, int nroDivisoes){
int i;
int total=nroDivisoes-1; //tirar maximo
	printf("\nX[%i] = %.2f", 0, minimo);
	for(i=0; i<total; i++){
		aloca(&x, i+1);
		*(x+i)=(minimo+(h*(i+1)));
		printf("\nX[%i] = %.2f", i+1, *(x+i));
	}
	printf("\nX[%i] = %.2f\n\n", nroDivisoes, maximo);
}//valoresx


/*
void definirValoresX(float *x, float h, float maximo, float minimo, int nroDivisoes){
	int i;
	for(i = 0; i< nroDivisoes-1; i++){ 
		aloca(&x, i+1);
		*(x+i)=h;
		//+ (h*(i+1));

		printf("\nX[%i] = %.2f", i, (x+i));
	}
}*/


/*
float calculaFx ()
{
	printf("alo");
}

float calculaPolinomioIntervalo()
{
	printf("alo");
}*/