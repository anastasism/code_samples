#include <iostream>

template <class Value, class ForwardIterator> 
void merge(ForwardIterator first, ForwardIterator last, ForwardIterator middle, Value *buf);

template <class Value, class ForwardIterator> 
void get_result(ForwardIterator first, ForwardIterator last, Value*buf); 

template <class Value, class ForwardIterator> 
void merge_sort(ForwardIterator first, ForwardIterator last, Value* buf){
	int size = last - first;
	if (size > 1){
		ForwardIterator middle = first + (size / 2);
		merge_sort<Value, ForwardIterator>(first, middle, buf);
		merge_sort<Value, ForwardIterator>(middle, last, buf);
		merge<Value, ForwardIterator>(first, last, middle, buf);
		get_result<Value, ForwardIterator>(first, last, buf);
	}

}
template <class Value, class ForwardIterator> 
void merge_sort(ForwardIterator first, ForwardIterator last)
{
	int n = last - first;
	Value *buf = new int[n];
	merge_sort<Value, ForwardIterator>(first, last, buf);
	delete[] buf;
}
template <class Value, class ForwardIterator> 
void merge(ForwardIterator first, ForwardIterator last, ForwardIterator middle, Value *buf){
	ForwardIterator tfirst = first;
	ForwardIterator tlast = middle;
	Value* t = buf;
	while (tfirst != middle && tlast != last){
		if (*tfirst > *tlast)
		{
			*t = *tlast;
			tlast++;
		}
		else{
			*t = *tfirst;
			tfirst++;
		}
		t++;
	}
	while (tfirst != middle){
		*t = *tfirst;
		tfirst++;
		t++;
	}
	while (tlast != last){
		*t = *tlast;
		tlast++;
		t++;
	}
}

template <class Value, class ForwardIterator> 
void get_result(ForwardIterator first, ForwardIterator last, Value*buf){
	ForwardIterator s = first;
	Value *t = buf;
	while (s != last)
	{
		*s = *t;
		s++;
		t++;
	}
}