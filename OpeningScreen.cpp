#include<iostream>
#include"Driver.h"
#include"Guest.h"
#include<conio.h>

using namespace std;
class admin {
	public:
		void admin_mainlogin();
		void admin_open_portal();
		void show_records();
};
class driver {
	public:
		int driver_login_screen();	
};
class guest {
	public: 
		
};
void admin::admin_mainlogin()
{
	char password[100],ch;
	int i=0;
	cout<<"\t\t\t\t\t\t\tWelcome to P&C Cabs\n\n\n";
	cout<<"\t\t\t\t\t\t\t   Admin Portal\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\tPassword: ";
	while(int(ch)!=13)
	{
		ch = getch();
		cout<<"*";
		if(int(ch)!=13)
		{
			password[i++]=ch;	
		}
		
	}
	if(strcmp(password,"1234")==0)
	{
		system("cls");
		admin_open_portal();
	}
}
void admin::admin_open_portal()
{
	int choice;
	cout<<"\t\t\t\t\t\t\tP&C Cabs\n\n";
	cout<<"Enter Respective Number:\n\n";
	cout<<"1. New Record\t\t\t\t\t4. Run Program\n\n";
	cout<<"2. Show Records\t\t\t\t\t5. Show Logs\n\n";
	cout<<"3. Update Records";
	cout<<"\n\nEnter your choice: ";
	cin>>choice;
	system("cls");
	switch(choice) 
	{
		case 1: 
				cout<<"\t\t\t\t\t\t\tP&C Cabs\n\n";
				cout<<"1 : Guest Record";
				cout<<"\n2 : Driver Record";
				int choice2;
				cout<<"\n\nEnter your choice: ";
				h:  cin>>choice2;
				switch(choice2) {
					case 1: add_guest_record();
							break;
							
					case 2: add_driver_record();
							break;
					
					default: goto h; 
				}
				
		case 2: show_records();
				break;
				
		case 3: int choiceUpdate;
				cout<<"\n1 <=> Guest Record Update\n2 <=> Driver Record Update\n";
				cin>>choiceUpdate;
				if(choiceUpdate==2)
				{
					int status = edit_record();
					if(status == 1)
					{
						cout<<"\nRecord Updated Successfully!\n";
					}
					else
					{
						cout<<"\nRecord Update Failed\n";
					}
				}
				else if(choiceUpdate==1)
				{
					int status = edit_guest_record();
					if(status == 1)
					{
						cout<<"\nGuest Record Updated Successfully!\n";
					}
					else
					{
						cout<<"\nGuest Record Update Failed\n";
					}
				}
	}
}
void admin::show_records()
{
	system("cls");
	int choice;
	string id;
	h: cout<<"\t\t\t\t\t\t\tP&C Cabs\n\n";
	cout<<"\t\t\t\t\t\t       Show Records\n\n\n\n";
	cout<<"1 : Driver Records\t\t\t2: Guest Records\t\t\t3: All Records\t\t\t4: Go Back";
	cout<<"\n\n\nEnter your choice: ";
	cin>>choice;
	switch(choice){
		case 1: cout<<"\nSpecific Record <=> 1";
				cout<<"\nAll Records <=> 2";
				int choice2;
				cout<<"\n\nEnter your choice: ";
				cin>>choice2;
				switch(choice2)
				{
					case 1: search_again: view_records();
							cout<<"\n\nSearch Another <=> 1";
							cout<<"\nGo Back <=> 2";
							cout<<"Enter your choice: ";
							int choice3;
							if(choice == 1)
							goto search_again;
							else if(choice == 2)
							goto h;
							break;
							
					case 2: view_drivers_records();
							break;
							
					default: system("cls");
							 goto h;
				}
				break;
				
		case 2: cout<<"\nSpecific Record <=> 1";
				cout<<"\nAll Records <=> 2";
				int choice4;
				
				cout<<"\n\nEnter your choice: ";
				cin>>choice4;
				switch(choice4)
				{
					case 1: cout<<"\nEnter ID: ";
							cin>>id;
							search_guest_again: view_specific_guest_records(id);
							cout<<"\n\nSearch Another <=> 1";
							cout<<"\nGo Back <=> 2";
							cout<<"Enter your choice: ";
							int choice3;
							if(choice == 1)
							goto search_guest_again;
							else if(choice == 2)
							goto h;
							break;
							
					case 2: view_guests_records();
							break;
							
					default: system("cls");
							 goto h;
				}
				break;
		
		case 3: cout<<"\nAll Drivers Records => \n";
				view_drivers_records();
				cout<<"\n\nAll Guests Records => \n";	
				view_guests_records();
				break;	
				
		case 4: system("cls");
				admin_open_portal();
				break;						
	}
	admin_open_portal();
}
int driver::driver_login_screen()
{
	char password[100],ch,id[4];
	int i=0;
	cout<<"\t\t\t\t\t\t\tWelcome to P&C Cabs\n\n\n";
	cout<<"\t\t\t\t\t\t\t   Driver Portal\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\tId: ";
	cin>>id;
	cout<<"\t\t\t\t\t\t\tPassword: ";
	while(int(ch)!=13)
	{
		ch = getch();
		cout<<"*";
		password[i++]=ch;
	}
	//cout<<"Password is "<<password;
	//system("cls");
}
int main()
{
	admin *ad;
	driver *d;
	int choice;
	cout<<"\t\t\t\t\t\t\tWelcome to P&C Cabs\n\n";
	cout<<"Enter respective number to enter in respective Portal";
	cout<<"\n\nAdministrator: 1";
	cout<<"\nDriver: 2";
	cout<<"\n\nEnter your choice: ";
	cin>>choice;
	system("cls");
	switch(choice)
	{
		case 1: ad->admin_mainlogin();
				break;
		case 2: d->driver_login_screen();
				break;
		
		default: exit(1);
	}
	
}
