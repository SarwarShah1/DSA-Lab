#include <iostream>
#include <fstream>
using namespace std;

int findAddress(int* arr,int size,int key)
{
	bool check = 0;
	for (int i = 0; i < size; i++)
	{
		int nearestGreater = 10000000000;
		int itsAdd;
		if (arr[i] == key)
			return i;
		
		if (arr[i] > key && key < nearestGreater)
		{
			nearestGreater = arr[i];
			itsAdd = i;
			if (i == size)
			{
				return itsAdd;
			}
		}
	}
}

int main()
{
	ifstream read;
	read.open("data.txt");
	if (!read.is_open())
		cout << "not open";
	
	int size = 0;
	int* SizeOfArray = &size;
	read >> *SizeOfArray;
	
	int* arr = new int[*SizeOfArray];
	for (int i = 0; i < *SizeOfArray; i++)
	{
		
		read >> arr[i];
	}

	for (int i = 0; i < *SizeOfArray; i++)
	{
		cout << arr[i];
	}
	
	int key;
	int* p2key = &key;
	cout << "\nEnter key\n";
	cin >> *p2key;
	
	cout << "Address is\n" << findAddress(arr, *SizeOfArray, *p2key) - 1;
	
	return 0;

}