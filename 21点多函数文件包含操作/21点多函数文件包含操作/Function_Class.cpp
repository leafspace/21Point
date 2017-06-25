#include "HEAD.h"
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
/***************************************************************************************************/
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
		cout << "×Ü·ÖÎª£º";
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