#include <iostream>
using namespace std;

//참조 reference

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};
StatInfo globalInfo;

//[매개변수][복귀주소][지역변수(info)] [매개변수(&info)][복귀주소][지역변수]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

StatInfo* FindMonster() {
	//특정 조건을 만족하는 몬스터를 찾고 
	//찾으면 해당 포인터 반환
	//못찾으면 nullptr 반환 --> 없는 값 null이 유용하게 쓰일 수 있음.
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
	if (info == nullptr)//null인지 확인 null-check
		return;
	cout << "----------주소---------" << endl;
	cout << "-----------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "-----------------------" << endl;

	//포인터에서도 const 가능...대참사 유발 변경 막기
	//info[주소값] 주소값[데이터]
	// info에 담긴 주소값을 변경 or 주소값이 담고있는 데이터를 변경
	//const StatInfo* info : (더 일반적) info를 타고가서 그 내용물을 바꿀 수 없게함
	//StatInfo* const info : info에 담긴 주소 변경 불가
	/*info = &globalInfo;
	info->hp = 10000;*/
}

void PrintInfoByRef(const StatInfo& info)
{	
	cout << "----------참조---------" << endl;
	cout << "-----------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "-----------------------" << endl;

	//아래와 같은 허용되지 않은 변경을 막기 위해 const
	//info.hp = 1000000;
}
int main()
{	
	//포인터 vs 참조
	
	//성능 : 완전 동일 --> assembly가 동일하다
	//편의성 : 참조 win --> 더 편함 ->보단 . 쓰는게  편하다
	
	//1)편의성이 "좋음"의 부작용: 포인터는 주소를 넘겨 원본을 건네준다는 것을 명확하게 보여줌
	//참조는 PrintInfo(info) 딱 봐서 원본을 넘겨주는건지 알기가 PrintInfo(&info)보다 덜 명확함.
	//원본을 마음대로 고치는 것을 막기 위해 const를 사용할 수 있음.
	
	//2)초기화 여부
	//참조 타입은 바구니의 2번째 이름으로 '별칭'임
	//참조하는 대상이 없으면 안됨.
	//반면 포인터는 그냥 어떤~ 주소라는 의미이고 대상이 실존하지 않을 수 있음

	StatInfo info;
	CreateMonster(&info);
	
	PrintInfoByPtr(&info);
	PrintInfoByRef(info); //참조전달 -> 알아서 주소값이 전달됨
	
	StatInfo* pointer; //StatInfo* pointer = NULL; //NULL = 0, nullptr 아무데도 안 가리키고 있어도 ok
	pointer = &info;
	//pointer = nullptr;//읽기 acess 위반으로 프로그램이 뻗을 수 있음
	//참조타입은 nullptr을 가리킬수 없음.
	PrintInfoByPtr(pointer);

	StatInfo& reference = info; // 유효한 대상을 가리켜야한다는 제약이 있다
	PrintInfoByRef(reference);
	
	//결론:
	//Team by Team 정해진 답은 없다
	//구글 오픈소스 보면 거의 포인터 사용
	//언리얼 엔진에선 reference도 애용
	 
	//바뀌지 않고 읽는 readonly : const ref&
	//그 외 일반적으로 ref 명시적으로 호출할 때 OUT을 붙인다 ChangeInfo(OUT info) #define OUT
	//OUT은 그냥 가독성 향상을 위해 define 해준 것.
	
	//어쨌든 팀의 스타일을 따르세요.

	//포인터로 쓰던걸 참조로 넘겨주기 - pointer[ 주소(&info) ]      ref(info의 별명), info[ 데이터 ]
	PrintInfoByRef(*pointer);
	//참조로 쓰던걸 포인터로 넘겨주기
	PrintInfoByPtr(&reference);
	return 0;

}