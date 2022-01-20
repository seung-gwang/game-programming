//디버그 기능
//f5 중단점까지 실행
//f10 프로시져 단위(함수 단위)실행 세부적으로 함수 안 까지 들어가는건 아님
//f11 프로시져 안으로 들어가서 한줄 한줄 실행

//어셈블리코드, 레지스터, 메모리 확인하여 stack의 변화 파악하기

#include <iostream>
using namespace std;


//두 숫자를 받고 그 곱을 반환
int MultiplyBy(int a, int b) {
	int retVal = a * b;
	return retVal;

}


int main() //진입점
{	
	int a = 3;
	int b = 5;
 	int result = MultiplyBy(a, b);
	//return 0; //main 함수에서는 기본적으로 return이 됨.
}


