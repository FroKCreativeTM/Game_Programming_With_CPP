#include <iostream>

using namespace std;

int main()
{
	/*
		���Ǻб⹮ (if) 
		������ ���� ���� �ݰ� �ȿ� ������ �����Ѵٴ��� ��
		
		�б⹮���� ũ�� if, switch���� �����Ѵ�.
		if�� : ������ üũ���ִ� ����̴�.
		���� : if (���ǽ�) {}(�ڵ��)
		if���� ���ǽ��� true�� �� ��� �ڵ� �� ���� �ڵ尡 ����.
		false�� ��쿣 ���۵��� �ʴ´�.
	*/

	const int iAttack = 0x00000001; // 1 (2����)
	const int iArmor = 0x00000002; // 10
	const int iHP = 0x00000004; // 100
	const int iMP = 0x00000008; // 1000
	const int iCritical = 0x00000010; // 10000

	int iBuf = iAttack | iHP | iCritical;

	if (true)
	{
		cout << "�� ������ True�� �� ��µ˴ϴ�." << endl;
	}
	
	// ������ �ִ� �� Ȯ��
	if ((iBuf & iAttack) != 0)
	{
		cout << "Attack ������ �ֽ��ϴ�." << endl;
	}

	// if�� �Ʒ��� �� �ڵ尡 1���� ��� �ڵ���� ������ �� �ִ�.
	if ((iBuf & iArmor) != 0)
		cout << "Armor ������ �ֽ��ϴ�." << endl;

	if ((iBuf & iHP) != 0)
		cout << "HP ������ �ֽ��ϴ�." << endl;

	if ((iBuf & iMP) != 0)
		cout << "MP ������ �ֽ��ϴ�." << endl;
	
	if ((iBuf & iCritical) != 0)
		cout << "Critical ������ �ֽ��ϴ�." << endl;

	/*
		if ���� ���� ����� �� �ִ� else if, else���� �ִ�.
		if�� ������ �ƴ� �� false�� ��� else�� �ִٸ� else ���� ���� �ڵ尡 ����
		else if�� �ڽ��� ���� �ִ� ���ǽ��� false�� ��� ���� else if�� ���ǽ���
		üũ�Ѵ�.
	*/

	if (false)
		cout << "if�� ������ true�Դϴ�." << endl;
	else
		cout << "if�� ������ false�Դϴ�." << endl;

	int iNumber;

	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> iNumber;

	if (10 <= iNumber && iNumber <= 20)
		cout << "�Էµ� ���ڰ� 10�� 20 ������ �����Դϴ�." << endl;
	else if (20 <= iNumber && iNumber <= 30)
		cout << "�Էµ� ���ڰ� 20�� 30 ������ �����Դϴ�." << endl;
	else if (30 <= iNumber && iNumber <= 40)
		cout << "�Էµ� ���ڰ� 30�� 40 ������ �����Դϴ�." << endl;
	else
		cout << "�� ���� �����Դϴ�." << endl;

	return 0;
}