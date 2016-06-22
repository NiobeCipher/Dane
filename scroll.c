#include <stdio.h>
#include <conio.h>

char ch,st;
int i,j,k,n;
char b[100][3][20];

void main()
{
	do{
	clrscr();
	printf("%s\n%s\n%s\n%s\n", "1 - Input","2 - Show","3 - Delete","4 - Exit");
	ch=getch();
	switch(ch)
	{
		case '1' :
		{
			do
			{
				clrscr();
				printf("%s", "Enter ID : ");
				scanf("%s",&b[n][0]);
				printf("%s", "Enter Title : ");
				scanf("%s",&b[n][1]);
				printf("%s", "Enter Qty : ");
				scanf("%s",&b[n][2]);
				n++;
				ch=getch();
			} while (ch!=27);
			break;
		}
		case '2' :
		{
			j=0;
			do{
				k=0;
				clrscr();
				printf("%s\t%40s\t%20s\n", "ID","Title","Qty");
				while(k<120)
				{
					printf("%c", 205);
					k++;
				}
				k=(n<3) ? n : 3;
				for(i=j;i<j+k;i++)
				{
					printf("%s\t%40s\t%20s\n", b[i][0], b[i][1], b[i][2]);
				}
				k=0;
				while(k<120)
				{
					printf("%c", 220);
					k++;
				}
				st=getch();
				if(st==72 && j>0) j--;
				if(st==80 && j+4<=n) j++;
			}while(st!=27);
			break;
		}
		case '4' : exit(0);
	}
	}while(ch!='q');
}
