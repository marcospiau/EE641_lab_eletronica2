/*
 * blink.c:
 *	Standard "blink" program in wiringPi. Blinks an LED connected
 *	to the first GPIO pin.
 *
 * Copyright (c) 2012-2013 Gordon Henderson. <projects@drogon.net>
 ***********************************************************************
 * This file is part of wiringPi:
 *	https://projects.drogon.net/raspberry-pi/wiringpi/
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with wiringPi.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

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
