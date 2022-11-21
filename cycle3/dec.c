
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int isEmpty(int top, int stack_arr[]);
void push(int x, int *top, int stack_arr[]);
int pop(int *top, int stack_arr[]);
void DecToBin(int num);
void DecToHex(int num);
int quotient;
char hexadecimalNumber[100];

int main()
{
        int num;
        printf("Enter an integer : ");
        scanf("%d",&num);
        printf("Binary Equivalent is : ");
        DecToBin(num);
        DecToHex(num);
        return 0;

}/*End of main()*/

void DecToBin(int num)
{
        int stack[MAX], top=-1, rem;
        while(num!=0)
        {
                rem = num%2;
                push(rem, &top, stack);
                num/=2;
        }
        while(top!=-1)
                printf("%d", pop(&top, stack));
        printf("\n");
}

void DecToHex(int num)
{
	int stack[MAX],top=-1,rem1;
	int i,j=0;
	while(num!=0)
	{
		rem1=num%16;
        if (rem1< 10)
           quotient = 48 + rem1;
        else
            quotient = 55 + rem1;
        num = num / 16;
        hexadecimalNumber[i++]=quotient;
		printf("Equivalent hexadecimal value of decimal number %d: ",num);
	for (j = i -1 ;j> 0;j--)
	      printf("%c",hexadecimalNumber[j]);
 
        
	}
}


void push(int x, int *top, int stack_arr[])
{
        if(*top == (MAX-1))
                printf("Stack Overflow\n");
        else
        {
                *top=*top+1;
                stack_arr[*top] = x;
        }
}/*End of push()*/

int pop(int *top, int stack_arr[])
{
        int x;
        if(*top == -1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        else
        {
                x = stack_arr[*top];
                *top=*top-1;
        }
        return x;
}