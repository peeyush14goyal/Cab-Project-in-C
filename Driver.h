#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdio>
#include<sstream>
#include<conio.h>
using namespace std;

void resignation()
{
	int num=0,num2=0;
	string choice;
	string ID,password,c,d;
	bool found=false;
	cout<<endl<<"Enter your ID:"; cin>>ID;
	cout<<endl<<"Enter your Password:"; cin>>password;
	
	cout<<endl<<"Are you sure, you want to resign ? (Y/N) :-("<<endl;
	cin>>choice;
	if(choice=="N")
		return ;
	ofstream write;
	ifstream read,read2;
	write.open("Driver Details_updated.txt");
	read.open("Driver Details_full properties.txt");
	read2.open("Driver Details_full properties.txt");
	
	getline(read,c);	
	num++;
	getline(read2,d);
	num2++;
	write<<c;
	while(!read.eof())
	{
		
		if(num>=num2)
		{
			getline(read2,d);	
			num2++;
		}
		getline(read,c);
		num++;
		if(!found && (num-4)%9==0)// && c=="Driver:"+ID)
		{
			getline(read2,d);
			num2++;
			if(d=="Driver:"+ID)
			{
				getline(read2,d);
				num2++;
				if(d.substr(9)==password)
				{
					found=true;
					for(int i=0;i<9;i++)
					{
						num++;
						getline(read,c);
//						if(!read.eof())
					}
				}
				if(read.eof())
					break;
			}
		}
		write<<endl<<c;
	}
	
	read.close();
	read2.close();
	write.close();
	
	if(!found)
		cout<<endl<<"Wrong ID or Password";
	else
		cout<<endl<<"You are no longer an employee. ThankYou for working with us, your money will be transferred to your account";
		
	remove("Driver Details_full properties.txt");
	rename("Driver Details_updated.txt","Driver Details_full properties.txt");		
}
void add1(string &lastID,int i)
{
	if(i==-1 or lastID=="")
		lastID="1"+lastID;
	if(lastID[i]=='9')
	{
		lastID[i]='0';
		add1(lastID,i-1);
	}
	else
		lastID[i]=lastID[i]+1;	
}
void view_new_record(string ID,string password)
{
	int num=0;
	string c,d;
	bool found=false;
	ifstream read,read2;
	read.open("Driver Details_full properties.txt");
	read2.open("Driver Details_full properties.txt");
	while(!read.eof())
	{
		num++;
		getline(read,c);
		
		if(!read2.eof())
			getline(read2,d);
		
		if(!found && (num-5)%9==0 && c=="Driver:"+ID)
		{
			getline(read2,d);
			if(d.substr(9)==password)
			{
				found=true;
				cout<<endl<<endl<<c;
				for(int i=0;i<6;i++)
				{
					getline(read2,d);
					cout<<endl<<d;
				}
			}
		}
	}
	
	read.close();
	read2.close();
	
	if(!found)
		cout<<endl<<"Wrong ID or Password";
}
void add_driver_record()
{
	system("cls");
	int num=0;
	string c,Name_first,Name_last,age,lastID,gender,DOB,contact,BldGrp,password;
	//cout<<endl<<"Welcome to Chaitanya and Peeyush Co. Earn money your way!! ";
	cout<<"\t\t\t\t\t\t\tP&C Cabs\n\n";
	cout<<"\t\t\t\t\t\t      Driver Record";
	cout<<endl<<"First name:";
	cin>>Name_first;
	cout<<endl<<"Last name:";
	cin>>Name_last;
	cout<<endl<<"Age:"; 
	cin>>age;
	cout<<endl<<"Gender (M/F):";
	cin>>gender;
	cout<<endl<<"Date of birth DD/MM/YYYY:";
	cin>>DOB;
	cout<<endl<<"Contact number:";
	cin>>contact;
	cout<<endl<<"Blood group:";
	cin>>BldGrp;
	
	ofstream write;
	ifstream read;
	
	write.open("Driver Details_updated.txt");
	read.open("Driver Details_full properties.txt");
	num++;
	getline(read,c);
	write<<c;
	while(!read.eof())
	{			
		num++;
		getline(read,c);
		write<<endl<<c;
		if(((num-5)%9)==0)
			lastID=c.substr(9);
		
	}
	cout<<endl<<"\n\nAre you sure you want to apply ? (Y/N):";
	cin>>c;
	if(c=="N")
		goto end;
	
	add1(lastID,lastID.size()-1);
	password=Name_first.substr(0,2)+Name_last.substr(0,2)+DOB.substr(0,2)+contact.substr(0,2);
	write<<endl;
	write<<endl<<"Driver:PC"<<lastID;
	write<<endl<<"Password:"<<password;
	write<<endl<<" Name:"<<Name_first<<" "<<Name_last;
	write<<endl<<" Age:"<<age<<" years";
	write<<endl<<" Gender:";
	gender=="M" ? write<<"Male" : write<<"Female";
	write<<endl<<" Date of birth: "<<DOB;
	write<<endl<<" Contact:"<<contact;
	write<<endl<<" Blood group:"<<BldGrp;
	end:
	read.close();
	write.close();
	
	remove("Driver Details_full properties.txt");
	rename("Driver Details_updated.txt","Driver Details_full properties.txt");
	cout<<"\n\nRecord Saved Successfully!\n\n";
	cout<<"Newly Saved Record : \n";
	ostringstream Id_digits;
	Id_digits << lastID;
	string num_id = Id_digits.str(); 
	view_new_record("PC" + num_id, password);
}
void view_records()
{
	int num=0;
	string ID,password,c,d;
	bool found=false;
	cout<<endl<<"Enter your ID:"; cin>>ID;
	cout<<endl<<"Enter your Password:"; cin>>password;
	
	ifstream read,read2;
	read.open("Driver Details_full properties.txt");
	read2.open("Driver Details_full properties.txt");
	while(!read.eof())
	{
		num++;
		getline(read,c);
		
		if(!read2.eof())
			getline(read2,d);
		
		if(!found && (num-5)%9==0 && c=="Driver:"+ID)
		{
			getline(read2,d);
			if(d.substr(9)==password)
			{
				found=true;
				cout<<endl<<endl<<c;
				for(int i=0;i<6;i++)
				{
					getline(read2,d);
					cout<<endl<<d;
				}
			}
		}
	}
	
	read.close();
	read2.close();
	
	if(!found)
		cout<<endl<<"Wrong ID or Password";
}

void view_drivers_records()
{
	ifstream read,read2;
	string c;
	read.open("Driver Details_full properties.txt");
	while(!read.eof())
	{
		getline(read,c);
		cout<<c<<endl;	
	}
	char ch;
	ch = getch();
	if(int(ch)==13)
	read.close();
}
int edit_record()
{
	int num=0,num2=0;
	string choice;
	string ID,password,c,d;
	string first_name, last_name;
	bool found=false;
	cout<<endl<<"Enter your ID:"; cin>>ID;
	cout<<endl<<"Enter your Password:"; cin>>password;
	
	ofstream write;
	ifstream read,read2;
	write.open("Driver Details_updated.txt");
	read.open("Driver Details_full properties.txt");
	read2.open("Driver Details_full properties.txt");
	
	getline(read,c);	
	num++;
	getline(read2,d);
	num2++;
	write<<c;
	while(!read.eof()&&!found)
	{
		
		if(num>=num2)
		{
			getline(read2,d);	
			num2++;
		}
		getline(read,c);
		num++;
		if(!found && (num-4)%9==0)// && c=="Driver:"+ID)
		{
			getline(read2,d);
			num2++;
			if(d=="Driver:"+ID)
			{
				getline(read2,d);
				num2++;
				if(d.substr(9)==password)
				{
					found=true;
					for(int i=0;i<9;i++)
					{
						num++;
						getline(read,c);
//						if(!read.eof())
					}
				}
				if(read.eof())
					break;
			}
		}
	}
	if(found)
	{
		int choice;
		cout<<"Enter the Property you want to edit =>\n";
		cout<<"1 <=> Name\n2 <=> Contact\n3 <=>Go Back\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: getline(read2, d);
					num2++;
					
					if(d.substr(1,3)=="Name")
					{
						cout<<"\nEnter your New First Name: ";
						cin>>first_name;
						cout<<"\nEnter your New Last Name: ";
						cin>>last_name;
						write<<endl<<c;
						write<<endl<<" Name:"<<first_name<<" "<<last_name;
					}
					break;
				
			case 2: getline(read2, d);
					num2++;
					long long int contact;
					if(d.substr(1,6)=="Contact")
					{
						cout<<"\nEnter your New Contact Number: ";
						cin>>contact;
						write<<endl<<c;
						write<<endl<<" Contact:"<<contact;
					}
					break;
		}
	}
	read.close();
	read2.close();
	write.close();
	
	if(!found)
	{
		cout<<endl<<"Wrong ID or Password";
		return 0;
	}	
		
	remove("Driver Details_full properties.txt");
	rename("Driver Details_updated.txt","Driver Details_full properties2.txt");		
	return 1;
}
