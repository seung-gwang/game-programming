#include <iostream>
using namespace std;
/*
별찍기 문제(1)
//유저들이 어떤 정수를 입력하면
N X N 개의 *을 출력하기

별찍기 문제(2)
//1개부터 시작해서 순차적으로 줄마다 증가하게 수정하기

별찍기 문제(3)
//처음에 N개부터 시작해서 줄마다 1개씩 줄어드는 형태로 * 출력

구구단 문제
//2단부터 9단까지 구구단 출력하기
*/


int main() 
{
	int userNum;
	cin >> userNum; //console input
	const int LINES = userNum;

	//별찍기 문제(1)
	/*for (int i = 0; i < LINES; i++)
	{
		for (int j = 0; j < LINES; j++)
		{
			cout << "*";
		}

		cout << endl;
	}*/

	//별찍기 문제(2)
	/*for (int i = 0; i < LINES; ++i)
	{
		for (int j = 0; j < i+1; j++)
			cout << "*";
		cout << endl;
	}*/
	
	//별찍기 문제(3)
	/*for (int i = LINES; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
			cout << "*";
		cout << endl;
	}*/

	//구구단 문제
	for (int i = 2; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cout << i << " X " << j << " = " << i * j << endl;
		}
	}
}