#ifndef SIMPLESERIALPROTOCOL_H
#define SIMPLESERIALPROTOCOL_H

#include <Arduino.h>

/**
 * Simple Serial Protocol
 * Kerry D. Wong
 * http://www.kerrywong.com
 * 1/2014
 */

class SimpleSerialProtocol {
public:
	static const byte BUF_MAX_LENGTH = 64;
	static const byte CMD_BEGIN_IND = 94; //^
	static const byte CMD_END_IND = 10; //Line Feed (LF)
	
	byte cmdBufferIdx;
	byte buf[BUF_MAX_LENGTH];
	boolean cmdBegan;
	boolean bufferFull;

	byte bufMaxLength;
	byte cmdBeginInd;
	byte cmdEndInd;

	void (*CmdReceivedPtr)(byte* buf, byte cmdLength);

	SimpleSerialProtocol();
	SimpleSerialProtocol(byte cmdBeginIndicator, byte cmdEndIndicator);
	
	void receive();
	void send(byte cmd);
	void send(byte* cmd, byte cmdLength);
};
#endif
