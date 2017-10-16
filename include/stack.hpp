#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
class stack
{
public:
	stack();
	size_t count() const;
	size_t array_size() const;
	T * operator[](unsigned int index) const;
	void push(T const &);
	void pop();
	T top();
	T last()const;
	void print();
	void swap();
	bool empty();
private:
	T * array_;
	size_t array_size_;
	size_t count_;
};

template <typename T>
stack<T>::stack()
{
	array_ = nullptr;
	array_size_ = 0;
	count_ = 0;
}
template <typename T>
size_t stack<T>::array_size() const
{
	return array_size_;
}
template <typename T>
size_t stack<T>::count() const
{
	return count_;
}
template <typename T>
T * stack<T>::operator[](unsigned int index) const
{
	return array_[index];
}
template <typename T>
void stack<T>::push(T const & value)
{
	if (array_size_ == 0)
	{
		array_size_ = 1;
		array_ = new T[array_size_]();
	}
	else if (array_size_ == count_)
	{
		array_size_ *= 2;
		swap();
	}
	array_[count_++] = value;
}
template <typename T>
void stack<T>::pop()
{
	if (empty())
		throw std::logic_error("Stack is empty");
	else
	{
		if (count_ - 1 == array_size_ / 2)
			array_size_ /= 2;
		swap();
	}
}
template <typename T>
T stack<T>::top()const
{
	if (empty())
		throw std::logic_error("Stack is empty");
	else return array_[count - 1];
}
template <typename T>
void stack<T>::print()
{
	for (unsigned int i = 0; i < count_; ++i)
		std::cout << array_[i] << " ";
	std::cout << std::endl;
}
template <typename T>
void stack<T>::swap()
{
	T * new_array = new T[array_size_]();
	std::copy(array_, array_ + count_, new_array);
	delete[] array_;
	array_ = new_array;
}
template <typename T>
bool stack<T>::empty()
{
	return (count_ == 0) ? true : false;
}
