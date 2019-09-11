/*
1���� 25������ ���ڰ� �ְ� �� ���ڸ� ���� ��� 5 x 5�� ����Ѵ�.
�÷��̾�� ���ڸ� �Է� �޴´�. 1~25 ������ ���ڸ� �Է¹޾ƾ��Ѵ�.
0�� �Է��ϸ� ������ �����Ѵ�.

���ڸ� �Է¹޾����� ���� ��� �� �Է¹��� ���ڸ� ã�Ƽ� *�� ������ش�.
���ڸ� *�� ���� �Ŀ� ���� �� ���� üũ�Ѵ�. 5 x 5�̱� ������ ���� 5�� ���� 5��
�밢�� 2���� ���� �� �ִ�. ���� ���� �� ������üũ�ؼ� ȭ���� �����ش�.
5�� �̻��� ��� ������ �����Ѵ�.
��Ʈ : �迭, for��
*/

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

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAiNumber[25] = {};

	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
		iAiNumber[i] = i + 1;
	}
	
	// ����
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		// �÷��̾�
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		// AI
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAiNumber[idx1];
		iAiNumber[idx1] = iAiNumber[idx2];
		iAiNumber[idx2] = iTemp;
	}

	// ���� Ai�� ���� üũ�� ��
	int iBingo = 0, iAiBingo = 0;
	int iAiMode;

	// Ai ���̵��� �����Ѵ�.
	// ���̵� �ػ��̴�.
	while (true)
	{
		system("cls");
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "Ai ��带 �����ϼ���. : ";
		cin >> iAiMode;

		if (iAiMode >= AM_EASY && iAiMode <= AM_HARD)
			break;
	}

	// ���� �� �� ��� �迭�� ������ش�.
	int iNoneSelect[25] = {};
	// ���� �� �� ������ ������ �����Ѵ�.
	int iNoneSelectCount = 0;

	while (true)
	{
		system("cls");

		//���ڸ� 5x5�� ���
		cout << "============= PLAYER =============" << endl;

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		cout << endl;

		cout << "Bingo Line : " << iBingo << endl << endl;

		// Ai�� ���� ���� �������.
		cout << "=============   AI   =============" << endl;

		switch (iAiMode)
		{
		case AM_EASY:
			cout << "AI Mode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AI Mode : Hard" << endl;
			break;
		}

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iAiNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iAiNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

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

		if (iInput == 0) {
			system("cls");
			cout << "������ �����մϴ�." << endl;
			break;
		}

		else if (iInput < 1 || iInput > 25)
			continue;

		// �ߺ� �Է��� üũ�ϱ� ���� �����̴�.
		// �⺻������ �ߺ��Ǿ��ٶ�� �ϱ� ���� true�� ����־���.
		bool bAcc = true;

		// ��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ�
		// �ִ� �� ã�Ƴ���.
		for (int i = 0; i < 25; i++)
		{
			if (iInput == iNumber[i])
			{
				// ���ڸ� ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ�
				// bAcc������ false�� �ٲ��ش�.
				bAcc = false;

				// ���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
				iNumber[i] = INT_MAX;

				// �� �̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ�
				// for���� ����������.
				break;
			}
		}

		// bAcc ������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *��
		// �ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue���ش�.
		if (bAcc)
			continue;

		// �ߺ��� �ƴ϶�� Ai�� ���ڵ� ã�Ƽ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; ++i)
		{
			if (iAiNumber[i] == iInput)
			{
				iAiNumber[i] = INT_MAX;
				break;
			}
		}

		//Ai�� ������ �Ѵ�. Ai�� �����ϴ� ���� Ai��忡 ���� �޶�����.
		switch (iAiMode)
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
				if (iAiNumber[i] != INT_MAX)
				{
					// *�� �ƴ� ������ ��� iNoneSelectCount�� �ε����� Ȱ���Ѵ�.
					// ���� �� �� ��Ͽ� �߰��� �� ���� ������ 1�� �������Ѽ�
					// �� ���� �� �� ������ �����ش�.
					// �׷��� 0���� ī��Ʈ�� �����̹Ƿ� 0���� �ְ� ++�ؼ�
					// 1�� �߰��Ǿ��ٰ� ���ش�.
					iNoneSelect[iNoneSelectCount] = iAiNumber[i];
					++iNoneSelectCount;
				}
			}

			// for���� ���������� �Ǹ� ���� �� �� ����� ���������
			// ���� �� �� ����� ������ ��������� �ȴ�.
			// ���� �� �� ����� ���� �� ������ �ϳ��� ���ڸ� ������ ����
			// �ε����� �����ϰ� �����ش�.
			iInput = iNoneSelect[rand() % iNoneSelectCount];
			break;

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
					if (iAiNumber[i * 5 + j] == INT_MAX)
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
					if (iAiNumber[j * 5 + i] == INT_MAX)
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
				if (iAiNumber[i] == INT_MAX)
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
				if (iAiNumber[i] == INT_MAX)
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
					if (iAiNumber[iLine * 5 + i] != INT_MAX)
					{
						iInput = iAiNumber[iLine * 5 + i];
						break;
					}
				}
			}

			else if (iLine <= LN_V5)
			{
				// �������� ��� iLine�� 5~9 ���� ���̴�.
				for (int i = 0; i < 5; ++i)
				{
					if (iAiNumber[i * 5 + (iLine - 5)] != INT_MAX)
					{
						iInput = iAiNumber[i * 5 - (iLine - 5)];
						break;
					}
				}
			}

			else if (iLine == LN_LT)
			{
				for (int i = 0; i < 25; i += 6)
				{
					if (iAiNumber[i] != INT_MAX)
					{
						iInput = iAiNumber[i];
						break;
					}
				}
			}

			else if (iLine == LN_RT)
			{
				for (int i = 4; i <= 20; i += 4)
				{
					if (iAiNumber[i] != INT_MAX)
					{
						iInput = iAiNumber[i];
						break;
					}
				}
			}

			break;
		}

		// Ai�� ���ڸ� ���������Ƿ� �÷��̾�� Ai�� ���ڸ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; ++i)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}
		}

		// Ai ���ڸ� �ٲ��ش�.
		for (int i = 0; i < 25; ++i)
		{
			if (iAiNumber[i] == iInput)
			{
				iAiNumber[i] = INT_MAX;
				break;
			}
		}

		// ���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��� �� ���� ó������
		// ���� ī��Ʈ�� �� ���̴�. �׷��Ƿ� iBingo ������ 0���� �Ź�
		// �ʱ�ȭ�� �ϰ� ���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = 0;
		iAiBingo = 0;

		// ����, ���� �� ���� �����ش�.
		int iStar1 = 0, iStar2 = 0;
		int iAiStar1 = 0, iAiStar2 = 0;
		for (int i = 0; i < 5; ++i)
		{
			// �� ���� üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
			iStar1 = iStar2 = 0;
			iAiStar1 = iAiStar2 = 0;
			for (int j = 0; j < 5; ++j)
			{
				// ���� �� ������ �����ش�.
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;

				// ���� �� ������ �����ش�.
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;

				// Ai ���� �� ������ �����ش�.
				if (iAiNumber[i * 5 + j] == INT_MAX)
					++iAiStar1;

				// Ai ���� �� ������ �����ش�.
				if (iAiNumber[j * 5 + i] == INT_MAX)
					++iAiStar2;
			}

			// j for���� ���������� ���� ���� ���� ���� �� ������ �� ������
			// iStar1 ������ ���� �ȴ�. iStar1�� 5�̸� ������
			// ��� *�̶�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
			if (iStar1 == 5)
				++iBingo;

			if (iStar2 == 5)
				++iBingo;

			if (iAiStar1 == 5)
				++iAiBingo;

			if (iAiStar2 == 5)
				++iAiBingo;
		}
		
		// ���� ��� > ������ �ϴ� �밢�� üũ
		iStar1 = 0;
		iAiStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iAiNumber[i] == INT_MAX)
				++iAiStar1;
		}

		if (iStar1 == 5)
			++iBingo;

		if (iAiStar1 == 5)
			++iAiBingo;

		iStar1 = 0;
		iAiStar1 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iAiNumber[i] == INT_MAX)
				++iAiStar1;
		}

		if (iStar1 == 5)
			++iBingo;

		if (iAiStar1 == 5)
			++iAiBingo;
	}

	return 0;
}