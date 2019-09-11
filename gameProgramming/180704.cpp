/*#include : 헤더 파일을 포함시키는 기능이다.*/
#include <iostream>

using namespace std;
// std라는 namespace를 사용하겠다.

// 실행 과정 : 컴파일 > 빌드 > 실행
// 컴파일 : 번역작업이다. 
// Ctrl + Shift + B를 이용해서 컴파일

int main()
{
	// C++ 표준 기능의 대부분은 std라는 namespace 안에 존재
	// 이름이 겹치는 것을 방지해주기 위해서.
	// cout : 콘솔창에 출력해주는 기능. "" 안에 있는 문자열을
	// 화면에 출력.

	//std::cout << "Hello world!" << std::endl;
	// 위 방법은 매번 std::를 붙여줘야 해서 불편

	cout << "using namespace를 이용한, Hello World!" << endl;


	return 0;
}