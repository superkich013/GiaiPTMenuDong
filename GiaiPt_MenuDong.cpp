#include <iostream>
#include <windows.h>
#include <cmath>
#include <conio.h>
#include <iomanip>
#include "mylib.h"
#define maxlist 3
using namespace std;
void giaibac1(){
	int a=0;
	int b=0;
	double x;
	cout<<"Nhap a,b:";
	VeHCNRong(HCN (0,8),HCN (6,10));
	gotoxy(7,9);
	cout<<"*x + ";
	VeHCNRong(HCN (12,8),HCN (18,10));
	gotoxy(19,9);
	cout<<" = 0";
	gotoxy(1,9);
	ChiNhapSo(a);
	gotoxy(13,9);
	ChiNhapSo(b);
	gotoxy(0,11);
	if ((a==0)&&(b==0))
		cout<<"Phuong trinh vo so nghiem.";
	else if ((a==0)&&(b!=0))
		cout<<"Phuong trinh vo nghiem.";
	else
	{
		x=(double)(-b)/a;
		cout<<"Nghiem phuong trinh: X= "<<x<<endl;
	}
}
void giaibac2(){
	int a=0;
	int b=0;
	int c=0;
	double k;
	cout<<"Nhap a,b,c:";
	double x1,x2;
	VeHCNRong(HCN (0,8),HCN (6,10));
	gotoxy(7,9);
	cout<<"*x*x + ";
	VeHCNRong(HCN (14,8),HCN (20,10));
	gotoxy(21,9);
	cout<<"*x + ";
	VeHCNRong(HCN (26,8),HCN (32,10));
	gotoxy(33,9);
	cout<<" = 0";
	gotoxy(1,9);
	ChiNhapSo(a);
	gotoxy(15,9);
	ChiNhapSo(b);
	gotoxy(27,9);
	ChiNhapSo(c);
	gotoxy(0,11);
	k=b*b-4*a*c;
	if (k<0)
	 cout<<"Phuong trinh vo nghiem.\n";
	else if (k>0)
	{
		x1=(-b+sqrt(k))/(2*a);
		x2=(-b-sqrt(k))/(2*a);
		cout<<"Phuong trinh co 2 nghiem: X1= "<<x1<<endl;
		cout<<"                          X2= "<<x2<<endl;
	}
	else if (k==0)
	{
	 	x1=(-b)/(2*a);
		cout<<"Nghiem phuong trinh: X= "<<x1<<endl;;
	}
}
int main(){
	cout<<std::setprecision(3);
	char* menu[maxlist];
	int pointer = 0;
	menu[0]= "1. Giai phuong trinh bac nhat a*x + b = 0";
	menu[1]= "2. Giai phuong trinh bac hai a*x*x + b*x + c = 0";
	menu[2]= "3. Thoat";
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		gotoxy(30,0);
		cout<<"---------------------- Menu ----------------------\n\n";
		for (int i=0; i<3; i++){
		 gotoxy(30,i+1);
		{
			if (i == pointer)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),23);
					cout<<" "<<menu[i]<<endl;
				}
			else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
					cout<<" "<<menu[i]<<endl;
				}
		}}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		gotoxy(30,5);
		cout<<"--------------------------------------------------\n\n";
		VeDuongThangDoc(29,1,5);
		VeDuongThangDoc(80,1,5);
		cout<<"\n\n";
		while (true)
		{
			if (kbhit())
			{
				char key = getch();
				if (key == 72)
				{
					pointer-=1;
					if (pointer == -1)
					{
						pointer = 2;
					}
					break;
				}
				else if (key == 80)
				{
					pointer+=1;
					if (pointer == 3)
					{
						pointer = 0;
					}
					break;
				}
				else if (key == 13)
				{
					if (pointer == 0)
					{
						giaibac1();
						system("pause");
						break;
					}
					else if (pointer == 1)
					{
						giaibac2();
						system("pause");
						break;
					}
					else if (pointer == 2)
					{
						exit(0);
					}
				}
				else if (key == 27){
					exit(0);
				}
			}
			Sleep(150);
		}
	}
	return 0;
}

