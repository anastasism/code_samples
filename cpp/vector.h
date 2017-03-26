#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <memory>

namespace my_lib {
	template <class T>
	class my_iterator : public std::iterator<std::input_iterator_tag, T> {
	public:
		my_iterator(const my_iterator&);
		my_iterator(T*);
		bool operator!=(const my_iterator &);
		bool operator==(const my_iterator&);
		my_iterator& operator++();
		my_iterator operator--();
		my_iterator operator+(int);
		my_iterator operator-(int);
		typename my_iterator::reference operator*() const;
	private:
		T* pointer;
	};

	template<class T>
	class vector {
	public:
		typedef int size_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef my_iterator<T> iterator;
		typedef my_iterator<const T> const_iterator;

		vector();
		vector(const vector&);
		explicit vector(size_type count);
		virtual ~vector();
		vector& operator=(const vector&);
		reference operator[](size_type);
		const_reference operator[](size_type) const;
		iterator begin();
		iterator end();
		const_iterator cbegin() const;
		const_iterator cend() const;
		bool empty() const;
		size_type size() const;
		size_type max_size() const;
		void shrink();
		iterator insert(iterator pos, T value);
		const_iterator insert(const_iterator pos, T value);
		void push_back(T);
		T pop_back();
		void resize(size_type);
	private:
		const size_type base_size = 100;
		std::unique_ptr<T[]> data;
		size_type msize;
		size_type rsize;
	};
}

template<class T>
my_lib::my_iterator<T>::my_iterator(T* p) :
	pointer(p)
{
}

template<class T>
my_lib::my_iterator<T>::my_iterator(const my_iterator& other):
	pointer(other.pointer)
{
}

template<class T>
bool my_lib::my_iterator<T>::operator!=(const my_iterator& other){
	return pointer!=other.pointer;
}

template<class T>
bool my_lib::my_iterator<T>::operator==(const my_iterator& other){
	return pointer==other.pointer;
}

template<class T>
typename my_lib::my_iterator<T>::reference my_lib::my_iterator<T>::operator*() const {
	return *pointer;
}

template<class T>
my_lib::my_iterator<T>& my_lib::my_iterator<T>::operator++(){
	pointer++;
	return *this;
}

template<class T>
my_lib::my_iterator<T> my_lib::my_iterator<T>::operator--(){
	pointer--;
	return *this;
}

template<class T>
my_lib::my_iterator<T> my_lib::my_iterator<T>::operator+(int value){
	return my_iterator(pointer + value);
}

template<class T>
my_lib::my_iterator<T> my_lib::my_iterator<T>::operator-(int value){
	return my_iterator(pointer - value);
}

template<class T>
my_lib::vector<T>::vector():
	data(new T[base_size]),
	msize(base_size),
	rsize(0)
{
}

//размер получившегося вектора = коль-ву элементов в том из которого копируем
template<class T>
my_lib::vector<T>::vector(const vector<T>& other):
	data(new T[other.size()]),
	msize(other.size()),
	rsize(other.size())
{
	std::copy(other.begin(), other.end(), data.get());
}

template<class T>
my_lib::vector<T>::vector(size_type count):
	data(new T[count]),
	msize(count),
	rsize(0)
{
}

template<class T>
typename my_lib::vector<T>::iterator my_lib::vector<T>::begin(){
	return iterator(data.get());
}

template<class T>
typename my_lib::vector<T>::iterator my_lib::vector<T>::end(){
	return iterator(data.get() + size());
}

template<class T>
typename my_lib::vector<T>::const_iterator my_lib::vector<T>::cbegin() const{
	return const_iterator(data.get());
}

template<class T>
typename my_lib::vector<T>::const_iterator my_lib::vector<T>::cend() const{
	return const_iterator(data.get() + size());
}

template<class T>
my_lib::vector<T>::~vector(){
	data.release();
}

template<class T>
my_lib::vector<T>& my_lib::vector<T>::operator=(const vector& other)
{
	this->data = other.data;
	return *this;
}

template<class T>
typename my_lib::vector<T>::reference my_lib::vector<T>::operator[](size_type index){
	if(index >= size() || index<0)
		throw "Index out of range";
	return *(this->data.get() + index);
}

template<class T>
typename my_lib::vector<T>::const_reference my_lib::vector<T>::operator[](size_type index) const{
	if(index >= size())
		throw "Index out of range";
	return *(this->data.get() + index);
}

template<class T>
typename my_lib::vector<T>::size_type my_lib::vector<T>::size() const {
	return rsize;
}

template<class T>
typename my_lib::vector<T>::size_type my_lib::vector<T>::max_size() const {
	return msize;
}
template<class T>
bool my_lib::vector<T>::empty() const{
	return size() == 0;
}

template<class T>
void my_lib::vector<T>::push_back(T value) {
	if(size() >= max_size()){
		resize(max_size() * 2);
	}
	*(data.get() + size()) = value;
	rsize++;
}

template<class T>
T my_lib::vector<T>::pop_back(){
	T val = *(data.get() + size() -1);
	rsize--;
	delete *end();
}

//TODO: реализовать
template<class T>
void my_lib::vector<T>::resize(size_type newsize){
	int* newarr = new T[newsize];
	for(int i=0; i<max_size(); i++){
		newarr[i] = *(data.get()+i);
	}
	data.reset(newarr);
	msize = newsize;
}

//не сходится при неправильном использовании
template<class T>
typename my_lib::vector<T>::iterator my_lib::vector<T>::insert(iterator pos, T value){
	if(size() >= max_size()) {
		resize(max_size() * 2);
	}
	for(auto iter = end()-1; iter !=pos-1; --iter){
		*(iter+1) = *iter;
	}
	*pos = value;
	rsize++;
	return pos;
}

template<class T>
typename my_lib::vector<T>::const_iterator my_lib::vector<T>::insert(const_iterator pos, T value){
	return const_cast<const_iterator>(insert(static_cast<iterator>(pos), value));
}

template<class T>
void my_lib::vector<T>::shrink() {
	int* newarr = new T[size()];
	for(int i=0; i<size(); i++){
		newarr[i] = *(data.get()+i);
	}
	data.reset(newarr);
	msize = size();
}
#endif