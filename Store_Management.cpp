#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include <cstring>

#include<stdio.h>
using namespace std;
class file{
public:
    file(){
        ofstream fout;
        fout.open("rlt.txt");
        fout<<"rlt";
        fout.close();
    }
};
class earn{
        public:
        double profit;
        void show()
		{
		ifstream x("ooo.txt");
        if(!x)
        cout<<"PROFIT = 0 "<<endl;
        else{
        x>>profit;
        cout<<"TOTAL STARTING PROFIT:  "<<profit<<endl;
        x.close();
        }
        
        }

};
class product:public virtual earn{
public:
           int quantity;
           char name[20];
           char id[20];
           double per_cost;
           double per_sell;
           double cost;
           double sell;
           void cal()
		   {
		    cost=per_cost*quantity;
        	sell=per_sell*quantity;
            profit=profit +(sell-cost)*365;
			}
           void file();
           void get();

};
void product::get()
{
 int s;
cout<<"Number of products produced?"<<endl;
cin>>s;
for(int i=0;i<s;i++)
{
  cout<<"Input product name:"<<endl;
  cin>>name;
  cout<<"Input product id:"<<endl;
  cin>>id;
  cout<<"Input cost price of product:"<<endl;
  cin>>per_cost;
  cout<<"Input selling price of product:"<<endl;
  cin>>per_sell;
  cout<<"Total product quantity:"<<endl;
  cin>>quantity;
    cal();
    file();
  }
 
}
void product::file()
{
char file[20];
strcpy(file,id);
strcat(file,".txt");
ofstream f(file);
f<< "Product name: "<<name<<"\n"<< "Product id: "<<id<<"\n"<<"Cost price of product: "<<per_cost<<"\n"<<"Selling price of product: "<<per_sell<<"\n"<<"Quantity: "<<quantity<<"\n"<<"Total cost: "<<cost<<"\n"<<"Sell: "<<sell<<endl;
f.close();
}

class staff:public virtual earn{
         protected:
         double emp_sal;
         char emp_name[12];
         char emp_id[10];
         int post_quantity;
         void cal()
         {
		 profit=(profit-emp_sal*post_quantity)*12;
         }
         void get_staff();
         void file();
};
void staff::get_staff()
{
  cout<<"Input salary:"<<endl;
  cin>>emp_sal;
  cout<<"Input number of employees:"<<endl;
  cin>>post_quantity;
  for(int i=0;i<post_quantity;i++)
  {
  	cout<<"Input employee name:"<<endl;
  	cin>>emp_name;
  cout<<"Input employee ID:"<<endl;
  cin>>emp_id;
  cal();
  file();
}
}
 void staff::file()
{  char file[20];
strcpy(file,emp_id);
strcat(file,".txt");
ofstream f(file);
f<< "Number of working employees:"<<post_quantity<<"\n"<<"Employee salary:"<<emp_sal<<"\n"<<"Employee name:"<<emp_name<<"\n"<<"Employee id:"<<emp_id<<endl;
f.close();
}

class amount:public staff, public product
{

 public:
    void add();
    void update_item();
    void update_emp();

};
void amount::add()
{
	int ch;
	char name[20];
	while(1)
	{
		cout<<"1)Input for product"<<endl;
		cout<<"2)Input for employee"<<endl;
		cout<<"3)Exit"<<endl;
		cout<<"Enter choice"<<endl;
		cin>>ch;
		if(ch==1){
				get();
				ofstream x("ooo.txt");
 				x<<profit;
 				x.close();
			}
			else if(ch==2){
				get_staff();
				ofstream x("ooo.txt");
 				x<<profit;
 				x.close();
				}
			else if(ch==3)
				break;
			else
				cout<<"Invaid Option. Please re-enter"<<endl;
			}
		}

 
	void amount::update_item()
	{
	char id[20];
	char p_id[20];
    char c;
    cout<<"Input product ID to modify"<<endl;
    cin>>id;
    char file[20];
    char file2[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
    if(!fout)
    {
    	cout<<"File couldn't be opened. product ID not found."<<endl;
	}
	else {
	cout<<"File found!"<<endl;
    cout<<"Update product name:"<<endl;
  	cin>>name;
 	cout<<"Update percost of product:"<<endl;
  	cin>>per_cost;
 	cout<<"Update persell of product:"<<endl;
  	cin>>per_sell;
 	cout<<"Update total product quantity:"<<endl;
 	cin>>quantity;
    cost=per_cost*quantity;
    sell=per_sell*quantity;
	profit=profit +(sell-cost)*365;
  	fout<<"Product name:"<<name<<"\n"<< "Product id:"<<id<<"\n"<<"Percost ofproduct:" <<per_cost<<"\n"<<"Persell of product:"<<per_sell<<"\n"<<"Quantity:"<<quantity<<"\n"<<"Total cost:"<<cost<<"\n"<<"Sell:"<<sell<<endl;
	fout.close();
}
}
   void amount::update_emp()	
	{
	char id[20];
    char c;
    cout<<"INPUT employee ID to modify:"<<endl;
    cin>>id;
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
     if(!fout)
    {								
    	cout<<"file couldn't be opened. product ID not found."<<endl;
	}
	cout<<"modify employee name:"<<endl;
  	cin>>emp_name;
  	fout<<"Number of working employees:"<<post_quantity<<"\n"<< "Employee salary:"<<emp_sal<<"\n"<< "Employee name:"<<emp_name<<"\n"<<"Employee id:"<<emp_id<<endl;
 	fout.close();
}

void admin()
{
  while(1)
  {
 	 cout<<"========================================"<<endl;
	 cout<<"||        WELCOME TO THE SHOP          ||"<<endl;
	 cout<<"||=====================================||"<<endl;
	 cout<<"||* * * * * * * * * * * * * * * * * * *||"<<endl;
	 cout<<"||1. Add Entries                       ||"<<endl;
	 cout<<"||2. Show profit                       ||"<<endl;
	 cout<<"||3. Search Product Details            ||"<<endl;
	 cout<<"||4. Search Employee Details           ||"<<endl;
	 cout<<"||5. Modify Product Details            ||"<<endl;
	 cout<<"||6. Modify Employee Details           ||"<<endl;
	 cout<<"||7. Exit                              ||"<<endl;
	 cout<<"||=====================================||"<<endl;
	 cout<<"Select your choice:"<<endl;
  int u;
  cin>>u;
if(u==1)
  {
  amount a;
  a.show();
  a.add();
}
  else if(u==2)
  {
  amount d;
  d.show();
}
  else if(u==3)
  {  
   char id[20];
   char c;
    cout<<"Input ID to search"<<endl;
    cin>>id;
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    ifstream x(file);
    if(!x)
    {
    	cout<<"file couldn't be opened. product ID not found."<<endl;
	}
    while(x)
    {x.get(c);
     cout<<c;
    }
    

    x.close();
}
   else if(u==4)
   {
   	char e_id[20];
   	char d;
   	cout<<"Input employee ID to search:"<<endl;
    cin>>e_id;
   	char file[20];
   	strcpy(file,e_id);
   	strcat(file,".txt");
   	ifstream y(file);
   	 if(!y)
    {
    	cout<<"file couldn't be opened. employee ID not found."<<endl;
	}
   	while(y)
   	{
   	y.get(d);
   	cout<<d;
   }
 
   y.close();
}
else if(u==5)
{
	amount u;
	u.update_item();
}
 else if(u==6)
 {
 	amount v;
 	v.update_emp();
 }
  else if(u==7)
  {
  break;
}
  else cout<<"Invalid option. Please select one of the available options"<<endl;
 }

}

int main()
{
    int ch;
    char  username[20];
    char password[20];
    char pwd[20];
    while(1){
        cout<<"============================================="<<endl;
        cout<<"||             WELCOME TO MY SHOP            ||"<<endl;
        cout<<"||===========================================||"<<endl;
        cout<<"||* * * * * * * * * * * * * * * * * * * * * *||"<<endl;
        cout<<"||1. ENTER SYSTEM                            ||"<<endl;
        cout<<"||2. EXIT                                    ||"<<endl;
        cout<<"||* * * * * * * * * * * * * * * * * * * * * *||"<<endl;
        cout<<"||Enter Your choice:                         ||"<<endl;
        cout<<"============================================="<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                admin();
                break;
            case 2:
                exit(0);
                break;
            default:
                cout<<"Enter valid choice"<<endl;
                break;
        }
    }
	system("pause");
    return 0;
}

