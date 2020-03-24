/*Convert a given binary tree into threaded binary tree. Analyze time and space complexity of the algorithm.*/
#include<iostream>
using namespace std;
struct node{
      int data,lbit,rbit;
      node *left,*right;
};
class TBT
{
      public:
      node *head,*root;
      TBT()
      {
            head=new node;
            head->lbit=0;
            head->rbit=1;
            head->left=head;
            head->right=head;
            head->data=0;
            root=NULL;
      }
      void create();    
      void preorder();
      void inorder();
   
};
void TBT::create()
{
      char ch='y';
      int x;
      node *temp,*curr;
      do
      {
            curr=new node;
            cout<<"Enter data";
            cin>>x;
            curr->data=x;
            curr->lbit=curr->rbit=1;
            if(root==NULL)
            {
                  root=curr;
                  root->left=root->right=head;
                  head->left=root;
                  head->lbit=0;
            }
            else
            {
                  temp=root;
                  while(1)
                  {
                        if(curr->data<temp->data)
                        {
                              if(temp->lbit=1)
                              {
                                    curr->left=temp->left;
                                    temp->left=curr;
                                    temp->lbit=0;
                                    curr->right=temp;
                                    break; 
                              }
                              else
                              {
                                    temp=temp->left;
                              }
                        }
                        else
                        {
                              if(temp->rbit==1)
                              {
                                    curr->right=temp->right;
                                    temp->right=curr;
                                    temp->rbit=0;
                                    curr->left=temp;
                                    break;
                              }
                              else
                              {
                                    temp=temp->right;
                              }
                        }
                  }
            }cout<<"Do you want to continue ?";
            cin>>ch;
            
      }while(ch=='y');
}
void TBT::preorder()
{
      cout<<"\n preorder :";
      node *temp=root;
      int flag=0;
      while(temp!=head)
      {
            if(flag==0)
            {
                  cout<<temp->data;
            }
                  if(temp->lbit==0 && flag==0)
                  {
                        temp=temp->left;
                  }
                  else
                  {
                        if(temp->rbit==0)
                        {
                              temp=temp->right;
                              flag=0;
                        }
                        else
                        {
                              temp=temp->right;
                              flag=1;
                        }
                  
                  }          
      }
      cout<<endl;
}
void TBT::inorder()
{
      node *temp=root;
      int flag=0;
      while(temp!=head)
      {
            if(temp->lbit==0 && flag==0)
            {
                  temp=temp->left;
            }
            else
            {
                  cout<<temp->data;
                  if(temp->rbit==0)
                  {
                        temp=temp->right;
                        flag=0;
                  }
                  else
                  {
                        temp=temp->right;
                        flag=1;
                  }
            }
      }
}
int main()
{
	int ch;
	TBT t1;
	do{
	cout<<"\n1.Create Root Node \n2.Preorder \n3.Inorder \n4.Exit";
	cin>>ch;
	switch(ch)
	{
		case 1:t1.create();
			break;

		case 2:cout<<"Preorder :";
			t1.preorder();
			break;

		case 3:cout<<"Inorder :";
			t1.inorder();
			break;
	      
	      case 4:break;
	       
	      default:cout<<"Invalid choice";
	}
	}while(ch!=4);
	return 0;
}
