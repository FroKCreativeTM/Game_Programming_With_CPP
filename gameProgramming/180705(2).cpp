#include <iostream>

using namespace std;

int main()
{
	/*
		조건분기문 (if) 
		간단한 예로 공격 반경 안에 들어오면 공격한다던지 등
		
		분기문에는 크게 if, switch문이 존재한다.
		if문 : 조건을 체크해주는 기능이다.
		형태 : if (조건식) {}(코드블럭)
		if문은 조건식이 true가 될 경우 코드 블럭 안의 코드가 동작.
		false일 경우엔 동작되진 않는다.
	*/

	const int iAttack = 0x00000001; // 1 (2진수)
	const int iArmor = 0x00000002; // 10
	const int iHP = 0x00000004; // 100
	const int iMP = 0x00000008; // 1000
	const int iCritical = 0x00000010; // 10000

	int iBuf = iAttack | iHP | iCritical;

	if (true)
	{
		cout << "이 문장은 True일 때 출력됩니다." << endl;
	}
	
	// 버프가 있는 지 확인
	if ((iBuf & iAttack) != 0)
	{
		cout << "Attack 버프가 있습니다." << endl;
	}

	// if문 아래에 들어갈 코드가 1줄일 경우 코드블럭을 생략할 수 있다.
	if ((iBuf & iArmor) != 0)
		cout << "Armor 버프가 있습니다." << endl;

	if ((iBuf & iHP) != 0)
		cout << "HP 버프가 있습니다." << endl;

	if ((iBuf & iMP) != 0)
		cout << "MP 버프가 있습니다." << endl;
	
	if ((iBuf & iCritical) != 0)
		cout << "Critical 버프가 있습니다." << endl;

	/*
		if 문과 같이 사용할 수 있는 else if, else문이 있다.
		if문 조건이 아닐 수 false일 경우 else가 있다면 else 구문 안의 코드가 동작
		else if는 자신의 위에 있는 조건식이 false일 경우 다음 else if의 조건식을
		체크한다.
	*/

	if (false)
		cout << "if문 조건이 true입니다." << endl;
	else
		cout << "if문 조건이 false입니다." << endl;

	int iNumber;

	cout << "숫자를 입력하세요 : ";
	cin >> iNumber;

	if (10 <= iNumber && iNumber <= 20)
		cout << "입력된 숫자가 10과 20 사이의 숫자입니다." << endl;
	else if (20 <= iNumber && iNumber <= 30)
		cout << "입력된 숫자가 20과 30 사이의 숫자입니다." << endl;
	else if (30 <= iNumber && iNumber <= 40)
		cout << "입력된 숫자가 30과 40 사이의 숫자입니다." << endl;
	else
		cout << "그 외의 숫자입니다." << endl;

	return 0;
}