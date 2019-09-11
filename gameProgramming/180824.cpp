#include <iostream>

using namespace std;

/*
함수 : 기능을 만들어준다. 일종의 사용할 수 있는 부품을 만들어 주는 것.
특정 상황에 동작하는 코드의 집합을 만들어주는 것이다.
형태 : 반환타입 함수명(인자(parameter)) {}
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
함수의 오버로딩 : 같은 이름의 함수지만 기능이 다르던가 인자가 다른 함수를 말한다.
오버로딩의 조건 : 함수의 이름이 무조건 같아야 한다. 단 인자의 갯수, 타입이 달라야
오버로딩이 성립이 된다. 반환타입은 오버로딩에 영향을 주지 않는다.
*/

// call by value
void ChangeNumber(int iNumber) {
	iNumber = 9999;
}

// Call by Address
void ChangeNumber(int * iNumber) {
	*iNumber = 9999;
}

// 함수의 default 인자 : 인자는 기본적으로 값을 넘겨받게 설계되어있다.
// 그런데 인자에 기본값을 대입해두면 인자를 넘겨주지 않을 경우 기본 설정한
// 값이 되고 인자를 넘겨줄 경우 넘겨받은 값으로 인자를 설정하는 기능이다.

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