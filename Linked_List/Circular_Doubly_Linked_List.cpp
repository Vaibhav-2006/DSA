#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head,*newptr;// using a rear pointer insertions become O(1). Check singly linked list for rear usage.
struct node* Create_node();
int count(struct node* ptr); 
void insertion_beginning(struct node*);  
void insertion_last(struct node*);  
void deletion_beginning();  
void deletion_last();  
void display();  
void search();  
int main()  
{  
int choice =0;  
    while(choice != 8)  
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in Beginning\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search\n6.Show\n7.Count\n8.Exit\n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insertion_beginning( Create_node());  
            break;  
            case 2:  
                    insertion_last(Create_node());  
            break;  
            case 3:  
            deletion_beginning();  
            break;  
            case 4:  
            deletion_last();  
            break;  
            case 5:  
            search();  
            break;  
            case 6:  
            display();  
            break;
			case 7:
			printf("Total count: %d",count(head));
			break;  
            case 8:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
struct node* Create_node()
{
	int item;
	newptr= (struct node*) malloc(sizeof(struct node)); 
	if(newptr==NULL)
	{
		printf("\nOVERFLOW");
		return NULL;
	}
	else{
	printf("\nEnter Item value:");
	scanf("%d",&item);
	newptr->data=item;
	newptr->next=NULL;
	newptr->prev=NULL;
	}
	return newptr;
}
int count(struct node* ptr)
{
	if(ptr==NULL)
	return 0;
	int i=1;
	while(ptr->next!=head)
	{
		ptr=ptr->next;
		i++;
	}
	return i;
}
void insertion_beginning(struct node* ptr)  
{  
   struct node *temp;     
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
   if(head==NULL)  
   {  
      head = ptr;  
      ptr -> next = head;   
      ptr -> prev = head;   
   }  
   else   
   {   
    head->prev-> next = ptr;  
    ptr -> prev = head->prev;  
    head -> prev = ptr;  
    ptr -> next = head;  
    head = ptr;  
   }  
   printf("\nNode inserted\n");  
}  
     
}  
void insertion_last(struct node *ptr)  
{   
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {    
       if(head == NULL)  
       {  
           head = ptr;  
           ptr -> next = head;   
           ptr -> prev = head;   
       }  
       else  
       {  
          head->prev->next=ptr;
          ptr->next=head;
          ptr->prev=head->prev;
          head->prev=ptr;
   }  
     printf("\nnode inserted\n");  
}  }
  
void deletion_beginning()  
{    
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == head)  
    {     
    newptr=head;
    head = NULL;
    free(newptr);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
      	newptr=head;
      	head->next->prev=head->prev;
      	head->prev->next=head->next;
       	head=head->next;  
        free(newptr);    
         printf("\nnode deleted\n");
    }  
  
}  
void deletion_last()  
{   
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == head)  
    {  
    newptr=head;
        head = NULL;   
        free(newptr);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
    newptr=head->prev;
        head->prev->prev->next=head;
        head->prev=head->prev->prev;
        free(newptr);
        newptr=NULL;
         printf("\nnode deleted\n");
    }  
}  
  
void display()  
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {  
        printf("\n printing values ... \n");  
          
        while(ptr -> next != head)  
        {  
          
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    } 
	printf("\n\n");
	printf("%d %d %d %d %d %d %d",head->data,head->prev->data,head->prev->prev->data,head->next->data,head->next->prev->data,head->prev->next->data,head->prev->prev->next->data); 
}
              
 
  
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag=1;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        if(head ->data == item)  
        {  
        printf("item found at location %d",i+1);  
        flag=0;  
        return;
        }  
        else if(head->prev->data==item){
        printf("item found at location %d\n",count(head));  
        flag=0;
		return;
		}
        else   
        {  
        while (ptr != head->prev)  
        {  
            if(ptr->data == item)  
            {  
                printf("item found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        }  
        if(flag != 0)  
        {  
            printf("Item not found\n");  
        }  
    }     
          
}  
