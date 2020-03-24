/*Implement all the functions of a dictionary (ADT) using hashing.
Data: Set of(key, value) pairs, keys are mapped to values, keys must be comparable, keys must be unique
Standard Operations: Insert(key, value),Find(key),Delete(key)
*/
#include<iostream>
#include<string.h>
using namespace std;
struct node
{
	char word[50],meaning[50];
	node *next;
};
class hash
{
	public:
	node *n[10];
	hash()
	{
		for(int i=0;i<10;i++)
		{
			n[i]=new node;
			strcpy(n[i]->word,"");
			strcpy(n[i]->meaning,"");
			n[i]->next=NULL;
		}
	}
	void insert();
	void display();
//	void get_meaning();
	int get_index(char key[]);
	int in(int k);
};
int hash::in(int k)
{
		return k%10;
}

int hash::get_index(char key[])
{
	int sum=0;
	for(int i=0;key[i]!='\0';i++)
	{
		sum+=int(key[i]);
	}
	return sum;
}
void hash::insert()
{
	char wd[50],mn[50];
	cout<<"\nEnter the word and meaning\n";
	cin>>wd>>mn;
	int k=get_index(wd);
	int index=in(k);
	cout<<index;
	if(strlen(n[index]->word)==0)
	{
		strcpy(n[index]->word,wd);
		strcpy(n[index]->meaning,mn);
	}
	else
	{
		node *temp=new node;
		strcpy(temp->word,wd);
		strcpy(temp->meaning,mn);
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
void hash::display()
{
	cout<<"Index";
	for(int i=0;i<10;i++)
	{
		node *temp=n[i];
		cout<<"\n"<<i<<"\tWord:"<<temp->word<<"  Meaning:"<<temp->meaning;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			cout<<"->"<<"Word:"<<temp->word<<"  Meaning:"<<temp->meaning;
		}
	}
}
int main()
{
	hash h1;
	int ch;
	do{
		cout<<"\n1.Insert \n2.Display \n3.Exit\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: h1.insert();
					break;
					
			case 2: h1.display();
					break;	
					
		}
	}while(ch!=3);	
	return 0;	
}
