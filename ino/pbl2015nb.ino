




int goToBefore(String command);
int goToAftor(String command);
int goToLeft(String command);
int goToRight(String command);
int goToRight22(String command);

//PUT YOUR VARIABLES HERE

const int bPin = A0;//前
const int aPin = A1;//後
const int lPin = A5;//左
const int rPin = A6;//右
const int pwPin = D0;//超音波



int flg = 1;//超音波→１ or ナビ→０

//const int pwPin = D0;
//const int vib_motor_pin =A0;


void setup()
{



   Spark.function("gtb", goToBefore);
   
   Spark.function("gta", goToAftor);
   
   Spark.function("gtl", goToLeft);
   
   Spark.function("gtr", goToRight);
   
   Spark.function("gtr22", goToRight22);
   
   

   //PUT YOUR SETUP CODE HERE
   
   pinMode(bPin, OUTPUT); 
   pinMode(aPin, OUTPUT); 
   pinMode(lPin, OUTPUT); 
   pinMode(rPin, OUTPUT); 
   
    
   
   
}

void loop()
{
//PUT YOUR LOOP CODE HERE



    long pulse;

    float inches,cm;

  if (flg == 1) {
      
      
          pinMode(pwPin,INPUT);
 
    pulse = pulseIn(pwPin,HIGH);
 
    inches = pulse/147;
 
    cm = inchesToCentimeters(inches);
 

    if(cm < 50){
        Serial.println("Object too near!");
        Serial.print("Object found at cm "); 
        Serial.println(cm);
        analogWrite( bPin, 200 );
        delay(100);
    }else{
        analogWrite( bPin, 0 );
    }
    
    
  }
 

    
    
    

}




int goToBefore(String command){
    
    flg = 0;
   int state = 0;

   // find out the state of the led

   if(command.substring(0,2) == "ON"){ state = 200;}

   else if(command.substring(0,3) == "OFF") {
       state = 0;
       
       flg = 1;
       }

   else return -1;

   // write to the appropriate pin
   analogWrite(bPin, state);
   //pinMode(D0, OUTPUT);

   return 1;
   
}

int goToAftor(String command){
    
   int state = 0;

   // find out the state of the led

   if(command.substring(0,2) == "ON") state = 200;

   else if(command.substring(0,3) == "OFF") state = 0;

   else return -1;

   // write to the appropriate pin
   analogWrite(aPin, state);
   //pinMode(D0, OUTPUT);

   return 2;
   
}





int goToLeft(String command){
    
   int state = 0;

   // find out the state of the led

   if(command.substring(0,2) == "ON") state = 200;

   else if(command.substring(0,3) == "OFF") state = 0;

   else return -1;

   // write to the appropriate pin
   analogWrite(lPin, state);
   //pinMode(D0, OUTPUT);

   return 3;
   
}


int goToRight(String command){
    
   int state = 0;

   // find out the state of the led

   if(command.substring(0,2) == "ON") state = 200;

   else if(command.substring(0,3) == "OFF") state = 0;

   else return -1;

   // write to the appropriate pin
   analogWrite(rPin, state);
   //pinMode(D0, OUTPUT);

   return 4;
   
}




int goToRight22(String command){
    
   int state = 0;

   // find out the state of the led

   if(command.substring(0,2) == "ON") state = 200;

   else if(command.substring(0,3) == "OFF") state = 0;

   else return -1;

   // write to the appropriate pin
   analogWrite(rPin, state);
   //pinMode(D0, OUTPUT);

   return 5;
   
}



float inchesToCentimeters(float inches){
    return inches * 2.54; 
}


unsigned long pulseIn(uint16_t pin, uint8_t state) {

    GPIO_TypeDef* portMask = (PIN_MAP[pin].gpio_peripheral);
    uint16_t pinMask = (PIN_MAP[pin].gpio_pin);
    unsigned long pulseCount = 0;
    unsigned long loopCount = 0;
    unsigned long loopMax = 25000000;

    // While the pin is *not* in the target state we make sure the timeout hasn't been reached.
    while (GPIO_ReadInputDataBit(portMask, pinMask) != state) {
        if (loopCount++ == loopMax) {
            return 0;
        }
    }

    // When the pin *is* in the target state we bump the counter while still keeping track of the timeout.
    while (GPIO_ReadInputDataBit(portMask, pinMask) == state) {
        if (loopCount++ == loopMax) {
            return 0;
        }
        pulseCount++;
    }

    // Return the pulse time in microsecond!
    return pulseCount * 0.405; // Calculated the pulseCount++ loop to be about 0.405uS in length.
}











