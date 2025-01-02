#include<stdio.h>
int RecursiveGCD(int a,int b)
{
    if(b==0){
        return a;
    }
    else{
        return RecursiveGCD(b,a%b);
    }
}
int main()
{
    int x,y;
    printf("Enter the numbers whose GCD you want::");
    scanf("%d %d",&x,&y);
    printf("The GCD of %d and %d is %d.",x,y,RecursiveGCD(x,y));
}