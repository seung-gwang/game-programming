#include <iostream>
using namespace std;

//참조 reference

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

//[매개변수][복귀주소][지역변수(info)] [매개변수(&info)][복귀주소][지역변수]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

//[매개변수][복귀주소][지역변수(info)] [매개변수(복사된 info - 100, 8, 5)][복귀주소][지역변수]

void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}

//값을 수정하지 않는다면, 양쪽 다 문제 없음
//1) 값 전달 방식 - 값이 복사되어 전달됨
void PrintInfoByCopy(StatInfo info)		
{
	cout << "---------- 값 ---------" << endl;
	cout << "-----------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "-----------------------" << endl;

}

//2) 주소 전달 방식 - 주소를 건네받고 그 주소에 담긴 원본을 보고 cout 수행함.
void PrintInfoByPtr(StatInfo* info)
{
	cout << "----------주소---------" << endl;
	cout << "-----------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "-----------------------" << endl;

}
//StatInfo 구조체가 1000 바이트 짜리라면
//복사 방식은 1000바이트를 복사받고 주소 방식은 4바이트(또는 8바이트) 포인터 하나만 받음.
//참조전달 STatInfo&은 8바이트
// 
// 값 전달처럼 편리하고 주소 전달처럼 주소값을 이용해 원본을 건드릴수 있음


//3) 참조 전달 (C에는 없고 C++에 추가된 기능)
void PrintInfoByRef(StatInfo& info)
{	
	cout << "----------참조---------" << endl;
	cout << "-----------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "-----------------------" << endl;

}
int main()
{	
	//4바이트 정수형 바구니를 사용할 것. 그 이름은 number라고 지었음.
	//number에서 뭘 꺼내거나, 넣을 것이면, 컴파일러가 알아서 알아듣고 해당 주소에 1을 넣음.
	int number = 1; 
	
	//* 포인터 : 주소를 담는 바구니, TYPE을 보면 그 바구니안의 주소를 따라가면 TYPE에 해당하는
	//데이터가 있음.
	int* pointer = &number;
	*pointer = 2;

	//참조 타입 reference ==> 실제 assembly에서의 작동 방식은 int*와 동일
	//실제로 어셈블리 레벨에서는 포인터와 100%와 똑같음.
	int& reference = number;
	//C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
	//number라는 바구니에 reference라는 다른 이름을 지어줌
	//앞으로 reference 바구니에다가 뭘 꺼내거나 넣으면
	//실제 number 바구니(원래 진퉁 바구니)에서 그 값을 꺼내거나 넣으면 됨.
	reference = 3;
	//그런데 굳이 reference가 있는 이유? ==> '참조 전달'을 위해
	//C++사용자 입장에서 간편하게 사용 가능, 어셈블리수준 low level에서의 작동은 주소전달과 동일
	
	
	StatInfo info;
	CreateMonster(&info);
	//CreateMonster(info); //info 구조체를 통채로 복사해서 넘겨짐
	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByRef(info); //참조전달 -> 알아서 주소값이 전달됨
	return 0;

}