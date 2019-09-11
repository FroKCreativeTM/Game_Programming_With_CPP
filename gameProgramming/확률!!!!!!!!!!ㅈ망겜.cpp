#include <iostream>
#include <time.h>  // 시간에 관련된 헤더임

using namespace std;

int main()
{
	srand((unsigned int)time(0));
	// 랜덤이 시간에 따라 달라지게 설정
	// 멈추지 않는 시간에 따라서 랜덤 테이블 또한 멈추지 않고 변화한다.

	int iUpgrade = 1;
	char choose;
	cout << "업그레이드 게임을 합시다~" << endl;

	// 강화 확률 : 업그레이드가 0~3 : 100%센트 성공 4~6 : 40% 7~9 : 10%
	// 10~13 : 1% 14~15 : 0.01%

	while (1)
	{
		float fPercent = rand() % 10000 / 100.f;
		// 강화 확률을 구한다.
		// 이 문장이 while 문 안에 없으면 지속적인 랜덤이 안 나온다.

		cout << "강화를 하시겠습니까?(Y/N) : ";
		cin >> choose;

		/*
		cout << "Upgrade : " << iUpgrade << endl;
		cout << "Percent : " << fPercent << endl;
		코드가 잘 작동하나 확인하는 방법
		*/

		if (choose == 'Y' || choose == 'y')
		{
			if (1 <= iUpgrade && iUpgrade <= 3)
			{
				cout << "강화 성공! 현재 " << iUpgrade << "강입니다.\n" << endl;
				iUpgrade++;
			}

			else if (4 <= iUpgrade && iUpgrade <= 6)
			{
				if (fPercent < 40.f)
				{
					cout << "강화 성공! 현재 " << iUpgrade << "강입니다.\n" << endl;
					iUpgrade++;
				}
				else
				{
					cout << "강화 실패 " << iUpgrade << "강에서 터졌습니다.." << endl;
					cout << "장비 없으면 꺼져 ㅋ" << endl;
					break;
				}
			}

			else if (7 <= iUpgrade && iUpgrade <= 9)
			{
				if (1 <= iUpgrade && iUpgrade <= 3)
				{
					cout << "강화 성공! 현재 " << iUpgrade << "강입니다.\n" << endl;
					iUpgrade++;
				}
				else
				{
					cout << "강화 실패 " << iUpgrade << "강에서 터졌습니다.." << endl;
					cout << "장비 없으면 꺼져 ㅋ" << endl;
					break;
				}
			}

			else if (10 <= iUpgrade && iUpgrade <= 13)
			{
				if (1 <= iUpgrade && iUpgrade <= 3)
				{
					cout << "강화 성공! 현재 " << iUpgrade << "강입니다.\n" << endl;
					iUpgrade++;
				}
				else
				{
					cout << "강화 실패 " << iUpgrade << "강에서 터졌습니다.." << endl;
					cout << "장비 없으면 꺼져 ㅋ" << endl;
					break;
				}
			}

			else if (14 <= iUpgrade && iUpgrade <= 15)
			{
				if (1 <= iUpgrade && iUpgrade <= 3)
				{
					cout << "강화 성공! 현재 " << iUpgrade << "강입니다.\n" << endl;
					iUpgrade++;
				}
				else
				{
					cout << "강화 실패 " << iUpgrade << "강에서 터졌습니다.." << endl;
					cout << "장비 없으면 꺼져 ㅋ" << endl;
					break;
				}
			}

			else
				cout << "지원하지 않는 업그레이드 수치입니다.\n" << endl;
		}

		else if (choose == 'N' || choose == 'n')
		{
			cout << "게임을 종료합니다.\n" << endl;
			break;
		}

		else
		{
			cout << "올바르게 입력하십시오.\n" << endl;
		}

	}
	return 0;

}