#include <iostream>
using namespace std;

int main()
{
	float  weight, height;
	cout << "�п�J�����魫" << endl;
	cin >> weight >> height;
	float BMI;
	BMI = weight / (height * height);
	cout << BMI << endl;
	if (BMI < 18.5)
		cout << "�魫�L��";
	else if (18.5 <= BMI && BMI < 24)
		cout << "���`�d��";
	else if (24 <= BMI && BMI < 27)
		cout << "�L��";
	else if (27 <= BMI && BMI < 30)
		cout << "���תέD";
	else if (30 <= BMI && BMI < 35)
		cout << "���תέD";
	else
		cout << "���תέD";
	

	    system("pause");
		return 0;

}