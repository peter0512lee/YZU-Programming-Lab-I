#include<iostream>
#include<fstream>
#include <iomanip>


using namespace std;

struct Data
{
	char id[20];
	char name[30];
	int coursework;
	int midTerm;
	int finalTerm;

};

int inputAnInteger(int begin, int end);
void loadUserData(ifstream &userdata, Data user[], int &numMembers);
void insert(Data user[], int &numMembers);
void print(Data user[], int &numMembers);
//void grade(Data user[], int &numMembers);
void saveUserData(Data user[], int &numMembers);

int main() {

	Data user[100] = { NULL };

	//ofstream outUserData("UserData.dat", ios::binary);//第一次開要把這個寫出來 之後把這行刪掉
	ifstream userdata("UserData.dat", ios::binary || ios::in);
	
	int numMembers = 0;

	loadUserData(userdata, user, numMembers);

	int choice;

	while (true)
	{
		cout << "Enter your choice:\n";
		cout << "(1)Show grades of all students\n";
		cout << "(2)Add a new student\n";
		cout << "(3)Exit\n";

		choice = inputAnInteger(1, 3);

		switch (choice) 
		{
		case 1:
			print(user, numMembers);
			break;

		case 2:
			insert(user, numMembers);
			break;

		case 3:
			saveUserData(user, numMembers);
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
void loadUserData(ifstream &userdata, Data user[], int &numMembers)
{

	for (int i = 0;; i++)
	{ //讀取檔案
		userdata.read(reinterpret_cast<char *>(&user[i]),
			sizeof(Data));

		if (userdata.eof())
			break;
		numMembers++;
	}

}
void insert(Data user[], int &numMembers)
{

	cout << "Enter the id :" << endl;
	cin >> user[numMembers].id;

	cout << "Enter the name :" << endl;
	cin >> user[numMembers].name;

	cout << "Enter the coursework score :" << endl;
	cin >> user[numMembers].coursework;

	cout << "Enter the midTerm score :" << endl;
	cin >> user[numMembers].midTerm;

	cout << "Enter the finalTerm score :" << endl;
	cin >> user[numMembers].finalTerm;

	numMembers++;

}


void print(Data user[], int &numMembers)
{

	cout << "Yoy search data is \n";
	cout << setw(15) << right << "學號";
	cout << setw(15) << right << "姓名";
	cout << setw(15) << right << "平時成績";
	cout << setw(15) << right << "期中考";
	cout << setw(15) << right << "期末考";
	cout << setw(15) << right << "學期成績\n";

	for (int i = 0; i < numMembers; i++)
	{
		
		cout << setw(15) << right << user[i].id;
		cout << setw(15) << right << user[i].name;
		cout << setw(15) << right << user[i].coursework;
		cout << setw(15) << right << user[i].midTerm;
		cout << setw(15) << right << user[i].finalTerm ;
		cout << setw(15) << right << user[i].coursework*0.3 + user[i].midTerm*0.3 + user[i].finalTerm*0.4 << endl;

	}


}

/*void grade(Data user[], int &numMembers)
{
	for (int i = 0; i < numMembers; i++)	
		user[i].finalTerm = user[i].coursework*0.3 + user[i].midTerm*0.3 + user[i].finalTerm*0.4;	

}*/

void saveUserData(Data user[], int &numMembers)
{
	ofstream outUserData("UserData.dat", ios::binary);
	for (int i = 0; i < numMembers; i++)  //將資料存入二元檔
		outUserData.write(reinterpret_cast<const char *>(&user[i]), sizeof(Data));
}