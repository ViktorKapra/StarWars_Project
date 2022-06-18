//!Template container with variable lenght
#ifndef _DynamicArray
#define _DynamicArray
#include <iostream>

const int Initial_Capacity = 4;

template <typename T>
class DynamicArray
{
private:
	T* elements;
	size_t size;
	size_t capacity;
	void resize();
	void copyArray(DynamicArray const& other);
public:
	size_t getSize()const { return size; }
	DynamicArray();
	DynamicArray(T* _elements, size_t _size);
	DynamicArray(DynamicArray const& other);
	~DynamicArray();
	DynamicArray& operator=(DynamicArray const& other);
	T& operator[](size_t n);
	void Add(T const& element);
	bool RemoveAt(unsigned n);
	bool Remove(T const&);
	T getTheMost(T initialValue, bool (*f)(T&, T&));
	void Clear();
};

template<typename T>
DynamicArray<T>::DynamicArray()
{
	elements = new T[Initial_Capacity];
	size = 0;
	capacity = Initial_Capacity;
}

template<typename T>
DynamicArray<T>::DynamicArray(T* _elements, size_t _size)
{
	if (_elements != nullptr)
	{
		capacity = _size + Initial_Capacity;
		elements = new T[capacity];
		size = _size;
		for (int i = 0; i < size; i++)
		{
			elements[i] = _elements[i];
		}
	}
	else
	{
		throw std::invalid_argument("Null pointer !!!");
	}
}

template<typename T>
void DynamicArray<T>::copyArray(DynamicArray const& other)
{
	if (other.getSize() != 0)
	{
		for (int i = 0; i < other.size; i++)
		{
			this->Add(other.elements[i]);
		}
	}
	//	else
	//	{
	//		std::cerr << "Empty array was given!" << std::endl;
	//	}
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray const& other) : DynamicArray(other.elements, other.size)
{
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] this->elements;
}

template<typename T>
void DynamicArray<T>::resize()
{
	size_t newCapacity = capacity * 2;
	T* newArray = new T[newCapacity];
	for (int i = 0; i < size; i++)
		newArray[i] = this->elements[i];
	delete[] this->elements;
	elements = newArray;
	capacity = newCapacity;
}

template<typename T>
void DynamicArray<T>::Add(T const& element)
{
	if (capacity == size)
	{
		resize();
	}
	elements[size++] = element;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray const& other)
{
	if (this != &other)
	{
		delete[] elements;
		elements = new T[other.capacity];
		copyArray(other);
	}
	return *this;
}
template <typename T>
T& DynamicArray<T>::operator[](size_t n)
{
	if (n < size) { return elements[n]; }
	else
	{
		throw std::invalid_argument("Argument was out of range");
	}
}

template<typename T>
bool DynamicArray<T>::RemoveAt(unsigned n)
{
	bool result = false;
	if (n < size)
	{

		for (int i = n; i < size - 1; i++)
			elements[i] = elements[i + 1];
		size--;
		return true;
	}
	else
	{
		throw std::invalid_argument("Argument was out of Range");
		return false;
	}
}
template<typename T>
bool DynamicArray<T>::Remove(T const& element)
{
	bool result = false;
	unsigned elementIndex = 0;
	int i = 0;
	while (i < size && result == false)
	{
		if (element == elements[i])
		{
			result = true;
			elementIndex = i;
		}
		i++;
	}
	if (result)
	{
		RemoveAt(elementIndex);
	}
	return result;
}

template<typename T>
void DynamicArray<T>::Clear()
{
	delete[] this->elements;
	elements = new T[Initial_Capacity];
	size = 0;
	capacity = Initial_Capacity;
}

/*
template<typename T>
DynamicArray<T>::getTheMost(T initialValue, bool (*f)(T&, T&))
{
	for (int i = 0; i < size; i++)
	{
		if (f(iniatialValue, elements[i]))
		{
			initiatialValue = elements[i];
		}
	}
	return initialValue;
}
*/

#endif // !_DynamicArray