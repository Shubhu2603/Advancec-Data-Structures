/*
There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. 
The cost of the edge can be the time that flight takes to reach city B from a, or.the amount of fuel used for the journey. 
Represent this as a graph. The node can be represented by airport name or name of the city.
Use adjacency list representation of the graph or use adjacency matrix representation of the graph.
Justi the storage re resentation used.
*/
#include <iostream>
#include<string.h>
using namespace std;
class node 
{
	public:
	char city[50];
	int fuel,time;
	node *next;
};
class graph
{
	public:
	int n1;
	char ct[50];
	node *n[10];
	graph()
	{
		cout<<"Enter the number of cities";
		cin>>n1;
		
		for(int i=0;i<n1;i++)
		{
			n[i]=new node;
			n[i]->fuel=n[i]->time=0;
			n[i]->next=NULL;
			cout<<"Enter the name of city "<<i;
			cin>>ct;
			strcpy(n[i]->city,ct);
		}
	}
	void insert();
//	void get flight();
	bool findcity(char a[50]);
	void display();
	void getroute();
};

bool graph::findcity(char a[50])
{
	for(int i=0;i<n1;i++)
	{
		if(strcmp(n[i]->city,a)==0)
		{
			return true;	
		}	
	}	
	return false;
}

void graph::insert()
{
	int cn;
	for(int i=0;i<n1;i++)
	{
		cout<<"Enter number of cities connected to "<<n[i]->city;	
		cin>>cn;
		for(int j=0;j<cn;j++)
		{
			node *temp=new node;
			char b[50];
			cout<<"Enter city name";
			cin>>b;
			while(findcity(b)!=true || strcmp(b,n[i]->city)==0)
			{
				cout<<"Invalid city,Enter valid city name";
				cin>>b;
			}
			cout<<"Enter time required from "<<n[i]->city<<" to "<<b;
			cin>>temp->time; 
			cout<<"Enter fuel required from "<<n[i]->city<<" to "<<b;
			cin>>temp->fuel;;
			strcpy(temp->city,b);
			temp->next=NULL;
			node* q=n[i];
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
}
void graph::display()
{
	cout<<"Source\tDestination\n";
	for(int i=0;i<n1;i++)
	{
		cout<<"\n";
		cout<<n[i]->city;
		node *p=n[i];
		while(1)
		{
			if(p->next==NULL)
			{
				break;
			}
			else
			{
				cout<<"\t||"<<p->next->city<<" Time :"<<p->next->time<<" Fuel:"<<p->next->fuel;
				p=p->next;
			}
		}
		cout<<"||";
	}
}

void graph::getroute()
{
	char src[50];
	char dest[50];
	cout<<"Enter source :";
	cin>>src;
	while(findcity(src)==false)
	{
		cout<<"Invalid city please enter again:";
		cin>>src;
	}
	cout<<"Enter destination :";
	cin>>dest;
	while(findcity(dest)==false)
	{
		cout<<"Invalid city please enter again:";
		cin>>dest;
	}
	node* temp;
	if(strcmp(src,dest)!=0 && findcity(src)==true && findcity(dest)==true)
	{
		for(int i=0;i<n1;i++)
		{
			if(strcmp(n[i]->city,src)==0)
			{
				temp=n[i];
			}
		}
			
			while(temp->next!=NULL)
			{
				if(strcmp(temp->next->city,dest)==0)
				{
					cout<<src<<"->"<<dest<<" Fuel :"<<temp->next->fuel<<" Time:"<<temp->next->time<<" mins";	
					break;
				}	
				else
				{
					temp=temp->next;
				}
			}
			
		
	}
	else
	{
		cout<<"NO FLIGHT AVAILABLE!!!";	
	}	
}

int main()
{
	graph g1;
	g1.insert();
	int ch;
	do
	{
	cout<<"\n1.Display all routes \n2.Get Route \n3.Exit \nEnter your choice:";
	cin>>ch;
	switch(ch)
	{
	
		case 1: g1.display();
				break;
		
		case 2: g1.getroute();
				break;
				
		case 3:break;
		
		default:cout<<"Invalid choice";
	}
	}while(ch!=3);
}	
