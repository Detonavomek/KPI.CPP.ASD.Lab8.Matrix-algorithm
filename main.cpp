#include <iostream>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#define n1 25
#define n2 80
using namespace std;
HANDLE  hConsole;
void gotoxy(int xpos, int ypos)
{
  COORD scrn;    
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}
void main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 char A[n1][n2];
 int i=1,j,k,p=n1/2;
 for(k=1;k<=p;k++)
 {
	 for (j=k-1;j<n1-k+1;j++)
	 {
		 SetConsoleTextAttribute(hConsole, (k*j)%12+225);
		 gotoxy(k-1,n1-j-1); 
		 A[n1-j-1][k-1]='*'; 
		 cout<<A[n1-j-1][k-1]; 
		 Sleep(30);
	 }
	 for (j=k;j<n2-k;j++)
	 {
		 SetConsoleTextAttribute(hConsole, (k*j)%12+225);
		 A[k-1][j]='*'; 
		 cout<<A[k-1][j]; 
		 Sleep(30);
	 }
	 for (j=k-1;j<n1-k+1;j++)
	 {
		 SetConsoleTextAttribute(hConsole, (k*j)%12+225);
		 gotoxy(n2-k,j);  
		 A[j][n2-k]='*'; 
		 cout<<A[j][n2-k]; 
		 Sleep(30);
	 }
	 for (j=n2-k-1;j>k-1;j--)
	 {
		 SetConsoleTextAttribute(hConsole, (k*j)%12+225);
		 gotoxy(j,n1-k); 
		 A[n1-k][j]='*'; 
		 cout<<A[n1-k][j]; 
		 Sleep(30);
	 }
 }
 gotoxy(1,n1);
 getch();
}