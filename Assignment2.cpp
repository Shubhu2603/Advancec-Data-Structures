#include<iostream>
#include<stack>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
class tree
{
	public:
	int count;
	node *root;
	int lh,rh;
	tree()
	{
		root=NULL;
		count=0;
		rh=0;
		lh=0;
	}
	void insert();
	void create();
	void inorder(struct node *);
	void preorder(struct node *);
	void postorder(struct node *);
	void inorderi();
	void preorderi();
	void postorderi();
	void searchi(int);
	void search(struct node *,int);
	int height(node *);
};
void tree::insert()
{
	char ch;
	int c;
	node *p,*q;
	p=new node;
	if(root==NULL)
	{
		create();
	}
	cout<<"Enter the data :";
	cin>>c;
	p->data=c;
	p->left=NULL;
	p->right=NULL;
	q=root;
	while(q!=NULL)
	{
		if(p->data<q->data)
		{
			if(q->left==NULL)
			{
				q->left=p;
				count++;
				return;
			}
			else
			{
				q=q->left;
			}
		}
		else if(p->data>q->data)
		{
			if(q->right==NULL)
			{
				q->right=p;
				count++;
				return;
			}
			else
			{
				q=q->right;
			}
		}
		else
		{
			cout<<"Invalid choice";	
		}
	}
	
}
void tree::create()
{
	if(root==NULL)
	{
		int r;
		root=new node;
		cout<<"Enter the data of root node :";
		cin>>r;
		root->data=r;
		root->left=NULL;
		root->right=NULL;
		count++;
	}
	else
	{
		cout<<"\nTree already exists,cannot create root node";
	}

}
void tree::preorderi()
{
        node *temp=root;
        stack<node *>s1;
       while(1)
       {
        while(temp!=NULL)
        {
                cout<<temp->data<<"\t";
                s1.push(temp);
                temp=temp->left;
        }
        if(s1.empty())
        {
                return;
        }
        temp=s1.top();
        s1.pop();
        temp=temp->right;
       }	
}
void tree::inorderi()
{
        node *temp=root;
        stack<node *>s2;
        while(1)
        {
                while(temp!=NULL)
                {
                        s2.push(temp);
                        temp=temp->left;       
                }
                if(s2.empty())
                {
                        return;
                }
                temp=s2.top();
                s2.pop();
                cout<<temp->data<<"\t";
                temp=temp->right;
        }
}
void tree::postorderi()
{
        node *temp=root;
        stack<node *>s3;
        stack<char>s4;
        char f;
        while(1);
        {
                while(temp!=NULL)
                {
                        s3.push(temp);
                        s4.push('l');
                        temp=temp->left;
                }
                if(s3.empty())
                {
                        return;
                }
                else{
                f=s4.top();
                s4.pop();
                temp=s3.top();
                s3.pop();
                if(f=='r')
                {
                        cout<<temp->data<<"\t";
                        temp=NULL;
                        
                }
                else 
                {       
                        s3.push(temp);
                        s4.push('r');
                        temp=temp->right;
                }
         }
   }
}
void tree::preorder(struct node *node1)
{
        if(node1!=NULL)
        {
                cout<<node1->data<<"\t";
                
                preorder(node1->left);
                
                preorder(node1->right);
        }
}
void tree::inorder(struct node *node1)
{
	if(node1!=NULL)
	{
		inorder(node1->left);		
		
		cout<<node1->data<<"\t";
	
		inorder(node1->right);
	}
}
void tree::postorder(struct node *node1)
{
	if(node1!=NULL)
	{
		postorder(node1->left);

		postorder(node1->right);
	
		cout<<node1->data<<"\t";
	}	
}
void tree::searchi(int key)
{
        node *temp=root;
        while(temp!=NULL)
        {
                if(temp->data==key)
                {
                        cout<<"\nFound";
                        return;
                }
                else if(temp->data>key)
                {
                        temp=temp->left;
                }
                else
                {
                        temp=temp->right;
                }
                cout<<"Element not found";
        }
}
void tree::search(node *temp,int key1)
{
        while(temp!=NULL)
        {
                if(temp->data==key1)
                {
                        cout<<"\nFound";
                        return;
                }
                else if(temp->data>key1)
                {
                        search(temp->left,key1);
                }
                else
                {
                        search(temp->right,key1);
                }
                cout<<"Element not found";
        }
}
int tree::height(node *temp)
{
        if(temp==NULL)
        {
                return 0;
        }
        else
        {       
                lh=height(temp->left);
                rh=height(temp->right);
        }
        if(lh>rh)
        {
                return lh+1;
        }
        else
        {
                return rh+1;
        }
}

int main()
{
	int ch1;
	tree t1;
	do{
	cout<<"\n1.Create Root Node \n2.Insert Node \n3.Preorder \n4.Inorder \n5.Postorder \n6.Iterative Preorder \n7.Iterative Inorder \n8.Iterative Postorder \n9.Number of nodes \n10.Search \n11.Iterative search \n12.Exit";
	cin>>ch1;
	switch(ch1)
	{
		case 1:t1.create();
			break;

		case 2:t1.insert();
			break;

		case 3:cout<<"Preorder :";
			t1.preorder(t1.root);
			break;

		case 4:cout<<"Inorder :";
			t1.inorder(t1.root);
			break;

		case 5:cout<<"Postorder :";
			t1.postorder(t1.root);
			break;
	
		case 6: cout<<"Iterative Preorder :";
		        t1.preorderi();
			break;
	
		case 7:cout<<"Iterative Inorder :";
		       t1.inorderi();
		       break;
		      
                case 8:cout<<"Iterative Postorder";
                       t1.postorderi();
                       break;
                
                case 9:cout<<t1.count;
                       break;
                
                case 10:cout<<"Enter key element to search";
                               int key;
                               cin>>key;
                               t1.searchi(key);
                               break;	
                               
                case 11:cout<<"Enter key element to search";
                        int key1;
                        cin>>key1;
                        t1.search(t1.root,key1);
                        break;
                        
                case 12:t1.height(t1.root);
                      break;
                
		default:cout<<"Invalid choice";
			break;
	}
	}while(ch1!=13);
	return 0;
}
