#include "HEAD.h"
bool setuser(USER *M)
{
	extern int member_number;
	if (M == NULL)
		return false;
	M[0].set_name("庄家（隐藏）");
	for (int i = 1; i <= member_number; i++){
		cout << "请输入第" << i << "位参赛者的姓名:";
		string NAME;
		cin >> NAME;
		M[i].set_name(NAME);
	}
	return true;
}

void showuser(USER *M, int F)
{
	int i;
	cout << M[0].show_name() << ",";
	M[0].show_card(F);
	for (i = 1; i <= member_number; i++){
		cout << M[i].show_name() << ",";
		M[i].show_card(1);
		//M[i].show_card(F||i);
	}
}

void extract(USER *M)
{
	extern int member_number;
	cout << "\n";
	for (int i = 1; i <= member_number; i++){
		cout << M[i].show_name() << ",";
		cout << "你想再抽一张牌吗（y,n）？";
		fflush(stdin);
		if ('y' == getc(stdin)){
			M[i].draw_card();
			cout << "抽的牌为:";
			M[i].show_draw();
			cout << "\n";
		}
		else
			continue;
	}
	cout << "\n";
}
void check(USER *M)
{
	extern int member_number;
	int f = 1;
	int pok_num, sum_point;
	for (int i = 1; i <= member_number; i++){
		M[i].show_data(&sum_point, &pok_num);
		if (pok_num != 3){
			f = 0;
			break;
		}
	}
	if (f){
		cout << "______________________\n";
		cout << "警告！所有人都抽牌了！\n";
		cout << M[0].show_name() << ",";
		M[0].show_card(1);
		cout << "\n";
		M[0].show_data(&sum_point, &pok_num);
		if (sum_point <= 16){
			cout << "*庄家需要抽牌!*\n";
			M[0].draw_card();
			cout << "庄家抽的牌是：";
			M[0].show_draw();
			cout << "\n";
			cout << "______________________\n";
		}
	}
	gameover(M, f);
}
void gameover(USER *M, int f)
{
	extern int member_number;
	int pok_num, sum_point;
	showuser(M, 1);
	cout << "================================================================================\n";
	for (int i = 1; i <= member_number; i++){
		M[i].show_data(&sum_point, &pok_num);
		cout << M[i].show_name() << ",";
		if (sum_point > 21)
			cout << "对不起，你输了！\n";
		else{
			if (f&&sum_point > 21)
				cout << "恭喜你，你赢了！\n";
			else{
				if (sum_point > sum_point)
					cout << "恭喜你，你赢了！\n";
				if (sum_point == sum_point)
					cout << "平局！\n";
				if (sum_point < sum_point)
					cout << "对不起，你输了！\n";
			}

		}
	}
}