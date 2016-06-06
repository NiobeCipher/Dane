#include<Pich.h>

void output();
void find();
void del();
void insert();
void sort(int);
void writetofile();
int readfromfile();
void password();
void loaderanim();
void menu();

FILE *Dane;

//void update(char,int,float);
char name[20][30],npas[]="haydane";
int id[20],unit[20],n,i,j,h;
float pri[20];
void main()
{
    clrscr();
    n=readfromfile();
    password();
}
void menu()
{
    nene:
    clrscr();
    n=readfromfile();
	puts("1. Output");
    puts("2. Search ID");
    puts("3. Delete ID");
    puts("4. Insert");
    puts("5. Sort");
    puts("6. Update");
    switch(getch())
    {
        case'1':
            {
                output();
                break;
            }
        case'2':
            {
                find();
                break;
            }
        case'3':
            {
                del();
                break;
            }
        case'4':
            {
                insert();
                break;
            }
        default :
            {
                menu();
            }
    }
    getch();
    goto nene;
}

	//function

void writetofile()
{
    int i;
    Dane=fopen("Dane.txt","w");
    for(i=1;i<=n;i++)
    {
        fprintf(Dane,"%d\t%s\t%d\t%.2f\n",id[i],name[i],unit[i],pri[i]);
    }
    fclose(Dane);
}

int readfromfile()
{
    int i,nb;
    Dane=fopen("Dane.txt", "r");
    for(i=1,nb=0;i<=20;i++,nb++)
    {
        fscanf(Dane,"%d\t%s\t%d\t%f\n",&id[i],&name[i],&unit[i],&pri[i]);
        if(id[i] == NULL || id[i] < 1 || id[i] > 20)break;
    }
    fclose(Dane);
    return nb;
}

   //output
void output()
{
    int s=0;
    for(i=1;i<=n;i++)id[i]=0;
    n=readfromfile();
    a:
    clrscr();
    puts("=============================");
    if(s==0)puts("ID\tName\tUnit\tPrice");
    else if(s==1)
    {
        textcolor(4);
        cprintf("ID");
        puts("\tName\tUnit\tPrice");
    }
    else if(s==2)
    {
        textcolor(4);
        printf("ID\t");
        cprintf("Name");
        puts("\tUnit\tPrice");
    }
    else if(s==3)
    {
        textcolor(4);
        printf("ID\tName\t");
        cprintf("Unit");
        puts("\tPrice");
    }
    else if(s==4)
    {
        textcolor(4);
        printf("ID\tName\tUnit\t");
        cprintf("Price");
        puts("");
    }
    puts("=============================");
    for(i=1;i<=n;i++)
    {
        printf("%d\t%s\t%d\t$%.2f\n",id[i],name[i],unit[i],pri[i]);
	}
    puts("=============================");
	switch(getch())
	{
    case '1' :
        {
            sort(1);
            s=1;
            goto a;
        }
    case '2' :
        {
            sort(2);
            s=2;
            goto a;
        }
    case '3' :
        {
            sort(3);
            s=3;
            goto a;
        }
    case '4' :
        {
            sort(4);
            s=4;
            goto a;
        }
    case 'x' :
        {
            menu();
        }
    default :
        {
            s=0;
            output();
        }
	}
}
	//search
void find()
{
    clrscr();
    int newid,a=0;
	printf("\nSearch by ID: ");
  	scanf("%d",&newid);
    for(i=1;i<=n;i++)
   	if(newid==id[i])
   	{
        a=1;
        printf("Result:\n");
        printf("ID : %d\n",id[i]);
        printf("Name : %s\n",name[i]);
        printf("Unit : %d\n",unit[i]);
        printf("Price : $%.2f\n",pri[i]);
   	}
    if(a==0)
   		puts("No Result");
}
	//Delete
void del()
{
    int newid,a=0;
    clrscr();
	printf("Delete ID: ");
  	scanf("%d",&newid);
		for(i=1;i<=n;i++)
        {
            if(newid==id[i])
            {
                n--;
                for(j=i;j<=n;j++)
                {
                    id[j]=id[j+1];
                    strcpy(name[j],name[j+1]);
                    unit[j]=unit[j+1];
                    pri[j]=pri[j+1];
                    a=1;
                }
                i--;
            }
        }
        if(a==1)puts("Delete Successful");
        else if(a==0)puts("Not Found");
        writetofile();
}
   //Insert
void insert()
{
    clrscr();
    n=readfromfile();
    for(i=n;i>=1;i--)
    {
  		id[i+1]=id[i];
        strcpy(name[i+1],name[i]);
  		unit[i+1]=unit[i];
  		pri[i+1]=pri[i];
    }
	printf("ID: ");scanf("%d",&id[1]);
    printf("Name: ");fflush(stdin);gets(name[1]);
    printf("Unit: ");scanf("%d",&unit[1]);
    printf("Price: ");scanf("%f",&pri[1]);

    n++;

    Dane=fopen("Dane.txt","w");
    for(i=1;i<=n;i++)
    {
        fprintf(Dane,"%d\t%s\t%d\t%.2f\n",id[i],name[i],unit[i],pri[i]);
    }
    fclose(Dane);
}

	//sorts

void sort(int h)
{
    int j,t,nunit;
    char nname[20];
    float npri;
    n=readfromfile();
    clrscr();
    for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
            if((h==1 && id[i]>id[j]) || (h==2 && strcmp(name[i],name[j])>0) ||  (h==3 && unit[i]>unit[j]) || (h==4 && pri[i]>pri[j]))
            {
				t=id[i];
				id[i]=id[j];
                id[j]=t;

				strcpy(nname,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],nname);

				nunit=unit[i];
				unit[i]=unit[j];
				unit[j]=nunit;

                npri=pri[i];
				pri[i]=pri[j];
				pri[j]=npri;
            }
}

void password()
{
    char pas[8],ch;
    int z=0,y;


    clrscr();
    printf("enter password: ");
    //scanf("%s",&pas);
    do
    {
        ch=getch();
        if(ch!=13 && ch!=8)
        {
            putch('*');
            pas[z] = ch;
            z++;
        }
    }while(ch!=13);
    pas[z] = '\0';
    y=strcmp(pas,npas);
    if(y==0)
    {
        loaderanim();
        menu();
    }
    else if(y!=0)
    {
        printf("\nwrong password");
        Sleep(800);
        password();
    }
}


void loaderanim()
{
   int loader;
   system("cls");
   gotoxy(50,10);
   printf("LOADING........");
   for(loader=52;loader<=72;loader++)
   {
       gotoxy(loader,11);Sleep(50);printf("%c",219);
       gotoxy(66,10);printf("%d%%",(loader-51)*5);
   }
}



