#include <stdio.h>

#define SIZE 10
int stack[SIZE], top=-1,n;

void create(){
    int i;
    printf("How many element do you want to push?\n");
    scanf("%d",&n);
    printf("Enter Value.\n");
    for(i = top+1; i<top+n+1; i++){
        scanf("%d",&stack[i]);
    }
    top = i-1;
    display();
}

void push(int value){
    if(top == SIZE -1){
        printf("The stack is Full\n");
    }
    else{
        top++;
        stack [top]= value;
        printf("Value Inserted.\n");
    }
    
    display();
}

void pop(){
    if (top==-1){
        printf ("Stack is Empty.\n");
    }
    else{
        top--;
    }
    
    display();
}

void display(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("Values are:\n");
        for(int i = top; i>=0; i--){
            
            printf("%d  ", stack[i]);
        }
        
        printf("\n");
    }
}



int main() {

    int value, choice; 
   // printf("Create Stack\n");
   // create();
    while(1){ 
    printf("\n\n***** MENU *****\n"); printf("1. Push\n2. Pop\n3. Display\n4. Exit\n5. Create"); 
    printf("\nEnter your choice: ");             scanf("%d",&choice); 
    switch(choice){      
    case 1: printf("Enter the value to be insert: ");          
    scanf("%d",&value);          
    push(value);          
    break;      
    case 2: 
    pop();          
    break;      
    case 3: 
    display();          
    break;      
    case 4: 
    exit(0); 
    case 5:
    create();
    default: 
    printf("\nWrong selection!!! Try again!!!"); 
    } 
   }
    return 0;
}

