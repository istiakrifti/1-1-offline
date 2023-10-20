#include<stdio.h>

int dayOFweek(int y,int m,int q);

int main()
{
    int q,m,y,check;

    printf("Enter year:");
    scanf("%d",&y);

    printf("Enter month(1-12):");
    scanf("%d",&m);

    printf("Enter day:");
    scanf("%d",&q);

    check=dayOFweek(y,m,q);

    if(m==1)
    {
        printf("\nJANUARY ");
    }
    if(m==2)
    {
        printf("\nFEBRUARY ");
    }
    if(m==3)
    {
        printf("\nMARCH ");
    }
    if(m==4)
    {
        printf("\nAPRIL ");
    }
    if(m==5)
    {
        printf("\nMAY ");
    }
    if(m==6)
    {
        printf("\nJUNE ");
    }
    if(m==7)
    {
        printf("\nJULY ");
    }
    if(m==8)
    {
        printf("\nAUGUST ");
    }
    if(m==9)
    {
        printf("\nSEPTEMBER ");
    }
    if(m==10)
    {
        printf("\nOCTOBER ");
    }
    if(m==11)
    {
        printf("\nNOVEMBER ");
    }
    if(m==12)
    {
        printf("\nDECEMBER ");
    }

    if(check==0)
    {
        printf("%d,%d is SATURDAY\n",q,y);
    }
    if(check==1)
    {
        printf("%d,%d is SUNDAY\n",q,y);
    }
    if(check==2)
    {
        printf("%d,%d is MONDAY\n",q,y);
    }
    if(check==3)
    {
        printf("%d,%d is TUESDAY\n",q,y);
    }
    if(check==4)
    {
        printf("%d,%d is WEDNESDAY\n",q,y);
    }
    if(check==5)
    {
        printf("%d,%d is THURSDAY\n",q,y);
    }
    if(check==6)
    {
        printf("%d,%d is FRIDAY\n",q,y);
    }

    return 0;
}

int dayOFweek(int y,int m,int q)
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
    h=(q+a+y+b+(6*x)+z)%7;

    return h;
}
