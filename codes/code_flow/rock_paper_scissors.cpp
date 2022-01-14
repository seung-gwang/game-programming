#include <iostream>
using namespace std;
//가위바위보 게임
int main()
{	
	const int ROCK = 1;
	const int PAPER = 2;
	const int SCISSORS = 3;
	char win = 0;
	char lose = 0;

	while (true) {
		srand(time(0)); //현재 시각을 기준으로 시드 생성
		int comp = (rand() % 3) + 1;

		cout << "가위(1) 바위(2) 보(3):\n";
		if (win == 0 && lose == 0)
			cout << "전적이 없습니다." << endl;
		else
			//float으로 캐스팅해야함! ==> 정수/정수 결과는 정수 1/4=0.25인데 정수만 남아서 0이 됨.
			//cout << "현재 승률: " << (float(win) / (win + lose)) * 100 << "%" << endl;
			//또는 아래와 같이 100을 먼저 곱해주면 됨
			cout << "현재 승률: " << (win * 100 / (win + lose)) << "%" << endl;
		cout << ">";

		int user;
		cin >> user;
		
		if (user > 3 || user < 1){
			cout << "GAME FINISHED" << endl;
			break;
		}

		else if (user == ROCK) {
			if (comp == ROCK)
				cout << "DRAW" << endl;
			else if (comp == PAPER){
				cout << "YOU LOSE" << endl;
				lose++;
			}
			else if (comp == SCISSORS){
				cout << "YOU WIN" << endl;
				win++;
			}
		}
		
		else if (user == PAPER) {
			if (comp == ROCK){
				cout << "YOU WIN" << endl;
				win++;
			}
			else if (comp == PAPER)
				cout << "DRAW" << endl;
			else if (comp == SCISSORS){
				cout << "YOU LOSE" << endl;
				lose++;
			}
		}

		else if (user == SCISSORS) {
			if (comp == ROCK){
				cout << "YOU LOSE" << endl;
				lose++;
			}
			else if (comp == PAPER){
				cout << "YOU WIN" << endl;
				win++;
			}
			else if (comp == SCISSORS)
				cout << "DRAW" << endl;	
		}

	}
}