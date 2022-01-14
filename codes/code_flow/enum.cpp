#include <iostream>
using namespace std;

#define DEFINE_SCISSORS 1 //#이 붙은 경우는 전처리 지시문
#define DEFINE_TEST cout << "this is define test" << endl;
//1)전처리 2)컴파일 3)링크
//1)전처리는 컴파일 전 기초작업
//#include iostream ==> 복붙해달라는 뜻임.
int main()
{
	DEFINE_TEST;
	const int ROCK = 1;
	const int PAPER = 2;
	const int SCISSORS = 3;
	
	//하나로 묶기 ==> enum
	//값 미지정시 0부터 시작, 첫 값은 0 그 다음부터는 1씩 증가해서 값이 지정 됨.
	//첫번째 값을 N으로 지정한다면 이전 값은 N+1, N+2 ... 로 1 씩 증가

	enum ENUM_SRP//scissors, rock and paper
	{
		ENUM_SCIOSSRS = 1,
		ENUM_ROCK, //2
		ENUM_PAPER //3
	};

	//아래와 같이 const의 주소가 필요한 경우가 없으면 각 변수는 컴파일시 상수로 변환될 수 있음.
	const int* paperPointer = &PAPER;
	//const 변수의 경우, 전역변수의 경우 컴파일시 그냥 상수로 바뀔 수 있음. 
	// 지역변수의 경우 stack에 들어가고 전역변수일 경우 주소를 참조할 때 상수로 바뀌지 않고 메모리에 올라갈 수도 있음.
	//ENUM의 경우 컴파일할때 전부 상수로 바꿔줘서 메모리 낭비를 줄일 수 있음.
	//따라서 열거형을 쓰는게 조금 더 좋다... define 매크로는 상수화 할 때 굳이 쓰지는 경우는 많지 않음.
}