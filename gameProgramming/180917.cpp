#include <iostream>

using namespace std;

/*
동적배열 할당 방법 : new 탑입[개수]; 의 형태로 사용
*/

int main(){

	int * pNum = new int;
	*pNum = 100;

	int * pArray = new int[100];

	pArray[1] = 300;

	delete[] pArray;
	delete pNum;

}