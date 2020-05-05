#include <iostream>
#include<cstring>
#include "MyVector.h"

using namespace std;

void PrintError()
{
	cout << "Invalid value" << "\n";
}

/*MyVector::MyVector(size_t size = 0, ResizeStrategy option=ResizeStrategy::MULTIPLICATIVE, float coef=1.5f)//  Конструктор по умолчанию.
{
	m_size = size;
	m_method = option;
	m_coefficient = coef;

	m_data=new ValueType[m_size]();
	
	
} */ // нельзя дважды писать констуктор с параметрами по умолчанию , либо объявить , либо определить.


MyVector::MyVector(const MyVector& copy)// конструктор копирования.
{

	m_size = copy.m_size;
	m_capacity = copy.m_size;
	m_method = copy.m_method;
	m_coefficient = copy.m_coefficient;
	m_data = new ValueType[m_capacity];
	for (size_t i = 0; i < m_capacity; i++) {
		m_data[i] = copy.m_data[i];
	}
}

float MyVector::loadFactor()
{
	float LoadFactor = static_cast<float>(m_size) / static_cast<float>(m_capacity);
	return LoadFactor;
}

const ValueType& MyVector::operator[](const size_t index)const // чтение элементов массива через перегрузку оператора.
{
	if (index>m_size || index<0) {       
		PrintError();
		//exit(0);
	}
	else {
		return m_data[index];
	}
}

void MyVector::reserve(const size_t capacity)
{
	if (capacity < m_size) {
		m_size = capacity; // емкость не может быть меньше длины вектора;
	}
	m_capacity = capacity;
	
}

void MyVector::pushBack(const ValueType& value)
{
	m_data[m_size] = value;
	m_size++;
	
	if (m_method==ResizeStrategy::MULTIPLICATIVE) {
		m_capacity = (m_capacity * 3) / 2;
	}
	else {
		m_capacity += 1;
	}
}

void MyVector::insert(const size_t i, const ValueType& value)
{
	if (m_capacity < i) {
		MyVector::reserve(i);
		m_data[i] = value;

	}
		m_data[i] = value;
}

void MyVector::popBack()
{
	//redistribution
	 m_size = m_size - 1;
	 this->ForpopBack();

}

void MyVector::ForpopBack() {
	float Load_Factor = this->loadFactor();
	if (Load_Factor < 0.5) {
		m_capacity = m_size;
		ValueType* redistribution = this->m_data;
		m_data = new ValueType[m_capacity];
		memcpy(this->m_data, redistribution, m_size * sizeof(ValueType));
		delete[] redistribution;
	}
}

void MyVector::erase(const size_t i) 
{
	for (int k = i; k < m_size; k++) {
		m_data[k] = m_data[k + 1];
	}
	--m_size;
	ForpopBack();

}

void MyVector::erase(const size_t i, const size_t len)
{
	for (int k = 0; k < len; k++) {
		erase(i);
	}
}

const long long int MyVector::find(const ValueType& value, bool isBegin) 
{
	if (isBegin == true) {
		for (size_t i = 0; i < m_size; i++) {
			if (m_data[i] == value) {
				return i;
			}
			else {
				return -1;
			}
		}
	}
	if (isBegin == false) {
		for (size_t i = m_size - 1; i >= 0; --i) {
			if (m_data[i] == value) {
				return(m_size - (m_size - i));
			}
			else {
				return -1;
			}
		}
	}
}

void MyVector::resize(const size_t size, const ValueType value)
{
	if (m_size < size) {
		for (size_t i = m_size; i < size; i++) {
			pushBack(value);
		}
	}
	else {
		m_size = size;
		m_capacity = (m_capacity * 3) / 2;
	}
}

void MyVector::clear()
{
	for (size_t i = 0; i < m_size; i++) {
		m_data[i] = 0;
	}
	m_size = 0;
}


/*MyVector& MyVector::operator=(const MyVector& copy)
{
	
}*/

void MyVector::PrintData()
{
	for (size_t i = 0; i < m_size; i++) {
		 cout << " " << m_data[i];
	}
}

size_t MyVector::capacity() const // получение емкости массива.
{
	return m_capacity;
}

size_t MyVector::size() const // получение количества активных элементов массива.
{
	return m_size;
}

MyVector::~MyVector() {
	delete[] m_data;
}