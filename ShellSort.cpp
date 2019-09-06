#include <bits/stdc++.h>
#include <chrono>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace std::chrono;

int shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {

            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
    return 0;
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
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

	shellSort(arreglo, size);
	cout<<"Sorted array: \n";

	auto stop = high_resolution_clock::now();
	auto durationMilli = duration_cast<milliseconds>(stop-start);

	printArray(arreglo, size);

	cout << "Le tomo " << durationMilli.count() << " milisegundos\n";

	return 0;
}
