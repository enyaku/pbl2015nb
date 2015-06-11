



const int pwPin = D0;
const int vib_motor_pin =A0;

void setup() {
    Serial.begin(9600);  
    pinMode(vib_motor_pin,OUTPUT);//１３
 
}

void loop() {
    long pulse;

    float inches,cm;
 
    pinMode(pwPin,INPUT);
 
    pulse = pulseIn(pwPin,HIGH);
 
    inches = pulse/147;
 
    cm = inchesToCentimeters(inches);
 

    if(cm < 50){
        Serial.println("Object too near!");
        Serial.print("Object found at cm "); 
        Serial.println(cm);
        analogWrite( vib_motor_pin, 200 );
        delay(100);
    }else{
        analogWrite( vib_motor_pin, 0 );
    }

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




