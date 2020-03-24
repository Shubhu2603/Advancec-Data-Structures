#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
struct node
{
      char data;
      node *left,*right;
};
class etree
{
      public:
      node *root;
      etree()
      {
            root=NULL;
      }     
      int isoperator(char r)
      {
            if(r=='+' || r=='-' || r=='*' || r=='/' || r=='^')
            {
                  return 1;
            } 
            else
            {
                  return 0;
            }
      }
};
void preorder(node* temp)
{
      if(temp!=NULL)
      {
            cout<<temp->data;
            
            preorder(temp->left);
            
            preorder(temp->right);
      }
}
int main()
{
      stack<node *>s;
      etree t1;
      node *l,*r,*temp;
      char exp[50];
      cout<<"Enter the expression";
      cin>>exp;
      for(int i=0;i<strlen(exp);i++)
      {
            if(t1.isoperator(exp[i])==0)
            {     
                  temp=new node;
                  temp->data=exp[i];
                  temp->left=NULL;
                  temp->right=NULL;
                  s.push(temp);
            }
            else
            {
                  temp=new node;
                  temp->data=exp[i];
                  r=s.top();
                  s.pop();
                  l=s.top();
                  s.pop();
                  temp->left=l;
                  temp->right=r;
                  s.push(temp);                  
            }     
            t1.root=s.top();
      
      }
      preorder(t1.root);
     
}    
