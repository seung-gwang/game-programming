// 분기문
#include <iostream>
using namespace std;

int main() 
{
	//int hp = 100;// 문스터 hp
	//int damage = 90; // 플레이어 damage

	//hp -= damage;
	//bool isDead = (hp <= 0);

	//if (isDead)
	//	cout << "몬스터를 처치했습니다." << endl;

	////if (isDead == false) //not isDead 또는 !isDead
	////	cout << "몬스터가 반격했습니다." << endl;
	//else//몬스터가 죽지 않은 경우
	//{	//if - else 중첩
	//	if (hp <= 20)
	//		cout << "몬스터가 도망가고 있습니다." << endl;
	//	else
	//		cout << "몬스터가 반격했습니다." << endl;
	//}
	
	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;

	int input = ROCK;

	if (input == ROCK)
		cout << "바위를 냈어요" << endl;
	else if (input == PAPER)
		cout << "보를 냈어요" << endl;
	else if (input == SCISSORS)
		cout << "가위를 냈어요" << endl;
	else
		cout << "뭘 낸겁니까?" << endl;

	//switch - case 문
	//if-else를 완벽하게 대체할 수는 없음. switch문은 오직 정수 계열만 평가할 수 있음.
	switch (input)//()안에는 평가할 대상 입력, 컴파일 후엔 if-else와 거의 비슷함. 
	{
	case ROCK:
		cout << "바위" << endl;
		break;//특별한 경우가 아니면 break을 해줘야 함.
	case PAPER:
		cout << "보" << endl;
		break;
	case SCISSORS:
		cout << "가위" << endl;
		break;
	default:
		cout << "뭘 낸겁니까??" << endl; //위의 case문에 하나도 안걸렸을 경우 이것 수행
		//break;
	}
}