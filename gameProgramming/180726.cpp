#include <iostream>

using namespace std;

#define NAME_SIZE 32
#define STUDENT_MAX 10

struct _tagStudent {
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENY_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main()
{
	_tagStudent tStudentArr[STUDENT_MAX] = {};

	while (true)
	{
		system("cls");

		//�޴� ���
		cout << "1. "
	}

	return 0;
}