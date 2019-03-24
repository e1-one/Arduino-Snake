class Game {
  

 Snake * snake;
 Buzzer * buzzer;
 public:
 SnakePart next;
 Game(Snake &sn, Buzzer &buz){
   snake = &sn;
   buzzer = &buz;
 };
 void randNext(){
      long randY;
      long randX;
      bool alreadyExist = true;
      while(alreadyExist){
        randY =  random(0,8);
        randX =  random(0,8);
       if(!snake->isCollision(randX, randY)){
         Serial.println("@@@@@!found");
         alreadyExist = false;
       }
      }
      Serial.println("random");
      next.positionX = randX; Serial.println(randX);
      next.positionY = randY; Serial.println(randY);
  }
  
  void checkCoughtFood(){
    Serial.println("checkCoughtFood");
    Serial.println(snake->getHeadPositionX());
    Serial.println(snake->getHeadPositionY());
    if( snake->getHeadPositionX() == next.positionX && snake->getHeadPositionY() == next.positionY){
        snake->grewUp();
        randNext();
        buzzer->eatSound();
    }
  }
  
  void initSnake(){
      SnakePart c;
      snake->sp[0] = c;
      snake->sp[0].positionX = 4;
      snake->sp[0].positionY = 4;
      SnakePart c1;
      snake->sp[1] = c1;
      snake->sp[1].positionX = 5;
      snake->sp[1].positionY = 4;
      SnakePart c2;
      snake->sp[2] = c2;
      snake->sp[2].positionX = 5;
      snake->sp[2].positionY = 4;
  
      randNext();
    }
};