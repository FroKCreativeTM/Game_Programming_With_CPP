/*
게임 이름 : Lotto Program
개발자 : FroK
개발 날짜 : 18.07.18
게임 단순 설명 : 랜덤한 숫자 6개를 맞추고 맞춘 만큼의 상금을 가져가는 게임이다.
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
	//// swap 알고리즘
	//int iNum1 = 1, iNum2 = 2, iNum3;
	//iNum3 = iNum1; // 3번에 1을 저장
	//iNum1 = iNum2; // 1번에 2를 저장
	//iNum2 = iNum3; // 2번에 1을 저장
	//// 결국 1번과 2번의 수를 바꿈


	// Shuffle < 이 swap알고리즘을 활용
	// TCG게임류에서 자주 쓰는 알고리즘이다.
	int iTemp, idx1, idx2;
	// 100번 정도 골고루 섞어준다.

	int iLotto[45]; // 1부터 45까지 숫자
	int MyLotto[45];

	int iChoice;
	
	int x, y;
	int z=0;

	while(1) 
	{

		srand((unsigned int)time(0));

		// 1~45까지의 숫자를 차례대로 넣어준다.
		for (int i = 0; i < 45; ++i)
		{
			iLotto[i] = i + 1;
		}

		cout << "================================" << endl;
		cout << "1. 직접 뽑기" << endl;
		cout << "2. 랜덤 뽑기" << endl;
		cout << "3. 현재 잔고 확인." << endl;
		cout << "9. 로또 프로그램 종료" << endl;
		cout << "================================" << endl;
		cout << "메뉴를 입력하시오. : ";
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
					cout << i + 1 << "번째 로또 번호를 입력하세요 : ";
					cin >> MyLotto[i];
				}

				cout << "보너스 로또 번호를 입력하세요 : ";
				cin >> MyLotto[6];

				Lottery(iLotto, MyLotto);
			}
			else
			{
				cout << "돈이 없습니다." << endl;
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
				cout << "돈이 없습니다." << endl;
			}
		}

		else if (iChoice == 3)
		{
			cout << "현재 잔고는 " << iAccount << "입니다." << endl;
		}

		else if (iChoice == 9)
		{
			system("cls");
			cout << "프로그램이 종료되었습니다." << endl;
			break;
		}

		else 
		{
			cout << "올바른 메뉴를 입력해주십시오." << endl;
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

	cout << "이번 주 로또 번호 : ";

	for (int i = 0; i < 6; ++i)
	{
		cout << iLotto[i] << " ";
	}

	cout << "보너스 번호 : " << iLotto[6] << endl;

	cout << "내가 고른 로또 번호 : ";

	for (int i = 0; i < 6; ++i)
	{
		cout << MyLotto[i] << " ";
	}

	cout << "보너스 번호 : " << MyLotto[6] << endl;

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

	cout << "맞춘 갯수 : " << z << endl;

	if (MyLotto[6] == iLotto[6])
		cout << "보너스도 맞추셨습니다!" << endl;
	else
		cout << "보너스를 맞추지 못하셨습니다." << endl;

	if (z == 3)
	{
		cout << "5등입니다!" << endl;
		iAccount += 5000;
	}
	else if (z == 4)
	{
		cout << "4등입니다!" << endl;
		iAccount += 50000;
	}
	else if (z == 5)
	{
		cout << "3등입니다!" << endl;
		iAccount += 500000 + iAccount * 12.5;
	}
	else if (z == 5 && MyLotto[6] == iLotto[6])
	{
		cout << "2등입니다!" << endl;
		iAccount += 5000000 + (iAccount + 5000000) * 12.5;
	}
	else if (z == 6)
	{
		cout << "1등입니다!" << endl;
		iAccount += 50000000 + iAccount * 75;
	}
}