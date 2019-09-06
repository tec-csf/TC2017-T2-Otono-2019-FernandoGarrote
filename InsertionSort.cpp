#include <bits/stdc++.h>
#include <chrono>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace std::chrono;


void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
	int n;
	int numeros = 1000000;

	cout << "Inserte el tamaño del arreglo" << endl;
	cin >> n;
	cout << "\n";

	int arreglo[n];

	srand((unsigned) time(0));

	for (int i = 0; i < n; i++) {
		arreglo[i] = (rand()%numeros)+1;
	}

	int size = sizeof(arreglo)/sizeof(arreglo[0]);

	auto start = high_resolution_clock::now();

	insertionSort(arreglo, size);
	cout<<"Sorted array: \n";

	auto stop = high_resolution_clock::now();
	auto durationMilli = duration_cast<milliseconds>(stop-start);

	printArray(arreglo, size);

	cout << "Le tomo " << durationMilli.count() << " milisegundos\n";

	return 0;
}
