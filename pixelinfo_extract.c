/* 4 color pixel extraction program
 * given a pixel info of 0xYYBBRRGG extract 4 8-bit wide values
 * and store in a given data structure element
 * AUTHOR: IVAN MORADO
 * UPDATED: 02/12/2023
 * */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


// Definition: Stores seperate 8-bit color information of a pixel with 32-bit info
typedef struct pixelColor_t{
      uint8_t red;
      uint8_t green;
      uint8_t blue;
      uint8_t yellow;
      } color;

void extractColor(uint32_t *val, color *retVal){ 
  uint32_t *ppixel = val; // function pointer to hold address of *val argument
  printf("Here is ppixel value which is accessing true value of pixelinfo not a local copy:> %d\n", *ppixel);
  printf("Here in function\n");
  printf("return value is currently: %d\n", *retVal);
  //uint8_t yellow =  (*ppixel >> 24);
  (*retVal).yellow = (*ppixel >> 24);
  printf("Here YY is extracted. Value is: %d\n", (*retVal).yellow);
  (*retVal).blue = ((*ppixel >> 16) & 0xff);
  printf("Here BB is extracted. Value is: %d\n", (*retVal).blue);
  (*retVal).red = ((*ppixel >> 8) & 0xff);
  printf("Here RR is extracted. Value is: %d\n", (*retVal).red);
  (*retVal).green = (*ppixel & 0xff);
  printf("Here GG is extracted. Value is: %d\n", (*retVal).green);


}

int main(){
  uint32_t YY, BB, RR, GG;
  YY = 0xA4;
  BB = 0x03;
  RR = 0x02;
  GG = 0x01;
  uint32_t pixelinfo = GG + (RR << 8) + (BB << 16) + (YY << 24);
  uint32_t *pColor = &pixelinfo;
  uint8_t colorValue = 0xff; // initialize variable int for storing color struct
  color *pcolorValue = &colorValue; // pointer of size 8-bit for storing color struct and passing to extractColor()
  printf("pixelinfo YYBBRRGG is: %d\n", pixelinfo);
  printf("pointer for 8-bit wide color struct is pcolorValue: %d\n", pcolorValue);
  extractColor(pColor, pcolorValue);
  return 0;
}

