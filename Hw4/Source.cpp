#include<iostream>

using namespace std;

void fillArray(int* a, int len);
void swap(int& a, int& b);
void mixArray(int* a, int len);
int bubbleSort(int* a, int len, int choice);
int insertionSort(int* a, int len, int choice);
int selectionSort(int* a, int len, int choice);


int main() 
{
	int len = 0;
	for (len = 5; len <= 20; len += 5) 
	{
		int* a = new int[len];
		fillArray(a, len);

		int bubblePer = 0;
		int bubbleCom = 0;

		int insertionPer = 0;
		int insertionCom = 0;

		int selectionPer = 0;
		int selectionCom = 0;

		for (int i = 0; i < 1000; i++) 
		{
			mixArray(a, len);
			bubblePer = bubblePer + bubbleSort(a, len, 0);
			bubbleCom = bubbleCom + bubbleSort(a, len, 1);

			mixArray(a, len);
			insertionPer = insertionPer + insertionSort(a, len, 0);
			insertionCom = insertionCom + insertionSort(a, len, 1);

			mixArray(a, len);
			selectionPer = selectionPer + selectionSort(a, len, 0);
			selectionCom = selectionCom + selectionSort(a, len, 1);
		}
		cout << "bubblePer = " << bubblePer / 1000;
		cout << "bubbleCom = " << bubbleCom / 1000;

		cout << "insertionPer" << insertionPer / 1000;
		cout << "insertionCom" << insertionCom / 1000;

		cout << "selectionPer" << selectionPer / 1000;
		cout << "selectionCom" << selectionCom / 1000;
		delete[] a;
	}
	return EXIT_SUCCESS;
}

void fillArray(int* a, int len) 
{
	for (int i = 0; i < len; i++) 
	{
		a[i] = rand() % 90 + 10;
	}
}

void swap(int& a, int& b) 
{
	int c = a;
	a = b;
	b = c;
}

void mixArray(int* a, int len) 
{
	for (int i = 0; i < len; i++) 
	{
		swap(a[i], a[rand() % len]);
	}
}

int bubbleSort(int* a, int len, int choice) 
{
	int bubblePer = 0;
	int bubbleCom = 0;
	for (int i = 0; i < len - 1; i++) 
	{
		for (int j = 0; j < len - i - 1; j++) 
		{
			bubbleCom++;
			if (a[j] > a[j + 1]) 
			{
				bubblePer++;
				swap(a[j], a[j+1]);
			}
		}
	}

	if (choice == 0) return bubblePer;
	else return bubbleCom;
}

int insertionSort(int* a, int len, int choice) 
{
	int insertionPer = 0;
	int insertionCom = 0;
	for (int i = 0; i < len; i++) 
	{
		int tamp = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > tamp) 
		{
			insertionCom++;
			a[j] = a[j - 1];
			j--;
			insertionPer++;
		}
		insertionCom++;
		a[j] = tamp;
		insertionPer++;
	}

	if (choice == 0) return insertionPer;
	else return insertionCom;
}

int selectionSort(int* a, int len, int choice) 
{
	int selectionPer = 0;
	int selectionCom = 0;
	for (int i = 0; i < len - 1; i++) 
	{
		int index = i;
		for (int j = i + 1; j < len; j++) 
		{
			selectionCom++;
			if (a[j] < a[index]) 
			{
				index = j;
			}
		}
		swap(a[i], a[index]);
		selectionPer++;
	}
	if (choice == 0) return selectionPer;
	else return selectionCom;
}