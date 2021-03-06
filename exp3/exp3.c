#include <stdio.h>
#include <wiringPi.h>
#include <math.h>

#define vo_IN	2 	// GPIO2 - pino 13 header
#define	LAMPADA	7 	// GPIO7 - pino 7 header
#define TE 	15	// GPIO3 - pino 15 header

float mede_temp(float correcao_temp)
	{
	
	int  k=0;					//Variaveis de iteração
	int R1=2184;					//colocar o Valor de R1
	float temp=0.0, res=0, high=0;			//temperatura e resistencia do termistor
	float Va=0.0;					//tensao analógica a ser medida
	float a=6883 ,b=-0.03774;			//parâmetros obtidos no ajuste exponencial(MATLAB)
	for(k=0 ;k<1000;k++)
		{
		if (digitalRead(vo_IN))
			high++;
		delay(1);
		}
	Va = 5 * high / (k+1);				//transformando o duty cycle em tensão
	res = R1 * (5 - Va) / Va ;			//obtendo a resistência do termostato através de Va
	temp = (1/b) * log(res / a);		//obtendo a temperatura através da resistencia do termistor e dos parâmetros do ajuste
	return temp + correcao_temp;
	}
	


int main(void)
{
	wiringPiSetup();
	pinMode(vo_IN, INPUT);
	pinMode(TE, OUTPUT);
	pinMode(LAMPADA, OUTPUT);
	float aux = 0.0, temp_amb=0, temp_atual=0;
	digitalWrite(LAMPADA, LOW); 		//apagando a lâmpada no começo
	digitalWrite(TE, HIGH);
	
	temp_amb = mede_temp(0.0);			//medindo a temperatura inicial, sem correção
	printf("A temperatura é %f ºC\n", temp_amb);
	printf("Digite a temperatura de correcao: ");
	scanf("%f",&aux);
	temp_amb = mede_temp(aux);
	
	for(;;)
	{
	temp_atual = mede_temp(aux);
	printf("A temperatura é %f ºC\n", temp_atual);
	if(temp_atual < temp_amb + 20)
		{
		digitalWrite(LAMPADA, HIGH);
		printf("acendeu\n");
		digitalWrite(TE, LOW);
		delay(1);
		digitalWrite(TE , HIGH);
		}
	else 	
		{
		digitalWrite(LAMPADA, LOW);
		digitalWrite(TE, LOW);
		delay(1);
		digitalWrite(TE , HIGH);
		}
	}
	
	return 0;
	
}
