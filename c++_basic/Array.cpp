#include <stdlib.h>
#include <iostream>
#include "Array.h"
using namespace std;

Array::Array(int size)
{
    if(size<1)
        cout << "Error!!\n";
    else
    {
        data=new int[size];
        len=size;
    }
}

Array::~Array()
{
    delete[] data;
}

int Array::length() const
{
    return len;
}

int& Array::operator[](int i)
{
	int static t;
    if(i<len && i>=0)
        return *(data+i);
    else
    {
        cout<<"Error!!\n";
        return t;
    }

}

int Array::operator[](int i) const
{

    if(i<len && i>=0)
        return *(data+i);
    else{
        cout<<"Error!!\n";
        return 0;
    }

}

void Array::print()
{
    int i;
    cout<<"[ ";
    for(i=0;i<len;i++)
        cout<<data[i]<<" ";
    cout<<"]\n";
}



