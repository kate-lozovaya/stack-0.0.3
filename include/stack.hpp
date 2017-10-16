#include <iostream>
#include <algorithm>

template <typename T>
class stack
{
public:
	stack();
	size_t count() const;
	size_t array_size() const;
	T * operator[](unsigned int index) const;
	void push(T const &);
	T pop();
	T last()const;
	void print();
	void swap();
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
T stack<T>::pop()
{
	if (count_ == 0)
		throw std::logic_error("Stack is empty");
	else
	{
		if (count_ - 1 == array_size_ / 2)
			array_size_ /= 2;
		T value = array_[--count_];
		swap();
		return value;
	}
}
template <typename T>
T stack<T>::last()const
{
	if (count_ == 0)
		throw std::logic_error("Stack is empty");
	else return array_[count_ - 1];
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
	std::copy(array_, array_ + count_, stdext::checked_array_iterator<T*>(new_array, count_));
	delete[] array_;
	array_ = new_array;
}
