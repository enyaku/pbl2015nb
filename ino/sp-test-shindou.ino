

int tinkerAnalogWrite(String command);


//PUT YOUR VARIABLES HERE

void setup()
{

   Spark.function("analogwrite", tinkerAnalogWrite);

   //PUT YOUR SETUP CODE HERE
   pinMode(D0, OUTPUT);
   
}

void loop()
{
//PUT YOUR LOOP CODE HERE


}

int tinkerAnalogWrite(String command){
    
   int state = 0;

   // find out the state of the led

   if(command.substring(0,2) == "ON") state = 200;

   else if(command.substring(0,3) == "OFF") state = 0;

   else return -1;

   // write to the appropriate pin
   analogWrite(D0, state);

   return 1;
   
}




