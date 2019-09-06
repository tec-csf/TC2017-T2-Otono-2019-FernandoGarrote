#include <bits/stdc++.h>
#include <chrono>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace std::chrono;


void bucketSort(int arr[], int n)
{
    vector<int> b[n];

    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i];
       b[bi].push_back(arr[i]);
    }

    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
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

	bucketSort(arreglo, size);
	cout<<"Sorted array: \n";

	auto stop = high_resolution_clock::now();
	auto durationMilli = duration_cast<milliseconds>(stop-start);

	printArray(arreglo, size);

	cout << "Le tomo " << durationMilli.count() << " milisegundos\n";

	return 0;
}
