#include "Array.h"
#include <string.h>
#include <iostream>
using namespace std;

template <class T>
class GrowableArray : public Array<T>
{
	using Array<T>::data;
	using Array<T>::len;
public:
	GrowableArray(int size);
	T& operator[](int i);
	T operator[] (int i) const;
private:
	void multwo(int mulsize);
};

template <class T>
GrowableArray<T>::GrowableArray(int size):Array<T>::Array(size){
}

template <class T>
T& GrowableArray<T>::operator[](int i)
{
	if (i >= len)
		multwo(i*2);
	return data[i];
}

template <class T>
T GrowableArray<T>::operator[](int i) const
{
	if (i >= len)
		multwo(i * 2);
	return data[i];
}

template <class T>
void GrowableArray<T>::multwo(int mulsize)
{
	T* temp = new T[mulsize];
	int i;
	for (i = 0; i < mulsize; i++)
		temp[i] = 0;
	for (i = 0; i < len; i++)
		temp[i] = data[i];
	len = mulsize;
	delete[] data;
	data = temp;
}
