#include <SimpleSerialProtocol.h>

SimpleSerialProtocol p;
byte b[]={65, 66, 67, 198}; // last byte is the check sum (65+66+67) % 256

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    p.send(b, 4); //sending A B C
}

