#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

bool InputID(char id[11])
{
	int length = strlen(id);
	
	if (length == 10)
		return true;
	else
		return false;

}

bool CheckID(char id[11], int firstChar[26])
{
	if (id[0] >= 'a' && id[0] <= 'z')
		return false;
	
	int leadingNumber;
	if (id[0] >= 'A' && id[0] <= 'Z')
		leadingNumber = firstChar[id[0] - 'A'];
	if (id[0] >= 'a' && id[0] <= 'z')
		leadingNumber = firstChar[id[0] - 'a'];

	int sum = (leadingNumber % 10) * 9 + (leadingNumber / 10);

	for (int i = 1; i <= 8; i++)
		sum += (id[i] - '0') * (9 - i);

	if (sum % 10 != 0)
		id[9] = 10 - (sum % 10) + '0';

	return true;
}

int main()
{
	for (; ; )
	{
		int firstChar[26] = { 10, 11, 12, 13, 14, 15, 16, 17, 34, 18,
			19, 20, 21, 22, 35, 23, 24, 25, 26, 27,
			28, 29, 32, 30, 31, 33 };

		char id[11] = "";
		cout << "please input your ID number: ";
		cin >> id;

		if (InputID(id) == false)
			cout << " Input error ! " << endl;

		else if (CheckID(id, firstChar) == false)
			cout << " Input error ! " << endl;

		else if (CheckID(id, firstChar))
			cout << "The ID is right ! " << endl;

	}

		system("pause");
	
}