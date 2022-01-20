#include <iostream>
using namespace std;

//function wrap up
//오버로딩 (중복 정의 - 함수 이름의 재사용)
//매개변수 개수나 type(순서가 다른 것도 포함)등이 달라서 구분 가능할때 가능
//반환 형식만 다른경우 불가능
int Add(int a, int b) {
	int result = a + b;
	return result;
}

//float Add(float a, float b)
float AddFloat(float a, float b) {//매개변수 type이 다르니까 Add로 지어도 OK
	float result = a + b;
	return result;
}

void SetPlayerInfo(int hp, int mp, int attack, int guildId = 0, int castleId = 1) {
	//매개변수 = 기본값 --> 기본값 세팅 가능, 단 맨 마지막에 와야함.
	//"기본 인수가 매개변수 목록의 끝에 없습니다"

	
}

//stack overflow 스택 오버플로우
//함수가 너무 많이 호출 --> 스택 메모리 고갈 --> stack overflow
int Factorial(int n) {
	if (n < 1)
		return 1;
	//else
	return n * Factorial(n - 1);
}


int main() {
	//int result = Add(1.5f, 2.1f); //Add는 정수를 받기때문에 1, 2가 들어감
	float result = AddFloat(1.5f, 2.1f);

	SetPlayerInfo(100, 40, 10, 0);
	SetPlayerInfo(122, 40, 10, 0);
	SetPlayerInfo(130, 40, 10, 0);
	SetPlayerInfo(160, 40, 10, 0);
	SetPlayerInfo(120, 40, 10, 0);

	int factorial = Factorial(5);//Factorial(천만) 이런식으로 하면 overflow 가능
	cout << factorial << endl;
	//stack overflow ==> factorial 예시
	
	return 0;

}