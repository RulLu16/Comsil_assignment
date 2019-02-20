#ifndef __ARRAY__
#define __ARRAY__

template <class T>
class Array
{
	protected:
		T*data;
		int len; 
	public:
		Array(int size); 
		~Array();

		int length() const;

		T& operator[](int i);
		T operator[](int i) const;

		void print();
};

template <class T>
Array<T>::Array(int size)
{
	if (size<1)
		cout << "Error!!\n";
	else
	{
		data = new T[size];
		len = size;
	}
}

template <class T>
Array<T>::~Array()
{
	delete[] data;
}

template <class T>
int Array<T>::length() const
{
	return len;
}

template <class T>
T& Array<T>::operator[](int i)
{
	T static t;
	if (i<len && i >= 0)
		return *(data + i);
	else
	{
		cout << "Error!!\n";
		return t;
	}

}

template <class T>
T Array<T>::operator[](int i) const
{

	if (i<len && i >= 0)
		return *(data + i);
	else {
		cout << "Error!!\n";
		return 0;
	}

}

template <class T>
void Array<T>::print()
{
	int i;
	cout << "[ ";
	for (i = 0; i<len; i++)
		cout << data[i] << " ";
	cout << "]\n";
}

#endif