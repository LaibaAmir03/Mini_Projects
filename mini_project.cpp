#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>

using namespace std;

class ice_cream
{
	protected:
		int choice, ch1, ch2;
	public:
	void menu();
	int num;
	int total;
}obj;

void ice_cream::menu()
{
    cout<<"==================================================================================="<<endl;
    cout<<"||                                                                               ||"<<endl;
    cout<<"||                          Laiba's Ice_cream Parlor                             ||"<<endl;
    cout<<"||                                                                               ||"<<endl;
    cout<<"||===============================================================================||"<<endl;
    cout<<"||                                                                               ||"<<endl;
    cout<<"||                         Welcome!! Here is the menu                            ||"<<endl;
    cout<<"||_______________________________________________________________________________||"<<endl;
    cout<<"||               Flavors           1 Scoop          2 Scoops                     ||"<<endl;
    cout<<"||           1) Chocolate           150 Rs           300 Rs                      ||"<<endl;
    cout<<"||           2) Vanilla             150 Rs           300 Rs                      ||"<<endl;
    cout<<"||           3) Strawberry          150 Rs           300 Rs                      ||"<<endl;
    cout<<"||           4) Mango               150 Rs           300 Rs                      ||"<<endl;
    cout<<"||_______________________________________________________________________________||"<<endl;
    cout<<"||                                                                               ||"<<endl;
    cout<<"||                       Kindly Place your Order                                 ||"<<endl;
    cout<<"||                                                                               ||"<<endl;
    cout<<"==================================================================================="<<endl;
}

class scoops: public ice_cream
{
	public:
	void num_of_scoops()
	{
	cout<<"Enter number of scoops(150Rs\- per scoop): "<<endl;
	cin>>num;
	if (num==1)
	{
		cout<<"150 Rs\- added to your bill"<<endl;
		num=150;
		total += num;
	}
	else if (num==2)
	{
		cout<<"300 Rs\- added to your bill"<<endl;
		num=300;
		total += num;
	}
}
}s;
class flavors : public ice_cream
{
	public:
	void set_flavor()
	{
		char f[100], f1[]="Chocolate", f2[]="Vanilla", f3[]="Strawberry", f4[]="Mango";
		cout<<"Enter your choice:"<<endl;
		cin>>choice;
		
		if(choice==1)
		{
			cout<<"You selected Chocolate Flavor"<<endl;
		}
		else if(choice==2)
		{
			cout<<"You selected Vanilla Flavor"<<endl;
		}
		else if(choice==3)
		{
			cout<<"You selected Strawberry Flavor"<<endl;
		}
		else if(choice==4)
		{
			cout<<"You selected Mango Flavor"<<endl;
		}
		else
		cout<<"Invalid Choice"<<endl;
	}
}f;

class toppings : public ice_cream
{
	public:
		void add_toppings()
	{


		scoops s;
		char f[100], f1[]="Chocolate syrup", f2[]="Sprinkles", f3[]="Vanilla Wafer";


			cout<<"============================================================"<<endl;
			cout<<"||           Toppings                   Price             ||"<<endl;
			cout<<"||     1) Chocolate syrup               20 Rs-            ||"<<endl;
			cout<<"||     2) Sprinkles                     10 Rs-            ||"<<endl;
			cout<<"||     3) Vanilla wafer                 15 Rs-            ||"<<endl;
			cout<<"============================================================"<<endl;	
			cout<<"Enter your choice:"<<endl;
			cin>>choice;
			
			if(choice==1)
			{
			cout<<"Chocolate syrup is added"<<endl;
			cout<<"Your bill is here"<<endl;
			total += (s.total*20);
			cout<<total<<"Rs\-"<<endl;
			}
			else if(choice==2)
			{
			cout<<"Sprinkles are added"<<endl;
			cout<<"Your bill is here"<<endl;
			total += (s.total*10);
			cout<<total<<"Rs\-"<<endl;
			}
			else if(choice==3)
			{
				cout<<"Vanilla Wafer is added"<<endl;
				cout<<"Your bill is here"<<endl;
				total += (s.total*15);
				cout<<total<<"Rs-"<<endl;
			}
			else 
			cout<<"Invalid Entry"<<endl;
			}

}t;



int main()
{
	ice_cream obj;
	flavors f;
	scoops s;
	toppings t;
	obj.menu();
	f.set_flavor();
	s.num_of_scoops();
	t.add_toppings();

	cout<<endl;
		cout<<"==============================================================================="<<endl;
      	cout<<"||                                                                           ||"<<endl;
cout<<"||                     THANK YOU FOR PLACING AN ORDER                        ||"<<endl;
	cout<<"||                           DO VISIT AGAIN                                  ||"<<endl;
	cout<<"||                                                                           ||"<<endl;
	cout<<"==============================================================================="<<endl;   
	


system("pause");
	return 0;
}


