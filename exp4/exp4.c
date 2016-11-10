#include <stdio.h>
#include <math.h>
#include <wiringPi.h>

void teste(void)
	{
	int v_chave=0.0;
	for(;;)
		{
		printf("Digite um valor de 0 a 15: ");
		scanf("%d", &v_chave);
		printf("%d \n", v_chave);
		digitalWriteByte(v_chave);
		}
	} 

	
void triangular(float freq)
	{
	int k1=0, k2=0;
	float dly_tm=0.0;
	dly_tm = 1000 * 1000.0 / (32.0 * freq);
	while(1)
		{
		while(k1<15)
			{
			delayMicroseconds(dly_tm);
			digitalWriteByte(k1);
			k1++;
			}
		k2 = k1;
		while(k2>0)
			{
			delayMicroseconds(dly_tm);
			digitalWriteByte(k2);
			k2--;
			}
		k1 = k2;
		}
	}

void senoidal(float freq)
	{
	int k1=0, k2=0, i=0;
	float fase1= -M_PI/2, fase2=0.0, tbl_dlys[15];
	printf("\t _______________________	\n");
	printf("\t| POSICAO |  DELAY(US)  |\n");
	printf("\t|_________|_____________|	\n");
	for(i=0; i<15; i++)
		{
			fase2 = asin((2*((float) i+1) - 15) / 15);
			tbl_dlys[i] =  1000 * 1000 * fabs(fase2 - fase1) / (2*M_PI*freq);			
			if (i < 10) 
				printf("\t|  %d      |   %f  |\n", i, tbl_dlys[i]);
			else
				printf("\t|  %d     |   %f  |\n", i, tbl_dlys[i]);
			
			
			fase1 = fase2;
		}
	printf("\t|_________|_____________|	\n");
	while(1)
		{
		k1 = 0;
		while(k1<15)
			{
			delayMicroseconds(tbl_dlys[k1]);
			digitalWriteByte(k1);
			k1++;
			}
		k2 = k1;
		k1 = 0;
		while(k2>0)
			{
			delayMicroseconds(tbl_dlys[k1]);
			digitalWriteByte(k2);
			k1++;
			k2--;
			}
		}
	}
	
	

int main(void)
	{
	wiringPiSetup();
	int i=0, n_op=0;
	float frequencia = 0;
	for (i=0; i<4; i++)
	 	{
	 		pinMode(i,OUTPUT);
	 	}
	while ((n_op != 1) && (n_op != 2) && (n_op != 3))
		{
		printf("Digite 1 para função de teste, 2 para triangular ou 3 para função senoidal:\n");
		scanf("%d", &n_op);
		}
	printf("Opcao escolhida:\n ");
	if (n_op == 1)
		{
		printf("-----------FUNCAO DE TESTE--------------\n");
		teste();
		}
	else if (n_op == 2)
		{
		printf("-----------ONDA TRIANGULAR--------------\n");
		printf("Digite a frequencia desejada:\n");
		scanf("%f",&frequencia);
		triangular(frequencia);
		}
	else if (n_op == 3)
		{
		printf("---------------ONDA SENOIDAL-------------\n");
		printf("Digite a frequencia desejada:\n");
		scanf("%f",&frequencia);
		senoidal(frequencia);
		}
		
	return 0;
	}
	
