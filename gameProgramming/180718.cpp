#include <iostream>

using namespace std;

int main()
{
	int i, j, l;

	int iLine = 7;
	int midLine = 4;

	int iStar = 1;

	for (i = 0; i < midLine; ++i)
	{
		int iCount = i;

		int iSpace = iLine / 2 - iCount;
		for (j = 0; j < iSpace+1; j++)
		{
			cout << " ";
		}
		for (l = 1; l <= iStar; ++l)
		{
			cout << "*";
		}
		cout << endl;
		iStar += 2;
	}

	iStar = 5;

	for (i = midLine; i < iLine; ++i)
	{
		int iCount = i-4;

		int iSpace = 1 + iCount;

		for (j = 0; j < iSpace + 1; j++)
		{
			cout << " ";
		}

		for (l = 1; l <= iStar; ++l)
		{
			cout << "*";
		}

		cout << endl;
		iStar -= 2;
	}


	return 0;
}