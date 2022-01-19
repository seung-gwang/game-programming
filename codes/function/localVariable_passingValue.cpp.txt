//주제: 지역 변수와  값 전달
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

void increaseHp(int hp) {
	hp = hp + 1;
}

int main(){ //진입점
	
	cout << "전역 변수의 값 : " << globalVal << endl;
	globalVal++;
	Test();
	
	//지역 변수 - 함수 내부에서 만들어지고 해당 함수의 stack에 들어감
	int localVal = 1;
	
	//[매개변수][복귀주소][지역변수] --> 매개변수, 복귀주소는 이전 함수에서 건네줌
	int hp = 1;
	cout << "increase 호출 전: " << hp << endl;
	increaseHp(hp);
	cout << "increase 호출 후: " << hp << endl; //위와 동일한 hp값이 출력됨... why?
	/*
					[지역변수]
					[복귀주소]
					[매개변수]
				==>
	[지역변수]		[지역변수]
	[복귀주소]		[복귀주소]
	[매개변수]		[매개변수]

	-increaseHp를 main이 호출하면 매개변수와 복귀주소를 stack에 push한다.
	-increaseHp는 건네받은 매개변수를 증가시킨다(hp++). 그런데 이 hp는 main의 hp와는 다르다.
	-increaseHp의 스택 프레임 내의 매개변수 값을 아무리 바꾼다 해도 main의 지역변수는 그대로다.
	-따라서 두번의 cout에서 동일한 hp가 출력된다.
	-위의 stack 그림을 이해하자.
	*/

	return 0;
}


