#include "HEAD.h"
int main()
{
	srand((unsigned)time(NULL));
	USER *M;
	extern int member_number;
	cout << "多少人参加游戏？（1~7）";
	cin >> member_number;
	M = new USER[member_number + 1];
	if (setuser(M) == false){
		cout << "内存设置失败，程序结束！";
		exit(-1);
	}
	else{
		cout << "*游戏开始！*\n\n";
	}
	showuser(M, 0);
	extract(M);
	system("pause");
	check(M);
	system("pause");
	return 0;
}