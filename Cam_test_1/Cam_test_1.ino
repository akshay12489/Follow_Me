
/* 
Yo! Track ball and shit!
*/

#include <SPI.h>  
#include <Pixy.h>
#include <Servo.h>
Servo leftservo;
Servo rightservo;
Pixy pixy;
  
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
  leftservo.attach(9);
  rightservo.attach(10);
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
//    i++;
//    
//    if (i%50==0)
//    {
//      sprintf(buf, "Detected %d:\n", blocks);
//      Serial.print(buf);
      for (j=0; j<blocks; j++)
      {
        sprintf(buf, "  block %d: ", j);
//        Serial.print(buf); 
//        pixy.blocks[j].print();
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
 // }
  }
}

