#pragma once

#import "PGMidi.h"
#include <vector>

@class PGMidi;
@class PGMidiSource;
@class PGMidiSourceDelegate;

class ofxPGMidiIn;

/// interface to pgmidi input
@interface ofxPGMidiSourceDelegate : NSObject <PGMidiSourceDelegate> {
	
	ofxPGMidiIn * inputPtr;	///< object to send receieved midi messages to
	
	bool bIgnoreSysex, bIgnoreTiming, bIgnoreSense;	///< ignore midi types?
	
	unsigned long long lastTime; ///< timestamp from last packet
	bool bFirstPacket; ///< is this the first received packet?
	bool bContinueSysex; ///< is this packet part of a sysex message?
	unsigned int maxMessageLen; ///< max size of the byte buffer
	
	std::vector<unsigned char> message;	///< raw byte buffer
}

/// pgmidi callback
- (void) midiSource:(PGMidiSource *)input midiReceived:(const MIDIPacketList *)packetList;

/// set the pointer to the ofxPGMidiIn object to send messages to
- (void) setInputPtr:(void *)i;

@property bool bIgnoreSysex;
@property bool bIgnoreTiming;
@property bool bIgnoreSense;

@end
