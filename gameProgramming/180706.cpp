/*
	C/C++ 에서는 난수를 발생시키기 위한 무작위의 난수 테이블이 있음.
	다만 완전히 랜덤이 되지 않음.

	고로 완벽한 랜덤이 되게 하기 위해선 설정을 해줘야함.
	
	쉬지 않고 바뀌는 것이 무엇인가?
	바로 시간! 시간값을 넣어 시간이 언제냐에 따라 난수 테이블을 따로 가져올 수 있음.
	즉 겹치지 않는 테이블을 얻어올 수 있다.

	srand()
*/

#include <iostream>
#include <ctime>  // 시간에 관련된 헤더임

using namespace std;

int main()
{

	// 난수발생!
	srand((unsigned int)time(0)); 
	// 0을 넣으면 현재 시간 값을 가져옴
	// unsigned int로 형 변환.
	// 안 하고 해도 에러는 없으나 
	// 다만 time_t라는 타입과 unsigned int타입이 충돌

	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	// 임의의 값을 가져와서 출력

	// 만약 100 아래의 값을 가지고 싶다.
	cout << (rand() % 100) << endl; 
	// 무조건 0~99

	// 만약 100에서 200 사이의 값을 가지고 싶다.
	cout << (rand() % 100 + 100) << endl;

	// 허나 실무에선 srand 는 잘 안 쓰고 알고리즘을 만들어서 씀.

	// 자 이제 강화 기계를 만들어보자.
	// 게임에 아주 좋은 템이 있다 치자.
	// 템이 나오는 확률은 소수점 단위

	cout << (rand() % 10000 / 100.f) << endl;
	// 안타깝지만 rand는 만 단위까지 밖에 안 나온다.
	// 그래서 난수를 만들어서 쓰는 것이다. ㅠㅠ
	// 타임 쓰려면 꼭 필요하다.

	int iUpgrade = 1;
	char choose;
	cout << "업그레이드 게임을 합시다~" << endl;

	// 강화 확률을 구한다.


	// 강화 확률 : 업그레이드가 0~3 : 100%센트 성공 4~6 : 40% 7~9 : 10%
	// 10~13 : 1% 14~15 : 0.01%

	while (1)
	{
		float fPercent = rand() % 10000 / 100.f;
		cout << "강화를 하시겠습니까?(Y/N) : ";
		cin >> choose;

		// 0~9999를 100으로 나누니 0~99.99까지의 숫자가 나온다.

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
					cout << "강화 실패 " << iUpgrade << "강에서 터졌습니다..\n" << endl;
					cout << "장비 없으면 꺼져 ㅋ" << endl;
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
					cout << "강화 실패 " << iUpgrade << "강에서 터졌습니다..\n" << endl;
					cout << "장비 없으면 꺼져 ㅋ" << endl;
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
					cout << "강화 실패 " << iUpgrade << "강에서 터졌습니다..\n" << endl;
					cout << "장비 없으면 꺼져 ㅋ" << endl;
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
					cout << "강화 실패 " << iUpgrade << "강에서 터졌습니다..\n" << endl;
					cout << "장비 없으면 꺼져 ㅋ" << endl;
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