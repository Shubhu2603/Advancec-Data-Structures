/*A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. 
Provide facility to display whole data sorted in ascending /descending order. 
Also find how many maximum comparisons may require for finding any keyword .
Use Binary search tree for implementation.*/
#include<iostream>
#include<string.h>
using namespace std;
struct node
{
      char word[50];
      char meaning[50];
      node *left;
      node *right;
};
class dictionary
{
      public:
      struct node *root;
      dictionary()
      {
            root=NULL;
      }
      void create();
      void insert();
      void search();
      void inorder(node *);
};
void dictionary::create()
{
      if(root==NULL)
      {
            char w[50];
            char m[50];
            root=new node;
            cout<<"Enter Word";
            cin>>w;
            cout<<"Enter meaning";
            cin>>m;
            strcpy(root->word,w);
            strcpy(root->meaning,m);
            root->left=NULL;
            root->right=NULL;
      }
      else
      {
            cout<<"Root already exists";
      }
}
void dictionary::insert()
{
      node *p,*q;
      if(root==NULL)
      {
            create();
      }
      p=new node;
      char w[50];
      char m[50];       
      cout<<"Enter Word";
      cin>>w;
      cout<<"Enter meaning";
      cin>>m;
      strcpy(p->word,w);
      strcpy(p->meaning,m);
      p->left=NULL;
      p->right=NULL;
      q=root;
      while(p!=NULL)
      {
      int cmp=strcmp(p->word,q->word);
      if(cmp<0)
      {
            if(q->left==NULL)
            {
                q->left=p;
                return;
            }
            else
            {
                  q=q->left;
            }     
      }
      else
      {
            if(q->right==NULL)
            {
                  q->right=p;
                  return;
            }
            else
            {
                  q=q->right;
            }      
      }   
      }                  
}

void dictionary::search()
{
      node *temp=root;
      char key[50];
      cout<<"Enter word to search";
      cin>>key;
      int val;
      while(temp!=NULL)
      {
            val=strcmp(key,temp->word);
            if(val==0)
            {
                  cout<<"Word :"<<temp->word<<"\nMeaning :"<<temp->meaning;
                  return;
            }
            if(val<0)
            {
                  temp=temp->left;
            }
            else if(val>0)
            {
                  temp=temp->right;
            }
      }
      cout<<"\nNOT FOUND";
}
void dictionary::inorder(node *node1)
{
      if(node1!=NULL)
      {
      inorder(node1->left);
      
      cout<<"\nWord :"<<node1->word<<"\nMeaning :"<<node1->meaning;
       
      inorder(node1->right);
      }
}
int main()
{
      dictionary d1;
      int ch;
      do{
      cout<<"\n1.Create \n2.Insert \n3.Search \n4.Display \n5.Exit \nEnter your choice:";
      cin>>ch;
      switch(ch)
      {
            case 1:d1.create();
                   break;
                   
            case 2:d1.insert();
                   break;
                  
            case 3:d1.search();
                   break;
               
            case 4:d1.inorder(d1.root);
                   break;
      
            case 5:break;
            
            default:"Invalid Choice";
      }
      }while(ch!=5);
      return 0;     
}
