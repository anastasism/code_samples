// sliv_potocov.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include "windows.h"

#define F_ARRAY_LENGTH 5 //длина 1
#define S_ARRAY_LENGTH 9 //длина 2
#define THREAD_NUMBER F_ARRAY_LENGTH+S_ARRAY_LENGTH //количество потоков

int C[THREAD_NUMBER];
int T[THREAD_NUMBER];

template <class ForwardIterator, class T>
int binary_search(ForwardIterator first, ForwardIterator last, const T& val){
	auto f = first;
	auto l = last;
	int dif = last - first;
	while (dif / 2 > 0){
		auto mid = f + dif / 2;
		if (val > *mid) {
			f = mid;
		}
		else {
			l = mid;
		}
		dif = l - f;
	}
	return f - first + dif;
}

struct MyStruct{ 
	int*a; //указатель на начало 1 массива
	int*b; //указатель на начало 2 массива
	int i; //индекс
	bool bela; //true усли находимся в массиве А, если в массиве В - false
	MyStruct(){}
	MyStruct(int*A, int*B, int I, bool N)
	{
		a = A;
		b = B;
		i = I;
		bela = N;
	}
};

void print(int* arr, int n){
	for (int i = 0; i < n; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

DWORD WINAPI MergeThread(CONST LPVOID lpParam)
{
	MyStruct *ms=(MyStruct*)(lpParam);
	int*A = ms->a;
	int*B = ms->b;
	if (ms->bela)
	{
		if (A[ms->i] < B[0])
		{
			C[ms->i] = A[ms->i];
		}
		else if (A[ms->i]>B[S_ARRAY_LENGTH - 1])
		{
			C[ms->i + S_ARRAY_LENGTH] = A[ms->i];
		}
		else
		{
			int pos = binary_search(B, B + S_ARRAY_LENGTH - 1, A[ms->i]);
			C[ms->i + pos] = A[ms->i];
		}
	}
	else
	{
		if (B[ms->i] < A[0])
		{
			C[ms->i] = B[ms->i];
		}
		else if (B[ms->i]>A[F_ARRAY_LENGTH - 1])
		{
			C[ms->i + F_ARRAY_LENGTH] = B[ms->i];
		}
		else
		{
			int pos = binary_search(A, A + F_ARRAY_LENGTH - 1, B[ms->i]);
			C[ms->i + pos] = B[ms->i];
		}
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(GetTickCount());
	for (int i = 1; i <= THREAD_NUMBER; i++)
	{
		T[i - 1] = i;
	}
	int*A = T;
	int*B = T + F_ARRAY_LENGTH;
	std::random_shuffle(T, T + THREAD_NUMBER);
	std::sort(A, A + F_ARRAY_LENGTH);
	std::sort(B, B + S_ARRAY_LENGTH);
	print(T, THREAD_NUMBER);
	HANDLE ARR_TH[THREAD_NUMBER];
	for (int i = 0; i < THREAD_NUMBER; i++)
	{
		MyStruct* Structure;
		if (i < F_ARRAY_LENGTH)
		{
			Structure = new MyStruct(A, B, i, TRUE);
		}
		else
		{
			Structure = new MyStruct (A, B, i - F_ARRAY_LENGTH, FALSE);
		}
		ARR_TH[i] = CreateThread(NULL, 0, &MergeThread, (LPVOID)Structure, 0, NULL);
	}

	WaitForMultipleObjects(THREAD_NUMBER, ARR_TH, TRUE, INFINITE);

	for (int i = 0; i < THREAD_NUMBER; i++)
	{
		CloseHandle(ARR_TH[i]);
	}
	print(C, THREAD_NUMBER);
	return 0;
}

