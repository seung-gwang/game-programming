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
//bool isInvincible; //����
//bool test;
//
//unsigned char flag; //bitFlag �Ҷ� ��ȣ�� ���־� >> �� �ϴ��� ��ȣ��Ʈ�� �������� ����
//int main_()
//{	
//#pragma region ��� ����
//	//a�� b�� �����ϰ� b�� ��ȯ�϶�.
//	//--> b��� �ٱ��� �ȿ� �ִ� ����, a��� �ٱ��� �ȿ� �����Ѵ�.
//	a = b;
//	a = (b = 3);
//#pragma endregion 
//	//pragma region���� �� ������ �����ٰ� ��ٰ� �� �� �ֵ��� ����� ��Ʃ����� ����.
//	//a = b;
//
//	//��Ģ ����
//	a = b + 3; 
//	//*-+/%
//	//���� ���� : ++, --... a++, ++a ==> �� ������ �ٸ�
//
//#pragma region �� ����
//	// ==, !=, >, <, >=, <=
//	isSame = (a == b);
//	isDifferent = (a != b);
//	isGreater = (a > b);
//	isSmaller = (a < b);
//#pragma endregion
//
//#pragma region �� ����
//	//���ǿ� ���� ���� ��� �ʿ���
//	//���̵� correct AND ��� correct ==> �α���
//	//��帶���� OR ��� ==> ����ػ� ����
//	
//	test = !isSame; //�� not...�ᱹ isDifferent �ǹ�
//	// AND : a&&b �Ѵ� 1 �϶��� true �ƴϸ� false 
//	
//#pragma region ��Ʈ����
//	//���� �ʿ�? ==> ��Ʈ ������ ����(���� �ʿ���) 
//	//ex) BitFlag
//
//	//~ : bitwise not ==> ���� ������ ��� bit�� ������� ����
//	//& : bitwise and ==> �� ������ ��� bit ���� ������� and
//	//| : bitwise or ==> �� ������ ��� bit ���� ������� or
//	//^ : bitwise xor ==> �� ������ ��� bit ���� ������� xor
//	//<< : bitwise shift left ==> ��Ʈ���� N��ŭ �������� �̵�, ���ʿ� ��ġ�� N���� ��Ʈ�� ������ ���� ����� N���� ��Ʈ�� 0
//	//>> : bitwise shift right ==> �и��� ��Ʈ�� �����. ���� �����Ǵ� N�� ��Ʈ: signed ���� ��ȣ��Ʈ�� ä��, unsigned ���� ==> 0 
//
//	//�ǽ�
//	//0b0000 [����][����][����][���ߺξ�]
//	flag = (1 << 3);//���� ���� 8�̶�� ���� �׳� 8�� ������ �ֱ⺸�� shift�� �ǹ̸� ����� �����ֵ��� <<�� ���� ����. ��������
//	flag |= (1 << 2);//���� ���� �߰�
//
//	//bitmask => �������� Ȯ���ϱ�
//	bool invincible = (flag & (1 << 3)) != 0; //ã�����ϴ� ��Ʈ�� �����  Ȯ�� ������� 1�̸� ������.
//
//	//�����̰ų� ���� �������� Ȯ���ϰ� �ʹٸ�?
//	//bool mask = (1 << 3) | (1 << 1); mask�� �����ϰ������ 1010�� ������ ���� ���� ����
//	bool stunOrInvincible = ((flag & 0b1010) != 0);
//#pragma endregion
//	return 0;
//}