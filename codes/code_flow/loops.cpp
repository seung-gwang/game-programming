// 반복문
#include <iostream>
using namespace std;

int main() 
{
	//while : ~한 동안에
	//특정 조건까지 계속 반복할 필요가 있을 때
	//ex) 게임을 끄기 전까지 계속 게임을 실행해라 ==> 반복문
	//    목적지에 도달할 때 까지 계속 이동해라 ==> 반복문
	int count = 0; //main 함수 내부 변수 ==> stack
	//while (count < 5) //()안에 조건식
	//{//한줄짜리인 경우 {}필요 없음
	//	cout << "hello world" << endl;
	//	count++; //없는 경우 무한 루프 ==> 의도한 경우가 아닌 경우엔 치명적 오류임.
	//}

	do
	{//일단 한번은 실행하고 조건식 검사, 잘 사용 안함.
		cout << "hello world" << endl;
		count++;
	} while (false);

	//while 문은 위에서 처럼 count를 초기화, loop 돌때마다 count 증감 등등... 귀찮음
	// ==> for 문

	//동작 횟수가 딱 정해져 있는 경우에 자주 사용.
	for (int count = 0; count < 5; count++)//초기식; 조건식; 제어식
	{
		cout << "hello for statement!" << endl;
	}

	//반복문 제어 : break, continue
	//break: 반복문 바로 탈출
	//continue: 현재 진행하는 loop 끝내고 다음 loop 진행

	//라운드가 있는 게임
	int round = 1;
	int hp = 100;
	int damage = 27;

	while (true) // 무한루프 - 전투 시작, 루프 안에서 적절하게 break 해야함
	{
		hp -= damage;
		if (hp < 0)
			hp = 0;// 음수 체력 0으로 보정

		//시스템 메시지
		cout << "Round " << round << "몬스터 체력 " << hp << endl;

		if (hp == 0)
		{
			cout << "몬스터 처치!" << endl;
			break; //loop 종료
		}

		if (round == 5)
		{
			cout << "제한 라운드 종료" << endl;
			break; //loop 종료
		}

		round++;

	}
}