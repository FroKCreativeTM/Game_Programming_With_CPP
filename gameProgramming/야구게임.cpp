/*
야구게임
1~9 사이의 랜덤한 숫자 3개를 얻어온다. 단 숫자는 중복되어선 안 된다.
3개의 숫자는 * * * 의 형태로 출력되고 이 3개의 숫자를 맞추는 게임ㅇ디ㅏ.
사용자는 3 개의 숫자를 맞출 때까지 계속해서 3개씩 숫자를 입력한다.
만약 맞춰야할 숫자가 7 3 8일 경우
사용자는 3개의 숫자를 계속 입력한다.
입력 : 1 2 4를 입력할 때 까지 맞춰야할 숫자 중 아무 것도 없으므로 OUT을 출력.

입력 : 7 5 9를 입력했을 경우 7은 맞춰야할 숫자 중 있고 위치도 같으므로 strike이다.
5 9 는 없으므로 출력은 1strike 0ball을 출력한다.

입력 : 7 8 6 을 엽력했을 경우 7은 1strike 8은 숫자는 있지만 위치가 다르므로 ball이 된다.
1strike 1ball을 출력한다.

이렇게 출력을 하고 입력을 받으면서 최종적으로 3개의 숫자를 자리까지 모두 일치하게 입력하면
게임이 종료된다.
*/

/*
게임 이름 : 야구 게임
개발자 : FroK
개발 날짜 : 18.07.23
게임 단순 설명 : 랜덤한 3개의 숫자를 맞추는 게임, 자세한 내용은 상단 내용 참고바람.
*/

#include <iostream>
#include <ctime>

// 줄 일일이 쓰기 귀찮다.
#define LINE cout << "================================" <<endl

using namespace std;

// 게임 메인
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

	cout << "야구게임 입니다~" << endl;

	while (1)
	{
		srand((unsigned int)time(0));

		// 랜덤한 숫자를 저장함.
		for (x = 0; x < 9; ++x)
		{
			iAi[x] = x + 1;
		}

		// swap 알고리즘을 이용해서 중복되지 않는 1~9사이의 수를 출력
		for (int i = 0; i < 9; ++i)
		{
			idx1 = rand() % 9;
			idx2 = rand() % 9;

			iTemp = iAi[idx1];
			iAi[idx1] = iAi[idx2];
			iAi[idx2] = iTemp;
		}

		//코딩 오류 확인용
		//cout << iAi[0] << endl;
		//cout << iAi[1] << endl;
		//cout << iAi[2] << endl;
		//cout << endl;
			
		//메인 메뉴 창
		LINE;
		cout << "1. 게임 시작" << endl;
		cout << "9. 게임 종료" << endl;
		LINE;
		cout << "메뉴를 입력하시오. : ";
		cin >> iChoose;

		// 게임 메뉴로 이동
		if (iChoose == 1)
		{
			system("cls");
			int i = 9;

			// 게임 창 표시
			while (1)
			{
				// 인 게임 메뉴
				LINE;
				cout << "1. 숫자 맞추기" << endl;
				cout << "2. 남은 기회 확인" << endl;
				cout << "9. 메인 메뉴로" << endl;
				LINE;
				cout << "메뉴를 입력하시오. : ";
				cin >> iChoice;

				// i가 0이 되거나 숫자를 전부 맞출 때까지 게임 플레이
				if (iChoice == 1)
				{
					
					// 수를 입력받음
					for (x = 0; x < 3; ++x)
					{
						cout << x + 1 << "번째 숫자를 입력하세요! : ";
						cin >> iPlayer[x];
					}

					// 이중 for문을 이용하여 정답인지 판별함
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

					// 모두 정답일 경우.
					if (iStrike == 3)
					{
						cout << "전부 맞추셨습니다. 축하드립니다." << endl;
						iStrike = 0, iBall = 0, iOut = 0;
						i = 9;

						// 랜덤한 숫자로 재지정
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

						// 코딩 오류 확인용
						//cout << iAi[0] << endl;
						//cout << iAi[1] << endl;
						//cout << iAi[2] << endl;
						//cout << endl;

						cout << endl;
					}

					// 틀렸을 경우
					else
					{
						// 기회를 다 소진했을 경우
						if (i == 0)
						{
							cout << "전부 틀렸습니다." << endl;
							cout << "정답은 " << iAi[0] << " " << iAi[1] << " " << iAi[2] << " 입니다." << endl;
							cout << endl;
							break;
						}

						// 기회가 남아있을 경우
						else
						{
							cout << iStrike << " Strike " << iBall << " Ball " << iOut << " Out 입니다." << endl;
							cout << endl;
							iStrike = 0 ,iBall = 0, iOut = 0;
							--i;
						}
					}
				}

				// 현재 내가 가지고 있는 기회를 표기해 줌
				else if (iChoice == 2)
				{
					cout << i << "번의 기회가 남았습니다." << endl;
					cout << endl;
					system("pause");
					system("cls");
				}

				// 메인 메뉴로 돌아감.
				else if (iChoice == 9)
				{
					system("cls");
					cout << "메인 메뉴로 가겠습니다." << endl;
					cout << endl;
					break;
				}

				else
				{
					cout << "올바른 메뉴를 입력해주십시오." << endl;
					cout << endl;
				}

			}
		}

		// 프로그램 종료
		else if (iChoose == 9)
		{
			system("cls");
			cout << "프로그램이 종료되었습니다." << endl;
			break;
		}

		// 잘못 입력 했을 경우
		else
		{
			cout << "올바른 메뉴를 입력해주십시오." << endl;
		}
		
	}

	return 0;
}