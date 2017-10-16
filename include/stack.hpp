#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
class stack
{
public:
	stack();
	~stack()noexcept;
	stack(stack<T> const&)noexcept;
	stack& operator=(stack<T> const&)noexcept;
	size_t count()const noexcept;
	size_t array_size()const noexcept;
	void push(T const&)noexcept;
	void pop()noexcept;
	T top()noexcept;
	void print(std::ostream&stream)const noexcept;
	friend std::ostream&operator << (std::ostream&stream, const stack<T>&)noexcept;
	void swap(stack<T>&)noexcept;
	bool empty()noexcept;
private:
	T * array_;
	size_t array_size_;
	size_t count_;
};

template <typename T>
stack<T>::stack() : array_{ nullptr }, array_size_{ 0 }, count_{ 0 } {}
template <typename T>
stack<T>::~stack()noexcept
{
	delete[] array_;
}
template <typename T>
stack<T>::stack(stack<T> const& other)noexcept
{
	array_size_ = other.array_size_;
	count_ = other.count_;	
	std::copy(other.array_, other.array_ + count_, array_);
}
template <typename T>
stack<T>& stack<T>::operator=(stack<T> const & other)noexcept
{
	if (&other != this)
		stack(other).swap(*this);
	return *this;
}
template <typename T>
size_t stack<T>::array_size()const noexcept
{
	return array_size_;
}
template <typename T>
size_t stack<T>::count()const noexcept
{
	return count_;
}
template <typename T>
void stack<T>::push(T const & value)noexcept
{
	if (empty())
	{
		array_size_ = 1;
		array_ = new T[array_size_]();
	}
	else if (array_size_ == count_)
	{
		array_size_ *= 2;
		T * new_array = new T[array_size_]();
		std::copy(array_, array_ + count_, new_array);
		delete[] array_;
		array_ = new_array;
	}
	array_[count_++] = value;
}
template <typename T>
void stack<T>::pop()noexcept
{
	if (empty())
		throw std::logic_error("Stack is empty");
	else
	{
		T * new_array = new T[array_size_]();
		--count_;
		std::copy(array_, array_ + count_, new_array);
		delete[] array_;
		array_ = new_array;
	}
}
template <typename T>
T stack<T>::top()noexcept
{
	if (empty())
		throw std::logic_error("Stack is empty");
	else return array_[count - 1];
}
template <typename T>
void stack<T>::print(std::ostream&stream)const noexcept
{
	for (unsigned int i = 0; i < count_; ++i)
		stream << array_[i] << " ";
	stream << std::endl;
}
template <typename T>
std::ostream& operator << (std::ostream&stream, const stack<T>&stack_)noexcept
{
	return stack_.print(stream);
}
template <typename T>
void stack<T>::swap(stack<T>& other)noexcept
{
	std::swap(array_, other.array_);
	std::swap(array_size_, other.array_size_);
	std::swap(count_, other.count_);
}
template <typename T>
bool stack<T>::empty()noexcept
{
	return (count_ == 0) ? true : false;
}
