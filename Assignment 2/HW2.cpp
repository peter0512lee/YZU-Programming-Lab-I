#include <iostream>
using namespace std;

int main()
{	
	int n;
	cout << "Please input an integer for listing a rhombus with n asterisks in each side: ";
	cin >> n;
	
	int space = n - 1;
	for (int k = 1; k <= n; k++)
	{
		for (int c = 1; c <= space; c++)
		{
			cout << " ";
		}
		space--;
		for (int c = 1; c <= 2 * k - 1; c++)
		{
			cout << "*";
		}
		cout << endl;
	}
	space = 1;
	for (int k = 1; k <= n; k++)
	{
		for (int c = 1; c <= space; c++)
		{
			cout << " ";
		}
		space++;
		for (int c = 1; c <= 2 * (n - k) - 1; c++)
		{
			cout << "*";
		}
		cout << endl;
	}
			
	system("pause");
	return 0;
}
