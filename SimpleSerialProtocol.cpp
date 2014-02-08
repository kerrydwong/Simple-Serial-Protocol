#include "SimpleSerialProtocol.h"

/**
 * Simple Serial Protocol
 * Kerry D. Wong
 * http://www.kerrywong.com
 * 1/2014
 */

SimpleSerialProtocol::SimpleSerialProtocol()
{
	cmdBufferIdx = 0;
	cmdBegan = false;
	bufferFull = false;
	
	cmdBeginInd = CMD_BEGIN_IND;
	cmdEndInd = CMD_END_IND;
}

SimpleSerialProtocol::SimpleSerialProtocol(byte cmdBeginIndicator, byte cmdEndIndicator)
{
	cmdBufferIdx = 0;
	cmdBegan = false;
	bufferFull = false;
	
	cmdBeginInd = cmdBeginIndicator;
	cmdEndInd = cmdEndIndicator;
}

void SimpleSerialProtocol::receive()
{
    while (Serial.available()) {
        byte b=Serial.read();
        
   	if (b == cmdBeginInd) 
        {
                cmdBegan = true;
                bufferFull = false;
                cmdBufferIdx = 0;                
	}
	else if (b == cmdEndInd)
	{
                cmdBegan = false;
                CmdReceivedPtr(buf, cmdBufferIdx);
	} 
	else
	{
                if (cmdBegan) {
                    if (cmdBufferIdx >= BUF_MAX_LENGTH) {
                        bufferFull = true;
                    } else {
                        buf[cmdBufferIdx] = b;
                        cmdBufferIdx++;
                    }
                }
        }
    }
}

void SimpleSerialProtocol::send(byte cmd)
{
	Serial.write(cmdBeginInd);
	Serial.write(cmd);
	Serial.write(cmdEndInd);
}

void SimpleSerialProtocol::send(byte* cmd, byte cmdLength)
{
	Serial.write(cmdBeginInd);
	for (byte i = 0; i < cmdLength; i++)
		Serial.write(cmd[i]);	
	Serial.write(cmdEndInd);
}

