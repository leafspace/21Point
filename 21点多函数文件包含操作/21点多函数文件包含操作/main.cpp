#include "HEAD.h"
/***************************************************************************************************/
int member_number;
const int A = 11;
int POKER_INDEX[53] = { 0 };
const string POKER_KIND[4] = { "����", "����", "����", "÷��" };
const char *P[14] = { "X", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
/***************************************************************************************************/
int main()
{
	srand((unsigned)time(NULL));
	USER *M;
	cout << "�����˲μ���Ϸ����1~7��";
	cin >> member_number;
	M = new USER[member_number + 1];
	if (setuser(M) == false){
		cout << "�ڴ�����ʧ�ܣ����������";
		exit(-1);
	}
	else{
		cout << "*��Ϸ��ʼ��*\n\n";
	}
	showuser(M,0);
	extract(M);
	system("pause");
	check(M);
	system("pause");
	return 0;
}