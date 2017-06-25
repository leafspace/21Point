#include "HEAD.h"
/***************************************************************************************************/
int member_number;
const int A = 11;
int POKER_INDEX[53] = { 0 };
const string POKER_KIND[4] = { "红桃", "黑桃", "方块", "梅花" };
const char *P[14] = { "X", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
/***************************************************************************************************/
int main()
{
	srand((unsigned)time(NULL));
	USER *M;
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
	showuser(M,0);
	extract(M);
	system("pause");
	check(M);
	system("pause");
	return 0;
}