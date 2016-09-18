#include <IRremote.h>
#include <IRremoteInt.h>


/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

 int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(irrecv.decode(&results)) 
    {
      //this checks to see if a code has been received
    if(results.value == 0x4EBB708F) //if the button press equals the hex value 0xC284
    {
       digitalWrite(13, HIGH); 
        //do something useful here
    }
    else
    
    if(results.value == 0x4EBB58A7) //if the button press equals the hex value 0xC284
    {
       digitalWrite(13, LOW); 
        //do something useful here
    }else
    
    if(results.value == 0x4EBB7C83) //if the button press equals the hex value 0xC284
    {
       digitalWrite(12, HIGH); 
        //do something useful here
    }

        if(results.value == 0x4EBB40BF) //if the button press equals the hex value 0xC284
    {
       digitalWrite(12, LOW); 
        //do something useful here
    }
   
  }
    irrecv.resume(); // Receive the next value
  }
}
