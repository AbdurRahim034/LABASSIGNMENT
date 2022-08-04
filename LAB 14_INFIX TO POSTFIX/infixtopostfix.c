#include <stdio.h>

char stack[20];
int top = -1;

void push(char value){
    top = top +1;
    stack[top]= value;
  //  printf("\n%c Inserted.\n",value);
}

char pop(){
    return stack[top--];
}

int precedent(char c){
    if(c=='+'|| c== '-')
    return 1;
    else if(c=='*' || c=='/')
    return 2;
    else if(c == '^')
    return 3;
    else
    return -1;

}

int main()
{
    while(1){
         int i;
    char a[20],c,x;
    printf("\nEnter the expression\n");
    gets(a);
    printf("The postfix expression is: \n");
    for(int i = 0; a[i] != '\0'; i++){
        c = a[i];
        if(precedent(c)>0){

            while(top != -1 && precedent(stack[top])>=precedent(c)){
                printf("%c",pop());
            }

             push(c);
        }

        else if(c== ')'){
            x = pop();
            while(x != '('){
                printf("%c",x);
                x = pop();
            }
        }

        else if( c == '('){
            push(c);
        }

        else
        printf("%c",c);

    }

     for(int i = 0; i<= top+1; i++){
          printf("%c",pop());
      }



    }

    return 0;
}
