#include<iostream>
#include<fstream>
#include <iomanip>

using namespace std;

struct Data
{
	char NO[5];
	char name[30];
	char sex[5];
	char age[5];
	struct Data *next;
};



int inputAnInteger(int begin, int end);
void loadUserData(ifstream &userdata, Data *&UserHead, Data *&UserLast);
void insert(Data *&UserHead, Data *&UserLast);
void Delete(Data *&UserHead);
void search(Data *UserHead);
void print(Data *UserHead);
void saveUserData(Data *&UserHead);

int main() {

	Data *UserHead = NULL;
	Data *UserLast = NULL;
	//ofstream outUserData("UserData.dat", ios::binary);//第一次開要把這個寫出來 之後把這行刪掉
	ifstream userdata("UserData.txt");
	

	int numMembers = 0;

	loadUserData(userdata, UserHead , UserLast);
	
	int choice;

	while (true)
	{
		cout << "Enter your choice:\n";
		cout << "(1)insert\n";
		cout << "(2)delete\n";
		cout << "(3)search\n";
		cout << "(4)print\n";
		cout << "(5)exit\n";

		choice = inputAnInteger(1, 5);
		switch (choice) {
		case 1:
			insert(UserHead,UserLast);
			break;

		case 2:
			Delete(UserHead);
			break;

		case 3:
			search(UserHead);
			break;

		case 4:
			print(UserHead);
			break;

		case 5:
			saveUserData(UserHead);
			return 0;

		default:
			cout << "Input Error!\n\n";
			break;
		
		}

	}
			


}
int inputAnInteger(int begin, int end)
{

	int integer;
	cin >> integer;

	if (integer<begin || integer > end)
	{

		cin.clear();
		cin.ignore(100, '\n');
		return -1;

	}
	else
		return integer;

}
void loadUserData(ifstream &userdata, Data *&UserHead, Data *&UserLast)
{
	for (int i = 0;;i++) //讀取檔案
	{
		Data *buffer = new Data;
		
		userdata >> buffer->NO >> buffer->name >> buffer->sex >> buffer->age;
		

		if (userdata.eof())
			return;

		if (i == 0) {


			UserHead = buffer;
			UserLast = buffer;
		}
		else {

			buffer->next = NULL;
			UserLast->next = buffer;
			UserLast = buffer;

		}

	}
	
	
}
void insert(Data *&UserHead, Data *&UserLast)
{
	Data *buffer = new Data;

	cout << "Enter the NO. :";
	cin >> buffer->NO;

	cout << "Enter the name :";
	cin >> buffer->name;

	cout << "Enter the sex :";
	cin >> buffer->sex;

	cout << "Enter the age :";
	cin >> buffer->age;

	buffer->next = NULL;

	if (UserHead != NULL) {
		

		UserLast->next = buffer;
		UserLast = buffer;
	}
	else {
		
		UserHead = buffer;
		UserLast = buffer;

	}
}
void Delete(Data *&UserHead)
{
	Data *ptr = UserHead;
	Data *previous = UserHead;

	
	char name[30];


	cout << "Enter the name of you want delete:\n";

	cin >> name;
	
	
	while (ptr != NULL) {
		
		if (strcmp(ptr->name, name) == 0) {
			if (previous != ptr) {
				previous->next = ptr->next;

				delete ptr;
				return;
			}
			else {
				UserHead = UserHead->next;
				delete ptr;
				return;

			}
		}
		
		previous = ptr;

		ptr = ptr->next;
		
		
	}
	cout << "You delete data doesn't exist\n";
}
void search(Data *UserHead)
{

	char name[30];

	cout << "Enter the name of you want search:\n";

	cin >> name;

	while (UserHead != NULL) {
		if (strcmp(UserHead->name, name) == 0)
		{

			cout << "Yoy search data is \n";
			cout << setw(10) << right << "NO.";
			cout << setw(10) << right << "Name";
			cout << setw(10) << right << "Sex";
			cout << setw(10) << right << "Age\n";
			cout << setw(10) << right << UserHead->NO;
			cout << setw(10) << right << UserHead->name;
			cout << setw(10) << right << UserHead->sex;
			cout << setw(9) << right << UserHead->age << endl;

			return;
		}

		UserHead = UserHead->next;
			

	}
	cout << "You search data doesn't exist\n";
}
void print(Data *UserHead)
{

	cout << "Yoy search data is \n";
	cout << setw(10) << right << "NO.";
	cout << setw(10) << right << "Name";
	cout << setw(10) << right << "Sex";
	cout << setw(10) << right << "Age\n";
	while(UserHead != NULL) {

		
		cout << setw(10) << right << UserHead->NO;
		cout << setw(10) << right << UserHead->name;
		cout << setw(10) << right << UserHead->sex;
		cout << setw(9) << right << UserHead->age << endl;
		UserHead = UserHead->next;
	}


}
void saveUserData(Data *&UserHead)
{
	ofstream outUserData("UserData.txt" );
	while(UserHead != NULL) {  //將資料存入二元檔
		outUserData << UserHead->NO << " ";
		outUserData << UserHead->name << " ";
		outUserData << UserHead->sex << " ";
		outUserData << UserHead->age << "\n";
		UserHead = UserHead->next;
	}
}