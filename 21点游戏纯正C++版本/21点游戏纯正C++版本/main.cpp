#include "HEAD.h"
int main()
{
	srand((unsigned)time(NULL));
	USER *M;
	extern int member_number;
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
	showuser(M, 0);
	extract(M);
	system("pause");
	check(M);
	system("pause");
	return 0;
}