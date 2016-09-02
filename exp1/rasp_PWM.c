#include <stdio.h>
#include <wiringPI.h>

#define vo_IN	2 //GPIO2 - pino 13 header

int main(void)
{
	wiringPiSetup();
	pinMode(vo_IN, INPUT);
	int high=0, k=0;
	for(k=0 ;k<100;k++)
	{
		if (digitalRead(vo_IN))
			high++;
		delay(1);
	}
	printf("Duty cycle = %d por cento\n", high);
	return 0;
	
}