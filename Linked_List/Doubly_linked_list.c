#include<stdio.h>  
#include<stdlib.h>  


struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
}*head,*rear,*newptr;  
struct node* Create_node();
int count(struct node* ptr);  
void insertion_beginning(struct node*);  
void insertion_last(struct node*);  
void insertion_specified(struct node*);  
void deletion_beginning();  
void deletion_last();  
void deletion_specified();  
void display();  
void search();  

void Reverse(struct node *p)
{
struct node *temp;
while(p!=NULL)
{
temp=p->next;
p->next=p->prev;
p->prev=temp;
p=p->prev;
if(p!=NULL && p->next==NULL)
head=p;
}
}

void main ()  
{  
int choice =0;  
    while(choice != 10)  
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node having given data\n7.Search\n8.Show\n9.Count\n10.Exit\n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insertion_beginning(Create_node());  
            break;  
            case 2:  
                    insertion_last(Create_node());  
            break;  
            case 3:  
            insertion_specified(Create_node());  
            break;  
            case 4:  
            deletion_beginning();  
            break;  
            case 5:  
            deletion_last();  
            break;  
            case 6:  
            deletion_specified();  
            break;  
            case 7:  
            search();  
            break;  
            case 8:  
            display();  
            break;  
            case 9:  
            printf("Total nodes:%d",count(head));
            break;
            case 10:
            break;  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
int count(struct node* ptr)
{
	int i=0;
	while(ptr)
	{
		ptr=ptr->next;
		i++;
	}
	return i;
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
	newptr->next=newptr->prev=NULL;}
	return newptr;
}
void insertion_beginning(struct node* ptr)  
{   
	if(ptr==NULL)
	{
		printf("\nOVERFLOW");
	}
   else if(head==NULL)  
   {      
       head=rear=ptr;  
   }  
   else   
   {  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("\nNode inserted\n");  
}  
     
void insertion_last(struct node* ptr)  
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
       }  
       else  
       {  
			rear->next=ptr;
			ptr->prev=rear;
			rear=ptr;
       }  
     printf("\nnode inserted\n");  
    }  
	}
void insertion_specified(struct node* ptr)  
{  
   struct node *temp;  
   int loc,i;  
   if(ptr == NULL)  
   {  
       printf("\n OVERFLOW");  
   }  
   else  
   {  
       temp=head;  
       printf("Enter the location: ");  
       scanf("%d",&loc);  
       if(loc==1)
	   insertion_beginning(ptr);
       else if(loc==(count(head)+1))
       insertion_last(ptr);
       else if(loc>count(head)+1)
       printf("\nInsertion request out of bounds\n");
       else{
       for(i=1;i<loc;i++)  
       {  
           temp = temp->next;   
       }
       ptr->next = temp; 
	   ptr->prev=temp->prev; 
	   temp->prev->next=ptr;
       temp->prev= ptr;    
       printf("\nnode inserted\n");  
}  
}
}
void deletion_beginning()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head==rear)  
    {  
    	ptr=head;
        head = rear=NULL;   
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
  
}  
void deletion_last()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
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
	ptr=rear;
	rear=rear->prev;
	rear->next=NULL;
	free(ptr); 
	printf("\nnode deleted\n");
    }  
}  
void deletion_specified()  
{  
    struct node *ptr=head, *temp;  
    int val;  
    printf("\nEnter the data of the node to be deleted : ");  
    scanf("%d", &val);  
    if(head->data==val)
	deletion_beginning();
	else if(rear->data==val)
	deletion_last(); 
	else{
    while(ptr -> data != val&&ptr!=NULL)  
    ptr = ptr -> next; 
	if(ptr==NULL)
	printf("\nNo match found for the entered value\n");
	else{
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		free(ptr);
	printf("\nnode deleted\n");
	}  
    }    
}  
void display()  
{  
    struct node *ptr;  
    printf("\n printing values...\n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr=ptr->next;  
    }  
}   
void search()  
{  
    struct node *ptr;  
    int item,i=1,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nitem found at location %d ",i);  
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
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}  

