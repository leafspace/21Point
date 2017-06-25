#ifndef _HEAD_H_
#define _HEAD_H_
#include <time.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;
/***************************************************************************************************/
int member_number;
const int A = 11;
int POKER_INDEX[53] = { 0 };
const string POKER_KIND[4] = { "����", "����", "����", "÷��" };
const char *P[14] = { "X", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
/***************************************************************************************************/
class POKER
{
private:
	string suit;
	int kind;
	int point;
public:
	void indata();
	void outdata();
	int show_point();
};
void POKER::indata()
{
	int num;
	extern int POKER_INDEX[53];
	do{
		num = rand() % 52 + 1;
	} while (POKER_INDEX[num]);
	POKER_INDEX[num] = 1;
	suit = POKER_KIND[num / 13];
	num = num % 13;
	num = kind = num == 0 ? 13 : num;
	point = num > 10 ? 10 : num == 1 ? A : num;
}
void POKER::outdata()
{
	cout << suit;
	cout << P[kind];
}
int POKER::show_point()
{
	return point;
}
class USER
{
private:
	string name;
	POKER POK[3];
	int sum_point;
	int pok_num;
public:
	USER();
	void set_name(string NAME);
	string show_name();
	void show_card(int F);
	void draw_card();
	void show_draw();
	void show_data(int *point,int *num);
};
USER::USER()
{
	pok_num = 2;
	POK[0].indata();
	POK[1].indata();
	sum_point = POK[0].show_point() + POK[1].show_point();
}
void USER::set_name(string NAME)
{
	name = NAME;
}
string USER::show_name()
{
	return name;
}
void USER::show_card(int F)
{
	int i;
	if (!F)
		POK[0].outdata();
	else{
		for (i = 0; i < pok_num; i++){
			POK[i].outdata();
			cout << " ";
		}
	}
	if (F){
		cout << "�ܷ�Ϊ��";
		cout << sum_point;
	}
	cout << "\n";
}
void USER::draw_card()
{
	pok_num++;
	POK[2].indata();
	sum_point += POK[2].show_point();
}
void USER::show_draw()
{
	POK[2].outdata();
}
void USER::show_data(int *point, int *num)
{
	(*point) = sum_point;
	(*num) = pok_num;
}
/***************************************************************************************************/
bool setuser(USER *M);
void showuser(USER *M);
void extract(USER *M);
void check(USER *M);
void gameover(USER *M, int f);
/***************************************************************************************************/
bool setuser(USER *M)
{
	extern int member_number;
	if (M == NULL)
		return false;
	M[0].set_name("ׯ�ң����أ�");
	for (int i = 1; i <= member_number; i++){
		cout << "�������" << i << "λ�����ߵ�����:";
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
		cout << "�����ٳ�һ������y,n����";
		fflush(stdin);
		if ('y' == getc(stdin)){
			M[i].draw_card();
			cout << "�����Ϊ:";
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
		M[i].show_data(&sum_point,&pok_num);
		if (pok_num != 3){
			f = 0;
			break;
		}
	}
	if (f){
		cout << "______________________\n";
		cout << "���棡�����˶������ˣ�\n";
		cout << M[0].show_name() << ",";
		M[0].show_card(1);
		cout << "\n";
		M[0].show_data(&sum_point,&pok_num);
		if (sum_point <= 16){
			cout << "*ׯ����Ҫ����!*\n";
			M[0].draw_card();
			cout << "ׯ�ҳ�����ǣ�";
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
			cout << "�Բ��������ˣ�\n";
		else{
			if (f&&sum_point > 21)
				cout << "��ϲ�㣬��Ӯ�ˣ�\n";
			else{
				if (sum_point > sum_point)
					cout << "��ϲ�㣬��Ӯ�ˣ�\n";
				if (sum_point == sum_point)
					cout << "ƽ�֣�\n";
				if (sum_point < sum_point)
					cout << "�Բ��������ˣ�\n";
			}

		}
	}
}
/***************************************************************************************************/
#endif