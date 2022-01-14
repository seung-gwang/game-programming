//#include <iostream>
//using namespace std;
//
//int a = 1;
//int b = 2;
//int hp2 = 0;
//
//bool isSame;
//bool isDifferent;
//bool isGreater;
//bool isSmaller;
//bool isInvincible; //무적
//bool test;
//
//unsigned char flag; //bitFlag 할때 부호를 없애야 >> 를 하더라도 부호비트가 딸려오지 않음
//int main_()
//{	
//#pragma region 산술 연산
//	//a에 b를 대입하고 b를 반환하라.
//	//--> b라는 바구니 안에 있는 값을, a라는 바구니 안에 복사한다.
//	a = b;
//	a = (b = 3);
//#pragma endregion 
//	//pragma region으로 그 영역을 접었다가 폈다가 할 수 있도록 비쥬얼 스튜디오에 전달.
//	//a = b;
//
//	//사칙 연산
//	a = b + 3; 
//	//*-+/%
//	//증감 연산 : ++, --... a++, ++a ==> 평가 순서가 다름
//
//#pragma region 비교 연산
//	// ==, !=, >, <, >=, <=
//	isSame = (a == b);
//	isDifferent = (a != b);
//	isGreater = (a > b);
//	isSmaller = (a < b);
//#pragma endregion
//
//#pragma region 논리 연산
//	//조건에 대한 논리적 사고가 필요함
//	//아이디 correct AND 비번 correct ==> 로그인
//	//길드마스터 OR 운영자 ==> 길드해산 가능
//	
//	test = !isSame; //논리 not...결국 isDifferent 의미
//	// AND : a&&b 둘다 1 일때만 true 아니면 false 
//	
//#pragma region 비트연산
//	//언제 필요? ==> 비트 단위의 조작(가끔 필요함) 
//	//ex) BitFlag
//
//	//~ : bitwise not ==> 단일 숫자의 모든 bit를 대상으로 반전
//	//& : bitwise and ==> 두 숫자의 모든 bit 쌍을 대상으로 and
//	//| : bitwise or ==> 두 숫자의 모든 bit 쌍을 대상으로 or
//	//^ : bitwise xor ==> 두 숫자의 모든 bit 쌍을 대상으로 xor
//	//<< : bitwise shift left ==> 비트열을 N만큼 왼쪽으로 이동, 왼쪽에 넘치는 N개의 비트는 버리고 새로 생기는 N개의 비트는 0
//	//>> : bitwise shift right ==> 밀리는 비트는 사라짐. 왼쪽 생성되는 N개 비트: signed 변수 부호비트로 채움, unsigned 변수 ==> 0 
//
//	//실습
//	//0b0000 [무적][변이][스턴][공중부양]
//	flag = (1 << 3);//무적 상태 8이라는 값을 그냥 8로 썡으로 넣기보단 shift의 의미를 살려서 보여주도록 <<를 적어 넣음. 무적상태
//	flag |= (1 << 2);//변이 상태 추가
//
//	//bitmask => 무적인지 확인하기
//	bool invincible = (flag & (1 << 3)) != 0; //찾고자하는 비트만 살려서  확인 결과값이 1이면 무적임.
//
//	//무적이거나 스턴 상태인지 확인하고 싶다면?
//	//bool mask = (1 << 3) | (1 << 1); mask를 생성하고싶으면 1010은 다음과 같이 생성 가능
//	bool stunOrInvincible = ((flag & 0b1010) != 0);
//#pragma endregion
//	return 0;
//}