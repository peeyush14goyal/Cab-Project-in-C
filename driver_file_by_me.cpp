#include<iostream>
using namespace std;
int register_driver_account()
{
	int num;
	cout<<"Enter the number of records you want to enter: ";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"Enter Name of "<<i+1<" Driver: ";
		cin>>name;
		cout<<"Enter Age: ";
		cin>>age;
		cout<<"Enter Gender: { 0 for Male <=> 1 for Female <=> 2 Not to be Specified }: ";
		cin>>gender;
		cout<<"\n**Date of birth should be written in DDMMYYYY format. All Integers value**\n"
		cout<<"Enter Date of Birth: ";
		cin>>dob;
		cout<<"Enter Current Address: ";
		cin>>current_address;
		/*make address it a string*/
		cout<<"Enter Permanent Address: ";
		cin>>permanent_address;
		cout<<"Enter Contact Number: ";
		cin>>contact_number;
		cout<<"Enter Blood Group: Select from the list provided below\n";
		cout<<"1 <=> A+\n";
		cout<<"2 <=> A-\n";
		cout<<"3 <=> B+\n";
		cout<<"4 <=> B-\n";
		cout<<"5 <=> O+\n";
		cout<<"6 <=> O-\n";
		cout<<"7 <=> AB+\n";
		cout<<"8 <=> AB-\n";
		cout<<"Enter your choice: ";
		cin>>blood_group;
		cout<<"If you have any previous medical condition then please specify: ";
		cin>>medical_condition;
		/*in above there will be a whole paragraph so make string large ans also
		we will be enter some words from our side like heart, liver and then search the whole para related to it 
		and then if found then increase the counter for the same in it*/
		cout<<"Any medications: ";
		cin>>history_medications;
		cout<<"\n**Following Details should be given of the person we will contact in case of emergency**\n";
		cout<<"Enter Name: ";
		cin>>emergency_name;
		cout<<"Enter Contact Number: ";
		cin>>emergency_contact_number;
		cout<<"Enter Relation: ";
		cin>>emergency_person_relation;
		/*driver_id=;
		password=;*/
	}
	return 1;
}
int get_guest_details()
{
	int flag=0,count=1,temp;
	h: cout<<"\nEnter Driver Id: ";
	cin>>check_driver_id;
	//n is the total number of drivers that we have stored
	for(int i=0;i<n;i++)
	{
		if(check_driver_id == drivers[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"Wrong Driver Id. Check Again!!!";
		goto h;
	}
	//in password we will implement in form of *** so that password appears like password only
	if(count==0)
	{
		cout<<"\nYour Password attempts have reached the maximum limit.For safety of our systems we are exiting the program";
		return 0;
	}
	cout<<"\n**You have "<<count+1<<" attempts left";
	cout<<"\nEnter Password: ";
	cin>>check_password;
	for(int i=0;i<n;i++)
	{
		if(check_password == passwords_list[i])
		{
			flag=1;
			temp=i;
			break;
		}
	}
	if(flag==0)
	{
		count--;
		cout<<"Wrong Password. Check Again!!!";
		goto g;
	}
	cout<<"\n\t\t\t***Welcome "<<driver_name[temp]<<"****";
	//We need to create a data structure for storing the date also
	/*We have used the sort function so we will provide a list of options to show the drivers trips according to 
	varied option and then he/she can view a particular trip in detail also.*/
	cout<<"\nDo you want to sort?\n";
	cout<<"0 <=> No\n1 <=> Yes";
	int want_sort;
	if(want_sort==1)
	{
		cout<<"\nList of options according to which you can sort your trips are given below: \n";
		cout<<"1 <=> Sort By Date";
		cout<<"2 <=> Sort By Destination Id";
		cout<<"3 <=> Sort By Guest Id";
		int sort_choice;
		cin>>sort_choice;
		switch(sort_choice)
		{
			case 1: sort
		}
	}
	/* status of the driver availability also needs to stored */
}
