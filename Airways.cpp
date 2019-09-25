#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

using namespace std;

class fl_details
{	public:
	char depar[50];
	char destin[50];
	int flight_no;
	float pr;
	void in_data();
	void out_data();
	int get_fl_no()
	{
	    return flight_no;
    }
}FD;
void fl_details::in_data()
{
    cout<<"\nDeparture:";
	gets(depar);
	cout<<"\nDestination\n";
	gets(destin);
	cout<<"\nFlight number:\n";
	cin>>flight_no;
	cout<<"\nPrice:\n";
	cin>>pr;
}
void fl_details::out_data()
{
	cout<<"\nDeparture:";
	puts(depar);
	cout<<"\nDestination\n";
	puts(destin);
	cout<<"\nFlight number:\n";
	cout<<flight_no;
	cout<<"\nPrice:\n";
	cout<<pr;
}
class Air_res
{	char name[50];
	int per_id;
	int tic_no;
	char dest[50];
	char dep[50];
	int fl_no;
	float price;

	public:
		void in_data();
		int get_perId()
		{return per_id;
		}
		void out_data();
		void Assign_details();
}A1;
void Air_res::in_data()
{	cout<<"\nName:\n";
	gets(name);
	cout<<"\nPerson ID number:\n";
	cin>>per_id;
	cout<<"\nDeparture:";
	gets(dep);
	cout<<"\nDestination\n";
	gets(dest);
	void Assign_details();
}
void Air_res::out_data()
{	cout<<"\nName:\n";
	puts(name);
	cout<<"\nPerson ID number:\n";
	cout<<per_id;
	cout<<"\nDeparture:";
	puts(dep);
	cout<<"\nDestination\n";
	puts(dest);
	cout<<"\nFlight number:\n";
	cout<<fl_no;
	cout<<"\nTicket Number:\n";
	cout<<tic_no;
	cout<<"\nPrice:\n";
	cout<<price;
}
void Air_res::Assign_details()
{	long long int tn=111111;
	tic_no=tn;
	tn++;
	fl_details fd;
	int count=0;
	ifstream fi("flight_details",ios::in|ios::binary);
	while(!fi.eof())
	{	fi.read((char*) & fd,sizeof(fd));
		if(!(strcmp(dep,fd.depar)&&strcmp(dest,fd.destin)))
		{	price=fd.pr;
			fl_no=fd.flight_no;
			count++;
		}
	}
	if(!count)
	{cout<<"\nNo such flight\n";
	}
}
void New_fl_details()
{
	fl_details fl;
	ofstream fo("flight_details",ios::binary|ios::app|ios::out);
	char ch;
	do
	{
		cout<<"\nEnter new details:\n";
		fl.in_data();
		fo.write((char*)&fl,sizeof(fl));
		cout<<"\nWant to enter more(flight_details):\n";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fo.close();
}
void search_flight(int n)
{	fl_details fl;
	int flag=0;
	ifstream fi("flight_details",ios::binary|ios::in);
	while(!fi.eof())
	{	fi.read((char*)&fl,sizeof(fl));
		if(fl.get_fl_no()==n)
			{	fl.out_data();
				flag++;
			}
	}
	if(!flag)
	{
		cout<<"\nNo such Flight\n";
	}
	fi.close();
}
void del_fl_details()
{	int n1;
	char ch;
	fl_details fl;
	cout<<"\nEnter the Flight no. whose record is to be deleted:\n";
	cin>>n1;
	search_flight(n1);
	cout<<"\nConfirmed(y/n):\n";
	cin>>ch;
	if(ch=='Y'||ch=='y')
	{
		fstream ft("temp",ios::binary|ios::app);
		fstream fo("flight_details",ios::binary|ios::app);
		while(!fo.eof())
		{	fo.read((char*)&fl,sizeof(fl));
			if(fl.get_fl_no()==n1)
			{
				continue;
			}
			else
			{
				ft.write((char*)&fl,sizeof(fl));
			}
				fo.close();
				ft.close();
		}
	}

}
void Mod_fl_details()
{
	int n1;
	char ch;
	fl_details fl,fl1;
	cout<<"\nEnter the Flight no. whose record is to be Modify:\n";
	cin>>n1;
	search_flight(n1);
	cout<<"\nConfirmed(y/n):\n";
	cin>>ch;
	if(ch=='Y'||ch=='y')
	{
		fstream ft("temp",ios::binary|ios::app);
		fstream fo("flight_details",ios::binary|ios::app);
		cout<<"\nEnter new details:\n";
		fl.in_data();
		while(!fo.eof())
		{
			fo.read((char*)&fl1,sizeof(fl1));
			if(fl.get_fl_no()>n1)
			{
				ft.write((char*)&fl,sizeof(fl));
			}
			fo.write((char*)&fl1,sizeof(fl1));
		}
		fo.close();
		ft.close();
		delete("flight_details");
	}	rename("temp","flight_details");
}
void ADMIN_input()
{	int n=0;
	char ch;
	do
	{
		cout<<"\nADMIN MENU\n1.New flight_details\n2.Delete flight_details\n3.Modify flight_details\n4.Search flight\n5.Exit\n";
		cout<<"\nEnter your choice:\n";
		cin>>n;
		switch(n)
		{
			case 1:	New_fl_details();
					break;
			case 2: del_fl_details();
					break;
			case 3: Mod_fl_details();
					break;
			case 4:	int n3;
					cout<<"\nEnter the flight number:\n";
					cin>>n3;
					search_flight(n3);
					break;
			case 5:	exit(0);
			default: cout<<"\nWrong choice!!!!!\n";
		}
		cout<<"\nWant to enter more(Admin menu):\n";
		cin>>ch;
	}while(ch=='Y'||ch=='y');

}
void New_pasgr()
{
	Air_res AR;
	ofstream fo("User_data",ios::out|ios::binary|ios::app);
		AR.in_data();
		fo.write((char*)&AR,sizeof(AR));

}
void search_pasrg(int n)
{	int count=0;
	Air_res ar;
	ifstream fi("User_data",ios::binary|ios::app|ios::in);
	while(!fi.eof())
	{
		fi.read((char*)&ar,sizeof(ar));
		if(n==ar.get_perId())
		{
			ar.out_data();
			count++;
		}
	}
	fi.close();
	if(!count)
		cout<<"\nNo such user!!!!\n";
}
void Delete_pasgr()
{	int n;
	char ch;
	Air_res ar;
	fstream fo("User_data",ios::binary|ios::app);
	fstream ft("temp1",ios::binary|ios::app);
	cout<<"\nEnter the person Id:\n";
	cin>>n;
	search_pasrg(n);
	cout<<"\nConfirm:\n";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		while(!fo.eof())
		{	fo.read((char*)&ar,sizeof(ar));
			if(n==ar.get_perId())
			{
				continue;
			}
			else
			{
				ft.write((char*)&ar,sizeof(ar));
			}
		}
	}
	delete("User_data");
	rename("temp","User_data");
}
void USER_input()
{	int n1;
	char ch;
	do
	{
	cout<<"\nUSER MENU\n1.New passenger\n2.Get information(flight)\n3.Cancel flight\n4.Exit\n";
	cout<<"\nEnter your choice\n";
	cin>>n1;
	switch(n1)
	{
		case 1:	New_pasgr();
				break;
		case 2: int n1;
				cout<<"\nEnter person ID";
				cin>>n1;
				search_pasrg(n1);
				break;
		case 3: Delete_pasgr();
				break;
		case 4:	exit(0);
				break;
		default:cout<<"\nWrong choice!!!\nTry again";
	}
	cout<<"\nUSER Menu(y/n):";
	cin>>ch;
	}while(ch=='y'||ch=='Y');
}
int main()
{	system("cls");
	int n=0,n2=0;
	char ch[50],ch1[50];
	char ch2;
	do
	{
	cout<<"\nLog in as:\n1.User\n2.Administrator\n3.Exit\n";
	cin>>n;

		if(n==2)
			{	start:
				cout<<"\nEnter Username:\n";
				gets(ch);
				cout<<"\nEnter password:\n";
				gets(ch1);
				if(!strcmp(ch,"Sirajul")&&!strcmp(ch1,"1234"))
				{
					ADMIN_input();
				}
				else if (n2==4)
				{
					cout<<"\nWrong details 5 times\n";
					cout<<"nExiting..................";
					for(long int i=0;i<10000;i++);
					exit(0);			}
				else if(n==2)
				{
				cout<<"\nWrong username or password\nTry Again\n";
				n2++;
				goto start;

				}

			}
			else if (n==1)
			{
				USER_input();
			}
			else if (n==3)
			{
				exit(0);		}
			else
			{
				cout<<"\nWrong choice\n";
			}
		cout<<"\nWant to enter more:(Main menu)\n";
		cin>>ch2;
	}while(ch2=='Y'||ch2=='y');

	getch();
	return 0;
}

