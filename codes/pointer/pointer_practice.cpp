#include <iostream>
using namespace std;

//포인터 실습
struct StatInfo
{
	int hp; //+0 offset
	int attack;//+4
	int defence;//+8
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);
bool StartBattle(StatInfo* player, StatInfo* monster); //플레이어 승리 여부 true

int main()
{
	cout << "로비에 입장했습니다" << endl;
	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defence = 0xbbbbbbbb;
	//[매개변수 복귀주소 지역변수(temp(ebp-110h), b,b,b)] [매개변수(&temp) 복귀주소 지역변수]
	//temp에다가 CreatePlayer가 쓰고 함수 종료시 temp에 쓰여진 값이 player에 복사됨.
	//복사가 많기 때문에 성능부하 쉬움
	player = CreatePlayer();
	
	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.attack = 0xbbbbbbbb;
	monster.defence = 0xbbbbbbbb;
	CreateMonster(&monster);

	//player = monster; //구조체 복사?
	/*
	player.hp = monster.hp;
	player.attack = monster.attack;
	player.defence = monster.defence; 한땀한땀 값 복사가 일어나므로 느릴수 있음.
	*/
	bool victory = StartBattle(&player, &monster);
	
	if (victory) {
		cout << "승리" << endl;
	}
	else
		cout << "패배" << endl;
}

StatInfo CreatePlayer()
{//return으로 player 정보를 건네주는 방식
	StatInfo ret; //반환할 값
	
	//
	cout << "플레이어 생성" << endl;
	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;

}
void CreateMonster(StatInfo* info) 
{//포인터로 받고 포인터에서 세팅하는 방식
//바로 써야할 주소를 알려줌
//[매개변수][RET][매개변수(monster(b-->40,b-->8,b-->1)] [매개변수(&monster)][RET][지역변수()]
//이 방식이 (어셈블리상으로) 훨씬 간결하고 빠르다.
	cout << "몬스터 생성" << endl;
	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
	while(true)
	{
		int damage = player->attack - monster->defence;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		cout << "몬스터 HP : " << monster->hp << endl;

		if (monster->hp == 0)
			return true;

		damage = monster->attack - player->defence;
		if (damage < 0)
			damage = 0;

		cout << "플레이어 HP :" << player->hp << endl;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		if (player->hp == 0)
			return false;

	}
}