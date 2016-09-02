#include <stdio.h>
#include <wiringPi.h>

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.

#define	LED	0   // GPIO 0 - pino 11 header
#define botao 1 // GPIO 1 - pino 12 header 

int main (void)
{
  printf ("Aperte o botao para acender o LED\n") ;

  wiringPiSetup () ;
  pinMode (LED, OUTPUT) ;
  pinMode (botao, INPUT) ;
  pullUpDnControl(botao, PUD_UP)
  digitalWrite(LED, LOW)  //apaga o LED inicialmente   
  
  for(;;)
  {
    if(digitalRead(botao))    //botão não pressionado, nível alto na porta
      digitalWrite(LED, LOW)
    else
      digitalWrite(LED, HIGH) //botão pressionado, nível baixo na porta
  }
  return 0 ;
}
