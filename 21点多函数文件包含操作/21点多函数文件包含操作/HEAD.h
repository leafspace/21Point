#ifndef _HEAD_H_
#define _HEAD_H_
#include <time.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;
/***************************************************************************************************/
extern int member_number;
extern const int A ;
extern int POKER_INDEX[53];
extern const string POKER_KIND[4];
extern const char *P[14];
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
/***************************************************************************************************/
bool setuser(USER *M);
void showuser(USER *M, int F);
void extract(USER *M);
void check(USER *M);
void gameover(USER *M, int f);
/***************************************************************************************************/
#endif