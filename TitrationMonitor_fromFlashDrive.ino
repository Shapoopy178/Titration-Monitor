/*	

	Titration Monitor.ino

	Program for monitoring progress of volumetric titrations using Arduino Uno.
	
	By: Steven King and Freddie Thompson, 2018
	University of Tennessee, CHEM 459
	Dr. Frank Vogt, Instructor

*/

#define ledControlPin 2
#define laserControlPin 4
#define laserReadPin A1
#define ledReadPin 3
#define buttonAPin 7
#define buttonBPin 8

//		Will need 3-4 more digital pins if using programmable operational amplifier

int dropCount = 0;
float volume_initial = 0;
float volume_final = 0;

void setup(){

	Serial.begin(9600);

	Serial.println("INITIALIZING...");

	pinMode(ledControlPin,OUTPUT);
	pinMode(laserControlPin,OUTPUT);
	pinMode(laserReadPin,INPUT);
	pinMode(ledReadPin,INPUT);

	digitalWrite(ledControlPin,LOW);
	digitalWrite(laserControlPin,LOW);

	Serial.println("Calibrate dark current, place barrier between laser and associated sensor.");
	Serial.println("Press button 2 to continue.");

	digitalWrite(laserControlPin,HIGH);
	digitalWrite(ledControlPin,HIGH);

	while(digitalRead(buttonBPin)==LOW){}

	float absDark = absorbanceRead();
	delay(250);

	Serial.println("Calibrate P_0, remove barrier between laser and associated sensor.");
	Serial.println("Press button 2 to continue");

	while(digitalRead(buttonBPin)==LOW){}

	float absMax = absorbanceRead();
	delay(250);

	Serial.println("Calibration complete!");
	delay(1000);

	/*

	Serial.println("Enter inital volume from buret in serial input...");

	while(Serial.available()==0){}
	volume_intial = Serial.read();
	
	*/

	Serial.println("Press button 1 to begin titration.");

	while(digitalRead(buttonAPin)==LOW){}

	Serial.println("Starting titration, press button 2 to end.");

}

void loop(){

	while(digitalRead(buttonBPin==LOW)){

		if(digitalRead(ledReadPin)==LOW){
	
			dropCount++;

			float absorbance = absorbanceRead();

			Serial.print(dropCount);
			Serial.print(" : ");
			Serial.println(absorbance);

		}

	}

	Serial.println("Titration complete!");
	delay(1000);

/*

	Serial.println("Enter final volume from buret in serial input.");

	while(Serial.available()==0){}
	volume_final = Serial.read();

*/

	while(1){};

}

float absorbanceRead(){

	int absSumSignal = 0;

	for(int i=0; i<=19; i++){

		absSumSignal = absSumSignal + analogRead(laserReadPin);
		delay(1);

	}
	
	float absMean = absSumSignal / 20.0;

	return(absMean);

}
