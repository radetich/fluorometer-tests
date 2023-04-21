/*
* TEENSYv4 CODE FOR THE BALL AEROSPACE IN WATER FLUOROMETER
* COLE RADETICH 2023
*/

#define HWSERIAL Serial1 // this makes it easier for us to reference the TX/RX, since serial as a keyword here references USB OTG mode and not RX/Tx
//CROSS CHECK THESE WITH HARDWARE VALUES, ENSURE THAT WE ARE REFERENCING THE CORRECT DIODES
const int sensorPin = 14; //sensor0 (hamamatsu, not filtered)
const int sensor1Pin = 15; //sensor1 (hammamatsu, filtered)
const int ledPin = 2; //driving LEDs, PWM**
const int boardLedPin = 13; //little orange fella
const int OpAMP = 18; //op amp

int emmReturn, filReturn, pwm_on, timestep; //variables
//extra pin info: https://www.pjrc.com/store/teensy40.html#pins
//setup
void setup() 
{
  //init TX/RX pins
  //HWSERIAL.begin(115200);
  //HWSERIAL.setTimeout(100);
  //init LED pin for PWM output
  pinMode(ledPin, OUTPUT);
  pinMode(OpAMP, OUTPUT);
  //init debug LED (this MUST remain off for the final unit, both for battery life purposes and light pollution)
  //pinMode(boardLedPin, OUTPUT);
  //init pwm flag. this is off since the device is off
  pwm_on = 0;
}

void loop() 
{
    //turn led on and set flag variable. This allows us to begin at 57/255 of our 4 KHz PWM and remain at that through capture.
    //this should be about 20% of our pwm or about 1.00185882353 KHz

    analogWrite(ledPin, 127);
    analogWriteFrequency(ledPin, 1000);
    digitalWrite(OpAMP, HIGH);
    
    pwm_on = 1;

  while(1)
  {
    timestep = 0;
    //orange debug light
    //analogWrite(boardLedPin, 255);
    //We are transferring! begin transfer.

    //record values from sensor until HWSERIAL responds to stop...
    emmReturn = analogRead(sensorPin);
    //control light return value (NO FILTER/FILTER FOR EMISSION)
    timestep++;

    filReturn = analogRead(sensor1Pin); 
    //FILTER RETURN

  }

}