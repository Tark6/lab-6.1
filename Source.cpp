#include <iostream>
#include <ctime>
#include <chrono>

const int SIZE = 10;

using namespace std;

template<class T>
void input(T* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 50;
	}
}

template<class T>
void BubbleSort(T* arr, int size)
{
	for (int i = 0; i < size; i++)

		for (int j = size - 1; j > i; j--)

			if (arr[j] < arr[j - 1])

				swap(arr[j], arr[j - 1]);
}

template<class T>
void output(T* arr, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));

	int arr[SIZE];
	input(arr, SIZE);
	output(arr, SIZE);

	auto begin = std::chrono::steady_clock::now();

	BubbleSort(arr, SIZE);

	auto end = std::chrono::steady_clock::now();

	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	cout << "Time to sort: " << elapsed_ms.count() << endl;

	output(arr, SIZE);

	return 0;
}
