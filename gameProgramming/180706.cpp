/*
	C/C++ ������ ������ �߻���Ű�� ���� �������� ���� ���̺��� ����.
	�ٸ� ������ ������ ���� ����.

	��� �Ϻ��� ������ �ǰ� �ϱ� ���ؼ� ������ �������.
	
	���� �ʰ� �ٲ�� ���� �����ΰ�?
	�ٷ� �ð�! �ð����� �־� �ð��� �����Ŀ� ���� ���� ���̺��� ���� ������ �� ����.
	�� ��ġ�� �ʴ� ���̺��� ���� �� �ִ�.

	srand()
*/

#include <iostream>
#include <ctime>  // �ð��� ���õ� �����

using namespace std;

int main()
{

	// �����߻�!
	srand((unsigned int)time(0)); 
	// 0�� ������ ���� �ð� ���� ������
	// unsigned int�� �� ��ȯ.
	// �� �ϰ� �ص� ������ ������ 
	// �ٸ� time_t��� Ÿ�԰� unsigned intŸ���� �浹

	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	// ������ ���� �����ͼ� ���

	// ���� 100 �Ʒ��� ���� ������ �ʹ�.
	cout << (rand() % 100) << endl; 
	// ������ 0~99

	// ���� 100���� 200 ������ ���� ������ �ʹ�.
	cout << (rand() % 100 + 100) << endl;

	// �㳪 �ǹ����� srand �� �� �� ���� �˰����� ���� ��.

	// �� ���� ��ȭ ��踦 ������.
	// ���ӿ� ���� ���� ���� �ִ� ġ��.
	// ���� ������ Ȯ���� �Ҽ��� ����

	cout << (rand() % 10000 / 100.f) << endl;
	// ��Ÿ������ rand�� �� �������� �ۿ� �� ���´�.
	// �׷��� ������ ���� ���� ���̴�. �Ф�
	// Ÿ�� ������ �� �ʿ��ϴ�.

	int iUpgrade = 1;
	char choose;
	cout << "���׷��̵� ������ �սô�~" << endl;

	// ��ȭ Ȯ���� ���Ѵ�.


	// ��ȭ Ȯ�� : ���׷��̵尡 0~3 : 100%��Ʈ ���� 4~6 : 40% 7~9 : 10%
	// 10~13 : 1% 14~15 : 0.01%

	while (1)
	{
		float fPercent = rand() % 10000 / 100.f;
		cout << "��ȭ�� �Ͻðڽ��ϱ�?(Y/N) : ";
		cin >> choose;

		// 0~9999�� 100���� ������ 0~99.99������ ���ڰ� ���´�.

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
					cout << "��ȭ ���� " << iUpgrade << "������ �������ϴ�..\n" << endl;
					cout << "��� ������ ���� ��" << endl;
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
					cout << "��ȭ ���� " << iUpgrade << "������ �������ϴ�..\n" << endl;
					cout << "��� ������ ���� ��" << endl;
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
					cout << "��ȭ ���� " << iUpgrade << "������ �������ϴ�..\n" << endl;
					cout << "��� ������ ���� ��" << endl;
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
					cout << "��ȭ ���� " << iUpgrade << "������ �������ϴ�..\n" << endl;
					cout << "��� ������ ���� ��" << endl;
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