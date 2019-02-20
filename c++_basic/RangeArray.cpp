#include <stdlib.h>
#include <iostream>
#include "Array.h"
#include "RangeArray.h"
using namespace std;

RangeArray::RangeArray(int one,int two) : Array(two-one+1)
{
	low=one;
	high=two;
}
RangeArray::~RangeArray()
{
}

int RangeArray::baseValue()
{
	return low;
}
int RangeArray::endValue()
{
	return high;
}

int& RangeArray::operator[](int i)
{
	int static t;
	if(i>high || i<low)
	{
		cout<<"Error!!\n";
		return t;
	}
	else
		return Array::data[i-low];
}
int RangeArray::operator[](int i) const
{
	if(i>high || i<low)
	{
		cout<<"Error!!\n";
		return 0;
	}
	else
		return Array::data[i-low];
}