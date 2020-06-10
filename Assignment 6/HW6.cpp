#include <iostream>
using namespace std;

bool fuck(char [], char [][100], int, int);

int main()
{

	

	cout << "Enter a string terminated by #:\n";

/*-------------------------------讀入字串開始-----------------------------------*/

	char original[10000] = {};
	int i = 0;

	char ch;
	ch = cin.get();
	while (ch != '\n')
	{
		original[i] = ch;
		i++;
		ch = cin.get();
	}
	original[i] = '\0';

/*-------------------------------讀入字串結束-----------------------------------*/
	


/*-----------------------------存進2維陣列開始----------------------------------*/

	char b[100][100] = {};
	int row = 0, col = -1;

	i = 0;
	while (true)
	{
		ch = original[i];
		if (ch == '#')
		{
			if ((int)b[row][0] != 0)
			{
				b[row][col + 1] = '\0';
				b[row + 1][0] = ch;
				break;
			}
			else
			{
				b[row][0] = ch;
				break;
			}
		}
		if (ch != 32 && ch != '.' && ch != ',' && ch != '\'')
		{
			col++;
			b[row][col] = ch;
		}
		else
		{
			if ((int)b[row][0] != 0)
			{
				b[row][col + 1] = '\0';
				col = -1;
				row++;
			}	
		}
		i++;
	}

/*-----------------------------存進2維陣列結束---------------------------------*/




/*-----------------------------排序開始---------------------------------*/

	char sorted[10000] = {};
	sorted[0] = '\0';
	char a[100] = {};
	i = 0;

	while (true)
	{
		col = 0, row = 0;

		while (true)
		{
			if (b[row][0] == '{')
				row++;
			else
			{
				strcpy_s(a, b[row]);
				break;
			}

			if (b[row][0] == '#')
				break;
		}
		
		if (b[row][0] == '#')
			break;

		i = row;

		for (; b[row][0] != '#'; row++)
			if (fuck(a, b, row, col))
			{
				strcpy_s(a, b[row]);
				i = row;
			}			
		
		b[i][0] = '{';
	
		strcat_s(sorted, a);
		
		for (i = 0; ; i++)
			if (sorted[i] == '\0')
			{
				sorted[i] = ' ';
				sorted[i + 1] = '\0';
				break;
			}

	}

/*-----------------------------排序結束---------------------------------*/

/*-----------------------------印出sorted開始---------------------------------*/

	char *nextTokenS;
	char *ptrS;
	cout << "\nsorted:\n";
	ptrS = strtok_s(sorted, "\"\',! #.", &nextTokenS);
	while (ptrS != NULL)
	{
		cout << ptrS << '\n';
		ptrS = strtok_s(NULL, "\"\',! #.", &nextTokenS);
	}

/*-----------------------------印出sorted結束---------------------------------*/


/*-----------------------------印出original開始---------------------------------*/
	char *nextTokenO;
	char *ptrO;
	cout << "\n\noriginal:\n";
	ptrO = strtok_s(original, "\"\',! #.", &nextTokenO);
	while (ptrO != NULL)
	{
		cout << ptrO << '\n';
		ptrO = strtok_s(NULL, "\"\',! #.", &nextTokenO);
	}

/*-----------------------------印出original結束---------------------------------*/

		
	system("pause");
	return 0;
}

bool fuck(char a[], char b[][100], int row, int col)
{
	if (b[row][col] == '\0')
		return true;
	if (a[col] == '\0')
		return false;

	if (b[row][col] < a[col])
		return true;
	else if (b[row][col] == a[col])
		return fuck(a, b, row, col + 1);
	else
		return false;

}