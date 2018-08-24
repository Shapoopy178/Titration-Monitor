float absorbanceRead(){

  int absSumSignal = 0;

  for(int i=1; i<=10; i++){

    absSumSignal = absSumSignal + analogRead(laserReadPin);
    delay(2);

  }
  
  float absMean = absSumSignal / 10.0;

  return(absMean);

}

// 9
