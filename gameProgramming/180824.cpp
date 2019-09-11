#include <iostream>

using namespace std;

/*
�Լ� : ����� ������ش�. ������ ����� �� �ִ� ��ǰ�� ����� �ִ� ��.
Ư�� ��Ȳ�� �����ϴ� �ڵ��� ������ ������ִ� ���̴�.
���� : ��ȯŸ�� �Լ���(����(parameter)) {}
*/

int Sum(int a, int b) {
	return a + b;
}

void OutputText() {
	cout << "OutputText Function!" << endl;
}

void OutputNumber(int iNumber) {
	cout << "Number : " << iNumber << endl;
}

/*
�Լ��� �����ε� : ���� �̸��� �Լ����� ����� �ٸ����� ���ڰ� �ٸ� �Լ��� ���Ѵ�.
�����ε��� ���� : �Լ��� �̸��� ������ ���ƾ� �Ѵ�. �� ������ ����, Ÿ���� �޶��
�����ε��� ������ �ȴ�. ��ȯŸ���� �����ε��� ������ ���� �ʴ´�.
*/

// call by value
void ChangeNumber(int iNumber) {
	iNumber = 9999;
}

// Call by Address
void ChangeNumber(int * iNumber) {
	*iNumber = 9999;
}

// �Լ��� default ���� : ���ڴ� �⺻������ ���� �Ѱܹް� ����Ǿ��ִ�.
// �׷��� ���ڿ� �⺻���� �����صθ� ���ڸ� �Ѱ����� ���� ��� �⺻ ������
// ���� �ǰ� ���ڸ� �Ѱ��� ��� �Ѱܹ��� ������ ���ڸ� �����ϴ� ����̴�.

void Output(int iNum1, int iNum2 = 10) {
	cout << iNum1 << endl;
	cout << iNum2 << endl;
}

int main()
{
	cout << Sum(10, 20) << endl;
	cout << Sum(102, 304) << endl;

	OutputText();
	OutputNumber(1234);

	int iNumber = 0;
	ChangeNumber(iNumber);
	cout << iNumber << endl;
	ChangeNumber(&iNumber);
	cout << iNumber << endl;

	Output(10);
	Output(10, 15);

	return 0;
}