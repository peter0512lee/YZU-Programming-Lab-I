#include <iostream>
using namespace std;

int main()
{
	float  weight, height;
	cout << "請輸入身高體重" << endl;
	cin >> weight >> height;
	float BMI;
	BMI = weight / (height * height);
	cout << BMI << endl;
	if (BMI < 18.5)
		cout << "體重過輕";
	else if (18.5 <= BMI && BMI < 24)
		cout << "正常範圍";
	else if (24 <= BMI && BMI < 27)
		cout << "過重";
	else if (27 <= BMI && BMI < 30)
		cout << "輕度肥胖";
	else if (30 <= BMI && BMI < 35)
		cout << "中度肥胖";
	else
		cout << "重度肥胖";
	

	    system("pause");
		return 0;

}