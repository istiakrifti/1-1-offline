#include<stdio.h>

int calender(int y,int m);
int firstDay(int y,int m);

int main()
{
    int y,m;

    printf("Enter year:");
    scanf("%d",&y);

    printf("Enter month(1-12):");
    scanf("%d",&m);

    calender(y,m);

    return 0;
}

int calender(int y,int m)
{
    int w=0,day,i,j;

    printf("\n  Calender for:\n\n");

    if(m==1)
    {
        printf("  JANUARY,%d\n",y);
    }
    if(m==2)
    {
        printf("  FEBRUARY,%d\n\n",y);
    }
    if(m==3)
    {
        printf("  MARCH,%d\n\n",y);
    }
    if(m==4)
    {
        printf("  APRIL,%d\n\n",y);
    }
    if(m==5)
    {
        printf("  MAY,%d\n\n",y);
    }
    if(m==6)
    {
        printf("  JUNE,%d\n\n",y);
    }
    if(m==7)
    {
        printf("  JULY,%d\n\n",y);
    }
    if(m==8)
    {
        printf("  AUGUST,%d\n\n",y);
    }
    if(m==9)
    {
        printf("  SEPTEMBER,%d\n\n",y);
    }
    if(m==10)
    {
        printf("  OCTOBER,%d\n\n",y);
    }
    if(m==11)
    {
        printf("  NOVEMBER,%d\n\n",y);
    }
    if(m==12)
    {
        printf("  DECEMBER,%d\n\n",y);
    }

    printf("  SUN  MON  TUE  WED  THU  FRI  SAT\n");

    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        day=31;
    }
    if(m==4 || m==6 || m==9 || m==11)
    {
        day=30;
    }
    if(m==2)
    {
        if(y%400==0 ||(y%4==0 && y%100!=0))
        {
            day=29;
        }
        else
        {
            day=28;
        }
    }
    w=firstDay(y,m);

    for(j=1; j<=w; j++)
    {
        printf("     ");
    }

    for(i=1; i<=day; i++)
    {
        printf("%5d",i);
        w++;
        if(w>=7)
        {
            w=0;
            printf("\n");
        }
    }
}

int firstDay(int y,int m)
{
    int h,a,b,x,z;

    if(m==1 || m==2)
    {
        m=m+12;
        y=y-1;
    }

    a=(int)(26*(m+1))/10;
    b=(int)(y/4);
    x=(int)(y/100);
    z=(int)(y/400);
    h=(a+y+b+(6*x)+z)%7;

    return h;
}


