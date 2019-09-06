#include <bits/stdc++.h>
#include <chrono>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace std::chrono;


struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void storeSorted(Node *root, int arr[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}

Node* insert(Node* node, int key)
{

    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void treeSort(int arr[], int n)
{
    struct Node *root = NULL;

    root = insert(root, arr[0]);
    for (int i=1; i<n; i++)
        insert(root, arr[i]);

    int i = 0;
    storeSorted(root, arr, i);
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

	treeSort(arreglo, size);
	cout<<"Sorted array: \n";

	auto stop = high_resolution_clock::now();
	auto durationMilli = duration_cast<milliseconds>(stop-start);


	cout << "Le tomo " << durationMilli.count() << " milisegundos\n";

	return 0;
}
