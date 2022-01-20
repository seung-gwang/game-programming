#include <iostream>
using namespace std;

//array 배열

struct StatInfo {
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defence = 0xDDDDDDDD;
};

int main() {
	//근데 몬스터가 최대 1만마리면... monster_10000까지 한땀한땀 만들수는 없음.
	/*StatInfo monster;
	StatInfo monster_2;
	StatInfo monster_3;*/

	//따라서 '배열'로 만들어준다. => TYPE 이름[개수];
	const int monsterCount = 10;//vs 컴파일러 기준, 배열 크기는 상수여야함.
	StatInfo monsters[monsterCount];

	//지금까지 변수들의 "이름"은 바구니의 이름
	//배열은 "이름"이 조금 다르게 동작함.
	StatInfo players[10];
	/*players = monsters; 이거 안됨*/
	auto WhoAmI = monsters; //auto는 StatInfo*
	//따라서 배열의 이름은 곧 배열의 시작 주소
	//정확히는 시작 위치를 가리키는 TYPE* 포인터.

	//Statinfo[100,10,1] Statinfo[] Statinfo[] Statinfo[] ... Statinfo[]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	//포인터의 덧셈: StatInfo 타입 1개씩 이동 -> +1
	//Statinfo[100,10,1] Statinfo[200,20,2] Statinfo[] Statinfo[] ... Statinfo[]
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	//포인터와 참조는 자유자재로 변환 가능
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;
	
	//이거는 완전 다른 의미
	//temp라는 새로운 StatInfo 변수에 monsters+2의 내용물을 값복사
	StatInfo temp = *(monsters + 2);
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	//for문으로 간결히 값 세팅
	for (int i = 0; i < 10; i++) {
		StatInfo& monster = *(monsters + i); //<- 이 부분이 가독성이 별로...
		monster.hp = 100*(i+1);
		monster.attack = 10*(i+1);
		monster.defence = i+1;
	}
	//위 코드의 가독성을 개선:
	for (int i = 0; i < 10; i++) {
		StatInfo& monster = monsters[i];
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = i + 1;
	}

	//배열 초기화 문법 몇가지
	int numbers[5] = {};//0으로 초기화
	int numbers1[10] = { 1,2,3,4,5 }; //설정해준 값은 그 값으로 초기화, 나머지는 0으로
	int numbers2[] = { 1,2,3,4,5,6,7,8,9 };//데이터 개수만큼의 크기에 해당하는 배열로 만들어줌
	char helloStr[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
	
	return 0;
}