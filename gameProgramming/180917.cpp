#include <iostream>

using namespace std;

/*
�����迭 �Ҵ� ��� : new ž��[����]; �� ���·� ���
*/

int main(){

	int * pNum = new int;
	*pNum = 100;

	int * pArray = new int[100];

	pArray[1] = 300;

	delete[] pArray;
	delete pNum;

}