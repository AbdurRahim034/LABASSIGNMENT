#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void create();
void add_first();
void insert_var();
void display();
void  insertAtEnd();
void removeBeginning();
void  removeEnd();

struct Node
{
    int reg;
    int data;
    char name[50];
    char study_center[50];
    char sem[10];
    char phone_num[11];
    struct Node *next;
}*head = NULL;

 int reg;
    int data;
    char name[50];
    char study_center[50];
    char sem[10];
    char phone_num[11];
    
    int temp; // extra variable for avoid taking string after integer
    //source: 
    // https://www.includehelp.com/c/c-program-to-read-string-with-spaces-using-scanf-function.aspx


int main(){
   
  
    int choice;
   create();
   while(1){
  printf("\n\n****** MENU ******\n1.Insert First\t2.Inst End\t3.Dlt First\n4.Dlt last\t\t5.Display\t6.Exit\nEnter your choice: ");
   scanf("%d",&choice);
   switch(choice)
   {
      
		
		   case 1: 	
		   printf("Enter the  value: ");
		   insert_var();
		   add_first();
			break;
		   case 2: 	
		   printf("Enter the  value: ");
		   insert_var();
		  insertAtEnd();
			break;
		   case 3:
		  removeBeginning();
			break;
		   case 4: 	
		   removeEnd();
				break;
		   
			
		case 5: display();
		break;
      case 6: 	exit(0);
      default: printf("\nWrong input!!! Try again!!\n\n");
  
   }
}
    
    
    return 0;
}

void create(){
    printf("How many element do you want to Enter?\n");
    
    int i, n=0;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        insert_var();
        add_first();
    }
    
  //  display();
    
    
}

void add_first(){
    struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   
   newNode->reg = reg;
  // printf(" %d\n",newNode->reg);
   strcpy(newNode->name, name);
 //  puts(newNode->name);
   strcpy(newNode->study_center, study_center);
//    puts(newNode->study_center);
   strcpy(newNode->sem, sem);
//   puts(newNode->sem);
   strcpy(newNode->phone_num, phone_num);
 //  puts(newNode->phone_num);
   
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
   
   display();
}



void insertAtEnd()
{
    
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   
   newNode->reg = reg;
 //  printf(" %d\n",newNode->reg);
   strcpy(newNode->name, name);
 //  puts(newNode->name);
   strcpy(newNode->study_center, study_center);
  //  puts(newNode->study_center);
   strcpy(newNode->sem, sem);
 //  puts(newNode->sem);
   strcpy(newNode->phone_num, phone_num);
//   puts(newNode->phone_num);
   
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


void insert_var(){
   
    printf("Enter values. Reg :");
    scanf("%d",&reg);
   // printf("%d", reg);
   scanf("%c",&temp); // temp statement to clear buffer

     printf("\nName :");
    fgets(name, 50, stdin);
  //  puts(name);
     printf("Study Center : ");
    fgets(study_center, 50, stdin);
   // puts(study_center);
     printf("Semester : ");
    fgets(sem, 10, stdin);
   // puts(sem);
     printf("Phone Number : ");
    fgets(phone_num, 11, stdin);
   // puts(phone_num);
     
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



void display(){
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
	
	 puts(temp->name);
	  puts(temp->study_center);
	   puts(temp->sem);
	    puts(temp->phone_num);
	     printf("%d --->",temp->reg);
	 temp = temp->next;
      }
      
       puts(temp->name);
	  puts(temp->study_center);
	   puts(temp->sem);
	    puts(temp->phone_num);
	    printf("%d --->NULL",temp->reg);
   }
}
