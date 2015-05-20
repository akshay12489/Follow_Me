
/* 
Yo! Tracking color and following you!
*/

#include <SPI.h>  
#include <Pixy.h>
#include <Servo.h>
/*Servo decleration*/
Servo leftservo;
Servo rightservo;
/*Camera decleration*/
Pixy pixy;

/* Movement Funtions*/  
void leftturn()
{
  leftservo.writeMicroseconds(1500);
  rightservo.writeMicroseconds(1440);
}

void rightturn()
{
  leftservo.writeMicroseconds(1560);
  rightservo.writeMicroseconds(1493);
}

void moveforward()
{
  leftservo.writeMicroseconds(1550);
  rightservo.writeMicroseconds(1450);
}

void stopmoving()
{
  leftservo.writeMicroseconds(1500);
  rightservo.writeMicroseconds(1493);
}

void setup()
{

//  Serial.begin(9600);
//  Serial.print("Starting...\n");
  /*Pin assignments*/
  leftservo.attach(9);
  rightservo.attach(10);
/*Camera initialisation*/
  pixy.init();
}

void loop()
{ 
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  
  blocks = pixy.getBlocks();
  
  if (blocks)
  {
      for (j=0; j<blocks; j++)
      {
        sprintf(buf, "  block %d: ", j);

        if (pixy.blocks[j].x > 140 && pixy.blocks[j].x < 180)
        {
          if (pixy.blocks[j].y < 120)
            moveforward();
          else
            stopmoving();
        }
        else
        {
          if(pixy.blocks[j].x < 150)
            leftturn();
          else if(pixy.blocks[j].x > 170)
            rightturn();
        }
      }
  }
}

