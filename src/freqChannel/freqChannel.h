#define same 1
#define oppo 0
#ifndef unsighned int
#define unsigned int uint


class freqChan {
	private:
		int channel;
		int direction;
	public:
		freqChan* left;
		freqChan* right;
		
	public:
		freqChan();
		
		void addLeft(freqChan leftMember);
		void addRight(freqChan rightMember);
}
