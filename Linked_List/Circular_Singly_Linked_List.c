//Circular linked list has two representations.
//The Abdul bari folder contains the first representation where head in itself
//is a node. This is the second representation where head is just a struct node pointer
//pointing to a dynamically created node in heap.

#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head,*rear,*newptr;  
struct node* Create_node();
int count(struct node* ptr);      
void beginsert (struct node*);   
void lastinsert (struct node*);  
void randominsert(struct node*);  
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  
void search();
//random_insert and random_delete will be same as in singly and doubly linked list.  
void main ()  
{  
    int choice =0;  
    while(choice != 8)   
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search for an element\n6.Show\n7.Count\n8.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            beginsert(Create_node());      
            break;  
            case 2:  
            lastinsert(Create_node());         
            break;  
            case 3:  
            begin_delete();       
            break;  
            case 4:  
            last_delete();        
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
	newptr->next=NULL;}
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
void beginsert(struct node* ptr)  
{      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else   
    {   
        if(head == NULL)  
        {  
            head =rear= ptr;  
            ptr -> next = head;  
        }  
        else   
        {     
            ptr->next = head;   
            head = ptr;
            rear->next=head;
        }   
        printf("\nnode inserted\n");  
    }  
              
}  
void lastinsert(struct node* ptr)  
{    
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        if(head == NULL)  
        {  
            head = rear=ptr;  
            ptr -> next = head;    
        }  
        else  
        {  
			rear->next=ptr;
			ptr->next=head;
			rear=ptr; 
        }  
        printf("\nnode inserted\n");  
    }  
  
}  
  
void begin_delete()  
{  
    struct node *ptr;   
    if(head == NULL)  
    {  
        printf("\nUNDERFLOW");    
    }  
    else if(head == rear)  
    {  
    ptr=head;
        head = rear=NULL;  
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
    else  
    {   
	  ptr=head;
	  head=head->next;
	  rear->next=head;
	  free(ptr);
        printf("\nnode deleted\n");  
    }  
}  
void last_delete()  
{  
    struct node *ptr;  
    if(head==NULL)  
    {  
        printf("\nUNDERFLOW");  
    }  
    else if (head  == rear)  
    {  
    ptr=head;
        head = rear=NULL;  
        free(ptr);  
        ptr=NULL;
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        ptr = head;  
        while(ptr->next != rear)  
        {    
            ptr = ptr->next;  
        }  
        free(ptr->next);
        ptr->next = head;   
		rear=ptr; 
        printf("\nnode deleted\n");  
  
    }  
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
        else if(rear->data==item){
        printf("item found at location %d\n",count(head));  
        flag=0;
		return;
		}
        else   
        {  
        while (ptr != rear)  
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
          do{
          	printf("%d ",ptr->data);
          	ptr=ptr->next;
		  } while(ptr!=head);
    }  
              
}
