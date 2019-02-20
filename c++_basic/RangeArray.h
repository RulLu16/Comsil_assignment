#ifndef MTT
#define MTT
#include "Array.h"

class RangeArray : public Array{
	protected : 
		int low;
		int high;
	public :
		RangeArray(int one,int two);
		~RangeArray();

		int baseValue();
		int endValue();

		int& operator[](int i);
		int operator[](int i) const;
	
};
#endif
