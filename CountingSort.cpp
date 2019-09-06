#include <bits/stdc++.h>
#include <chrono>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace std::chrono;



int getMax(int array[], int size) {
   int max = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max;
}
void countingSort(int *array, int size) {
   int output[size+1];
   int max = getMax(array, size);
   int count[max+1];
   for(int i = 0; i<=max; i++)
      count[i] = 0;
   for(int i = 1; i <=size; i++)
      count[array[i]]++;
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1;
   }
   for(int i = 1; i<=size; i++) {
      array[i] = output[i];
   }
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

	countingSort(arreglo, size);
	cout<<"Sorted array: \n";

	auto stop = high_resolution_clock::now();
	auto durationMilli = duration_cast<milliseconds>(stop-start);


	cout << "Le tomo " << durationMilli.count() << " milisegundos\n";

	return 0;
}
