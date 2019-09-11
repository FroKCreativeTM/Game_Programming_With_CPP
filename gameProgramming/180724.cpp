#include <iostream>
#include <ctime>
#include <conio.h>

// C����� ����� conio.h
// console input output�� �������
// �ܼ�â���� ����� �ϴ� ��ɵ��� �������ִ� �������

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i)
	{
		iNumber[i] = i + 1;
	}

	// ���� ������ ĭ�� �������� ����д�. ������ �ǹ��ϴ� ������ Ư���� ���� 
	// ����� ���ε� INT_MAX��� ���� ����� ��. INT_MAX�� �̹� ���ǵǾ� �ִ� ������
	// int�� ǥ���� �� �ִ� �ִ밪�̴�.
	iNumber[24] = INT_MAX; 
	// F12������ INT_MAX�� ������ �� �� ����
	// ���ڰ� ����ֱ������ �Ǵ��ϸ� ��(�����̴�.)
	
	// ���� �ִ� ��ġ�� ������ ������ ������ش�.
	int iStarIndex = 24;

	// ������ ������ �����ϰ� 1~24������ ���ڸ� �����ش�. �� ���ؽ��� 0~23��
	// �ε��� ������ �����ش�.

	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	// i : ������ , j ����ĭ
	// 2D���ӿ��� ������ ���� ���� ����
	// �ٹ�ȣ * ���ΰ��� + ĭ��ȣ

	while (1)
	{
		system("cls");

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; j++)
			{
				// i�� 0�϶� j�� 0~4���� �ݺ�. �� ��� 0*5+(0~4)
				// �ε����� 0~4�� ������ �ȴ�.
				// i�� 1�϶� j�� 0~4���� �ݺ�.
				// �ε����� 5~8�� ������ �ȴ�. (��� �ݺ�)
				if (iNumber[i * 5 + j] == INT_MAX)
				{
					cout << "*\t";
				}
				else
				{
					cout << iNumber[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}

		// true�� �־ ���� ��� ���߾��ٰ� ��������.
		bool bWin = true;

		// ������ ���߾����� üũ�Ѵ�.
		for (int i = 0; i < 24; ++i)
		{
			if (iNumber[i] = i + 1)
			{
				bWin = false;
				break;
			}
		}

		if (bWin == true)
		{
			system("cls");
			cout << "���ϵ帳�ϴ�. ���ڸ� ��� ���߾����ϴ�." << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}

		cout << "W : �� S : �Ʒ� A : ���� D : ������ Q : ���� : ";
		char cInput = _getch();
		// _getch() �Լ��� ���� 1���� �Է¹޴� �Լ��̴�. �� �Լ��� Enter�� ġ��
		// �ʴ��� ���ڸ� ������ ���� �ٷ� �� ���ڸ� ��ȯ�ϰ� �����Ѵ�.
		//cin >> cInput; // �̷��� �츮�� �Է��� �ϰ� ���͸� �������.

		if (cInput == 'q' || cInput == 'Q')
			break;

		// �츮�� Ű������ wasd�� ������ �� �迭�� ����� ���ϰ� ������
		switch (cInput)
		{
		// starindex���� 5�� �� �� ���̶� �ٲ�
		case 'w':
		case 'W':
			// ���⼭ ������ �� ���� �ö��� �� �� �� �� ������
			// �߸��� ���� ������ �ϱ� ������ ���� �� ������ �� w�� ������ �ö��� �ʵ��� ���� �ʿ�
			// i�� 0�� �� �� �ö󰡰�!

			if (iStarIndex > 4)
			{
				// ���� �ִ� ��ġ�� �ٷ� ���� �ִ� ���� �־��ش�.
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				// ���� ��ġ�� ���� �־��־ 2���� ���� ���� ��ü�Ѵ�.
				iNumber[iStarIndex - 5] = INT_MAX;
				// ���� �� ĭ ���� �ö����Ƿ� iStarIndex�� ���� �����Ѵ�.
				iStarIndex -= 5;
			}
			break;

		case 's':
		case 'S':
			// �� �Ʒ����̸� �Ʒ��� �������� �ʵ���
			if (iStarIndex < 20) // �� �̻� ���� �����ϸ� ������ ���� ����
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				iNumber[iStarIndex + 5] = INT_MAX;
				iStarIndex += 5;
			}
			break;

		case 'a':
		case 'A':
			// �� ���� ���̸� �� �̻� �������� ���� �ʵ���
			if (iStarIndex % 5 != 0)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				iNumber[iStarIndex - 1] = INT_MAX;
				iStarIndex -= 1;
			}
			break;

		case 'd':
		case 'D':
			if (iStarIndex % 5 != 4)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				iNumber[iStarIndex + 1] = INT_MAX;
				iStarIndex += 1;
			}
			break;

		default:
			break;
		}
	}

	system("cls");
	cout << "������ �����մϴ�." << endl;

	return 0;
}