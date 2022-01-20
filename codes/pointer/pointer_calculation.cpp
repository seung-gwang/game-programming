#include <iostream>
using namespace std;
//포인터 연산

//1) 주소 연산자 &
//2) 산술 연산자 +,-
//3) 간접 연산자 *
//4) 간접 멤버 연산자 ->

struct Player {
	int hp;// +0 "offset"
	int damage;// +4 "offset"
};

int main()
{
	int number = 1;
	//1)  주소 연산자 & -> 해당 변수의 주소 알려줌
	//해당 변수 type에 따라서 type* 으로 변환
	int* pointer = &number;

	//2) 산술 연산자 (+,-)
	/*number = number + 1;
	number++;
	number += number;

	pointer = pointer + 1;
	pointer++;
	++pointer;
	pointer += 1;*/
	number += 1;
	pointer += 1;//pointer에 담긴 주소가 "4" 증가함.
	//why? =>
	// int*의 의미를 생각해보면... 
	//int*에서 * 포인터 타입이다 (4 또는 8 바이트) 주소를 담는 바구니
	//int*에서 int => 주소를 따라가면 int(4바ㅣ트 정수형 바구니)가 있다.
	//포인터에서 +- 등 산술 연산으로 1을 더하거나 빼면
	//한번에 TYPE의 크기만큼 이동해달라는 의미임. "바구니 단위"로 이동
	//1을 더하기 == 바구니 1개 이동해주세요.
	//3을 더하기 == 바구니 3개 이동해주세요.
	pointer += 2;
	
	//3) 간접 연산자 (*)
	//포인터에 담긴 주소로 가서 그 값을 본다
	*pointer = 3;

	//4) 간접 멤버 연산자
	Player player;
	player.hp = 100;
	player.damage = 10;

	Player* playerPtr = &player;
	(*playerPtr).hp = 200;
	(*playerPtr).damage = 200;
	//위와 같이 해도 되지만...
	playerPtr->hp = 300;
	playerPtr->damage = 300; //이렇게 하면 좀 더 편하게 쓸 수 있음.
	//-> 구조체의 특정 멤버를 다룰 때 사용(어셈블리상에서 .과 같이 그냥 덧셈임.
	//(*playerPTr).damage 와 완전 동일한 어셈블리코드 생성.

	return 0;
}


