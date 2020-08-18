#include<iostream>
#include "Driver.h"
using namespace std;
void driver_portal()
{
	system("cls");
	int choice;
	cout<<endl<<"Welcome to Chaitanya and Peeyush's Cab services"<<endl<<"Bringing comfort at your doorsteps :-)";
	cout<<endl<<endl<<"Welcome to the Driver section.";
	while(1){
	
	cout<<endl<<"Select one of the following options: ";
	cout<<endl<<"1. Apply for job"<<endl<<"2. View information"<<endl<<"3. Edit your details"<<endl<<"4. Resignation portal"<<endl<<"Press any other key to exit"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			add();
			cout<<endl;
			break;
		case 2:
			view();
			cout<<endl;
			break;
		case 3:
			edit_record();
			break;
		case 4:
			resignation();	
			break;
		default:
			goto end;
	}
	}
	end:
	cout<<endl<<endl<<"Thank you for using our Driver Portal";	
}
