#include "LedControl.h"
#include "buzzer.h"
#include "snake.h"
#include "helper.h"
#include "game.h"
#include "led.h"

//joystic
int xPin = A1;
int yPin = A0;
int buttonPin = 2;

Buzzer buzzer = Buzzer();

Snake s = Snake();
Game game = Game(s, buzzer);

unsigned long gameFrameSpeed = 500;  // Delay between Frames


void setup()
{
  Serial.begin(9600); 
  randomSeed(analogRead(A5));
  
  //joystic
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  
  lc.shutdown(ledMatrixIndex, false);  // Wake up displays
  lc.setIntensity(ledMatrixIndex, ledBrightness);
  lc.clearDisplay(ledMatrixIndex);
  game.initSnake();
  buzzer.wellcomeSong();
}

void loop()
{
  delay(gameFrameSpeed);
  if(!s.isAlive()){
    gameOver();
    return;
  }
  int xPosition = analogRead(xPin);
  int yPosition = analogRead(yPin);
  int buttonState = digitalRead(buttonPin);
  
  int turnX =  mapJoysticToSide(xPosition);
  int turnY =  mapJoysticToSide(yPosition);
  //Serial.println("turnX: %d", turnX);
  //Serial.println("turnY: "+turnY);
  if(turnX < 0){
    s.changeDirection(LEFT);  //Serial.println("JOYSTIC: left");
  } else if(turnX > 0){
    s.changeDirection(RIGHT); //Serial.println("JOYSTIC: right");
  } else if(turnY < 0){
    s.changeDirection(UP); //Serial.println("JOYSTIC: UP");
  } else if(turnY > 0){
    s.changeDirection(DOWN); //Serial.println("JOYSTIC: DOWN");
  }
  
  s.moveForvard();
  game.checkCoughtFood();
  renderSnake(s, game);
}

void gameOver(){
  printBoolMatrix(gameOverSlide1);
  delay(200);
  printBoolMatrix(gameOverSlide2);
  buzzer.gameOver();
}