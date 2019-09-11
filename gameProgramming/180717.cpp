#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

enum SRP
{
	SRP_S = 1,
	SRP_R,
	SRP_P,
	SRP_END
};
// 가위 바위 보를 enum(열거체)을 통해 구현

int main()
{
	int iPlayer, iAi;

	srand((unsigned int) time(0));

	while (1)
	{
		system("cls");

		Beep(262, 500);
		cout << "1.가위" << endl;
		cout << "2.바위" << endl;
		cout << "3.보" << endl;
		cout << "4.종료" << endl;

		cout << "메뉴를 선택하세요 : ";
		cin >> iPlayer;

		if (iPlayer < SRP_S || iPlayer >> SRP_END)
		{
			Beep(262, 500);
			cout << "잘못된 값을 입력하셨습니다." << endl;
			system("pause");
			// 일시 정지
			continue;
			// 반복문의 시작점으로 이동시켜주는 기능
		}

		else if (iPlayer == SRP_END)
			break;

		switch (iPlayer)
		{
		case SRP_S:
			cout << "Player : 가위" << endl;
			break;
		case SRP_R:
			cout << "Player : 바위" << endl;
			break;
		case SRP_P:
			cout << "Player : 보" << endl;
			break;
		}

		// 봇이 선택
		iAi = rand() % 3 + SRP_S; /*(1~3)*/
		switch (iAi)
		{
		case SRP_S:
			cout << "AI : 가위" << endl;
			break;
		case SRP_R:
			cout << "AI : 바위" << endl;
			break;
		case SRP_P:
			cout << "AI : 보" << endl;
			break;
		}

		int iWin = iPlayer - iAi;

		/*if (iWin == 1 || iWin == -2) 
		{
			Beep(262, 500);
			cout << "플레이어의 승리!" << endl;
		}

		else if (iWin == 0)
		{
			Beep(262, 500);
			cout << "비긴 경기입니다." << endl;
		}

		else
		{
			Beep(262, 500);
			cout << "스카이넷의 승리..." << endl;
		}*/

		switch (iWin)
		{
		case 1:
		case -2:
			Beep(262, 500);
			cout << "플레이어의 승리!" << endl;
			Sleep(1250);
			break;
		case 0:
			Beep(262, 500);
			cout << "비긴 경기입니다." << endl;
			Sleep(1250);
			break;
		default:
			Beep(262, 500);
			cout << "스카이넷의 승리..." << endl;
			Sleep(1250);
			break;			
		}
	}

	return 0;
}

/*
system("cls");
// cmd 창 클리어

system("pause");
//시스템 일시정지 (continue로 풀어 재개)

Sleep(1000);
1초간 프로그램을 멈춤(딜레이 구현시 사용)

*/