#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;


int Bsearch(int A[], int key, int left, int right)
{
	if (left > right)
		return -1;
	
	if (left <= right)
	{
		int	mid = (left + right) / 2;
				
		if (A[mid] == key)
			return mid;

		else if (key < A[mid])
			return Bsearch(A, key, left, mid - 1);

		else
			return Bsearch(A, key, mid + 1, right);
				
	}
	
	
}

int main()
{
	int number, left = 0, right = 9, key;
	srand(time(0));
	for ( ; ; )
	{

		cout << "(1)Start" << endl;
		cout << "(2)End" << endl;

		cin >> number;



		
		if (number == 1)
		{
			int A[10];

			

			for (int i = 0; i < 10; i++)
			{
				
				A[i] = (rand() % 100) + 1;
				
				
			}
			

			for (int i = 0; i < 9; i++)
			{
				if (A[i] > A[i + 1])
				{
					int temp;
					temp = A[i];
					A[i] = A[i + 1];
					A[i + 1] = temp;
					i = 0;
					
				}
				
			}

			for (int i = 1; i < 10; i++)
				cout << A[i] << " ";

			cout << endl;


			cout << "Please input number that you want to search: ";
			cin >> key;



			number = Bsearch(A, key, left, right);
			if (number == -1)
				cout << key << " is not in the array!";
			else
				cout << key << " is in the array, and the position is " << number;

			cout << endl << endl;

		}
		else
			break;

	}
	system("pause");
}