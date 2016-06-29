#include <stdio.h>
#include <conio.h>

typedef struct{ int id;
	char name[20];
	int salary;
}E;

void input(E[],int);
void output(E[],int);

void main(){
	E employee[50];
	int n;
	printf("input n: "); scanf("%d",&n);
	input(employee,n);
	output(employee,n);
	getch();
}

void input(E emp[],int n){
	int i;

	for(i=0;i<n;i++){
		printf("id: ");
		scanf ("%d",&emp[i].id);
		printf("name: ");
		fflush(stdin);
		gets(emp[i].name);
		printf("salary: ");
		scanf("%d",&emp[i].salary);
	}

}
void output(E e[],int n){

	int i;
	puts("Id\tName\tSa1ary");
	for(i=0;i<n;i++)
	printf("%d\t%s\t%d\n",e[i].id,e[i].name,e[i].salary);
}
