#include <iostream>
using namespace std;

//호출 스택
// 
//선언을 일단 먼저 해줌, 뭘 하는지는 몰라도 call시 어디로 jump할지는 알수 있게 함.
void Func1(); 
void Func2(int a, int b); //a,b는 생략해도 됨.
void Func3(float a);


void Func3(float a) {
	cout << "Func3" << endl;
}


void Func2(int a, int b) {
	cout << "Func2" << endl;

	Func3(10);
}


void Func1() {
	cout << "Func1" << endl;

	Func2(1, 2); //Func2가 위에 없다면 compile error
	/*
	어셈블리에서...
	push2
	push1
	call Func2 ... 할것인데 Func2의 위치를 모르면 안됨==> '선언'을 앞에서 해주면 됨.
	*/
}


int main() {
	cout << "main" << endl;
	Func1();

	return 0;
}

//'호출스택' 창에서 코드 및 함수 호출 경로를 볼 수 있음. 
//나는 누구... 여기는 어디...? ==> 호출 스택을 보고 파악
//호출 스택 보기 + f10/f11 디버깅을 잘 할 수 있게 연습해야함!