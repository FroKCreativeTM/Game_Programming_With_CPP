#include <iostream>
#include <ctime>

using namespace std;

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUM
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

// 함수는 선언과 정의 부분으로 나눌 수 있다.
// 선언
void SetNumber(int * pArray);
void Shuffle(int * pArray);
AI_MODE SelectAIMode();
void OutputNumber(int * pArray, int iBingo);
bool ChangeNumber(int * pArray, int iInput);
int SelectAINumber(int * pArray, AI_MODE eMode);
int BingoCounting(int * pArray);
int BingoCountingH(int* pArray);
int BingoCountingV(int* pArray);
int BingoCountingLTD(int* pArray);
int BingoCountingRTD(int* pArray);

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAiNumber[25] = {};

	// 숫자 설정해주기
	SetNumber(iNumber);
	SetNumber(iAiNumber);

	// 숫자 섞기
	Shuffle(iNumber);
	Shuffle(iAiNumber);

	// 나와 Ai의 빙고를 체크해 줌
	int iBingo = 0, iAiBingo = 0;

	// Ai 난이도를 선택한다.
	AI_MODE eAiMode = SelectAIMode();

	while (true)
	{
		system("cls");

		// 플레이어 빙고판
		cout << "============= PLAYER =============" << endl;
		OutputNumber(iNumber, iBingo);
		cout << "Bingo Line : " << iBingo << endl << endl;

		// Ai 빙고 판
		cout << "=============   AI   =============" << endl;

		switch (eAiMode)
		{
		case AM_EASY:
			cout << "AI Mode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AI Mode : Hard" << endl;
			break;
		}

		OutputNumber(iAiNumber, iAiBingo);

		// AI 빙고 줄 수를 출력.
		cout << "AiBingo Line : " << iAiBingo << endl;

		// 빙고 줄 수가 5줄 이상일 경우 게임을 종료한다.
		if (iBingo >= 5)
		{
			cout << "축하드립니다. 플레이어의 승리입니다." << endl;
			break;
		}

		else if (iAiBingo >= 5)
		{
			cout << "AI가 승리했습니다. 당신은 패배하셨습니다." << endl;
			break;
		}

		cout << "숫자를 입력하세요(0:종료) : ";
		int iInput;
		cin >> iInput;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		cout << "\a";

		if (iInput == 0) {
			system("cls");
			cout << "게임을 종료합니다." << endl;
			break;
		}

		else if (iInput < 1 || iInput > 25)
			continue;

		// 중복 입력을 체크하기 위한 변수이다.
		// 기본적으로 중복되었다라고 하기 위해 true로 잡아주었다.
		bool bAcc = ChangeNumber(iNumber, iInput);

		// bAcc 변수가 true일 경우 중복된 숫자를 입력해서 숫자를 *로
		// 바꾸지 못했으므로 다시 입력받게 continue해준다.
		if (bAcc)
			continue;

		// 중복이 아니라면 Ai의 숫자도 찾아서 *로 바꿔준다.
		ChangeNumber(iAiNumber, iInput);

		// AI가 숫자를 선택한다. AI모드에 맞춰서 선택되도록 함수가 구성되어 있다.
		iInput = SelectAINumber(iAiNumber, eAiMode);

		// Ai가 숫자를 선택했으므로 플레이어와 Ai의 숫자를 *로 바꿔준다.
		ChangeNumber(iNumber, iInput);
		ChangeNumber(iAiNumber, iInput);

		// 빙고 줄 수를 체크하는 것은 매번 숫자를 입력할 때 마다 처음부터
		// 새로 카운트를 할 것이다. 그러므로 iBingo 변수를 0부터 매번
		// 초기화를 하고 새롭게 줄 수를 구해주도록 한다.
		iBingo = BingoCounting(iNumber);
		iAiBingo = BingoCounting(iAiNumber);

	}

	return 0;
}

void SetNumber(int * pArray) {
	for (int i = 0; i < 25; ++i) {
		pArray[i] = i + 1;
	}
}

void Shuffle(int * pArray) {

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = pArray[idx1];
		pArray[idx1] = pArray[idx2];
		pArray[idx2] = iTemp;
	}

}

AI_MODE SelectAIMode() {
	int iAiMode;
	while (true)
	{
		system("cls");
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "Ai 모드를 선택하세요. : ";
		cin >> iAiMode;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iAiMode >= AM_EASY && iAiMode <= AM_HARD)
			break;
	}

	// int -> AI_MODE
	return (AI_MODE)iAiMode;
}

void OutputNumber(int * pArray, int iBingo) {
	//숫자를 5x5로 출력

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (pArray[i * 5 + j] == INT_MAX)
				cout << "*\t";

			else
				cout << pArray[i * 5 + j] << "\t";
		}
		cout << endl;
	}

	cout << endl;

}

bool ChangeNumber(int * pArray, int iInput) {
	// 모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 숫자가
	// 있는 지 찾아낸다.
	for (int i = 0; i < 25; i++)
	{
		if (iInput == pArray[i])
		{
			// 숫자를 *로 변경하기 위해 특수한 값인 INT_MAX로 해준다.
			pArray[i] = INT_MAX;

			// 더 이상 다른 숫자를 찾아볼 필요가 없으므로
			// false를 반환하고 for문을 빠져나간다.
			return false;
		}
	}

	// 여기까지 오게 되면 return false가 동작 안 된 것이므로 같은 숫자가
	// 없다는 것이다. 즉, 중복된 숫자를 입력했기 때문에 true를 리턴한다.
	return true;
}

int SelectAINumber(int * pArray, AI_MODE eMode) {

	// 선택 안 된 목록 배열을 만들어준다.
	int iNoneSelect[25] = {};
	// 선택 안 된 숫자의 갯수를 저장한다.
	int iNoneSelectCount = 0;

	//Ai가 선택을 한다. Ai가 선택하는 것은 Ai모드에 따라서 달라진다.
	switch (eMode)
	{
		/*
		AI Easy 모드는 현재 Ai의 숫자 목록 중 *로 바뀌지 않은 숫자 목록을 만들고
		그 목록 중 하나를 선택하게 된다.(랜덤하게)
		*/
	case AM_EASY:
		// 선택 안 된 숫자 목록을 만들어준다.
		// 선택 안 된 숫자 갯수는 목록을 만들 때 카운팅해준다.
		iNoneSelectCount = 0;
		for (int i = 0; i < 25; ++i)
		{
			// 현재 숫자가 *이 아닐 경우
			if (pArray[i] != INT_MAX)
			{
				// *이 아닌 숫자일 경우 iNoneSelectCount를 인덱스로 활용한다.
				// 선택 안 된 목록에 추가할 때 마다 개수를 1씩 증가시켜서
				// 총 선택 안 된 갯수를 구해준다.
				// 그런데 0부터 카운트가 시작이므로 0번에 넣고 ++해서
				// 1개 추가되었다고 해준다.
				iNoneSelect[iNoneSelectCount] = pArray[i];
				++iNoneSelectCount;
			}
		}

		// for문을 빠져나오게 되면 선택 안 된 목록이 만들어지고
		// 선택 안 된 목록의 갯수가 만들어지게 된다.
		// 선택 안 된 목록의 숫자 중 랜덤한 하나의 숫자를 얻어오기 위해
		// 인덱스를 랜덤하게 구해준다.
		return iNoneSelect[rand() % iNoneSelectCount];

	case AM_HARD:
		// 하드모드는 현재 숫자중 빙고줄 완성 가능성이 가장 높은 줄을 찾아서
		// 그 줄에 있는 숫자 중 하나를 *로 만들어준다.
		int iLine = 0;
		int iStarCount = 0;
		int iSaveCount = 0;

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (pArray[i * 5 + j] == INT_MAX)
					++iStarCount;
			}

			// 별이 5개보다 미만이아야 빙고 줄이 아닌 기존에 가장 많은 라인의 
			// 별보다 커야 가장 별이 많은 라인이므로 라인을 교체해주고
			// 저장된 별 수를 교체한다.
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				// 여기는 가로 라인 중 가장 별이 많은 라인을 체크하는 곳이다.
				// 가로 라인은 0~4로 의미를 부여했다.
				iLine = i; // i : 가로라인
				iSaveCount = iStarCount;
			}
		}

		// 가로 라인 중 가장 별이 많은 라인은 이미 구했다.
		// 이 값과 세로 라인들을 비교하여 별이 가장 많은 라인들을 구한다.
		for (int i = 0; i < 5; ++i)
		{
			iStarCount = 0;
			for (int j = 0; j < 5; ++j)
			{
				if (pArray[j * 5 + i] == INT_MAX)
					++iStarCount;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				// 세로라인은 5~9로 의미 부여
				iLine = i + 5;
				iSaveCount = iStarCount;
			}

		}

		//왼쪽 > 오른쪽 대각선 체크
		iStarCount = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}

		if (iStarCount < 5 && iSaveCount < iStarCount)
		{
			iLine = LN_LT;
			iSaveCount = iStarCount;
		}

		// 오른쪽 > 왼쪽 대각선 체크
		iStarCount = 0;
		for (int i = 0; i <= 20; i += 4)
		{
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}

		if (iStarCount < 5 && iSaveCount < iStarCount)
		{
			iLine = LN_RT;
			iSaveCount = iStarCount;
		}

		// 모든 라인을 조사했으면 iLine에 가능성이 가장 높은 줄 번호가
		// 저장되었다.
		// 그 줄에 있는 *이 아닌 숫자 중 하나를 선택하게 한다.
		// 가로줄일 경우
		if (iLine <= LN_H5)
		{
			// 가로줄일 경우 iLine이 0~4 사이의 값이다.
			for (int i = 0; i < 5; ++i)
			{
				//현재 줄에서 *이 아닌 숫자를 찾아낸다.
				if (pArray[iLine * 5 + i] != INT_MAX)
				{
					return pArray[iLine * 5 + i];
				}
			}
		}

		else if (iLine <= LN_V5)
		{
			// 세로줄일 경우 iLine이 5~9 사이 값이다.
			for (int i = 0; i < 5; ++i)
			{
				if (pArray[i * 5 + (iLine - 5)] != INT_MAX)
				{
					return pArray[i * 5 - (iLine - 5)];
				}
			}
		}

		else if (iLine == LN_LT)
		{
			for (int i = 0; i < 25; i += 6)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
				}
			}
		}

		else if (iLine == LN_RT)
		{
			for (int i = 4; i <= 20; i += 4)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
				}
			}
		}

		return (-1);
	}
}
int BingoCounting(int * pArray) {
	int iBingo = 0;

	// 가로줄 체크
	iBingo += BingoCountingH(pArray);
	// 세로줄 체크
	iBingo += BingoCountingV(pArray);
	// 왼쪽 상단 대각선 체크
	iBingo += BingoCountingLTD(pArray);
	// 오른쪽 상단 대각선 체크
	iBingo += BingoCountingRTD(pArray);

	return iBingo;
}
int BingoCountingH(int* pArray) {
	// 가로 줄 수를 구해준다.
	int iStar1 = 0, iBingo = 0;
	for (int i = 0; i < 5; ++i)
	{
		// 한 줄을 체크하기 전에 먼저 0으로 별 개수를 초기화한다.
		iStar1 = 0;
		for (int j = 0; j < 5; ++j)
		{
			// 가로 별 개수를 구해준다.
			if (pArray[i * 5 + j] == INT_MAX)
				++iStar1;
		}

		// j for문을 빠져나오고 나면 현재 줄의 가로 별 개수가 몇 개인지
		// iStar1 변수에 들어가게 된다. iStar1이 5이면 한줄이
		// 모두 *이라는 의미이므로 빙고 줄 카운트를 추가해준다.
		if (iStar1 == 5)
			++iBingo;
	}

	return iBingo;
}
int BingoCountingV(int* pArray) {
	// 가로 줄 수를 구해준다.
	int iStar1 = 0, iBingo = 0;
	for (int i = 0; i < 5; ++i)
	{
		// 한 줄을 체크하기 전에 먼저 0으로 별 개수를 초기화한다.
		iStar1 = 0;
		for (int j = 0; j < 5; ++j)
		{
			// 가로 별 개수를 구해준다.
			if (pArray[j * 5 + i] == INT_MAX)
				++iStar1;
		}

		// j for문을 빠져나오고 나면 현재 줄의 가로 별 개수가 몇 개인지
		// iStar1 변수에 들어가게 된다. iStar1이 5이면 한줄이
		// 모두 *이라는 의미이므로 빙고 줄 카운트를 추가해준다.
		if (iStar1 == 5)
			++iBingo;
	}
	return iBingo;
}
int BingoCountingLTD(int* pArray) {
	// 왼쪽 상단 > 오른쪽 하단 대각선 체크
	int iStar1 = 0, iBingo = 0;
	for (int i = 0; i < 25; i += 6)
	{
		if (pArray[i] == INT_MAX)
			++iStar1;
	}

	if (iStar1 == 5)
		++iBingo;

	return iBingo;
}
int BingoCountingRTD(int* pArray) {
	int iStar1 = 0, iBingo = 0;
	for (int i = 4; i <= 20; i += 4)
	{
		if (pArray[i] == INT_MAX)
			++iStar1;
	}

	if (iStar1 == 5)
		++iBingo;

	return iBingo;
}