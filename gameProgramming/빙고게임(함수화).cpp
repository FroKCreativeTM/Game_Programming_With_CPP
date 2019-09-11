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

// �Լ��� ����� ���� �κ����� ���� �� �ִ�.
// ����
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

	// ���� �������ֱ�
	SetNumber(iNumber);
	SetNumber(iAiNumber);

	// ���� ����
	Shuffle(iNumber);
	Shuffle(iAiNumber);

	// ���� Ai�� ���� üũ�� ��
	int iBingo = 0, iAiBingo = 0;

	// Ai ���̵��� �����Ѵ�.
	AI_MODE eAiMode = SelectAIMode();

	while (true)
	{
		system("cls");

		// �÷��̾� ������
		cout << "============= PLAYER =============" << endl;
		OutputNumber(iNumber, iBingo);
		cout << "Bingo Line : " << iBingo << endl << endl;

		// Ai ���� ��
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

		// AI ���� �� ���� ���.
		cout << "AiBingo Line : " << iAiBingo << endl;

		// ���� �� ���� 5�� �̻��� ��� ������ �����Ѵ�.
		if (iBingo >= 5)
		{
			cout << "���ϵ帳�ϴ�. �÷��̾��� �¸��Դϴ�." << endl;
			break;
		}

		else if (iAiBingo >= 5)
		{
			cout << "AI�� �¸��߽��ϴ�. ����� �й��ϼ̽��ϴ�." << endl;
			break;
		}

		cout << "���ڸ� �Է��ϼ���(0:����) : ";
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
			cout << "������ �����մϴ�." << endl;
			break;
		}

		else if (iInput < 1 || iInput > 25)
			continue;

		// �ߺ� �Է��� üũ�ϱ� ���� �����̴�.
		// �⺻������ �ߺ��Ǿ��ٶ�� �ϱ� ���� true�� ����־���.
		bool bAcc = ChangeNumber(iNumber, iInput);

		// bAcc ������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *��
		// �ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue���ش�.
		if (bAcc)
			continue;

		// �ߺ��� �ƴ϶�� Ai�� ���ڵ� ã�Ƽ� *�� �ٲ��ش�.
		ChangeNumber(iAiNumber, iInput);

		// AI�� ���ڸ� �����Ѵ�. AI��忡 ���缭 ���õǵ��� �Լ��� �����Ǿ� �ִ�.
		iInput = SelectAINumber(iAiNumber, eAiMode);

		// Ai�� ���ڸ� ���������Ƿ� �÷��̾�� Ai�� ���ڸ� *�� �ٲ��ش�.
		ChangeNumber(iNumber, iInput);
		ChangeNumber(iAiNumber, iInput);

		// ���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��� �� ���� ó������
		// ���� ī��Ʈ�� �� ���̴�. �׷��Ƿ� iBingo ������ 0���� �Ź�
		// �ʱ�ȭ�� �ϰ� ���Ӱ� �� ���� �����ֵ��� �Ѵ�.
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
		cout << "Ai ��带 �����ϼ���. : ";
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
	//���ڸ� 5x5�� ���

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
	// ��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ�
	// �ִ� �� ã�Ƴ���.
	for (int i = 0; i < 25; i++)
	{
		if (iInput == pArray[i])
		{
			// ���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
			pArray[i] = INT_MAX;

			// �� �̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ�
			// false�� ��ȯ�ϰ� for���� ����������.
			return false;
		}
	}

	// ������� ���� �Ǹ� return false�� ���� �� �� ���̹Ƿ� ���� ���ڰ�
	// ���ٴ� ���̴�. ��, �ߺ��� ���ڸ� �Է��߱� ������ true�� �����Ѵ�.
	return true;
}

int SelectAINumber(int * pArray, AI_MODE eMode) {

	// ���� �� �� ��� �迭�� ������ش�.
	int iNoneSelect[25] = {};
	// ���� �� �� ������ ������ �����Ѵ�.
	int iNoneSelectCount = 0;

	//Ai�� ������ �Ѵ�. Ai�� �����ϴ� ���� Ai��忡 ���� �޶�����.
	switch (eMode)
	{
		/*
		AI Easy ���� ���� Ai�� ���� ��� �� *�� �ٲ��� ���� ���� ����� �����
		�� ��� �� �ϳ��� �����ϰ� �ȴ�.(�����ϰ�)
		*/
	case AM_EASY:
		// ���� �� �� ���� ����� ������ش�.
		// ���� �� �� ���� ������ ����� ���� �� ī�������ش�.
		iNoneSelectCount = 0;
		for (int i = 0; i < 25; ++i)
		{
			// ���� ���ڰ� *�� �ƴ� ���
			if (pArray[i] != INT_MAX)
			{
				// *�� �ƴ� ������ ��� iNoneSelectCount�� �ε����� Ȱ���Ѵ�.
				// ���� �� �� ��Ͽ� �߰��� �� ���� ������ 1�� �������Ѽ�
				// �� ���� �� �� ������ �����ش�.
				// �׷��� 0���� ī��Ʈ�� �����̹Ƿ� 0���� �ְ� ++�ؼ�
				// 1�� �߰��Ǿ��ٰ� ���ش�.
				iNoneSelect[iNoneSelectCount] = pArray[i];
				++iNoneSelectCount;
			}
		}

		// for���� ���������� �Ǹ� ���� �� �� ����� ���������
		// ���� �� �� ����� ������ ��������� �ȴ�.
		// ���� �� �� ����� ���� �� ������ �ϳ��� ���ڸ� ������ ����
		// �ε����� �����ϰ� �����ش�.
		return iNoneSelect[rand() % iNoneSelectCount];

	case AM_HARD:
		// �ϵ���� ���� ������ ������ �ϼ� ���ɼ��� ���� ���� ���� ã�Ƽ�
		// �� �ٿ� �ִ� ���� �� �ϳ��� *�� ������ش�.
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

			// ���� 5������ �̸��̾ƾ� ���� ���� �ƴ� ������ ���� ���� ������ 
			// ������ Ŀ�� ���� ���� ���� �����̹Ƿ� ������ ��ü���ְ�
			// ����� �� ���� ��ü�Ѵ�.
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				// ����� ���� ���� �� ���� ���� ���� ������ üũ�ϴ� ���̴�.
				// ���� ������ 0~4�� �ǹ̸� �ο��ߴ�.
				iLine = i; // i : ���ζ���
				iSaveCount = iStarCount;
			}
		}

		// ���� ���� �� ���� ���� ���� ������ �̹� ���ߴ�.
		// �� ���� ���� ���ε��� ���Ͽ� ���� ���� ���� ���ε��� ���Ѵ�.
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
				// ���ζ����� 5~9�� �ǹ� �ο�
				iLine = i + 5;
				iSaveCount = iStarCount;
			}

		}

		//���� > ������ �밢�� üũ
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

		// ������ > ���� �밢�� üũ
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

		// ��� ������ ���������� iLine�� ���ɼ��� ���� ���� �� ��ȣ��
		// ����Ǿ���.
		// �� �ٿ� �ִ� *�� �ƴ� ���� �� �ϳ��� �����ϰ� �Ѵ�.
		// �������� ���
		if (iLine <= LN_H5)
		{
			// �������� ��� iLine�� 0~4 ������ ���̴�.
			for (int i = 0; i < 5; ++i)
			{
				//���� �ٿ��� *�� �ƴ� ���ڸ� ã�Ƴ���.
				if (pArray[iLine * 5 + i] != INT_MAX)
				{
					return pArray[iLine * 5 + i];
				}
			}
		}

		else if (iLine <= LN_V5)
		{
			// �������� ��� iLine�� 5~9 ���� ���̴�.
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

	// ������ üũ
	iBingo += BingoCountingH(pArray);
	// ������ üũ
	iBingo += BingoCountingV(pArray);
	// ���� ��� �밢�� üũ
	iBingo += BingoCountingLTD(pArray);
	// ������ ��� �밢�� üũ
	iBingo += BingoCountingRTD(pArray);

	return iBingo;
}
int BingoCountingH(int* pArray) {
	// ���� �� ���� �����ش�.
	int iStar1 = 0, iBingo = 0;
	for (int i = 0; i < 5; ++i)
	{
		// �� ���� üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
		iStar1 = 0;
		for (int j = 0; j < 5; ++j)
		{
			// ���� �� ������ �����ش�.
			if (pArray[i * 5 + j] == INT_MAX)
				++iStar1;
		}

		// j for���� ���������� ���� ���� ���� ���� �� ������ �� ������
		// iStar1 ������ ���� �ȴ�. iStar1�� 5�̸� ������
		// ��� *�̶�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
		if (iStar1 == 5)
			++iBingo;
	}

	return iBingo;
}
int BingoCountingV(int* pArray) {
	// ���� �� ���� �����ش�.
	int iStar1 = 0, iBingo = 0;
	for (int i = 0; i < 5; ++i)
	{
		// �� ���� üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
		iStar1 = 0;
		for (int j = 0; j < 5; ++j)
		{
			// ���� �� ������ �����ش�.
			if (pArray[j * 5 + i] == INT_MAX)
				++iStar1;
		}

		// j for���� ���������� ���� ���� ���� ���� �� ������ �� ������
		// iStar1 ������ ���� �ȴ�. iStar1�� 5�̸� ������
		// ��� *�̶�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
		if (iStar1 == 5)
			++iBingo;
	}
	return iBingo;
}
int BingoCountingLTD(int* pArray) {
	// ���� ��� > ������ �ϴ� �밢�� üũ
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