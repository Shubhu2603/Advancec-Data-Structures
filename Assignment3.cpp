#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
struct node
{
	char data; 
	node *left,*right;
};
class E_tree
{
	public:
	char exp[50];
	node *root;
	void accept();
	node* insert();
	void preorder(node*);
	int isoperator(char);
	void inorder(node *);
};
int E_tree::isoperator(char c)
{
	if(c=='+' || c=='*' || c=='+' || c=='/' || c=='^')
		return 1;
	else
		return 0;
}
void E_tree::accept()
{
	cout<<"Enter the expression";
	cin>>exp;
}

node* E_tree::insert()
{
	stack<node *>s;
	node *t1,*t2;
	for(int i=0;i<strlen(exp);i++)
	{
		if(isoperator(exp[i])==0)
		{
			node *temp=new node;
			temp->data=exp[i];
			temp->left=NULL;
			temp->right=NULL;
			s.push(temp);
		}
		else
		{
			node *temp2=new node;
			temp2->left=temp2->right=NULL;
			temp2->data=exp[i]; //+
			t1=s.top(); //b
			s.pop();
			t2=s.top(); //a
			s.pop();
			temp2->right=t1;
			temp2->left=t2;
			s.push(temp2);
		}
	}
	root=s.top();
	s.pop();
	
}
void E_tree::inorder(node *temp1)
{
	if(temp1!=NULL)
	{	
		inorder(temp1->left);
		
		cout<<temp1->data;

		inorder(temp1->right);
	}
}
void E_tree::preorder(node *temp1)
{
	if(temp1!=NULL)
	{
		cout<<temp1->data;
			
		preorder(temp1->left);
		
		preorder(temp1->right);
	}
}
int main()
{
	E_tree t1;
	int ch;
	do{
		cout<<"\n1.Accept \n2.Insert \n3.Preordr \n4.Postorder \n5.Exit";
	
	cout<<"\nEnter your choice :";
	cin>>ch;
	switch(ch)
	{
	case 1:t1.accept();
		   break;
		   
	case 2:t1.insert();
		   break;
		   
	case 3:t1.preorder(t1.root);
		   break;
		   
	case 4:t1.inorder(t1.root);
		   break;
		   
	case 5:break;
	default:cout<<"Invalid choice";
	}}while(ch!=5);
	
	return 0;
}
