int mapJoysticToSide(int joysticPosition){
  if(joysticPosition < 490){
    return -1;
  } else if( joysticPosition > 520){
    return 1;
  } else {
    return 0;
  }
}