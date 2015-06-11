
#include <math.h>

// -----------------
// Read temperature
// -----------------

// Create a variable that will store the temperature value
int temperature = 0;
double voltage = 0.0;
double tempinC = 0.0;

char vStr[10];
char tStr[10];

void setup()
{
  // Register a Spark variable here
  Spark.variable("temperature", &temperature, INT);
  Spark.variable("voltage", &voltage, DOUBLE);
  Spark.variable("tempinC", &tempinC, DOUBLE);

  // Connect the temperature sensor to A7 and configure it to be an input
  Serial.begin(9600);  
      
  pinMode(A7, INPUT);
}

void loop()
{
  // Keep reading the temperature so when we make an API
  // call to read its value, we have the latest one
  temperature = analogRead(A7);
  voltage = (temperature * 3.3)/4095;
  tempinC = (voltage - 0.5)*100;
  
          Serial.print("now temperature: "); 
        Serial.println(tempinC);
        

}

/**
 * The API request will look something like this:
 * GET /v1/devices/{DEVICE_ID}/temperature
 * # EXAMPLE REQUEST IN TERMINAL
 * # Core ID is 0123456789abcdef
 * # Your access token is 123412341234
 * curl -G https://api.spark.io/v1/devices/0123456789abcdef/tempinC \
 * -d access_token=123412341234
 */

