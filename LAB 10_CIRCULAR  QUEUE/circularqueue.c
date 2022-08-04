#include <stdio.h>


#define size 5

 int arr[size],R=-1,F=0,te=0;
 int ch,n,i;
 
 void enQue(){
     if(te==size)
                {
                    printf("Queue is full");
                  
                }
                else
                {
                    printf("Enter a number ");
                    scanf("%d",&n);
                    R=(R+1)%size;
                    arr[R]=n;
                    te=te+1;
                    printf("You have entered %d",arr[R]);
                }
                 printf("\n");
                 
                 display();
                
     
 }
 
 void deQue(){
      if(te==0)
                {
                    printf("Queue is empty");
                   
                }
                else
                {
                    printf("Number Deleted = %d",arr[F]);
                    F=(F+1)%size;
                    te=te-1;
                    
                }
                 printf("\n");
                 display();
 }
 
 void display(){
     int x;
 
      if(te==0)
                {
                    printf("Queue is empty");
                    
                }
                else
                {
                    printf("Values in Queue are:     ");
                    x=F;
                    for(i=1; i<=te; i++)
                    {
                        printf("%d ",arr[x]);
                        x=(x+1)%size;
                    }
                    
                    printf("\n");
                    
                }
 }

int main()
{
   

    for(;;)		// An infinite loop
    {
       
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                enQue();
                break;

            case 2:
               deQue();
                break;

            case 3:
               display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Wrong Choice");
                
        }
    }
    return 0;
}