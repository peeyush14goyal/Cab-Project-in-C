#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdio>

using namespace std;
int main()
{
	string c,NewVal1,NewVal2,ID; //NewVal1 for Age and First name, NewVal2 for Last Name.
	char file1[]="Driver Details.txt";
	char file2[]="Driver Details_updated";
	char file3[]="YO.txt";
	int num=0;					//to keep count of the line number.
	bool age=false;				//You want to change age or not?
	cout<<"ID : ";
	cin>>ID;
	cout<<"Welcome "<<ID<<endl<<"What do you want to change? Press 0 for Name and 1 for Age : ";
	cin>>age;
	cout<<endl<<"Enter new val : ";
	cin>>NewVal1;
	if(!age)    //if name to be changed ask for last name
		cin>>NewVal2;  
	ofstream write;
	ifstream read;
	write.open("Driver Details_updated.txt");
	read.open("Driver Details.txt");

	while(!read.eof())
	{
		num++;
		getline(read,c);
		write<<c<<endl;
		if((num-5)%4==0 && c=="Driver:"+ID)
		{
			if(!age)
			{
				num++;
				getline(read,c);
				write<<"Name:"<<NewVal1<<" "<<NewVal2<<endl;
			}
			else
			{
				num+=2;
				getline(read,c);
				write<<c<<endl;
				getline(read,c);
				write<<"Age:"<<NewVal1<<" years"<<endl;
			}
		}
	}
	read.close();
	write.close();	
	num=remove("Driver Details.txt");
	cout<<num<<endl;
	num=rename("Driver Details_updated.txt","Driver Details.txt");
	cout<<num;
	return 0;
}
