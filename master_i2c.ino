// Wire Master Reader


#include <Wire.h>

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
 
}

byte x = 0; 

void loop()
{
  Wire.requestFrom(2, 6);    // request 6 bytes from slave device #2

  while(Wire.available())    // slave may send less than requested
  { 
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);     
  char c = Wire.read(); // receive a byte as character
  Serial.print(c);         // print the character
    
  }
  Wire.endTransmission();    // stop transmitting
  x++;
  delay(500);

}
