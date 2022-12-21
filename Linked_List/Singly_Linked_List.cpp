#include<iostream>
#include<process.h>
#include<stdlib.h>
using namespace std;


struct Student{
	int data;
	Student* next;
}*start=NULL,*ptr=NULL,*newptr=NULL, *rear=NULL;


class single_llist
{// if you want multiple lists make start a public data member of this class
    public:
        Student* CreateElement(int);
        int count(Student*);
        void Insert_begin(Student *);
        void insert_pos();    
        int findMiddle(Student* start);//IMPORTANT APPROACH
        void Insert_end(Student*);
        void Deletion_front();
        void Deletion_end();
        void delete_pos();//check
        void Sort();//check
        void search();//check
        void update();//check
        void reverse(Student *);
        void Display(Student*);
        void Recursive_reverse(Student* q, Student* p);
        single_llist() 
        {
            start = NULL;
        }
};

int single_llist::findMiddle(Student* start)
{//1-2-3-4-5-6
	Student *slow=start, *fast=start;
	if(start==NULL)
	return -1;
	while(fast!=NULL)
	{
		fast=fast->next;
		fast=fast?fast->next:NULL;
		if (fast)
		slow=slow->next;
	}
	return slow->data;
}

int single_llist::count(Student* ptr)
{
	int i=0;
	while(ptr)
	{
		ptr=ptr->next;
		i++;
	}
	return i;
}
Student* single_llist::CreateElement(int no)
{
	newptr= new Student(); 
	if(newptr==NULL)
	{
		cout<<"Memory could not be alloted";
		Display(start);
		exit(-1);
	}
	else
	{
	newptr->data=no;
	newptr->next=NULL;
	}
	return newptr;
}
void single_llist::Insert_begin(Student* ptr)
{
	if(start==NULL){
	start=ptr;
	rear=ptr;
}
	else
	{
		ptr->next=start;
		start=ptr;
	}
}
void single_llist::Deletion_front()
{
if(start==NULL)
{
cout<<"Underflow";
exit(-2);}
else if(start==rear)
{
	Student* p=start;
	start=rear=NULL;
	delete p;
}
else{
	Student* p=start;
	start=start->next;
	delete p;
}	
}

void single_llist::Deletion_end()
{
	struct Student* ptr=start;
	if(start==NULL)
	{
		cout<<"Underflow!!";
		exit(-2);
	}
	else if(start==rear)
	{
		start=rear=NULL;
		delete ptr;
	}
	else{
	while(ptr->next!=rear)
		ptr=ptr->next;
		
	ptr->next=NULL;
	delete rear;
	rear=ptr;
	}
}


void single_llist::delete_pos()
{
    int pos, i;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the position of value to be deleted: ";
    cin>>pos;
    struct Student *s, *ptr;
    s = start;
    ptr=NULL;
    if (pos == 1)
    {
        Deletion_front();
    }
    else if(pos>1)
    {
        for(i=1;i<pos&&s;i++)
        {
        	ptr=s;
        	s=s->next;
		}
		if(s)
		{
			ptr->next=s->next;
			delete s;
		}
        else
        {
            cout<<"Position out of range"<<endl;
        }
    }
}
void single_llist::update()
{
    int value, pos, i;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the node postion to be updated: ";
    cin>>pos;
    cout<<"Enter the new value: ";
    cin>>value;
    struct Student *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start->data = value; 
    }
    else
    {
        for (i = 0;i < pos - 1;i++)
        {
            if (s == NULL)
            {
                cout<<"There are less than "<<pos<<" elements";
                return;
            }
            s = s->next;
        }
        s->data = value;  
    }
    cout<<"Node Updated"<<endl;
} 
void single_llist::search()
{
    int value, pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the value to be searched: ";
    cin>>value;
    struct Student *s;
    s = start;
    while (s != NULL)
    {
        pos++;
        if (s->data == value)
        {
            flag = true;
            cout<<"Element "<<value<<" is found at position "<<pos<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"Element "<<value<<" not found in the list"<<endl;  
}
void single_llist::reverse(Student* p)
{//sliding pointers approach
    struct Student *r=NULL, *q=NULL; 
    while (p != NULL)
    {
        r=q;
		q=p;
		p=p->next;
		q->next=r;
    }
    start = q;
}
void single_llist::Display(Student* link)
{
cout<<"\n";
	while(link!=NULL)
	{
		cout<<link->data<<"\t";
		link=link->next;
	}
}
void single_llist::Insert_end(Student* p)
{
	if(start==NULL)
	start=rear=p;
	else
	{
	rear->next=p;
	rear=p;
	}
}
void single_llist::insert_pos()
{
    int value, pos; 
    cout<<"\nEnter the value to be inserted: ";
    cin>>value;
    struct Student *temp,*ptr;
    temp = this->CreateElement(value);
    cout<<"\nEnter the postion at which node to be inserted: ";
    cin>>pos;
    int i=1;
    if (pos == 1)
    {
Insert_begin(temp);
    }
    else if (pos > 1){
    	ptr=start;
    	while(ptr&&pos!=i+1)
    	{
    		ptr=ptr->next;
			i++;	
		}
		if(ptr)
		{
			temp->next=ptr->next;
			ptr->next=temp;
		}
		else
			cout<<"No insertion allowed at position "<<pos<<" as it lies outside the list.";
	}
	}
void single_llist::Sort()
{
    struct Student *ptr, *s;
    int value;
    if (start == NULL)
    {
        cout<<"The List is empty"<<endl;
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        for (s = ptr->next;s !=NULL;s = s->next)
        {
            if (ptr->data > s->data)
            {
                value = ptr->data;
                ptr->data = s->data;
                s->data = value;
            }
        }
        ptr = ptr->next;
    }
}

void single_llist::Recursive_reverse(Student* q, Student* p)
{
if(p)
{
	Recursive_reverse(p,p->next);
	p->next=q;
}
else
	start=q;
}
int main()
{
	single_llist list;
	int no,n;
	char reply;
	cout<<"Create a linked list:"<<endl;
	do
	{
		cout<<"Enter data:";
		cin>>no;
		ptr=list.CreateElement(no);//ptr=newptr
		list.Insert_begin(ptr);
		cout<<"Do you want to create any more elements:"<<endl;
		cin>>reply;
	}while(reply=='y'||reply=='Y');
	list.Display(start);
	cout<<"\nCount:"<<list.count(start);
	cout<<"\nEnter y or Y if you wish to add elements at the end:";
	scanf(" %c",&reply);//wasting a \n
	while(reply=='y'||reply=='Y'){
		cout<<"Enter data:";
		cin>>no;
		ptr=list.CreateElement(no);
		list.Insert_end(ptr);
		cout<<"Do you want to create any more elements:"<<endl;
		cin>>reply;
	}
	list.Display(start);
	cout<<"\nCount:"<<list.count(start);
	cout<<"\nThe middle of the list is: "<<list.findMiddle(start);
	cout<<"\nEnter the number of elements to be deleted from front: ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		list.Deletion_front();
	}
	list.Display(start);
	cout<<"\nCount:"<<list.count(start);
	cout<<"\nThe middle of the list is: "<<list.findMiddle(start);
	cout<<"\nEnter y or Y if you wish to add elements randomly:";
	scanf(" %c",&reply);//wasting a \n
	while(reply=='y'||reply=='Y'){
	list.insert_pos();
	list.Display(start);
	cout<<"\nCount:"<<list.count(start);
	cout<<"\nDo you want to create any more elements:"<<endl;
	cin>>reply;
	}
	cout<<"\nEnter y or Y if you wish to delete elements randomly:";
	scanf(" %c",&reply);//wasting a \n	
	while(reply=='y'||reply=='Y'){
	list.delete_pos();
	list.Display(start);
	cout<<"\nCount:"<<list.count(start);
	cout<<"\nDo you want to delete any more elements:"<<endl;
	cin>>reply;
	}
	cout<<"\nSorting the list and displaying:";
	list.Sort();
	list.Display(start);
}

//Some extra functions
//void single_llist::Deletion_specific_node()
//{
//	int value;
//	Node *ptr=start, *prev=start;
//	cout<<"\nEnter the value of node to be deleted:";
//	cin>>value;
//	if(start)
//	{
//		while(ptr&&ptr->data!=value)
//		{
//		prev=ptr;
//		ptr=ptr->next;
//		}
//		if(ptr==NULL)
//		cout<<"Value does not exist in list";
//		else if(ptr==start)//value found at start of list
//		Deletion_front();
//		else
//		{
//			prev->next=ptr->next;
//			delete ptr;
//			cout<<"Node is successfully deleted!";
//		}
//	}
//	else{
//		cout<<"List is empty! Try Insertion at beginning or end.";
//	}
//	
//}

//void single_llist::Insert_after_a_node(struct Node* temp)
//{
//	int value;
//    struct Node *ptr=start, *prev;
//    cout<<"\nEnter the value of the previous node: ";
//    cin>>value;
//    if(start)
//    {
//    	while(ptr&&ptr->data!=value)
//    	ptr=ptr->next;

//    	if(ptr)
//    	{
//    	temp->next=ptr->next;
//    	ptr->next=temp;
//     	}
//     	else{
//     		cout<<"Entered value does not exist in list!";
//     		return;
//		 }
//	}
//	else
//	cout<<"List is empty! Try insertion at front or end."; 
//}

//void Delete_all_occurrences(int key)
//{
//	int n=0;
//	Node* temp=start,*prev=start, *Free=NULL;
//	if(!start)
//	{
//	cout<<"List is empty";
//	return;
//	}
//	else{
//		while(temp)
//		{
//			if(temp==start&&temp->data==key)
//			{
//			Deletion_front();//start moves to next element after deletion at front
//			temp=start;
//			n++;
//			continue;
//			}
//			else if(temp->data==key)
//			{
//				prev->next=temp->next;
//				Free=temp;
//				temp=temp->next;
//				delete Free;
//				n++;
//			}
//			else
//			{
//			prev=temp;
//			temp=temp->next;
//			}
//		}
//	}
//	cout<<"The updated list is:";
//	Display(start);
//	cout<<"\nNumber of occurrences of "<<key<<" deleted:"<<n;
//}
