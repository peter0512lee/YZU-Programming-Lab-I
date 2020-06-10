#include <cstdlib>
#include <iostream>
using namespace std;

void bubblesort(int i, int j, int m, int g[10])
{
	for (i = 1; i<10; i++)
	{
		for (j = 0; j<10 - i; j++)
		{
			if (g[j]<g[j + 1])
			{
				m = g[j];
				g[j] = g[j + 1];
				g[j + 1] = m;
			}
		}
	}
	cout << "Sort from large to small: " << endl;
	for (j = 0; j<10; j++)
	{
		cout << g[j] << " ";
	}
	cout << endl;
	cout << endl;
}

void selectionsort(int i, int j, int m, int g[10])
{
	
		for (i = 0; i<10; i++)
		{
			for (j = 0; j<10 - i; j++)
			{
				if (g[j]<g[j + 1])
				{
					m = g[j];
					g[j] = g[j + 1];
					g[j + 1] = m;
				}
			}
		}
		cout << "Sort from small to large: " << endl;
		for (j = 9; j>=0; j--)
		{
			cout << g[j] << " ";
		}
		cout << endl;
		cout << endl;

		system("PAUSE");
}

int main()
{
	int i=0, j=0, m=0, h=0, t=0, temp=0;
	int g[10];

	cout << "Please input 10 numbers: " << endl;
	for (h = 0; h<10; h++)
	{
		cin >> g[h];
	}

	cout << "The input numbers is:" << endl;
	
	for (h = 0; h<10; h++)
	{
		cout << g[h] << " ";
	}

	cout << endl;
	cout << endl;

	bubblesort(i, j, m, g);

	selectionsort(i, j, m, g);
}

