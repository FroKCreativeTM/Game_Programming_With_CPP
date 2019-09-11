#include <iostream>

using namespace std;

int main()
{
	// 상수 : 변하지 않는 수. 값을 한 번 지정해놓으면 바꿀 수 없다.
	// 상수는 선언과 동시에 초기화를 해둬야 함.
	// 예로 들어 버프 시스템을 만든다.
	// 버프 종류 많음.
	// 예를 들어 공격 버프를 16진수로 선언하자.
	const int iAttack = 0x00000001; // 1 (2진수)
	const int iArmor = 0x00000002; // 10
	const int iHP = 0x00000004; // 100
	const int iMP = 0x00000008; // 1000
	const int iCritical = 0x00000010; // 10000
	// 이런 식으로 비트 단위로 32개까지 지정 가능

	// 버프는 몇 초 지나면 사라지게 됨
	// 버프는 변수로 줘야 함.

	// 1 | 100 = 101 | 10000 = 10101
	// 어떤 값이던 0만 아니면 참
	// 어? 이거 어택, HP, 크리티컬만 버프를 주네?
	int iBuf = iAttack | iHP | iCritical;

	// 연산자 축약형
	// 아래를 풀어서 쓰면 iBuf = iBuf ^ iHP;
	// 10101 ^ 00100 = 10001 (다를때만 참)
	// HP만 사라짐
	iBuf ^= iHP;

	// 10001 ^ 00100 = 10101
	// 다시 HP버프가 켜짐
	// 마치 스위치같은 기능을 만들어 낼 수 있음.
	iBuf ^= iHP;

	// 10101 & 00001 = 00001 (1)
	cout << "Attack : " << (iBuf & iAttack) << endl;
	// 10101 & 00010 = 0
	cout << "Armor : " << (iBuf & iArmor) << endl;
	// 10101 & 00100 = 00100 (4)
	cout << "HP : " << (iBuf & iHP) << endl;
	// 10101 & 01000 = 0
	cout << "MP : " << (iBuf & iMP) << endl;
	// 10101 & 10000 = 10000 (16)
	cout << "Critical : " << (iBuf & iCritical) << endl;

	/*
		쉬프트 연산자 : << >> 값 대 값을 연산하여 값으로 나오게 된다.
		이 연산자 또한 이진수 단위의 연산을 하게 된다.
		20 << 2 = ?
		20을 2진수로 변환한다.
		10100
		이런 경우 간단히 뒤에 00 붙힌다.
		1010000 = 80
		20 << 2 = 80

		20 >> 2 = ?
		10100
		101 = 5
		20 >> 2 = 5
		20 >> 3 = 2 // int형이기 때문에
		// 여기서 알고리즘 적인 측면으로 보자면 나눗셈 /은 굉장히 무거운 연산이다.
		// 고로 비트 연산자를 이용하면 빠른 연산이 가능하다.
		// 최적화 문제

	*/

	int iHigh = 187;
	int iLow = 13560;

	int iNumber = iHigh;

	// iNumber에는 187 들어가 있다. 이 값을 <- 이 방향으로 16비트 이동시키면
	// 상위 16비트의 값이 들어가게 된다.
	iNumber <<= 16;

	// 하위 16비트를 채운다.
	iNumber |= iLow;

	// High값을 출력한다.
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;

	// 증감 연산자. : ++, -- 가 있다. 1증가, 1감소이다.
	iNumber = 10;

	// 전치
	++iNumber;

	// 후치
	iNumber++;

	cout << ++iNumber << endl; // 일단 1증가 후 다른 것을 처리
	cout << iNumber++ << endl; // 출력 먼저 하고 다음에 증가.
	cout << iNumber << endl;

	// 이것 때문에 문제가 생길 소지가 많음.
	// 멀티 쓰레드를 활용한 환경에서 그런 편.
	
	return 0;
}