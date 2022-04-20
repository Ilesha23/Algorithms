#define N 10000

#include <iostream>
#include <time.h>

using namespace std;

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
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void InsertionSort(int* arr) {
	int j;
	for (int i = 0; i < N - 1; i++)
	{
		j = i + 1;
		while (arr[j] < arr[j - 1])
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}
void ShellSort(int * arr)
{
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
			}
		}
		d /= 2;
	}
}
void SelectionSort(int* arr) {
	int j;
	for (int i = 0; i < N; i++)
	{
		j = i;
		while (j < N - 1 && arr[j] > arr[j + 1])
			j++;
		swap(arr[j], arr[i]);
	}
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

int main()
{
	int* arr = new int[N];

	cout.setf(ios::fixed);
	cout.precision(6);

	FillRand(arr);
	clock_t start1 = clock();
	InsertionSort(arr);
	clock_t end1 = clock();
	cout << (double)(end1 - start1) / CLOCKS_PER_SEC << endl;

	FillUp(arr);
	start1 = clock();
	InsertionSort(arr);
	end1 = clock();
	cout << (double)(end1 - start1) / CLOCKS_PER_SEC << endl;

	FillDown(arr);
	start1 = clock();
	InsertionSort(arr);
	end1 = clock();
	cout << (double)(end1 - start1) / CLOCKS_PER_SEC << endl << endl;



	FillRand(arr);
	clock_t start2 = clock();
	ShellSort(arr);
	clock_t end2 = clock();
	cout << (double)(end2 - start2) / CLOCKS_PER_SEC << endl;

	FillUp(arr);
	start2 = clock();
	ShellSort(arr);
	end2 = clock();
	cout << (double)(end2 - start2) / CLOCKS_PER_SEC << endl;

	FillDown(arr);
	start2 = clock();
	ShellSort(arr);
	end2 = clock();
	cout << (double)(end2 - start2) / CLOCKS_PER_SEC << endl << endl;



	FillRand(arr);
	clock_t start3 = clock();
	SelectionSort(arr);
	clock_t end3 = clock();
	cout << (double)(end3 - start3) / CLOCKS_PER_SEC << endl;

	FillUp(arr);
	start3 = clock();
	SelectionSort(arr);
	end3 = clock();
	cout << (double)(end3 - start3) / CLOCKS_PER_SEC << endl;

	FillDown(arr);
	start3 = clock();
	SelectionSort(arr);
	end3 = clock();
	cout << (double)(end3 - start3) / CLOCKS_PER_SEC << endl;

	delete[] arr;
	return 0;
}