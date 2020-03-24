/*Consider telephone book database of N clients. Make use of hash table implementation to quickly look up client's telephone number.*/

#include <iostream>
#include<string.h>
using namespace std;
struct node
{
	unsigned long long int data;
	node *next;
	char person[50];
	
};
class directory
{
	public:
	node *n[10];
	char name[50];
	unsigned long long int no;
	int index;
	directory()
	{
		for(int i=0;i<10;i++)
		{
			n[i]=new node;
			n[i]->data=0;
			n[i]->next=NULL;
			strcpy(n[i]->person,"Null Entry");	
		}
	}
	void insert();
	int hash(int);
	int convert(char name[]);
	void display();
	void search();
};
void directory::insert()
{	
	cout<<"Enter name :";
	cin>>name;
	cout<<"Enter phone number :";
	cin>>no;
	int key=convert(name);
	index=hash(key);
	if(n[index]->data==0)
	{
		n[index]->data=no;
		strcpy(n[index]->person,name);
	}
	else
	{
		node *temp=new node;
		temp->data=no;
		strcpy(temp->person,name);
		temp->next=NULL;
		node *q=n[index];
		while(1)
		{
			if(q->next==NULL)
			{
				q->next=temp;
				break;
			}
			else
			{
				q=q->next;
			}
		}
	}
}

int directory::hash(int key)
{
	return key%10;
}

int directory::convert(char name[])
{
	int val=0;
	for(int i=0;name[i]!='\0';i++)
	{
		val=val+int(name[i]);
	}	
	return val;
}

void directory::display()
{
	cout<<"\nIndex\t\t\tName:Number";
		for(int i=0;i<10;i++)
		{	
			node *p=n[i];
			cout<<"\n"<<i<<"\t\t\t"<<n[i]->person<<":"<<n[i]->data;
			while(p->next!=NULL)
			{
				p=p->next;
				cout<<"->"<<p->person<<":"<<p->data;
			}	
		}		
}
void directory::search()
{
		char nm[50];
		cout<<"Enter the name for contact to be found:";
		cin>>nm;
		int val=convert(nm);
		int in=hash(val);
		node *r=n[in];
		while(r!=NULL)
		{
			if(strcmp(r->person,nm)==0)
			{
				cout<<"Name:"<<r->person<<"\nContact Number:"<<r->data;
				return;
			}
			r=r->next;
		}
		cout<<"\nEntry not found";
		
		
}

int main()
{
	directory d1;
	int ch;
	do{
		cout<<"\n1.Insert \n2.Display \n3.Search \n4.Exit\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: d1.insert();
					break;
				
			case 2: d1.display();
					break;
					
			case 3: d1.search();
					break;
					
			case 4: break;
			
			default:cout<<"invalid choice";
		}
	}while(ch!=4);
	return 0;	
}
