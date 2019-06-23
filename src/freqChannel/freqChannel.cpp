#include "freqChannel.h"

namespace frequency {

waveChan::waveChan(){
	this.chanID = -1;
	this.direction = -1;
	this.waveLen = -1;
	this.freq = -1;
	this.left = nullptr;
	this.right = nullptr;
}

waveChan::waveChan(int chanID, int direction, double waveLen, double freq) {
	this.chanID = chanID;
	this.direction = direction;
	this.waveLen = waveLen;
	this.freq = freq;

	this.left = nullptr;
	this.right = nullptr;
}

void setLeft(waveChan* memberPtr) {
	this.left = MemberPtr;
}
void setRight(waveChan* memberPtr) {
	this.right = memberPtr;
}

}
