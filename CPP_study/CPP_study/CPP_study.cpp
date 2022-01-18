#include <iostream>
using namespace std;

//전역 변수 : 코드가 길어지면 관리하기 어려우니 가급적 사용X
int globalVal = 0;//데이터 영역에 들어감
//참고) 초기화 여부,const 등에 따라 
//rodata, data, bss로 세분화 할 수 있음.

void Test() {
	cout << "전역 변수의 값 : " << globalVal << endl;
	globalVal++;
	//localVal++; //main의 지역변수는 사용할 수 없다.
}

int main() //진입점
{	
	cout << "전역 변수의 값 : " << globalVal << endl;
	globalVal++;
	Test();
	
	//지역 변수 - 함수 내부에서 만들어짐.
	int localVal = 1;
	
	return 0;
}


