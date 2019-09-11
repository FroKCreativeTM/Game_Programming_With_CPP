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
// ���� ���� ���� enum(����ü)�� ���� ����

int main()
{
	int iPlayer, iAi;

	srand((unsigned int) time(0));

	while (1)
	{
		system("cls");

		Beep(262, 500);
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "3.��" << endl;
		cout << "4.����" << endl;

		cout << "�޴��� �����ϼ��� : ";
		cin >> iPlayer;

		if (iPlayer < SRP_S || iPlayer >> SRP_END)
		{
			Beep(262, 500);
			cout << "�߸��� ���� �Է��ϼ̽��ϴ�." << endl;
			system("pause");
			// �Ͻ� ����
			continue;
			// �ݺ����� ���������� �̵������ִ� ���
		}

		else if (iPlayer == SRP_END)
			break;

		switch (iPlayer)
		{
		case SRP_S:
			cout << "Player : ����" << endl;
			break;
		case SRP_R:
			cout << "Player : ����" << endl;
			break;
		case SRP_P:
			cout << "Player : ��" << endl;
			break;
		}

		// ���� ����
		iAi = rand() % 3 + SRP_S; /*(1~3)*/
		switch (iAi)
		{
		case SRP_S:
			cout << "AI : ����" << endl;
			break;
		case SRP_R:
			cout << "AI : ����" << endl;
			break;
		case SRP_P:
			cout << "AI : ��" << endl;
			break;
		}

		int iWin = iPlayer - iAi;

		/*if (iWin == 1 || iWin == -2) 
		{
			Beep(262, 500);
			cout << "�÷��̾��� �¸�!" << endl;
		}

		else if (iWin == 0)
		{
			Beep(262, 500);
			cout << "��� ����Դϴ�." << endl;
		}

		else
		{
			Beep(262, 500);
			cout << "��ī�̳��� �¸�..." << endl;
		}*/

		switch (iWin)
		{
		case 1:
		case -2:
			Beep(262, 500);
			cout << "�÷��̾��� �¸�!" << endl;
			Sleep(1250);
			break;
		case 0:
			Beep(262, 500);
			cout << "��� ����Դϴ�." << endl;
			Sleep(1250);
			break;
		default:
			Beep(262, 500);
			cout << "��ī�̳��� �¸�..." << endl;
			Sleep(1250);
			break;			
		}
	}

	return 0;
}

/*
system("cls");
// cmd â Ŭ����

system("pause");
//�ý��� �Ͻ����� (continue�� Ǯ�� �簳)

Sleep(1000);
1�ʰ� ���α׷��� ����(������ ������ ���)

*/