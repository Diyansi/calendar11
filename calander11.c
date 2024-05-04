#include<stdio.h>
#include<conio.h>
#include<windows.h>

int getkey();
void display(int,int,int,int[]);
void calendar(int,int);

void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void SetColor(int ForgC)
{
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


char *month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
char *week[]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

int main()
{
    int nmonth,nyr,ch;
    enteryear:
    while(1)
    {
        printf("Enter year and month(number):" );
        scanf("%d%d",&nyr,&nmonth);
        if(nyr<1945)
        {

            printf("\n\t Please enter year above 1945\n");
            continue;
        }
        else
        {

            calendar(nyr,nmonth);
        }
        

    }
    getch();
    return 0;
}


//============== DISPLAYING THE  CALENDAR ===================
void display(int nyr,int nmonth,int tdays,int days[])
{
    int i,j,pos;
    SetColor(12); //Color red
    gotoxy(56,6);printf("%s %d",month[nmonth-1],nyr);
    for(i=0,pos=30;i<7;i++,pos+=10)
    {
         if(i==6)
            SetColor(9); //Sunday color blue
         else
            SetColor(10);  //Others day color green
        gotoxy(pos,8);printf("%s",week[i]);
    }

    SetColor(15); //setting the color white

   tdays++; 
    if(tdays==0 || tdays==7)
        pos=91; //if tdays is 0 or 7, position is sunday
    if(tdays==1)
        pos=31; //if tdays is 1, position is monday
    if(tdays==2)
        pos=41;  //if tdays is 2, position is tuesday
    if(tdays==3)
        pos=51;  //if tdays is 3, position is wednesday
    if(tdays==4)
        pos=61;  //if tdays is 4, position is thursday
    if(tdays==5)
        pos=71;  //if tdays is 5, position is friday
    if(tdays==6)
        pos=81;  //if tdays is 6, position is saturday

    for(i=0,j=10,pos;i<days[nmonth-1];i++,pos+=10)
    {
        if(pos==91)
            SetColor(8); 
        else
            SetColor(7); 
        gotoxy(pos,j);printf("%d",i+1);
        if(pos==91)
        {
            pos=21; 
            j++; 
        }
    }

    SetColor(5); //Changing color to purple

    //Drawing horizontal line
    for(i=22;i<102;i++)
    {
        gotoxy(i,4);printf("%c",196);
        gotoxy(i,17);printf("%c",196);
    }

    //Drawing all the corner of the rectangle
    gotoxy(21,4);printf("%c",218);
    gotoxy(102,4);printf("%c",191);
    gotoxy(21,17);printf("%c",192);
    gotoxy(102,17);printf("%c",217);

    //Drawing vertical line
    for(i=5;i<17;i++)
    {
        gotoxy(21,i);printf("%c",179);
        gotoxy(102,i);printf("%c",179);
    }

    SetColor(11); //Changing color to aqua

    //Drawing left and the right navigation symbol
    gotoxy(24,11);printf("%c",174);
    gotoxy(98,11);printf("%c",175);

}



//============ Calculating ====================
void calendar(int nyr,int nmonth)
{
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int tdays=0,k,myear;
    system("cls");
    myear=nyr-1; 
            if(myear>=1945)
            {
                for(k=1945;k<=myear;k++)
                {
                    if(k%4==0) 
                        tdays=tdays+366;
                    else 
                        tdays=tdays+365;
                }
            }

            if(nyr%4==0)
                days[1]=29; 
            else
                days[1]=28; 

            for(k=0;k<(nmonth-1);k++)
            {

                tdays=tdays+days[k];
            }

            tdays=tdays%7; 
            display(nyr,nmonth,tdays,days); 
}
