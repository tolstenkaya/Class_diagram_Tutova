#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
const int num_of_tables = 20;
const int n_dishes = 50;
const int n_staff = 10;
bool CheckingNumbers(const string& s) {
	bool f = true;
	for (auto& i : s)
	{
		if (!isdigit(i))
		{
			f = false;
			break;
		}
	}
	return f;
}
bool CheckingSymbols(char ch)
{
	if (ch == '+' || ch == '-') return true;
	else return false;
}
class Storage
{
public:
	string products[100] = { "flour", "milk", "potato", "tomato", "cucumber", "cheese", "camambert", "mozzarella", "olives", "mushrooms", "sausage", "chicken", "yeast", "basil", "onion", "olive oil", "cacao", "corn", "cottage cheese", "savoyardi", "eggs", "sour cream", "sugar", "salt", "condensed milk", "vanilla sugar", "peaches", "sweet cherry", "dark chocolate", "butter", "fresh shrimp", "anchovy filets", "pepper", "pumpkin" };
	float kol_products[100] = { 15, 8, 15, 5, 5, 2, 2, 2, 0.5, 2.5, 4, 5, 0.5, 0.5, 3, 3, 4, 5, 3, 50, 5, 5, 3, 3, 0.5, 3, 3, 2, 3, 4, 4, 0.5, 5 };
	int amount_products = 34;
};
class Provider
{
public:
	Storage S;
	string name;
	string adress;
	string all_products[51] = { "flour", "milk", "potato", "tomato", "cucumber", "cheese", "camambert", "mozzarella", "olives", "mushrooms", "sausage", "chicken", "yeast", "basil", "onion", "olive oil", "cacao", "corn", "cottage cheese", "savoyardi", "eggs", "sour cream", "sugar", "salt", "condensed milk", "vanilla sugar", "peaches", "sweet cherry", "dark chocolate", "butter", "fresh shrimp", "anchovy filets", "pepper", "pumpkin", "wine", "tea", "coffe", "meat", "juice", "rice", "buckwheat", "apple", "strawberry", "pear","grape", "dill", "parsley", "zucchini", "eggplant", "carrot", "salad pepper" };
	float num_of_all_products[51] = { 100,50,40,25,25,20,20,20,10, 25, 50, 35, 25, 10, 15, 10, 10, 15, 20, 20, 200, 20, 50, 50, 20, 5, 15, 10, 5, 25, 50, 40, 5, 15, 10, 5,5, 50, 10, 20,20,5,5,5,5,3,3,15, 15,15,15 };
	float price_for_one[51] = { 3,4,5,2,4,5,2.2,1.5,3.7,4,1.2,3,5.5, 6, 5,3,6,2,1,3,4,2.3,3.4,1.2,1.4,3.2,2,3,4,5,2,3,4,5,2.2,1.5,3.7,4,3,5.5,6,3,6,2,1,3,4,2.3,1.4,1.5,3.2 };
	string ordered_products[100];
	float ord_kol[100];
	float price_ord_prod[100];
	float sum_paid_for_product[100];
	int count_ord_pr = 0;
	int count = 51;
	float pay;
	int pos = 0;
	int kol_1_product = 0;
	Provider()
	{
		name = "TradeMaster";
		adress = "Dnipro-city, st. European, 4";
		pay = 0;
	}
	bool checkPaid()
	{
		if (pay == 0) { cout << "Payment has not been made.\n"; return false; }
		else { cout << "Payment was successful!\n"; return true; }
	}
	void SendProduct()
	{
		if (checkPaid())
		{
			cout << "Your order is on the way.\n";
			S.products[S.amount_products] = all_products[pos];
			S.kol_products[S.amount_products] = kol_1_product;
		}
		else
		{
			cout << "Your order has not been paid.\n";
		}
	}
};
class Document
{
public:
	float number;
	string date;
	Document()
	{
		number = 0;
		date = "0";
	}
	Document(float n, string d)
	{
		number = n;
		date = d;
	}
};
class Order_products : public Document
{
public:
	Order_products()
	{
		number = 1;
		date = "0";
	}
	Order_products(float n, string d)
	{
		number = n;
		date = d;
	}
	string ordered_products[100];
	float price_products[100];
	int count_products[100];
	int IDproduct = 0;
	float sum_paid = 0;
	void form_Order_products()
	{
		ofstream file("ordered products.txt", ios::app);
		if (file.is_open())
		{
			file << "Number: " << IDproduct+1 << "\n";
			file << "The date of payment: " << date << "\n";
			for (int i = 0; i < IDproduct+1; i++)
			{
				file << i + 1 << ". " << ordered_products[i] << " -- $" << price_products[i] << "\n";
				file << count_products[i] << " * " << price_products[i] << " = " << count_products[i] * price_products[i] << "\n";
			}
			file << "Total order value: $" << sum_paid << "\n";
		}
		file.close();
	}
};
class Invoice : public Document
{
public:
	Invoice()
	{
		number = 1;
		date = "0";
	}
	Invoice(float n, string d)
	{
		number = n;
		date = d;
	}
	string FIO_recipient;
	string send_product[100];
	float count_send_product[100];
	float price_for_one_send_product[100];
	int amount_of_products=0;
	float sum_cost;
	Provider P;
	void formInvoice()
	{
		if (P.checkPaid())
		{
			ofstream file("invoice.txt", ios::app);
			if (file.is_open())
			{
				file << "Number of invoice: " << number << "\n";
				file << "Date: " << date << "\n";
				for (int i = 0; i < amount_of_products; i++)
				{
					file << i + 1 << ". " << send_product[i] << " -- $" << price_for_one_send_product[i] << "\n";
					file << count_send_product[i] << " * " << price_for_one_send_product << " = " << count_send_product[i] * price_for_one_send_product[i] << "\n";
				}
				file << "Total amount: " << sum_cost << "\n";
				file << "FIO recipient: " << FIO_recipient << "\n";
			}
			file.close();
		}
		else
		{
			cout << "The invoice cannot be generated because the order has not yet been paid to the supplier.\n";
		}
		number++;
	}
};
class Cheque : public Document
{
public:
	Cheque()
	{
		number = 1;
		date = '0';
	}
	Cheque(float n, string d)
	{
		number = n;
		date = d;
	}
	float sum_paid;
	int amount_of_order_dish=0;
	string order_dish[100];
	float price_order_dish[100];
	void formCheque()
	{
		ofstream file("cheque.txt", ios::app);
		if (file.is_open())
		{
			file << "Account number: " << number << "\n";
			file << "Date: " << date << "\n";
			for (int i = 0; i < amount_of_order_dish; i++)
			{
				file << i + 1 << ". " << order_dish[i] << " -- $" << price_order_dish[i] << "\n";
			}
			file << "Total amount: " << sum_paid << "\n\n";
		}
		file.close();
	}
};
class Visitor
{
public:
	char name[100];
	int age;
	float cash;
	int table;
	int order[50];
	int n_order;
	float sum_order;
	Visitor()
	{
		*name = '0';
		age = 0;
		cash = 0;
		table = 0;
		sum_order = 0;
		n_order = 0;
		*order = NULL;
	}
	void input(int num)
	{
		cout << "Enter your name: ";
		gets_s(name);
		table = num;
		cout << "Please, enter your amount of cash ($): ";
		cin >> cash;
		sum_order = 0;
		*order = 0;
		n_order = 0;
	}
	void Order(int meals)
	{
		order[n_order] = meals;
		n_order++;
	}
	bool Pay()
	{
		cash -= sum_order;
		if (cash > 0) { return true; }
		else { cash += sum_order; return false; }
	}
	bool leave()
	{
		if (sum_order == 0 && n_order == 0) return true;
		else return false;
	}
};
class Staff
{
public:
	string FIO;
	string vacancies[5] = { "manager" , "waiter" , "pr-manager" , "chef" ,"accounting" };
	string job_title;
	float salary;
	Staff()
	{
		FIO = "Petrov H. O.";
		job_title = "manager";
		salary = 1800;
	}
	Staff(string n, string j, float s)
	{
		FIO = n;
		job_title = j;
		salary = s;
	}
	void input()
	{
		cin.ignore();
		cout << "Enter name: ";
		getline(cin, FIO);
	ret: cout << "Enter the job title: ";
		getline(cin, job_title);
		int f = 0;
		for (int i = 0; i < 5; i++)
		{
			if (job_title == vacancies[i])
			{
				f = 1;
			}
		}
		if (f == 0) { cout << "Incorrect data entered! The entered position is not in the list of vacancies.\n"; goto ret; }
		cout << "Enter the average salary: ";
		cin >> salary;
	}
	void output()
	{
		cout << "Name: " << FIO << endl;
		cout << "Job title: " << job_title << endl;
		cout << "Salary: " << salary << endl;
	}
};
class Chef :public Staff
{
public:
	Chef()
	{
		FIO = "Fill L. R.";
		job_title = "chef";
		salary = 2500;
		count_dishes = 30;
	}
	string menu[n_dishes] = { "Pizza Margarita", "Pizza Capricciosa", "4 cheeses", "Pizza Marinara", "Pepperoni pizza", "Seafood pizza","Pasta Carbonara", "Pasta Bolognese", "Campanelle with tuna and vegetables", "Pasta with pesto cream sause", "Minestrone", "Chicken soup", "Mushroom cream soup", "Pumpkin puree soup", "Salad 'Greek", "'Caesar' salad with chicken breast", "Salmon carpaccio", "Tuna tartare with avocado", "Camembert with lingonberry sause", "Curly Pinscher","Cheesecake 'New York'", "Panna-cotta", "Tiramisu", "Green tea", "Fruit tea", "Espresso", "Americano", "Cappucino","Cocoa","Juice in assortment", "emmental cheese", "gorgonzola cheese", "parmesan cheese", "oregano"};
	int code_menu[n_dishes] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
	int count_dishes=30;
	float price_menu[n_dishes] = { 5.75, 5.5, 7, 5, 6.4, 6.8, 5.25, 6.9, 8, 6.4, 6,  5.7, 5, 5.2, 6.3, 7.5, 7.25,  6.9, 7, 4.7,4.25, 4,4.85, 1.5, 1.75, 2, 2.25, 2.15, 2.5, 1.9 };
	float pay_provider = 0;
	Provider P;
	Order_products OP;
	Invoice I;
	Storage S;
	void displayMenu()
	{
		cout << "----------------------PIZZA----------------------\n";
		cout << "_________________________________________________\n";
		for (int i = 0; i < 6; i++)
		{
			if (i == 2)
			{
				cout << i + 1 << ". " << menu[i] << "\t\t\t\t| $" << price_menu[i] << "\t|\n";
			}
			else
			{
				cout << i + 1 << ". " << menu[i] << "\t\t\t| $" << price_menu[i] << "\t|\n";
			}
		}
		cout << "_________________________________________________\n";
		cout << "\n-----------------PASTA & RISOTTO-----------------\n";
		cout << "_________________________________________________\n";
		for (int i = 6; i < 10; i++)
		{
			if (i == 8 || i == 9)
			{
				cout << i + 1 << ". " << menu[i] << "\t| $" << price_menu[i] << "\t|\n";
			}
			else
			{
				cout << i + 1 << ". " << menu[i] << "\t\t\t| $" << price_menu[i] << "\t|\n";
			}
		}
		cout << "_________________________________________________\n";
		cout << "\n----------------------SOUPS----------------------\n";
		cout << "_________________________________________________\n";
		for (int i = 10; i < 14; i++)
		{
			if (i == 10)
			{
				cout << i + 1 << ". " << menu[i] << "\t\t\t\t| $" << price_menu[i] << "\t|\n";
			}
			else
			{
				cout << i + 1 << ". " << menu[i] << "\t\t\t| $" << price_menu[i] << "\t|\n";
			}
		}
		cout << "_________________________________________________\n";
		cout << "\n---------------------SALADS----------------------\n";
		cout << "_________________________________________________\n";
		for (int i = 14; i < 16; i++)
		{
			if (i == 15)
			{
				cout << i + 1 << ". " << menu[i] << "\t| $" << price_menu[i] << "\t|\n";
			}
			else
			{
				cout << i + 1 << ". " << menu[i] << "\t\t\t| $" << price_menu[i] << "\t|\n";
			}
		}
		cout << "_________________________________________________\n";
		cout << "\n-------------------APPETIZERS--------------------\n";
		cout << "_________________________________________________\n";
		for (int i = 16; i < 19; i++)
		{
			if (i == 17)
			{
				cout << i + 1 << ". " << menu[i] << "\t\t| $" << price_menu[i] << "\t|\n";
			}
			else
			{
				if (i == 18)
				{
					cout << i + 1 << ". " << menu[i] << "\t| $" << price_menu[i] << "\t|\n";
				}
				else
				{
					cout << i + 1 << ". " << menu[i] << "\t\t\t| $" << price_menu[i] << "\t|\n";
				}
			}
		}
		cout << "_________________________________________________\n";
		cout << "\n--------------------DESERTS---------------------\n";
		cout << "_________________________________________________\n";
		for (int i = 19; i < 23; i++)
		{
			if (i == 20)
			{
				cout << i + 1 << ". " << menu[i] << "\t\t| $" << price_menu[i] << "\t|\n";
			}
			else
			{
				if (i == 21 || i == 22)
				{
					cout << i + 1 << ". " << menu[i] << "\t\t\t\t| $" << price_menu[i] << "\t|\n";
				}
				else
				{
					cout << i + 1 << ". " << menu[i] << "\t\t\t| $" << price_menu[i] << "\t|\n";
				}
			}
		}
		cout << "_________________________________________________\n";
		cout << "\n---------------------DRINKS----------------------\n";
		cout << "_________________________________________________\n";
		for (int i = 23; i < 30; i++)
		{
			if (i == 29)
			{
				cout << i + 1 << ". " << menu[i] << "\t\t\t| $" << price_menu[i] << "\t|\n";
			}
			else
			{
				cout << i + 1 << ". " << menu[i] << "\t\t\t\t| $" << price_menu[i] << "\t|\n";
			}
		}
		cout << "_________________________________________________\n";
	}
	bool checkingStorage()
	{
		string check_product;
		cout << "Enter the name of product you want to check for stock: ";
		getline(cin, check_product);
		int f = 0;
		for (int i = 0; i < S.amount_products; i++)
		{
			if (check_product == S.products[i])
			{
				f = 1;
				cout << "The product you are looking for is in stock\n";
				cout << "-" << S.products[i] << " available in amount of " << S.kol_products[i] << "\n";
				return true;
			}
		}
		if (f == 0) {
			cout << "The product you are looking for are out of stock\n"; return false;
		}
	}
	void orderProduct()
	{
		string order;
		cout << "Enter the name of product you want to order: ";
		getline(cin, order);
		int kol;
		cout << "Enter the amount of " << order << ": ";
		cin >> kol;
		cin.ignore();
		int f = 0;
		for (int i = 0; i < P.count; i++)
		{
			if (order == P.all_products[i])
			{
				f = 1;
				P.ordered_products[P.count_ord_pr] = order;
				P.price_ord_prod[P.count_ord_pr] = P.price_for_one[i];
				OP.ordered_products[OP.IDproduct] = order;
				I.send_product[I.amount_of_products] = order;
				if (kol <= P.num_of_all_products[i])
				{
					P.kol_1_product = kol;
					P.ord_kol[P.count_ord_pr] = kol;
					pay_provider += kol * P.price_for_one[i];
					P.sum_paid_for_product[P.count_ord_pr] = kol * P.price_for_one[i];
					OP.price_products[OP.IDproduct] = P.price_for_one[i];
					OP.sum_paid = pay_provider;
					OP.count_products[OP.IDproduct] = kol;
					P.pos = i;
					I.price_for_one_send_product[I.amount_of_products] = P.price_for_one[i];
					I.sum_cost = pay_provider;
					I.count_send_product[I.amount_of_products] = kol;
				}
				else
				{
					char ch;
					cout << "There are no products in the desired quantity\n";
					cout << "Available quantity of " << order << ": " << P.num_of_all_products[i] << "\n";
					system("cls");
					cout << "Order all available quantity of the product?\n";
					cout << "1 - Yes.\n";
					cout << "2 - No.\n";
					cout << "Your choice: ";
					ch = _getch();
					switch (ch)
					{
					case '1':
					{
						P.kol_1_product = P.num_of_all_products[i];
						OP.count_products[OP.IDproduct] = P.num_of_all_products[i];
						P.sum_paid_for_product[P.count_ord_pr] = P.num_of_all_products[i] * P.price_for_one[i];
						pay_provider += P.num_of_all_products[i] * P.price_for_one[i];
						OP.sum_paid = pay_provider;
						I.sum_cost = pay_provider;
						I.count_send_product[I.amount_of_products] = P.num_of_all_products[i];
						P.ord_kol[P.count_ord_pr] = kol;
						
					}
					break;
					}
				}
				OP.IDproduct++;
				I.amount_of_products++;
				P.count_ord_pr++;
			}
		}
		system("cls");
		if (f == 0) { cout << "Sorry, but the product you are looking for is not in stock at the supplier.\n"; }
		else
		{
			cout << "You ordered " << order << " in amount of " << P.kol_1_product<< "\n";
		}
	}
	void displayOrder()
	{
		cout << "\tYOUR ORDER\n";
		cout << "---------------------------------\n";
		for (int i = 0; i < P.count_ord_pr; i++)
		{
			cout << i + 1 << ". " << P.ordered_products[i] << " (in the amount of " << P.ord_kol[i] << ")" << "\n";
			cout << P.ord_kol[i] << " * " << P.price_ord_prod[i] << " = $" << P.sum_paid_for_product[i] << "\n";
			cout << "---------------------------------\n";
		}
		cout << "ORDERED COST: $" << pay_provider << "\n";
		cout << "---------------------------------\n";
	}
};
class Waiter : public Chef
{
public:
	int n_visitor = 0;
	int n_taken_tables = 0;
	int n_free_tables = num_of_tables;
	int table[num_of_tables] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int free_table[num_of_tables];
	int taken_table[num_of_tables];
	Visitor* mas;
	string str_order;
	int num_order;
	float payment;
	Cheque cheque;
	Waiter()
	{
		FIO = "Romanov A. S.";
		job_title = "waiter";
		salary = 1500;
		for (int i = 0; i < n_free_tables; i++)
		{
			free_table[i] = table[i];
		}
		num_order = 0;
		*taken_table = 0;;
	}
	~Waiter()
	{
		delete[] mas;
	}
	Visitor* addVisitor(int num)
	{
		mas = (Visitor*)realloc(mas, (n_visitor + 1) * sizeof(Visitor));
		mas[n_visitor].input(num);
		n_visitor++;
		return mas;
	}
	bool checkFreeTable(int num)
	{
		int f = 0;
		for (int i = 0; i < n_taken_tables; i++)
		{
			if (num == taken_table[i])
			{
				f++;
			}
		}
		if (f == 0)return true;
		else return false;
	}
	void seatTable(Visitor V)
	{
		string str_table;
		int f = 0;
		if (n_taken_tables < num_of_tables)
		{
			cout << "Free number of tables.\n";
			for (int i = 0; i < n_free_tables; i++)
			{
				cout << free_table[i] << " ";
			}
			do {
			ret:cout << "\nYour choice: ";
				cin >> str_table;
				if (CheckingNumbers(str_table)) { V.table = stoi(str_table); }
				if (!CheckingNumbers(str_table) || V.table <= 0 || V.table > 20) { cout << "\nIncorrect data entered! Try again!\n"; }
			} while (!CheckingNumbers(str_table));
			for (int i = 0; i < num_of_tables; i++)
			{
				if (V.table == table[i])
				{
					f = 1;
				}
			}
			if (f == 1 && checkFreeTable(V.table))
			{
				cout << "This tables is free. You are welcome)\n";
				taken_table[n_taken_tables] = V.table;
				n_taken_tables++;
				for (int i = 0; i < n_free_tables; i++)
				{
					if (V.table == free_table[i])
					{
						for (int j = i; j < n_free_tables - 1; j++)
						{
							free_table[j] = free_table[j + 1];
						}
						n_free_tables--;
					}
				}
			}
			else
			{
				cout << "We're sorry, but this table is not available! Please choose another.\n";
				goto ret;
			}
			f = 0;
		}
		else
		{
			cout << "There are no free seatplaces, sorry.\n";
		}
		cin.ignore();
		system("pause");
		system("cls");
		addVisitor(V.table);
		system("cls");
	}
	void takeOrder()
	{
		int pos = 0;
		string check_name;
		cout << "Enter your name: ";
		cin >> check_name;
		int check_table;
		cout << "Enter your number of table: ";
		cin >> check_table;
		int f = 0;
		for (int i = 0; i < n_visitor; i++)
		{
			if (mas[i].name == check_name && mas[i].table == check_table)
			{
				pos = i;
				f = 1;
			}
		}
		if (f == 1)
		{
			displayMenu();
			char check = '+';
			do {
				cout << "What do you want to eat?\n";
			ret3: cout << "Your choice (enter the number of meals): ";
				cin >> str_order;
				if (CheckingNumbers(str_order)) { num_order = stoi(str_order); }
				if (!CheckingNumbers(str_order) || num_order <= 0 || num_order > 30) { cout << "\nIncorrect data entered! Try again!\n"; goto ret3; }
				num_order--;
				mas[pos].Order(num_order);
			ret4: cout << "\nIf you have made a final order? than press '-' Else - press '+'.\n\n";
				check = _getch();
				if (!CheckingSymbols(check)) { cout << "\nIncorrect data entered! Try again!\n"; goto ret4; }
			} while (check == '+');
			system("cls");
			if (mas[pos].n_order != 0) {
				cout << "------------------YOUR ORDER-------------------\n";
				cout << "_________________________________________________\n";
				for (int i = 0; i < mas[pos].n_order; i++)
				{
					cout << i + 1 << ". " << menu[mas[pos].order[i]] << "   --   $" << price_menu[mas[pos].order[i]] << "\n";
					mas[pos].sum_order += price_menu[mas[pos].order[i]];
					cheque.order_dish[i] = menu[mas[pos].order[i]];
					cheque.price_order_dish[i] = price_menu[mas[pos].order[i]];

				}
				cout << "_________________________________________________\n";
				cout << "------------------ORDER COST-------------------\n";
				cout << "_________________________________________________\n";
				cout << "                    " << mas[pos].sum_order << "$\n";
				cheque.sum_paid = mas[pos].sum_order;
				cheque.amount_of_order_dish = mas[pos].n_order;
			}
			else
			{
				cout << "You have not ordered yet.\n";
			}
		}
		else { system("cls"); cout << "There are no visitors with entered name on the table.\n"; }
	}
	void takePayment()
	{
		int pos = 0;
		string check_name;
		cout << "Enter your name: ";
		cin >> check_name;
		int check_table;
		cout << "Enter your number of table: ";
		cin >> check_table;
		int f = 0;
		for (int i = 0; i < n_visitor; i++)
		{
			if (mas[i].name == check_name && mas[i].table == check_table)
			{
				pos = i;
				f = 1;
			}
		}
		system("cls");
		if (f == 1 && mas[pos].n_order > 0)
		{
			cheque.number = n_visitor;
			bool b = mas[pos].Pay();
			if (!b)
			{
				while (!b)
				{
					system("cls");
					cout << "You don't have enough money(( Change your order.\n\n";
					system("pause");
					delOrder(pos);
					b = mas[pos].Pay();
					if (mas[pos].sum_order == 0) { cout << "You have no orders.\n"; break; }
				}
				if (b == true && mas[pos].sum_order != 0) {
					cout << "You have to pay for the order " << mas[pos].sum_order << " $\n";
					payment = mas[pos].sum_order;
					system("pause");
					system("cls");
					cout << "Payment was successful.\nBon appetit)\n";
				}
			}
			else
			{
				cout << "You have to pay for the order " << mas[pos].sum_order << " $\n";
				payment = mas[pos].sum_order;
				system("pause");
				system("cls");
				cout << "Payment was successful.\nBon appetit)\n";
			}
			memset(mas[pos].order, 0, sizeof(mas[pos].order));
			mas[pos].n_order = 0;
			mas[pos].sum_order = 0;
		}
		else
		{
			cout << "You have not ordered yet.\n";
		}
	}
	void delOrder(int pos)
	{
		string del_meal;
		int num_del_meal = 0;
		system("cls");
		cout << "------------------YOUR ORDER-------------------\n";
		cout << "_________________________________________________\n";
		for (int i = 0; i < mas[pos].n_order; i++)
		{
			cout << i + 1 << ". " << menu[mas[pos].order[i]] << "(CODE IN MENU: " << mas[pos].order[i] << ")   --$" << price_menu[mas[pos].order[i]] << "\n";
		}
		cout << "_________________________________________________\n";
		cout << "------------------ORDER COST-------------------\n";
		cout << "_________________________________________________\n";
		cout << "                    " << mas[pos].sum_order << "$\n";
	ret5: cout << "Change the CODE of meals you want to remove from the order: ";
		cin >> del_meal;
		if (CheckingNumbers(del_meal)) { num_del_meal = stoi(del_meal); }
		if (!CheckingNumbers(del_meal) || num_del_meal < 0 || num_del_meal > 30) { cout << "\nIncorrect data entered! Try again!\n"; goto ret5; }
		int f = 0;
		int del_pos = 0;
		for (int i = 0; i < mas[pos].n_order; i++)
		{
			if (num_del_meal == mas[pos].order[i])
			{
				del_pos = i;
				f = 1;
			}
		}
		mas[pos].sum_order -= price_menu[mas[pos].order[del_pos]];
		if (f == 1)
		{
			for (int j = del_pos; j < mas[pos].n_order; j++)
			{
				mas[pos].order[j] = mas[pos].order[j + 1];
			}
			mas[pos].n_order--;
			system("cls");
			cout << "You order has been updated.\n";
		}
		else { cout << "You have not ordered yet.\n"; }
		system("pause");
		system("cls");
		cout << "------------------YOUR ORDER-------------------\n";
		cout << "_________________________________________________\n";
		for (int i = 0; i < mas[pos].n_order; i++)
		{
			cout << i + 1 << ". " << menu[mas[pos].order[i]] << "   --   $" << price_menu[mas[pos].order[i]] << "\n";
			cheque.order_dish[i] = menu[mas[pos].order[i]];
			cheque.price_order_dish[i] = price_menu[mas[pos].order[i]];
		}
		cout << "_________________________________________________\n";
		cout << "------------------ORDER COST-------------------\n";
		cout << "_________________________________________________\n";
		cout << "                    " << mas[pos].sum_order << "$\n";
		cheque.sum_paid = mas[pos].sum_order;
		cheque.amount_of_order_dish = mas[pos].n_order;
		system("pause");
		system("cls");
	}
	void deleteVisitor()
	{
		int pos = 0;
		string check_name;
		cout << "Enter your name: ";
		cin >> check_name;
		int check_table;
		cout << "Enter your number of table: ";
		cin >> check_table;
		int f = 0;
		for (int i = 0; i < n_visitor; i++)
		{
			if (mas[i].name == check_name && mas[i].table == check_table)
			{
				pos = i;
				f = 1;
			}
		}
		system("cls");
		if (f == 0)
		{
			cout << "You have not ordered yet.\n";
		}
		if (f == 1 && mas[pos].n_order > 0)
		{
			cout << "You haven't paid for the order yet!\n";
			system("pause");
			system("cls");
		}
		if (f == 1 && mas[pos].n_order == 0)
		{
			cout << "Bye-bye! See you later)\n";
			int k = 0;
			int p = 0;
			for (int i = 0; i < n_taken_tables; i++)
			{
				if (mas[pos].table == taken_table[i])
				{
					k = 1;
					p = i;
					for (int j = i; j < n_taken_tables; j++)
					{
						taken_table[j] = taken_table[j + 1];
					}
					n_taken_tables--;
				}
			}
			if (k == 1)
			{
				free_table[n_free_tables] = mas[pos].table;
				n_free_tables++;
			}
			for (int j = pos; j < n_visitor; j++)
			{
				mas[j] = mas[j + 1];
			}
			mas = (Visitor*)realloc(mas, (n_visitor - 1) * sizeof(Visitor));
			n_visitor--;
		}
	}
};
class PR_Manager : public Staff
{
public:
	int key = 0;
	PR_Manager()
	{
		FIO = "Topol K. A.";
		job_title = "pr-manager";
		salary = 2200;
	}
	void saveToFile1(Chef C)
	{
		ofstream file("menu.txt");
		if (file.is_open())
		{
			file << C.count_dishes << "\n";
			for (int i = 0; i < C.count_dishes; i++)
			{
				file << i + 1 << ". " << C.menu[i] << " -- $" << C.price_menu[i] << "\n";
			}
		}
		file.close();
	}
	void readFromFile1()
	{
		string file_menu[100];
		float file_price_menu[100];
		int file_count_dishes;
		ifstream file("menu.txt");
		if(file.is_open())
		{
			file >> file_count_dishes;
			cout << "Count of dishes: "<<file_count_dishes<<"\n";
		for (int i = 0; i <= file_count_dishes; i++)
		{
			getline(file,file_menu[i]);
			cout << file_menu[i] << "\n";
		}
		}
		file.close();
	}
	void correctMenu(Chef C)
	{
		char ch;
		cout << "1 - Add the meals to the menu.\n";
		cout << "2 - Remove the meals from the menu.\n";
		cout << "3 - Display new menu.\n";
		cout << "Your choice: ";
		ch = _getch();
		switch (ch)
		{
		case '1':
		{
			system("cls");
			string meals;
			float price;
			if (key == 0)
			{
				cout << "Enter the name of new meal: ";
				getline(cin, meals);
				cout << "Enter the price of the new meal: ";
				cin >> price;
				key++;
			}
			else
			{
				cin.ignore();
				cout << "Enter the name of new meal: ";
				getline(cin, meals);
				cout << "Enter the price of the new meal ($): ";
				cin >> price;
			}
			C.menu[C.count_dishes] = meals;
			C.code_menu[C.count_dishes] = C.count_dishes + 1;
			C.price_menu[C.count_dishes] = price;
			C.count_dishes++;
			system("cls");
			cout << "New meal added to the menu.\n";
			break;
		}
		case '2':
		{
			system("cls");
			string meals;
			cout << "Enter the name of meal you want to delete: ";
			getline(cin, meals);
			int pos = 0;
			int f = 0;
			for (int i = 0; i < C.count_dishes; i++)
			{
				if (C.menu[i] == meals)
				{
					pos = i;
					f = 1;
				}
			}
			if (f == 1)
			{
				for (int j = pos; j < C.count_dishes; j++)
				{
					C.menu[j] = C.menu[j + 1];
					C.code_menu[j] = C.code_menu[j + 1];
					C.price_menu[j] = C.price_menu[j + 1];
				}
				C.menu[C.count_dishes] = "0";
				C.code_menu[C.count_dishes] = 0;
				C.price_menu[C.count_dishes] = 0;
				C.count_dishes--;
			}
			break;
		}
		case '3':
		{
			system("cls");
			readFromFile1();
			break;
		}
		}
	}
};
class Accounting : public Staff
{
public:
	float incomes=0;
	float credit_arrears=0;
	float stocks=0;
	float salary_payment=0;
	Accounting()
	{
		FIO = "Derek S. I.";
		job_title = "accounting";
		salary = 2200;
		credit_arrears = 0;
	}
	void AddIncomes(float payment)
	{
		incomes += payment;
	}
	void FormReportIncomeAndExpense()
	{
		cout << "Incomes: " << incomes << "\n";
		cout << "Stocks: " << stocks << "\n";
	}
	void PaySalaries(float* mas, int kol)
	{
		for (int i = 0; i < kol; i++)
		{
			salary_payment += mas[i];
		}
		cout << "Salaries are paid for employees.\n";
	}
	float PayProvider(float pay_provider, Provider P)
	{
		if (incomes < pay_provider)
		{
			cout << "Insufficient revenue to pay supplier for products.\n";
			credit_arrears = pay_provider-incomes;
			cout << "So, accounts payable in the amount of $" << credit_arrears << " was formed.\n";
			P.pay = pay_provider;
		}
		else
		{
			P.pay = pay_provider;
			cout << "The products have been paid to the supplier in amount of $" <<P.pay << ".\n";
			incomes -= pay_provider;
			stocks += pay_provider;
		}
		return P.pay;
	}
};
class Manager : public Staff
{
public:
	Waiter W;
	PR_Manager PR;
	Chef C;
	Accounting A;
	float pay_provider;
	Manager()
	{
		FIO = "Petrov H. O.";
		job_title = "manager";
		salary = 1800;
	}
	Staff S[n_staff] =
	{
		{W.FIO, W.job_title, W.salary},
		{PR.FIO, PR.job_title, PR.salary},
		{C.FIO,C.job_title, C.salary},
		{A.FIO, A.job_title, A.salary},
		{FIO, job_title, salary}
	};
	float salary_staff[n_staff] = { W.salary, PR.salary, C.salary, A.salary, salary };
	int count_staff = 5;
	void  addStaff()
	{
		S[count_staff].input();
		salary_staff[count_staff] = S[count_staff].salary;
		count_staff++;
	}
	void deleteStaff()
	{
		string del_name;
		cin.ignore();
		cout << "Enter the full name of employee you want to fire: ";
		getline(cin, del_name);
		int f = 0;
		for (int i = 0; i < count_staff; i++)
		{
			if (S[i].FIO == del_name)
			{
				f = 1;
				for (int j = i; j < count_staff; j++)
				{
					S[j] = S[j + 1];
				}
				S[count_staff].FIO = "0";
				S[count_staff].job_title = "0";
				S[count_staff].salary = 0;
				count_staff--;
			}
		}
		if (f == 0) { cout << "There is no worker with the given name.\n"; }
		else { cout << "Employee removed.\n"; }
	}
	void displayStaff()
	{
		for (int i = 0; i < count_staff; i++)
		{
			S[i].output();
			cout << "\n";
		}
	}
};
class Financial_reports
{
	Accounting A;
	string EGRPOU;
	string data;
	void formFinancialReport()
	{
		ofstream file("financial report.txt", ios::app);
		if (file.is_open())
		{
			file << "Incomes: $" << A.incomes << "\n";
			file << "Costs: $" << A.stocks << "\n";
			file << "Credit arears: $" << A.credit_arrears << "\n";
			file << "Salary payment: $" << A.salary_payment << "\n";
			file << "Net profit: $" << A.incomes - A.stocks << "\n";
		}
		file.close();
	}
};
int main()
{
	char choice;
	Visitor V;
	Waiter W;
	PR_Manager PR;
	Chef C;
	Accounting A;
	Manager M;
	Provider P;
	Order_products OP;
	Invoice I;
	Cheque ch;
	Storage S;
	cout << "\t\t\t\tWelcome to Farfalle Restaurant!\n";
	system("cls");
	do {
		system("cls");
		cout << "Who are you?\n";
		cout << "1 - I'm a visitor.\n";
		cout << "2 - I'm a manager.\n";
		cout << "3 - I'm a PR-manager.\n";
		cout << "4 - I'm a chef.\n";
		cout << "5 - I'm a accountant.\n";
		cout << "6 - I'm a provider.\n";
		cout << "Your choice: ";
		choice = _getch();
		switch (choice)
		{
		case '1':
		{
			system("cls");
			char ch;
			do {
				system("cls");
				cout << "1 - Seat on the table.\n";
				cout << "2 - Make Order.\n";
				cout << "3 - Pay for the order.\n";
				cout << "4 - Leave the restaurant.\n";
				cout << "Esc. - Exit.\n";
				cout << "Your choice: ";
				ch = _getch();
				switch (ch)
				{
				case '1':
				{
					system("cls");
					W.seatTable(V);
					system("pause");
					break;
				}
				case '2':
				{
					system("cls");
					W.takeOrder();
					system("pause");
					break;
				}
				case '3':
				{
					system("cls");
					W.takePayment();
					system("pause");
					break;
				}
				case '4':
				{
					system("cls");
					W.deleteVisitor();
					system("pause");
					break;
				}
				}
			} while (ch != 27);
			system("pause");
			break;
		}
		case '2':
		{
			system("cls");
			char ch;
			do {
				system("cls");
				cout << "1 - Show all employees.\n";
				cout << "2 - Add the employee.\n";
				cout << "3 - Remove the employee.\n";
				cout << "Esc. - Exit.\n";
				cout << "Your choice: ";
				ch = _getch();
				switch (ch)
				{
				case '1':
				{
					system("cls");
					M.displayStaff();
					system("pause");
					break;
				}
				case '2':
				{
					system("cls");
					M.addStaff();
					system("pause");
					break;
				}
				case '3':
				{
					system("cls");
					M.deleteStaff();
					system("pause");
					break;
				}
				}
			} while (ch != 27);
			system("pause");
			break;
		}
		case '3':
		{
			system("cls");
			char ch;
			do {
				system("cls");
				cout << "1 - Correct menu.\n";
				cout << "Esc. - Exit.\n";
				cout << "Your choice: ";
				ch = _getch();
				switch (ch)
				{
				case '1':
				{
					system("cls");
					PR.correctMenu(C);
					PR.saveToFile1(C);
					cout << "Changes is saved!\n";
					system("pause");
					break;
				}
				}
			} while (ch != 27);
			system("pause");
			break;
		}
		case '4':
		{
			system("cls");
			char ch;
			do {
				system("cls");
				cout << "1 - Display menu.\n";
				cout << "2 - Check the availability of product in the storage.\n";
				cout << "3 - Order product from a supplier.\n";
				cout << "4 - Display order.\n";
				cout << "Esc. - Exit.\n";
				cout << "Your choice: ";
				ch = _getch();
				switch (ch)
				{
				case '1':
				{
					system("cls");
					C.displayMenu();
					system("pause");
					break;
				}
				case '2':
				{
					system("cls");
					C.checkingStorage();
					system("pause");
					break;
				}
				case '3':
				{
					system("cls");
					C.orderProduct();
					system("pause");
					break;
				}
				case '4':
				{
					system("cls");
					C.displayOrder();
					system("pause");
					break;
				}
				}
			} while (ch != 27);
			system("pause");
			break;
		}
		case '5':
		{
			system("cls");
			char ch;
			do {
				system("cls");
				cout << "1 - Pay the supplier for the products.\n";
				cout << "2 - Pay salaries to employees.\n";
				cout << "Esc. - Exit.\n";
				cout << "Your choice: ";
				ch = _getch();
				switch (ch)
				{
				case '1':
				{
					system("cls");
					C.displayOrder();
					cout << "\n";
					P.pay=A.PayProvider(C.pay_provider,P);
					system("pause");
					break;
				}
				case '2':
				{
					system("cls");
					A.PaySalaries(M.salary_staff, M.count_staff);
					system("pause");
					break;
				}
				}
			} while (ch != 27);
			system("pause");
			break;
		}
		case '6':
		{
			system("cls");
			char ch;
			do {
				system("cls");
				cout << "1 - Order payment verification.\n";
				cout << "2 - Sending ordered products.\n";
				cout << "Esc. - Exit.\n";
				cout << "Your choice: ";
				ch = _getch();
				switch (ch)
				{
				case '1':
				{
					system("cls");
					C.displayOrder();
					cout << "\n";
					P.checkPaid();
					system("pause");
					break;
				}
				case '2':
				{
					system("cls");
					P.SendProduct();
					system("pause");
					break;
				}
				}
			} while (ch != 27);
			system("pause");
			break;
		}
		}
	} while (choice != 27);
}