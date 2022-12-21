//Intersection of two linked lists
#include<iostream>
#include<cstdlib>
using namespace std;
class LLNode{
	public:
		int data;
		LLNode* next;
		public:
			LLNode(int data)
			{
				this->data=data;
				this->next=NULL;
			}
};
class singlyLL{
	public://To push a common LLNode rear is kept public
		LLNode *start,*rear;
		singlyLL(){
			start=rear=NULL;
		}
		void Insert_end(int);
		void Display();
		LLNode* FindIntersection(singlyLL *s2);
		int count();
};
void singlyLL::Insert_end(int data)
{
	LLNode* p= new LLNode(data);
	if(start==NULL)
	start=rear=p;
	else
	{
	rear->next=p;
	rear=p;
	}
}

int singlyLL::count()
{
	LLNode* ptr=start;
	int i=0;
	while(ptr)
	{
		ptr=ptr->next;
		i++;
	}
	return i;
}

void singlyLL::Display()
{
	LLNode* link=start;
cout<<"\n";
	while(link!=NULL)
	{
		cout<<link->data<<"\t";
		link=link->next;
	}
}

LLNode* singlyLL::FindIntersection(singlyLL *s2)
{
	LLNode *larger_list_start=NULL , *smaller_list_start=NULL;
	int m , n , d , count;
	m = this->count();   //calculate length
	n = s2->count();
	
	d = abs(m-n);  //find absolute difference
	
	if(m > n) //   find larger length linked list
		{
			larger_list_start = this->start;
			smaller_list_start = s2->start;
		}
	else
		{
			larger_list_start = s2->start;
			smaller_list_start = this->start;
		}
		
	count = 0;
	while(count < d)    // move d nodes in larger_list_start linked list
	{
		larger_list_start = larger_list_start->next;
		count++;
	}
	
	while(larger_list_start != smaller_list_start)   // then move one step each in both linked lists
	{
		larger_list_start = larger_list_start->next;
		smaller_list_start= smaller_list_start->next;
	}
	
	return larger_list_start;   // this is the intersection
	
}

int main()
{
	//Create two linked lists
	singlyLL s1,s2;
	s1.Insert_end(20);
	s1.Insert_end(30);//Making s1 longer on purpose
	for(int i=0;i<5;i++)
	{
	s1.Insert_end(2*i);
	s2.Insert_end(3*i);
	}//Pushing common LLNodes
	for(int i=0;i<5;i++)
	{
	LLNode *p=new LLNode(100*i);
	s1.rear->next=s2.rear->next=p;
	s1.rear=s2.rear=p;
	}
	s1.Display();
	s2.Display();
	cout<<"\nThe intersection is:"<<s1.FindIntersection(&s2)->data;
}
