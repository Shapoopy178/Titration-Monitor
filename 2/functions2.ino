float absorbanceRead(){

  int absSumSignal = 0;

  for(int i=0; i<=19; i++){

    absSumSignal = absSumSignal + analogRead(laserReadPin);
    delay(1);

  }
  
  float absMean = absSumSignal / 20.0;

  return(absMean);

}
