#include <iostream>
#include <time.h>  // �ð��� ���õ� �����

using namespace std;

int main()
{
	srand((unsigned int)time(0));
	// ������ �ð��� ���� �޶����� ����
	// ������ �ʴ� �ð��� ���� ���� ���̺� ���� ������ �ʰ� ��ȭ�Ѵ�.

	int iUpgrade = 1;
	char choose;
	cout << "���׷��̵� ������ �սô�~" << endl;

	// ��ȭ Ȯ�� : ���׷��̵尡 0~3 : 100%��Ʈ ���� 4~6 : 40% 7~9 : 10%
	// 10~13 : 1% 14~15 : 0.01%

	while (1)
	{
		float fPercent = rand() % 10000 / 100.f;
		// ��ȭ Ȯ���� ���Ѵ�.
		// �� ������ while �� �ȿ� ������ �������� ������ �� ���´�.

		cout << "��ȭ�� �Ͻðڽ��ϱ�?(Y/N) : ";
		cin >> choose;

		/*
		cout << "Upgrade : " << iUpgrade << endl;
		cout << "Percent : " << fPercent << endl;
		�ڵ尡 �� �۵��ϳ� Ȯ���ϴ� ���
		*/

		if (choose == 'Y' || choose == 'y')
		{
			if (1 <= iUpgrade && iUpgrade <= 3)
			{
				cout << "��ȭ ����! ���� " << iUpgrade << "���Դϴ�.\n" << endl;
				iUpgrade++;
			}

			else if (4 <= iUpgrade && iUpgrade <= 6)
			{
				if (fPercent < 40.f)
				{
					cout << "��ȭ ����! ���� " << iUpgrade << "���Դϴ�.\n" << endl;
					iUpgrade++;
				}
				else
				{
					cout << "��ȭ ���� " << iUpgrade << "������ �������ϴ�.." << endl;
					cout << "��� ������ ���� ��" << endl;
					break;
				}
			}

			else if (7 <= iUpgrade && iUpgrade <= 9)
			{
				if (1 <= iUpgrade && iUpgrade <= 3)
				{
					cout << "��ȭ ����! ���� " << iUpgrade << "���Դϴ�.\n" << endl;
					iUpgrade++;
				}
				else
				{
					cout << "��ȭ ���� " << iUpgrade << "������ �������ϴ�.." << endl;
					cout << "��� ������ ���� ��" << endl;
					break;
				}
			}

			else if (10 <= iUpgrade && iUpgrade <= 13)
			{
				if (1 <= iUpgrade && iUpgrade <= 3)
				{
					cout << "��ȭ ����! ���� " << iUpgrade << "���Դϴ�.\n" << endl;
					iUpgrade++;
				}
				else
				{
					cout << "��ȭ ���� " << iUpgrade << "������ �������ϴ�.." << endl;
					cout << "��� ������ ���� ��" << endl;
					break;
				}
			}

			else if (14 <= iUpgrade && iUpgrade <= 15)
			{
				if (1 <= iUpgrade && iUpgrade <= 3)
				{
					cout << "��ȭ ����! ���� " << iUpgrade << "���Դϴ�.\n" << endl;
					iUpgrade++;
				}
				else
				{
					cout << "��ȭ ���� " << iUpgrade << "������ �������ϴ�.." << endl;
					cout << "��� ������ ���� ��" << endl;
					break;
				}
			}

			else
				cout << "�������� �ʴ� ���׷��̵� ��ġ�Դϴ�.\n" << endl;
		}

		else if (choose == 'N' || choose == 'n')
		{
			cout << "������ �����մϴ�.\n" << endl;
			break;
		}

		else
		{
			cout << "�ùٸ��� �Է��Ͻʽÿ�.\n" << endl;
		}

	}
	return 0;

}