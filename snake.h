
enum direction { LEFT, UP, RIGHT, DOWN };

class SnakePart {
  public:
    int positionX;
    int positionY;
};

class Snake {
    direction currentDirection = LEFT;
    bool alive = true;
  public:
    int isAlive(){return alive;}
    int getHeadPositionX () {return sp[0].positionX;}
    int getHeadPositionY () {return sp[0].positionY;}
    int length = 3;
    SnakePart sp[64];
    void grewUp(){
      length++; Serial.println("Snake: Grown");
    }
    
    bool isCollision(int x, int y){
       for(int i=0; i < length; i++) {
          if(sp[i].positionX == x && sp[i].positionY == y){
            return true;
          }
       }
       return false;
    }
    
    void setHeadPosition (int x,int y){
      if(isCollision(x,y)){
         Serial.println("Snake is Dead !!!1");
        alive = false;
      }
      for(int i = length - 1; i > 0; i--) {
       sp[i] = sp[i-1];
      }
      
      sp[0].positionX = x;
      sp[0].positionY = y;
    }
    void changeDirection(direction dir){
      if(currentDirection == dir){
        return;
      } else if(isOpposite(dir)){
        return;
      } else {
        currentDirection = dir;
      }
    }
    void moveForvard(){
       switch (currentDirection)
      {
      case direction::LEFT:
        moveLeft();  //Serial.println("Snake: left");
        break;
      case direction::RIGHT:
        moveRight();  //Serial.println("Snake: right");
        break;
      case direction::UP: 
        moveUp();  //Serial.println("Snake: up");
        break;
      case direction::DOWN:
        moveDown();  //Serial.println("Snake: down");
        break;
      }
    }
    bool isOpposite(direction dir){
      return (currentDirection == LEFT && dir == RIGHT) || (currentDirection == RIGHT && dir == LEFT) || (currentDirection == UP && dir == DOWN) || (currentDirection == DOWN && dir == UP);
    }
    void moveLeft(){
      if(getHeadPositionX() > 0){
        setHeadPosition(getHeadPositionX()-1, getHeadPositionY());
      } else {
        setHeadPosition(7, getHeadPositionY());
      }
    }
    void moveRight(){
      if(getHeadPositionX() < 7){
        setHeadPosition(getHeadPositionX()+1, getHeadPositionY());
      } else {
        setHeadPosition(0, getHeadPositionY());
      }
    }
    void moveUp(){
      if(getHeadPositionY() > 0){
        setHeadPosition(getHeadPositionX(), getHeadPositionY()-1);
      } else {
        setHeadPosition(getHeadPositionX(), 7);
      }
    }
    void moveDown(){
      if(getHeadPositionY() < 7){
        setHeadPosition(getHeadPositionX(), getHeadPositionY()+1);
      } else {
        setHeadPosition(getHeadPositionX(), 0);
      }
    }
};