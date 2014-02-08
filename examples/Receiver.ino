#include <SimpleSerialProtocol.h>

SimpleSerialProtocol p;

void setup()
{
    Serial.begin(9600);
    p.CmdReceivedPtr = CmdReceived;
}

void loop()
{
    p.receive();
}

void CmdReceived(byte* cmd, byte cmdLength)
{
    if (cmdLength > 0 && cmdLength < SimpleSerialProtocol::BUF_MAX_LENGTH) {
        int sum = 0;
        for (int i = 0; i < cmdLength - 1; i++) sum +=cmd[i];
        
        if ((sum & 0xFF) == cmd[cmdLength - 1]) {
            Serial.print("----");
            Serial.print(char(cmd[0])); //A
            Serial.print(", ");
            Serial.print(char(cmd[1])); //B
            Serial.print(", ");
            Serial.print(char(cmd[2])); //C
            Serial.print(", ");
            Serial.print(char(cmd[cmdLength - 1])); //4
            Serial.println("----");
        }
    }
}
