#include<stdio.h>
#include<stdlib.h>
void create();
void insertAtBeginning(int);
void insertAtEnd(int);
void insertBetween(int,int);
void display();
void removeBeginning();
void removeEnd();
void removeSpecific(int);

struct Node
{
    int data;
    struct Node *next;
}*head = NULL;

void main()
{
    int choice,value,loc1,loc2;
   create();
   while(1){
  printf("\n\n****** MENU ******\n1.Insert First\t2.Inst End\t3.Inst Btwn\t4.Dlt First\n5.Dlt last\t\t6.Dlt fix\t7.Display\t8.Exit\nEnter your choice: ");
   scanf("%d",&choice);
   switch(choice)
   {
      
		
		   case 1: 	
		   printf("Enter the  value: ");
		   scanf("%d",&value);
		   insertAtBeginning(value);
			break;
		   case 2: 	
		   printf("Enter the  value: ");
		   scanf("%d",&value);
		   insertAtEnd(value);
			break;
		   case 3:
		   printf("Enter the the value where you wanto insert: ");
				scanf("%d",&loc1);
				printf("Enter the  value: ");
		   scanf("%d",&value);
				insertBetween(value,loc1);
				break;
		   case 4: 	removeBeginning();
				break;
		   case 5: 	removeEnd();
				break;
		   case 6: printf("Enter the value which you wanto delete: ");
				scanf("%d",&loc2);
				removeSpecific(loc2);
				break;
		case 7: display();
		break;
      case 8: 	exit(0);
      default: printf("\nWrong input!!! Try again!!\n\n");
  
   }
}
}

void create(){
    printf("How many values you want to enter: ");
    int i,n,value;
    scanf("%d",&n);
    printf("Enter values: ");
    for( i=0; i<n; i++){
         scanf("%d",&value);
    struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(head == NULL)
   {
      newNode->next = NULL;
      head = newNode;
   }
   else
   {
      newNode->next = head;
      head = newNode;
   }
    }
      display();
}

void insertAtBeginning(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(head == NULL)
   {
      newNode->next = NULL;
      head = newNode;
   }
   else
   {
      newNode->next = head;
      head = newNode;
   }
   printf("One node inserted!!!\n");
   display();
}
void insertAtEnd(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode->next = NULL;
   if(head == NULL)
	head = newNode;
   else
   {
      struct Node *temp = head;
      while(temp->next != NULL)
	temp = temp->next;
      temp->next = newNode;
   }
   printf("\nOne node inserted!!!\n");
   display();
}
void insertBetween(int value, int loc1)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(head == NULL)
   {
   
      printf("\nList is empty. Use insert first or insert last option!!!\n");
   }
   else
   {
      struct Node *temp = head;
      while(temp->data != loc1  ){
	    
	  //  printf("******  %d  *******\n",temp->data);
	    
	    if(temp->next == NULL)
	     break;
	     temp = temp->next;
	     
	     
      }
      
     //  printf("####  %d  ####\n",temp->data);
	  //  int x = temp->data;
	   // printf("X = %d\n",x);
    if(temp->data != loc1){
    
     printf("Not Possible to insert\n");
   
    }
    else{
     newNode->next = temp->next;
      temp->next = newNode;
      printf("\nOne node inserted!!!\n");
}

     
   }
   
   display();
}

void removeBeginning()
{
   if(head == NULL)
	printf("\n\nList is Empty!!!");
   else
   {
      struct Node *temp = head;
      if(head->next == NULL)
      {
	 head = NULL;
	 free(temp);
      }
      else
      {
	head = temp->next;
	free(temp);
	printf("One node deleted!!!\n");
      }
   }
   display();
}
void removeEnd()
{
   if(head == NULL)
   {
      printf("\nList is Empty!!!\n");
   }
   else
   {
      struct Node *temp1 = head,*temp2;
      if(head->next == NULL)
	head = NULL;
      else
      {
	 while(temp1->next != NULL)
	 {
	    temp2 = temp1;
	    temp1 = temp1->next;
	 }
	 temp2->next = NULL;
      }
      free(temp1);
      printf("\nOne node deleted!!!\n\n");
   }
   display();
}
void removeSpecific(int delValue)
{
   struct Node *temp1 = head, *temp2;
   while(temp1->data != delValue)
   {
     if(temp1 -> next == NULL){
	printf("\nGiven node not found in the list!!!");

     }
     temp2 = temp1;
     temp1 = temp1 -> next;
   }
   temp2 -> next = temp1 -> next;
   free(temp1);
   printf("\nOne node deleted!!!\n\n");
   display();

}
void display()
{
   if(head == NULL)
   {
      printf("\nList is Empty\n");
   }
   else
   {
      struct Node *temp = head;
      printf("List elements are - \n");
      while(temp->next != NULL)
      {
	 printf("%d --->",temp->data);
	 temp = temp->next;
      }
      printf("%d --->NULL",temp->data);
   }
}