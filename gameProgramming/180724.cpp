#include <iostream>
#include <ctime>
#include <conio.h>

// C언어의 기능인 conio.h
// console input output의 헤더파일
// 콘솔창에서 입출력 하는 기능들을 제공해주는 헤더파일

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i)
	{
		iNumber[i] = i + 1;
	}

	// 가장 마지막 칸은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한 값을 
	// 사용할 것인데 INT_MAX라는 값을 사용할 것. INT_MAX는 이미 정의되어 있는 값으로
	// int로 표현할 수 있는 최대값이다.
	iNumber[24] = INT_MAX; 
	// F12누르면 INT_MAX가 몇인지 알 수 있음
	// 숫자가 비어있구나라고 판단하면 됨(공백이다.)
	
	// 별이 있는 위치를 저장할 변수를 만들어준다.
	int iStarIndex = 24;

	// 마지막 공백을 제외하고 1~24까지의 숫자만 섰어준다. 즉 인텍스는 0~23번
	// 인덱스 까지만 섞어준다.

	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	// i : 세로줄 , j 가로칸
	// 2D게임에서 굉장히 많이 쓰는 공식
	// 줄번호 * 가로갯수 + 칸번호

	while (1)
	{
		system("cls");

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; j++)
			{
				// i가 0일때 j는 0~4까지 반복. 이 경우 0*5+(0~4)
				// 인덱스는 0~4가 나오게 된다.
				// i가 1일때 j는 0~4까지 반복.
				// 인덱스는 5~8이 나오게 된다. (계속 반복)
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

		// true로 주어서 먼저 모두 맞추었다고 가정하자.
		bool bWin = true;

		// 퍼즐을 맞추었는지 체크한다.
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
			cout << "축하드립니다. 숫자를 모두 맞추었습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		cout << "W : 위 S : 아래 A : 왼쪽 D : 오른쪽 Q : 종료 : ";
		char cInput = _getch();
		// _getch() 함수는 문자 1개를 입력받는 함수이다. 이 함수는 Enter를 치지
		// 않더라도 문자를 누르는 순간 바로 그 문자를 반환하고 종료한다.
		//cin >> cInput; // 이러면 우리가 입력을 하고 엔터를 쳐줘야함.

		if (cInput == 'q' || cInput == 'Q')
			break;

		// 우리가 키보드의 wasd를 누르면 그 배열에 저장된 값하고 변경함
		switch (cInput)
		{
		// starindex에서 5를 뺀 그 값이랑 바꿈
		case 'w':
		case 'W':
			// 여기서 문제는 맨 위로 올라갔을 때 한 번 더 넘으면
			// 잘못된 값을 참조를 하기 때문에 가장 맨 윗줄일 때 w를 눌러도 올라가지 않도록 설정 필요
			// i가 0일 때 못 올라가게!

			if (iStarIndex > 4)
			{
				// 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				// 위의 위치에 별을 넣어주어서 2개의 값을 서로 교체한다.
				iNumber[iStarIndex - 5] = INT_MAX;
				// 별이 한 칸 위로 올라갔으므로 iStarIndex의 값을 갱신한다.
				iStarIndex -= 5;
			}
			break;

		case 's':
		case 'S':
			// 맨 아랫줄이면 아래로 움직이지 않도록
			if (iStarIndex < 20) // 그 이상 수로 설정하면 쓰레기 값이 나옴
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				iNumber[iStarIndex + 5] = INT_MAX;
				iStarIndex += 5;
			}
			break;

		case 'a':
		case 'A':
			// 맨 왼쪽 줄이면 더 이상 왼쪽으로 가지 않도록
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
	cout << "게임을 종료합니다." << endl;

	return 0;
}