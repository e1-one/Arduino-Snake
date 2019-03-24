LedControl lc = LedControl(11,10,12,1);  // Pins: DIN,CLK,CS, # of Display connected

int ledBrightness = 0; //0 min 15 max
int ledMatrixIndex = 0;
//  Take values in Arrays and Display them
void renderSnake(Snake s, Game game)
{
  lc.clearDisplay(ledMatrixIndex);
  for(int i=0; i < s.length; i++) {
    //if(s.sp[i] != null)
    lc.setLed(ledMatrixIndex, s.sp[i].positionY, s.sp[i].positionX, true);
  }
  lc.setLed(ledMatrixIndex, game.next.positionY, game.next.positionX, true);
  
}

byte gameOverSlide1[] =
{
   B10100101, 
   B01000010,
   B10100101,
   B00000000,
   B00000000,
   B00000000,
   B00011000,
   B00100100
};

byte gameOverSlide2[] =
{
   B10100101, 
   B01000010,
   B10100101,
   B00000000,
   B00000000,
   B00011000,
   B00100100,
   B00000000
};

void printBoolMatrix(byte matrix[])
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0, i, matrix[i]);
  }
}