#include <iostream>

void finnify(int* i)
{
	// *i can cause segmentation fault if address is not valid or null and crash the program
	*i = 5;
	// correct way
	if (i != nullptr) { *i = 5; }
}

//void finnifyRef(const int& i)
//const makes reference immutable
void finnifyRef(int& i)
{
	// reference will always be valid
	i = 5;
}

//RAII
class IntArray
{
	size_t m_size = 0;
	int* m_array = nullptr;
public:
	IntArray(size_t size)
		: m_size(size)
		, m_array(new int[size])
	{
		std::cout << "Array Constructor\n";
	}

	~IntArray()
	{
		std::cout << "Array Destructor\n";
		delete[] m_array;
	}

	int get(size_t index)
	{
		return m_array[index];
	}

	void set(size_t index, int value)
	{
		m_array[index] = value;
	}

	void print()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			std::cout << i << " : " << m_array[i] << "\n";
		}
	}

	int& operator[] (size_t index)
	{
		return m_array[index];
	}
};

// generic implementation
template <class T>
class DynamicArray
{
	size_t m_size = 0;
	T* m_array = nullptr;
public:
	DynamicArray(size_t size)
		: m_size(size)
		, m_array(new T[size])
	{
		std::cout << "DynamicArray Constructor\n";
	}

	~DynamicArray()
	{
		std::cout << "DynamicArray Destructor\n";
		delete[] m_array;
	}

	T get(size_t index)
	{
		return m_array[index];
	}

	void set(size_t index, T value)
	{
		m_array[index] = value;
	}

	void print()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			std::cout << i << " : " << m_array[i] << "\n";
		}
	}

	T& operator[] (size_t index)
	{
		return m_array[index];
	}
};

int main(int argc, char* argv[])
{
	int a = 10;
	int b = 20;

	std::cout << "value of a: " << a << "\n";
	std::cout << "value of b: " << b << "\n";

	int* pa = &a;
	int* pb = &b;

	std::cout << "addr of a: " << pa << "\n";
	std::cout << "addr of b: " << pb << "\n";

	*pb = 42;

	finnify(&b);
	finnifyRef(b);

	std::cout << "value of a: " << a << "\n";
	std::cout << "value of b: " << b << "\n";

	// RAII
	IntArray arr(10);

	arr.set(4, 42);
	arr[5] = 55;
	arr.print();

	DynamicArray<int> arr2(10);

	arr2.set(4, 42);
	arr2[5] = 55;
	arr2.print();

	return 0;
}