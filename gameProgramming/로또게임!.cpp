/*
���� �̸� : Lotto Program
������ : FroK
���� ��¥ : 18.07.18
���� �ܼ� ���� : ������ ���� 6���� ���߰� ���� ��ŭ�� ����� �������� �����̴�.
*/

#include <iostream>
#include <ctime>

enum lotteryRank {
	fifthRank = 1,
	fourthRank,
	thirdRank,
	secondRank,
	firstRank
};

using namespace std;

void Lottery(int * iLotto, int * MyLotto);

double iAccount = 100000;

int main()
{
	//// swap �˰���
	//int iNum1 = 1, iNum2 = 2, iNum3;
	//iNum3 = iNum1; // 3���� 1�� ����
	//iNum1 = iNum2; // 1���� 2�� ����
	//iNum2 = iNum3; // 2���� 1�� ����
	//// �ᱹ 1���� 2���� ���� �ٲ�


	// Shuffle < �� swap�˰����� Ȱ��
	// TCG���ӷ����� ���� ���� �˰����̴�.
	int iTemp, idx1, idx2;
	// 100�� ���� ���� �����ش�.

	int iLotto[45]; // 1���� 45���� ����
	int MyLotto[45];

	int iChoice;
	
	int x, y;
	int z=0;

	while(1) 
	{

		srand((unsigned int)time(0));

		// 1~45������ ���ڸ� ���ʴ�� �־��ش�.
		for (int i = 0; i < 45; ++i)
		{
			iLotto[i] = i + 1;
		}

		cout << "================================" << endl;
		cout << "1. ���� �̱�" << endl;
		cout << "2. ���� �̱�" << endl;
		cout << "3. ���� �ܰ� Ȯ��." << endl;
		cout << "9. �ζ� ���α׷� ����" << endl;
		cout << "================================" << endl;
		cout << "�޴��� �Է��Ͻÿ�. : ";
		cin >> iChoice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iChoice == 1)
		{
			if (iAccount >= 5000) 
			{
				iAccount -= 5000;
				for (int i = 0; i < 6; ++i)
				{
					cout << i + 1 << "��° �ζ� ��ȣ�� �Է��ϼ��� : ";
					cin >> MyLotto[i];
				}

				cout << "���ʽ� �ζ� ��ȣ�� �Է��ϼ��� : ";
				cin >> MyLotto[6];

				Lottery(iLotto, MyLotto);
			}
			else
			{
				cout << "���� �����ϴ�." << endl;
			}
		}

		else if (iChoice == 2)
		{
			if (iAccount >= 5000)
			{
				iAccount -= 5000;

				for (int i = 0; i < 45; ++i)
				{
					MyLotto[i] = i + 1;
				}

				for (int i = 0; i < 100; ++i)
				{
					idx1 = rand() % 45;
					idx2 = rand() % 45;

					iTemp = MyLotto[idx1];
					MyLotto[idx1] = MyLotto[idx2];
					MyLotto[idx2] = iTemp;
				}

				Lottery(iLotto, MyLotto);
			}
			else
			{
				cout << "���� �����ϴ�." << endl;
			}
		}

		else if (iChoice == 3)
		{
			cout << "���� �ܰ�� " << iAccount << "�Դϴ�." << endl;
		}

		else if (iChoice == 9)
		{
			system("cls");
			cout << "���α׷��� ����Ǿ����ϴ�." << endl;
			break;
		}

		else 
		{
			cout << "�ùٸ� �޴��� �Է����ֽʽÿ�." << endl;
		}

		cout << endl;

		z = 0;
	}
	

	return 0;
}

void Lottery(int * iLotto, int * MyLotto)
{
	int iTemp, idx1, idx2;

	int x = 0, y = 0, z = 0;

	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	}

	cout << "�̹� �� �ζ� ��ȣ : ";

	for (int i = 0; i < 6; ++i)
	{
		cout << iLotto[i] << " ";
	}

	cout << "���ʽ� ��ȣ : " << iLotto[6] << endl;

	cout << "���� �� �ζ� ��ȣ : ";

	for (int i = 0; i < 6; ++i)
	{
		cout << MyLotto[i] << " ";
	}

	cout << "���ʽ� ��ȣ : " << MyLotto[6] << endl;

	for (x = 0; x < 6; ++x)
	{
		for (y = 0; y < 6; y++)
		{
			if (MyLotto[x] == iLotto[y])
				z++;
			else
				continue;
		}
	}

	cout << "���� ���� : " << z << endl;

	if (MyLotto[6] == iLotto[6])
		cout << "���ʽ��� ���߼̽��ϴ�!" << endl;
	else
		cout << "���ʽ��� ������ ���ϼ̽��ϴ�." << endl;

	if (z == 3)
	{
		cout << "5���Դϴ�!" << endl;
		iAccount += 5000;
	}
	else if (z == 4)
	{
		cout << "4���Դϴ�!" << endl;
		iAccount += 50000;
	}
	else if (z == 5)
	{
		cout << "3���Դϴ�!" << endl;
		iAccount += 500000 + iAccount * 12.5;
	}
	else if (z == 5 && MyLotto[6] == iLotto[6])
	{
		cout << "2���Դϴ�!" << endl;
		iAccount += 5000000 + (iAccount + 5000000) * 12.5;
	}
	else if (z == 6)
	{
		cout << "1���Դϴ�!" << endl;
		iAccount += 50000000 + iAccount * 75;
	}
}