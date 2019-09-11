#include <iostream>

using namespace std;

enum NUM
{
	NUM_0 = 10, // 아무 것도 부여하지 않을 경우 0부터 1칙 차례로 값이 부여된다.
	NUM_1,	// 0에 10을 선언할 시 아래엔 11 12 13 이런식으로 차례대로 
	NUM_2 = 0x0010, // 이런 식으로 중간에 숫자 바꾸기 가능
	NUM_3
};
// API에서 이런 열거체로 플레그를 만들어놓고 의미를 부여해서 쓴다.

/*
열거체 : 연속된 숫자의 이름을 부여할 수 있는 기능히다.
enum 열거체명 {} 의 형태로 구성
열거체명을 이용해서 열거체 타입의 변수를 선언도 가능하다.
즉 열거체 자체가 사용자 정의 변수 타입이 될 수도 있다.
열거체는 숫자에 이름을 붙혀주는 것이다.
*/

#define  NUM_4	4
// 똑같은 상수이다.
/*
	앞에 #이기 때문에 전처리기
	이것은 컴퓨터가 알아들을 수 있게 번역하는 과정 중 하나.
*/

int main()
{
	int iNumber;
	cout << "숫자를 입력하세요 : ";
	cin >> iNumber;

	switch (iNumber)
	{
	case NUM_0:
		cout << "입력한 숫자는 10입니다." << endl;
		break;
	case NUM_1:
		cout << "입력하신 숫자는 11입니다." << endl;
		break;
		// 여기서 break가 없다면 바로 아래있는 case구문도 강제로
		// 실행하게 된다.
	case NUM_2:
		cout << "입력하신 숫자는 16입니다." << endl;
		break;
	case NUM_3:
		cout << "입력하신 숫자는 17입니다." << endl;
		break;
	case NUM_4:
		cout << "입력하신 숫자는 4입니다." << endl;
		break;
	default:
		cout << "어쩌라구요" << endl;
	}

	// 열거체 타입의 변수를 선언했다.
	// 열거체 타입 변수는 무조건 4byte를 차지하게 된다.
	// 열거체를 이용해서 선언한 변수는 값의 표현 범위가
	// 열거체에 나열된 값들 안에서 선택해서 사용한다.
	NUM eNum = (NUM)10;
	// NUM eNum=10; 이런 식으로 쓰면 에러를 뱉는 데 이 오류는 타입이 맞지 않아서 그럼
	// NUM eNum = (NUM)10; 이런 식으로 타입 캐스팅을 하면 가능은 하다.

	// 어떤 타입이나 변수의 메모리 크리를 구해줌
	cout << sizeof(NUM) << endl;
	// typeid(타입이나 변수).name() 를 하게 되면 typeid 안에 들어간 타입 혹은 변수의 타입을
	// 문자열로 반환해준디ㅏ.
	cout << typeid(NUM).name() << endl;
	cout << eNum << endl;


	return 0;
}

/*
switch 문 : 분기문의 한 종류이다. if 문이 조건을 체크하는 분기라면
switch문은 값이 뭔지를 체크하는 분기문이다.

형태
switch(변수) {}
코드블럭 {} 안에는 case break 구문이 들어가게 된다.
case 상수의 형태로 처리가 되고 변수값이 무엇인지에 따라서
case 뒤에 오는 상수를 비교하게 된다.
*/

