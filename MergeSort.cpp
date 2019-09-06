#include <bits/stdc++.h>
#include <chrono>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace std::chrono;


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
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

  	mergeSort(arreglo,0, size-1);
  	cout<<"Sorted array: \n";

  	auto stop = high_resolution_clock::now();
  	auto durationMilli = duration_cast<milliseconds>(stop-start);


  	cout << "Le tomo " << durationMilli.count() << " milisegundos\n";

  	return 0;
  }
