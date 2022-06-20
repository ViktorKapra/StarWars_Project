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
	/// <summary>
	/// Function returns index of the givven element, if the element is not found than
	///  it returns default index -1.
	/// </summary>
	/// <param name="elem"></param>
	/// <returns></returns>
	int getIndexOfElement(T const& elem);
	void Add(T const& element);
	/// <summary>
	/// Function removes element on givven index.
	/// </summary>
	/// <param name="n"></param>
	/// <returns></returns>
	bool removeAt(unsigned n);
	/// <summary>
	/// Function remove the first match of the given element
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool remove(T const&);
	/// <summary>
	/// Function returns element which is the most higher by the condition f. 
	/// If an array is empty it throws an exception.
	/// </summary>
	/// <param name="f"></param>
	/// <returns></returns>
	T getTheMost(bool (*f)(T const&, T const&))const;
	/// <summary>
	/// Function sort the elelemts by the given condition. The complexity of that method is O(n^2)
	/// </summary>
	/// <param name="f"></param>
	void sort(bool (*f)(T const&, T const&));
	/// <summary>
	/// Function clears all objects of the container
	/// </summary>
	/// <typeparam name="T"></typeparam>
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
	if (n < size || n == 0) { return elements[n]; }
	else
	{
		throw std::invalid_argument("Argument was out of range");
	}
}

template<typename T>
bool DynamicArray<T>::removeAt(unsigned n)
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
bool DynamicArray<T>::remove(T const& element)
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
		removeAt(elementIndex);
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

template<typename T>
int DynamicArray<T>::getIndexOfElement(T const& elem)
{
	int defaultIndex = -1;
	int arrSize = this->getSize();
	for (int i = 0; i < arrSize; i++)
	{
		if (elements[i] == elem)
			return i;
	}
	return defaultIndex;
}

template<typename T>
T DynamicArray<T>::getTheMost(bool (*f)(T const&, T const&))const
{
	if (this->getSize() > 0)
	{
		T initialValue = elements[0];
		for (int i = 1; i < size; i++)
		{
			if (f(initialValue, elements[i]))
			{
				initialValue = elements[i];
			}
		}

		return initialValue;
	}
	else throw std::logic_error("There is no elements in this array!");
}

template<typename T>
void DynamicArray<T>::sort(bool (*f)(T const&, T const&))
{
	for (int i = 0; i < this->size; i++)
	{
		T el = elements[i];
		int elIndex = i;
		for (int y = i + 1; y < this->size; y++)
		{
			if (f(el, elements[y]))
			{
				el = elements[y];
				elIndex = y;
			}
		}
		T swaper = elements[i];
		elements[i] = elements[elIndex];
		elements[elIndex] = swaper;
	}
}

#endif // !_DynamicArray