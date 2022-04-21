#define N 10000

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void FillRand(int* arr);
void FillUp(int* arr);
void FillDown(int* arr);
void show(int* arr);
void swap(int& a, int& b);
void InsertionSort(int* arr);
void ShellSort(int* arr);
void SelectionSort(int* arr);
int increment(long  inc[], long  size);
void ShellInc(int* arr);

int main()
{
	int* arr = new int[N];

	cout.setf(ios::fixed);
	cout.precision(6);

	FillRand(arr);
	clock_t start1 = clock();
	InsertionSort(arr);
	clock_t end1 = clock();
	cout << setw(25) << "Insertion sort (random): " << setw(10) << (double)(end1 - start1) / CLOCKS_PER_SEC << endl;

	FillUp(arr);
	start1 = clock();
	InsertionSort(arr);
	end1 = clock();
 	cout << setw(25) << "Insertion sort (Up): " << setw(10) << (double)(end1 - start1) / CLOCKS_PER_SEC << endl;

	FillDown(arr);
	start1 = clock();
	InsertionSort(arr);
	end1 = clock();
	cout << setw(25) << "Insertion sort (Down): " << setw(10) << (double)(end1 - start1) / CLOCKS_PER_SEC << endl << endl;



	FillRand(arr);
	clock_t start2 = clock();
	ShellSort(arr);
	clock_t end2 = clock();
	cout << setw(25) << "Shell sort (random): " << setw(10) << (double)(end2 - start2) / CLOCKS_PER_SEC << endl;

	FillUp(arr);
	start2 = clock();
	ShellSort(arr);
	end2 = clock();
	cout << setw(25) << "Shell sort (Up): " << setw(10) << (double)(end2 - start2) / CLOCKS_PER_SEC << endl;

	FillDown(arr);
	start2 = clock();
	ShellSort(arr);
	end2 = clock();
	cout << setw(25) << "Shell sort (Down): " << setw(10) << (double)(end2 - start2) / CLOCKS_PER_SEC << endl << endl;



	FillRand(arr);
	clock_t start3 = clock();
	SelectionSort(arr);
	clock_t end3 = clock();
	//show(arr);
	cout << setw(25) << "Selection sort (random): " << setw(10) << (double)(end3 - start3) / CLOCKS_PER_SEC << endl;

	FillUp(arr);
	start3 = clock();
	SelectionSort(arr);
	end3 = clock();
	cout << setw(25) << "Selection sort (Up): " << setw(10) << (double)(end3 - start3) / CLOCKS_PER_SEC << endl;

	FillDown(arr);
	start3 = clock();
	SelectionSort(arr);
	end3 = clock();
	cout << setw(25) << "Selection sort (Down): " << setw(10) << (double)(end3 - start3) / CLOCKS_PER_SEC << endl;

	delete[] arr;
	return 0;
}

void FillRand(int* arr) {
	srand(time(0));
	for (int i = 0; i < N; i++)
		arr[i] = rand() % N;
}
void FillUp(int* arr) {
	for (int i = 0; i < N; i++)
		arr[i] = i;
}
void FillDown(int* arr) {
	for (int i = 0; i < N; i++)
		arr[i] = N - i - 1;
}
void show(int* arr) {
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void InsertionSort(int* arr) {
	int j;
	long long k = 0;
	for (int i = 0; i < N - 1; i++)
	{
		j = i + 1;
		while (arr[j] < arr[j - 1])
		{
			swap(arr[j], arr[j - 1]);
 			j--;
			k++;
		}
	}
	cout << k << endl;
}
void ShellSort(int* arr)
{
	long long k = 0;
	int d = N / 2, j;
	while (d > 0)
	{
		for (int i = 0; i < N - d; i++)
		{
			j = i;
			while (arr[j] > arr[j + d])
			{
				swap(arr[j], arr[j + d]);
				j--;
				k++;
			}
		}
		d /= 2;
	}
	cout << k << endl;
}
void SelectionSort(int* arr) {
	int min_index;
	long long k = 0;
	for (int i = 0; i < N - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] < arr[min_index])
			{
				min_index = j;
				k++;
			}
			//k++;
		}
		if (min_index != i)
		{
			swap(arr[i], arr[min_index]);
			k++;
		}
		k++;
	}
	cout << k << endl;
}
int increment(long  inc[], long  size) {
	int p1, p2, p3, s;

	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2) {
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < size);

	return s > 0 ? --s : 0;
}
void ShellInc(int* arr) {
	long inc, i, j, seq[40];
	int s;
	s = increment(seq, N);
	while (s >= 0) {
		inc = seq[s--];
		for (i = inc; i < N; i++) {
			int temp = arr[i];
			for (j = i - inc; (j >= 0) && (arr[j] > N); j -= inc)
				arr[j + inc] = arr[j];
			arr[j + inc] = temp;
		}
	}
}