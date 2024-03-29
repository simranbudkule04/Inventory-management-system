#include<iostream>
#include<conio.h>
#include<string>
#include<math.h>
#include<cstring>
#include<iomanip>
using namespace std;

class items
{
public:

	string household_i[5] = { "wheat flour","sugar","rice","bread","cooking oil" };
	string dairy[3] = { "milk","cheese","butter" };
	string veggies[5] = { "Apple","Papaya","Onions","Broccoli","Potatoes" };
	string iname[10];
	int price_h[5] = { 40,40,65,35,100 };
	int price_d[3] = { 25,40,100 };
	int price_v[5] = { 120,40,40,30,20 };    //iname,quant,price used as shopping cart to store the values
	int choice, count, a, quant[20], l = 0, q1, m = 0;
	double price[20], q2;
	void purchase(int count, double q1)
	{

		if (choice == 1)
		{
			if (count == 1 || count == 2 || count == 3)
			{
				quant[l] = q1;
				price[l] = price_h[count - 1];
			}

		}
		if (choice == 3)
		{
			if (count <= 5 && count > 0)
			{
				quant[l] = q1;
				price[l] = price_v[count - 1];
			}
		}
		l++;
	}
	void purchase(int count, int q1)
	{
		if (choice == 1)
		{
			if (count == 4 || count == 5)
			{

				quant[l] = q1;
				price[l] = price_h[count - 1];
			}
		}
		if (choice == 2)
		{
			if (count <= 3 && count > 0)
			{

				quant[l] = q1;
				price[l] = price_d[count - 1];
			}
		}
		l++;
	}
	void operator++(int)
	{

		++m;
	}
	void show_items()
	{

		while (choice != 4)
		{
			cout << "Enter the section you want to shop in: " << endl;
			cout << "Enter 1 for Household items" << endl;
			cout << "Enter 2 for Dairy products" << endl;
			cout << "Enter 3 for Fruits and Vegetable" << endl;
			cout << "Enter 4 to proceed for billing" << endl;
			cin >> choice;
			if (choice == 1)
			{
				a = 1;
				cout << "----------------HOUSEHOLD ITEMS-----------------" << endl;
				for (int i = 0; i < 5; i++)
				{
					cout << i + 1 << " " << household_i[i] << " = >\t Price : " << price_h[i] << endl;
				}

				while (a != 0)
				{
					cout << "Enter your choice: " << endl;
					cin >> count;
					cout << "Enter quantity(in kg/nos.): " << endl;
					if (count <= 3 && count > 0) //in kg
					{
						cin >> q2;
						iname[l] = household_i[count - 1];
						purchase(count, q2);
					}
					else                   //in nos.
					{
						cin >> q1;
						iname[l] = household_i[count - 1];
						purchase(count, q1);
					}
					cout << "To exit the household items section,press 0,to continue press 1" << endl;
					cin >> a;

				}
				cout << "------------------------------------------" << endl;
				if (a == 0)
				{
					count = 0;
					choice = 0;
				}
			}
			if (choice == 2)
			{
				a = 1;
				cout << "----------------DAIRY PRODUCTS-----------------" << endl;
				for (int i = 0; i < 3; i++)
				{
					cout << i + 1 << " " << dairy[i] << " = >\t\t Price : " << price_d[i] << endl;
				}

				while (a != 0)
				{
					cout << "Enter your choice: " << endl;
					cin >> count;
					cout << "Enter quantity(in kg/nos.): " << endl;
					if (count <= 3 && count > 0)   //in no of packets
					{
						cin >> q1;
						iname[l] = dairy[count - 1];
						purchase(count, q1);
					}
					cout << "To exit the Dairy Products section,press 0,to continue press 1" << endl;
					cin >> a;

				}
				cout << "------------------------------------------" << endl;
				if (a == 0)
				{
					count = 0;
					choice = 0;
				}
			}
			if (choice == 3)
			{
				a = 1;
				cout << "----------------FRUITS AND VEGETABLES-----------------" << endl;
				for (int i = 0; i < 5; i++)
				{
					cout << i + 1 << " " << veggies[i] << " = >\t Price : " << price_v[i] << endl;
				}

				while (a != 0)
				{
					cout << "Enter your choice: " << endl;
					cin >> count;
					cout << "Enter quantity(in kg/nos.): " << endl;
					if (count <= 5 && count > 0)   //in kgs
					{
						cin >> q2;
						iname[l] = veggies[count - 1];
						purchase(count, q2);
					}
					cout << "To exit the Fruits and Vegetables section,press 0,to continue press 1" << endl;
					cin >> a;

				}
				cout << "------------------------------------------" << endl;
				if (a == 0)
				{
					count = 0;
					choice = 0;
				}
			}

		}
	}
};
class customer
{
	int cust_id;
	string customer_name;
	string phno;

public:
	customer() {}
	customer(string c, string p, int id)
	{
		customer_name = c;
		phno = p;
		cust_id = id;
	}

	void customer_details()
	{
		cout << "Enter your name: ";
		cin >> customer_name;
		cout << "Enter customer id: ";
		cin >> cust_id;
		cout << "Enter phone number: ";
		cin >> phno;
		system("cls");
		cout << "WELCOME ";
		for (int i = 0; i < customer_name.length(); i++)
		{
			cout << char(toupper(customer_name[i]));
		}
		cout << "\n";
		cout << "Customer ID: " << cust_id << endl;
		cout << "Phone no." << phno << endl;

	}

};
class invoice :public items, public customer
{
	float billamount = 0, disct = 0;
	int billno;
	float Totalquantity = 0;
public:

	float calc_bill()
	{
		for (int i = 0; i < l; i++)
		{
			billamount = billamount + quant[i] * price[i];
		}
		return billamount;
	}
	void discount(float billamount)
	{
		if (billamount >= 15000)
		{
			disct = (15 * billamount) / 100;

		}
		else if (billamount >= 10000 && billamount < 15000)
		{
			disct = (10 * billamount) / 100;
			billamount = billamount - disct;
		}
		else if (billamount >= 5000 && billamount < 10000)
		{
			disct = (5 * billamount) / 100;
			billamount = billamount - disct;
		}
		cout << disct;
	}
	void display_bill()
	{
		system("cls");
		cout << "\n\t **** Grocery store management system ****\n";
		cout << "   Here are our store discount rates\n";
		cout << "***************************************\n";
		cout << "|-------------------------------------|\n";
		cout << "| greater than 5000 buy at 5%% discount   |\n";
		cout << "|-------------------------------------|\n";
		cout << "| greater than 10000 buy at 10%% discount |\n";
		cout << "|-------------------------------------|\n";
		cout << "| greater than 15000 buy at 15%% discount |\n";
		cout << "***************************************\n\n";
		billno = 1 + (rand() % 10000);
		cout << "Bill no: " << billno << "\n";
		cout << "  | --------------------------------------------------------\n";
		cout << "  |  Product\tQuantity\tPrice   |\n";
		cout << "  |--------------------------------------------------------\n";
		for (int j = 0; j < l; j++)
		{
			cout << ++m << iname[j] << setw(10) << quant[j] << setw(10) << price[j] << endl;
		}

		//calculating the quantity
		for (int i = 0; i < l; i++)
		{
			Totalquantity = Totalquantity + quant[i];
		}

		cout << endl << "| Total product(s): " << Totalquantity << "\t" << "Total amount" << setw(10) << calc_bill() << endl;
		cout << "|--------------------------------------------------------" << endl;
		cout << "|                   \tDiscount        " << setw(10);
		discount(billamount);
		cout << endl;
		cout << "|--------------------------------------------------------" << endl;
		cout << "|                  \tPayable amount " << billamount - disct << endl;
		cout << "|--------------------------------------------------------";
	}

};

void main()
{
	invoice j;
	cout << "GROCERY STORE MANAGEMENT SYSTEM" << endl;
	j.customer_details();
	j.show_items();
	j.display_bill();
	_getch();
}