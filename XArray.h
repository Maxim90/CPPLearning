#pragma once

#include <iostream>

template <typename T>
class XArray
{
public:

	XArray()
	{

	}

	XArray(int p_initialSize)
	{
		m_maxArraySize = p_initialSize;
		m_firstElement = (T*)malloc(m_maxArraySize * sizeof(T));
	}

	XArray(const XArray<T>& p_otherArr) : XArray(p_otherArr.m_maxArraySize)
	{
		m_arraySize = p_otherArr.m_arraySize;
		memcpy(m_firstElement, p_otherArr.m_firstElement, m_arraySize * sizeof(T));
	}

	XArray(XArray<T>&& p_otherArr)
	{
		m_maxArraySize = p_otherArr.m_maxArraySize;
		m_arraySize = p_otherArr.m_arraySize;
		m_firstElement = p_otherArr.m_firstElement;
		p_otherArr.m_firstElement = nullptr;
	}

	XArray(const T* p_otherArr, int p_numEle) : XArray(p_numEle)
	{
		m_arraySize = m_maxArraySize;
		memcpy(m_firstElement, p_otherArr, m_arraySize * sizeof(T));
	}

	XArray(const T*&& p_otherArr, int p_numEle) : XArray(p_numEle)
	{
		m_arraySize = m_maxArraySize;
		memcpy(m_firstElement, p_otherArr, m_arraySize * sizeof(T));
	}

	virtual ~XArray()
	{
		free(m_firstElement);
		m_firstElement = nullptr;
		m_arraySize = 0;
		m_maxArraySize = 0;
	}

	T& operator=(const T& p_otherArr) // copy assignment
	{
		std::cout << "using: " << "T& operator=(const T& p_otherArr)" << std::endl;
		if (&p_otherArr == this) return;

		if (m_maxArraySize < p_otherArr.MaxArraySize)
		{
			m_maxArraySize = p_otherArr.MaxArraySize;

			T* newArrayPtr = (T*)realloc(m_firstElement, m_maxArraySize * sizeof(T));
			if (newArrayPtr == nullptr)
			{
				// TODO: throw exception and log
				return 0;
			}

			m_firstElement = newArrayPtr;
		}

		m_arraySize = p_otherArr.ArraySize;
		memcpy(m_firstElement, p_otherArr.firstElement, m_arraySize * sizeof(T));

		return *this;
	}

	T& operator=(T&& p_otherArr) // move assignment
	{
		std::cout << "using: " << "T& operator=(T&& p_otherArr)" << std::endl;
		free(m_firstElement);
		m_maxArraySize = p_otherArr.MaxArraySize;
		m_arraySize = p_otherArr.ArraySize;
		m_firstElement = p_otherArr.firstElement;
		p_otherArr.firstElement = nullptr;

		return *this;
	}

	bool append(const XArray<T>& p_otherArr)
	{


		return true;
	}

	bool append(XArray<T>&& p_otherArr)
	{
		
		return true;
	}

	bool append(const T* p_otherArr, int p_numEle)
	{


		return true;
	}

	int add(const T& p_element)
	{
		if (m_arraySize + 1 > m_maxArraySize)
		{
			m_maxArraySize++;
			T* newArrayPtr = (T*) realloc(m_firstElement, m_maxArraySize * sizeof(T));

			if (newArrayPtr == nullptr)
			{
				// TODO: throw exception and log
				return 0;
			}

			m_firstElement = newArrayPtr;
		}

		m_firstElement[m_arraySize] = p_element;
		m_arraySize++;
		return 1;
	}

	int add(const T&& p_element)
	{
		add(p_element);
		return 1;
	}

	int remove(const T& p_element, bool p_shrink = false)
	{
		int index = contains(p_element);
		if (index >= 0)
		{
			return removeAtIndex(index, p_shrink);
		}

		return 0;
	}

	int removeAtIndex(int p_index, bool p_shrink = false)
	{
		if (!isIndexInRange(p_index)) return 0; // TODO: throw exception

		m_arraySize--;
		memcpy(m_firstElement + p_index, m_firstElement + p_index + 1, (m_arraySize - p_index) * sizeof(T));

 		if (p_shrink)
 		{
 			m_maxArraySize--;
			T* newArrayPtr = (T*) realloc(m_firstElement, m_maxArraySize * sizeof(T));

			if (newArrayPtr == nullptr)
			{
				// TODO: throw exception and log
				return 0;
			}

			m_firstElement = newArrayPtr;
 		}

		return 1;
	}

	bool addUnique(const T& p_element)
	{
		if (contains(p_element) >= 0) return false;

		add(p_element);
		return true;
	}

	bool isIndexInRange(int p_index)
	{
		return p_index >= 0 && p_index < m_arraySize;
	}

	int getSize() const
	{
		return m_arraySize;
	}

	int contains(const T& p_element) const
	{
		if (m_arraySize == 0) return -1;

		for (int i = 0; i < m_arraySize; ++i)
		{
			if (m_firstElement[i] == p_element) return i;
		}

		return -1;
	}

	int countElements(const T& p_element) const
	{
		if (m_arraySize == 0) return 0;

		int count = 0;
		for (int i = 0; i < m_arraySize; ++i)
		{
			if (m_firstElement[i] == p_element) count++;
		}

		return count;
	}

	T* data() const
	{
		return m_firstElement;
	}

	void print() const
	{
		std::cout << "{ ";
		for (int i = 0; i < getSize(); ++i)
		{
			std::cout << m_firstElement[i] << ", ";
		}
		std::cout << " }" << std::endl;
	}

	void toString() const
	{
		// TODO: just do it
		
	}

private:

	T* m_firstElement = nullptr;

	int m_arraySize = 0;
	int m_maxArraySize = 0;
};

