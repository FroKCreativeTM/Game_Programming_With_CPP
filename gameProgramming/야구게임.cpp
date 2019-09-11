/*
�߱�����
1~9 ������ ������ ���� 3���� ���´�. �� ���ڴ� �ߺ��Ǿ �� �ȴ�.
3���� ���ڴ� * * * �� ���·� ��µǰ� �� 3���� ���ڸ� ���ߴ� ���Ӥ���.
����ڴ� 3 ���� ���ڸ� ���� ������ ����ؼ� 3���� ���ڸ� �Է��Ѵ�.
���� ������� ���ڰ� 7 3 8�� ���
����ڴ� 3���� ���ڸ� ��� �Է��Ѵ�.
�Է� : 1 2 4�� �Է��� �� ���� ������� ���� �� �ƹ� �͵� �����Ƿ� OUT�� ���.

�Է� : 7 5 9�� �Է����� ��� 7�� ������� ���� �� �ְ� ��ġ�� �����Ƿ� strike�̴�.
5 9 �� �����Ƿ� ����� 1strike 0ball�� ����Ѵ�.

�Է� : 7 8 6 �� �������� ��� 7�� 1strike 8�� ���ڴ� ������ ��ġ�� �ٸ��Ƿ� ball�� �ȴ�.
1strike 1ball�� ����Ѵ�.

�̷��� ����� �ϰ� �Է��� �����鼭 ���������� 3���� ���ڸ� �ڸ����� ��� ��ġ�ϰ� �Է��ϸ�
������ ����ȴ�.
*/

/*
���� �̸� : �߱� ����
������ : FroK
���� ��¥ : 18.07.23
���� �ܼ� ���� : ������ 3���� ���ڸ� ���ߴ� ����, �ڼ��� ������ ��� ���� ����ٶ�.
*/

#include <iostream>
#include <ctime>

// �� ������ ���� ������.
#define LINE cout << "================================" <<endl

using namespace std;

// ���� ����
int main()
{
	int iPlayer[3];
	int	iAi[10];

	int iChoose = 0;
	int iChoice = 0;

	int x, y;
	int idx1, idx2, iTemp;

	int iStrike = 0;
	int iBall = 0;
	int iOut = 0;

	cout << "�߱����� �Դϴ�~" << endl;

	while (1)
	{
		srand((unsigned int)time(0));

		// ������ ���ڸ� ������.
		for (x = 0; x < 9; ++x)
		{
			iAi[x] = x + 1;
		}

		// swap �˰����� �̿��ؼ� �ߺ����� �ʴ� 1~9������ ���� ���
		for (int i = 0; i < 9; ++i)
		{
			idx1 = rand() % 9;
			idx2 = rand() % 9;

			iTemp = iAi[idx1];
			iAi[idx1] = iAi[idx2];
			iAi[idx2] = iTemp;
		}

		//�ڵ� ���� Ȯ�ο�
		//cout << iAi[0] << endl;
		//cout << iAi[1] << endl;
		//cout << iAi[2] << endl;
		//cout << endl;
			
		//���� �޴� â
		LINE;
		cout << "1. ���� ����" << endl;
		cout << "9. ���� ����" << endl;
		LINE;
		cout << "�޴��� �Է��Ͻÿ�. : ";
		cin >> iChoose;

		// ���� �޴��� �̵�
		if (iChoose == 1)
		{
			system("cls");
			int i = 9;

			// ���� â ǥ��
			while (1)
			{
				// �� ���� �޴�
				LINE;
				cout << "1. ���� ���߱�" << endl;
				cout << "2. ���� ��ȸ Ȯ��" << endl;
				cout << "9. ���� �޴���" << endl;
				LINE;
				cout << "�޴��� �Է��Ͻÿ�. : ";
				cin >> iChoice;

				// i�� 0�� �ǰų� ���ڸ� ���� ���� ������ ���� �÷���
				if (iChoice == 1)
				{
					
					// ���� �Է¹���
					for (x = 0; x < 3; ++x)
					{
						cout << x + 1 << "��° ���ڸ� �Է��ϼ���! : ";
						cin >> iPlayer[x];
					}

					// ���� for���� �̿��Ͽ� �������� �Ǻ���
					for (x = 0; x < 3; ++x)
					{

						for (y = 0; y < 3; ++y)
						{
							if (iPlayer[x] == iAi[y])
							{
								if (x == y)
								{
									iStrike++;
								}
								else if (x != y)
								{
									iBall++;
								}
							}
						}
						iOut = 3 - (iStrike + iBall);
					}

					// ��� ������ ���.
					if (iStrike == 3)
					{
						cout << "���� ���߼̽��ϴ�. ���ϵ帳�ϴ�." << endl;
						iStrike = 0, iBall = 0, iOut = 0;
						i = 9;

						// ������ ���ڷ� ������
						for (x = 0; x < 9; ++x)
						{
							iAi[x] = x + 1;
						}

						for (int i = 0; i < 9; ++i)
						{
							idx1 = rand() % 9;
							idx2 = rand() % 9;

							iTemp = iAi[idx1];
							iAi[idx1] = iAi[idx2];
							iAi[idx2] = iTemp;
						}

						// �ڵ� ���� Ȯ�ο�
						//cout << iAi[0] << endl;
						//cout << iAi[1] << endl;
						//cout << iAi[2] << endl;
						//cout << endl;

						cout << endl;
					}

					// Ʋ���� ���
					else
					{
						// ��ȸ�� �� �������� ���
						if (i == 0)
						{
							cout << "���� Ʋ�Ƚ��ϴ�." << endl;
							cout << "������ " << iAi[0] << " " << iAi[1] << " " << iAi[2] << " �Դϴ�." << endl;
							cout << endl;
							break;
						}

						// ��ȸ�� �������� ���
						else
						{
							cout << iStrike << " Strike " << iBall << " Ball " << iOut << " Out �Դϴ�." << endl;
							cout << endl;
							iStrike = 0 ,iBall = 0, iOut = 0;
							--i;
						}
					}
				}

				// ���� ���� ������ �ִ� ��ȸ�� ǥ���� ��
				else if (iChoice == 2)
				{
					cout << i << "���� ��ȸ�� ���ҽ��ϴ�." << endl;
					cout << endl;
					system("pause");
					system("cls");
				}

				// ���� �޴��� ���ư�.
				else if (iChoice == 9)
				{
					system("cls");
					cout << "���� �޴��� ���ڽ��ϴ�." << endl;
					cout << endl;
					break;
				}

				else
				{
					cout << "�ùٸ� �޴��� �Է����ֽʽÿ�." << endl;
					cout << endl;
				}

			}
		}

		// ���α׷� ����
		else if (iChoose == 9)
		{
			system("cls");
			cout << "���α׷��� ����Ǿ����ϴ�." << endl;
			break;
		}

		// �߸� �Է� ���� ���
		else
		{
			cout << "�ùٸ� �޴��� �Է����ֽʽÿ�." << endl;
		}
		
	}

	return 0;
}