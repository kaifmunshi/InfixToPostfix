/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
    int rank=0;
    char infix_[20];
    int top=-1;
    int postfix_index=0;
   
    
    int infix_index=0;
    char stack[20];
    char postfix_[20];
    int input_prece(char a)
    {
        if(a=='*'|| a=='/')
        {
            return 3;
        }
        else if(a=='+'|| a=='-')
        {
            return 1;
        }
        else if(a>=65 && a<=96 || a>=97 && a<=123)
        {
            return 7;
        }
        else if(a=='(')
        {
            return 9;
        }
        else if(a==')')
        {
            return 0;
        }
        else if(a=='^')
        {
           return 6; 
        }
        else 
        {
            return -1;
        }
    }
    int stack_prece(char a)
    {
        if(a=='*'|| a=='/')
        {
            return 4;
        }
        else if(a=='+'|| a=='-')
        {
            return 2;
        }
        else if(a>=65 && a<=96 || a>=97 && a<=123)
        {
            return 8;
        }
        else if(a=='(')
        {
            return 0;
        }
        else if(a==')')
        {
            return -1;
        }
        else if(a=='^')
        {
           return 5; 
        }
        else 
        {
            return -1;
        }
        return -1;
    }
    int rank_(char a)
    {
        if(a=='*'|| a=='/')
        {
            return -1;
        }
        else if(a=='+'|| a=='-')
        {
            return -1;
        }
        else if(a>=65 && a<=123)
        {
            return 1;
        }
        
        else if(a=='^')
        {
           return -1; 
        }
        else 
        {
            return -1;
        }
    }
    char next_char()
    {
        char next=infix_[infix_index];
        infix_index++;
        return next;
    }
    int push_(char a)
    {
        top++;
        stack[top]=a;
        
    }
    int pop_()
    {
        char a=stack[top];
        top--;
        return a;
    }
int main()
{
    
    char next;
    int str_len=0;
    printf("Enter any infix");
    scanf("%s",infix_);
    str_len=strlen(infix_);
    top++;
    stack[top]='(';
    
     infix_[str_len] = ')';
      next=next_char();
    while(next!= NULL)
    {
        if(top<0)
        {   
        printf("invalid expression");
        }
       // printf("\n%d < %d",input_prece(next),stack_prece(stack[top]));
        while(input_prece(next)<stack_prece(stack[top]))
        {
          char temp=pop_();
          postfix_[postfix_index]=temp;
          postfix_index++;
          rank+=rank_(temp);
          if(rank<1)
          {
              printf("Invalid expression");
              return -1;
          }
        }
        if(input_prece(next)!=stack_prece(stack[top]))
        {
            push_(next);
        }
        else
        {
            pop_();
        }
        next=next_char();
    }
    printf("%s",postfix_);
    
}


