#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

void aloca(float **p, int tam);

//Trapézios
float definirValoresX(float *x, float h, float maximo, float minimo, int nroDivisoes);
float calculaH (float minimo, float maximo, float h, int nroDivisoes);
float calculaIt (float h, float minimo, float maximo );

int main(){
	

	setlocale(LC_ALL, "portuguese");

	int i, tam, menu, grau;
	//Trapézios
	int nroDivisoes;
	float *coeficiente = NULL;
	float minimo=0, maximo=0, h=0;
	float *valoresFx = NULL, *valoresX = NULL;

	definirValoresX(valoresX, 0.2, 4,2,10);

	do{
	system("cls");
	printf("----------------------MENU-------------------\n\n");
	printf("[1]Regra dos Trapézios\n[2]Métodos dos Mínimos Quadrados\n[3]Saída\n\n");
	scanf("%i", &menu);
    fflush(stdin);
	
	switch (menu){
		
		//Regra dos Trapézios 
		case 1: system("cls");
				printf("---------------- Metodos Numericos Computacionais - Regra dos Trapézios ----------------");
				
				printf("\n\nDigite o intervalo \n");
				printf("\n\nValor Minimo: \n");
				scanf("%f", &minimo);
				fflush(stdin);

				printf("\n\nValor Maximo: \n");
				scanf("%f", &maximo);
				fflush(stdin);

				printf("\n\nDigite o numero de divisoes: \n");
				scanf("%i", &nroDivisoes);
				fflush(stdin);
				
				printf("\n\nDigite o grau da equacao: \n");
				scanf("%i", &grau);
				fflush(stdin);
                   
                    for(i=0; i<=grau; i++){
                        aloca(&coeficiente, i+1);
                        printf("\n\nDigite o valor do coeficiente do x^%i\n", i);
                        scanf("%f", coeficiente+i);
                        fflush(stdin);  
                    }
                    
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
float calculaH (float minimo, float maximo, float h, int nroDivisoes)
{
	h = (maximo - minimo)/nroDivisoes;
	return h;
}

/*float calculaIt (flcalcula oat h, float minimo, float maximo )
{
	float it = (h/2)*()	
}*/
//		lista de valores de x, o passo entre as divisões, e o valor, int nroDivisoes máximo e mínimo
float definirValoresX(float* x, float h, float maximo, float minimo, int nroDivisoes){
	int i;
	for(i = 0; i< nroDivisoes-1; i++){ 
		aloca(&x, i+1);
		*(x+i) = minimo + (h*i);
	}
	}

float calculaFx ()
{
	printf("alo");
}

float calculaPolinomioIntervalo()
{
	printf("alo");
}