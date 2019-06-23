#define same 1
#define oppo 0
#ifndef unsighned int
#define unsigned int uint

namespace frequency {
class waveChan {
	private:
		int chanID;
		int direction;	// -1:invalid, 0:negative, 1:positive.
		double waveLen;
		double freq;
	public:
		waveChan* left;
		waveChan* right;
		
	public:
		waveChan();
		waveChan(int chanID, int direction, double waveLen, double freq);
		
		void setLeft(waveChan* memberPtr);
		void setRight(waveChan* memberPtr);
};
}
