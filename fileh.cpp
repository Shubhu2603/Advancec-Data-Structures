#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class Student 
{
	public:
	int rollno;
	char Division,name[30],address[30];
	void getdata();
	void display();
	int getrollno()
	{
		return rollno;
	}
	
}s;
void Student::getdata()
{
	cout<<"Enter Roll No";
	cin>>rollno;
	
	cout<<"Enter name";
	cin>>name;
	
	cout<<"Enter address";
	cin>>address;
	
	cout<<"Enter division";
	cin>>Division;
}
void Student::display()
{
	
 cout<<"\n=================================================\n";
 cout<<"Roll No. : "<<rollno<<"\tName  : "<<name<<"\n";
 cout<<"Address    : "<<address <<"\tDivision : "<<Division;
 cout<<"\n=================================================\n";
}

int main()
{

	int ch;
	do{
	
	char c='y';
	cout<<"\n\t...MENU OF PROGRAM...\n";
 	cout<<"\t1. Add the record...\n";
	cout<<"\t2. Display all records...\n";
 	cout<<"\t3. Modify the Record...\n";
 	cout<<"\t4. Delete the Record...\n";
	cout<<"\t5. Search the record...\n";
	cout<<"\t6. View deleted records...\n";
	cout<<"\t7..Exit...\n";
	cout<<"\nEnter Your Choice  : ";
	cin>>ch;
	switch(ch)
	{	
		case 1: {		
				ofstream fout("student.dat",ios::out|ios::app|ios::binary);
				while(c=='y'||c=='Y')
				{
					s.getdata();
					fout.write((char*)&s,sizeof(s));
					cout<<"Do you want to add more ?";
					cin>>c;
				}
				cout<<"Data transferred to file";
				fout.close();
				}
				break;
		
		case 2: {
		
				ifstream fin("student.dat",ios::in|ios::binary);
				while(fin.read((char*)&s,sizeof(s)))
				{
					s.display();	
				}	
				fin.close();
				}break;
			
		case 3:	{
				fstream fio("student.dat",ios::out|ios::in|ios::binary);
				int rno;
				char found='n';
				fio.seekg(0);
				
				cout<<"\nEnter roll number whose record is to be modified";
				cin>>rno;
				
				while(fio)
				{
					int loc=fio.tellg();
					fio.read((char*)&s,sizeof(s));
					if(s.getrollno()==rno)
					{
						s.getdata();
						found='y';
						fio.seekg(loc);
						fio.write((char*)&s,sizeof(s));
						cout<<"\nRecord Updated!";
						
					}
				}
				if(found=='n')
				{
					cout<<"Record does not exsist";
				}
				break;
				}		
	
	case 4: {
			int rn;
			char fnd='n';
			fstream fi("student.dat",ios::in|ios::out|ios::app|ios::binary);
			ofstream fou("temp.dat",ios::in|ios::out|ios::app|ios::binary);
			ofstream out("trash.dat",ios::out|ios::app|ios::binary);
			
			cout<<"\nEnter roll no whose record is to be deleted";
			cin>>rn;
			
			while(fi.read((char*)&s,sizeof(s)))
			{
				if(s.getrollno()==rn)
				{
					out.write((char*)&s,sizeof(s));
					fnd='y';
				}
				else
				{
					fou.write((char*)&s,sizeof(s));
				}
			}
			if(fnd=='n')
			{
				cout<<"\nRecord does not exsist";
			}
			else
			{
				cout<<"Deleted successfully";
			}
			fi.close();
			fou.close();
			remove("student.dat");
			rename("temp.dat","student.dat");
			break;
			}
			
	case 5: {
			ifstream ifs("student.dat",ios::in|ios::binary);
			int r;
			char f='n';
			cout<<"\nEnter roll no to be searched";
			cin>>r;
			 
			while(ifs.read((char*)&s,sizeof(s)))
			{
				if(s.getrollno()==r)
				{
					s.display();
					f='y';
				}
			}
			if(f=='n')
			{
				cout<<"\nRecord not found!";
			}
			ifs.close();
			break;
			}
			
	case 6:{
		ifstream ifst("trash.dat",ios::in|ios::binary);
		char del='n';
		while(ifst.read((char*)&s,sizeof(s)))
		{
			s.display();
		}
		ifst.seekg(0,ios::end);
		if(ifst.tellg()==0)
		{
			cout<<"\nNo deleted files";
		}
		break;
	}
}
	}while(ch!=7);
}
