#include<iostream>
#include<iomanip>

using namespace std;

int main() {

	int number;


	cout << "Enter the number of primes you would like:\n";
	cin >> number;

	int* primes = new int[number];

	int p = 0;

	for (int i = 2; ; i++) {
		
		for (int j = 2; j <= i; j++) {	
			

			if (i == j) {
				primes[p] = i;
				p++;
			}
			if (i % j == 0)
				break;
			
			

		}
		if (p == number)
			break;
		
	}

	for (int i = 0; i < number; i++) {

		if (i % 10 == 9 || i % 10 == 4)
			cout << right << setw(5) << primes[i] << endl;
		else
			cout << right << setw(5) << primes[i];
	}

	delete[] primes;
	cout << endl;
	system("pause");
}