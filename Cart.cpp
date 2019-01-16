
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

const int number = 20;
struct store{
	string serial;
	string date;
	string item_name;
	int taxNum;
	int items;
	double price;
	store* next;
	
};


void add(store* &head , string item_n, int items, string serial, double price);
store* Build ();
store* checkout(store* &ptr,string nameArr[number], int quanArr[number], double price[number], int &counter);
store* search(store* &ptr, string name, int quan);
//store* checkout();
void update(store* &head, int items, string serial);
void printList(store *ptr);
void remove(store* &head, int items, string serial);
void menu();
void showList(store *ptr);
void about();
void recipet(string nameArr[number], int quanArr[number],int counter,double price[number]);



//void printRank(store *ptr);

int main (){
	
store* head;
store* final;
int tax_rate,items,choice,quantityy;
double price;
string namesOfitems[number];
int quan[number];
double thePrice[number];
int count;
string seriall,name;
ifstream infile;

head = Build();
	
infile.open("storeData.txt");	
    if (head==NULL)
{
        cout<<"Cannot open Input file"<<endl;
        cout<<"Exit the program"<<endl;
return 1;
}



do
{
	
	menu();
cin >> choice;

switch (choice)
{
case 1: cout << "   Name:  " << "               Serial:   " << "        Quantity:  " << "      Price:  " << endl;
printList(head);
break;
case 2:
cout << "Enter the Serial Number: " << endl;
cin >> seriall;
cout << "Enter the quantity number:  " << endl;
cin >> quantityy;
update(head, quantityy, seriall);
break;
case 3: 
cout << "Enter the Serial Number: " << endl;
cin >> seriall;
cout << "Enter the quantity number:  " << endl;
cin >> quantityy;
remove(head, quantityy, seriall);
break;
case 4:
cout << "Enter the name of the item: " << endl;
cin >> name;
cout << "Enter the price: "<< endl;
cin >> price;
cout << "Enter the Serial Number: " << endl;
cin >> seriall;
cout << "Enter the quantity number:  " << endl;
cin >> quantityy;
add(head , name, quantityy , seriall, price);
break;
case 5:
checkout(head, namesOfitems ,quan,thePrice,count);

printList(head);
break;
case 6:
about();
break;
case 9:
recipet(namesOfitems ,quan,count,thePrice);
break;
default: cout << "Invalid, try again." << endl;
break;

}

}	
while (choice != 9);
	
	
	return 0;
}
void showList(store *ptr)
{
	
while (ptr != NULL)
{
cout << ptr->item_name << "  " << ptr->serial << endl;
ptr = ptr->next;
}
}

store* Build ()
{

store* head = NULL;

string itemName;
string SerialNum;
string line;
int quintity,price;

ifstream myfile ("storeData.txt");
if(myfile.is_open()){

while(getline (myfile,line))
{

stringstream lineStream(line);

lineStream >> itemName;

lineStream >> SerialNum;

lineStream >> quintity;

lineStream >> price;

// Delete the date
add(head , itemName, quintity, SerialNum, price);
}
	
myfile.close();	
}	


return head;
}

void add(store* &head, string item_n, int items, string serial, double price)
{
store *current=head;
store *last;
store *newNode;


bool found = false;
newNode = new store;
newNode->serial = serial;
newNode->item_name = item_n;
newNode->items = items;
newNode->price = price;
newNode->next = NULL;



if (head == NULL)

	head = newNode; ////////////////////////////////////

else 
{
current = head; 
while (current != NULL && !found)
if (current->item_name < item_n)/////////////////////////////////////////////////////////
found = true;
else
{
	last = current;
	current = current->next;
}
if (current == head )
{
newNode->next=head;
head=newNode;
}
else
{
last->next=newNode;
newNode->next=current;
}

	
}	
	
}

void update(store* &head, int items, string serial)
{

store* current = head;

while (current != NULL){
	

	if ((current->serial == serial) && (current->items == items))
	{
	cout << "The name of the item " << endl;
	cout << current->item_name << endl;
	cout << "The serial number for the item:   ";
	cout << current->serial << endl;
	cout << "The quantity:   ";
	cout << current->items << endl;
	cout << "Enter the number of quantity:  "<<endl;
	cin >> current->items;
	cout << "The price:   $" ;
	cout << current->price << endl;
	
	return;
	}
	current = current->next;
}	
cout << "There is no info for this Serial number:  " << serial << endl;	
	
}

void remove(store* &head, int items, string serial)
{
store* current = head;
store* last = NULL;

while (current != NULL)
{
	
if ((current->serial <= serial) && (current->items == items))	
{
if ((current->serial <= serial) && (current->items == items))	
{
	last->next = current->next;
	delete current;
	
return;
}
}
last = current;
current=current->next;
}
cout << "Not found !!" << endl << endl;
}
void menu()
{
cout << "***** Welcome to iSmart Store *****" << endl << endl;

cout << "To make a selection enter the number and press enter: " << endl;
cout << "1:To print items prices: " << endl;
cout << "2:To update quantity number: "<<endl;
cout << "3:To remove an item: " << endl;
cout <<"4:To add a new item: " << endl;
cout <<"5:To add items to the cart: " << endl;
cout <<"6:About the program: " << endl;
cout << "9:To show the recipet: " << endl;
}
void printList(store *ptr)
{
store* current = ptr;
cout << "   ";
while (current != NULL)
{
cout  << current->item_name << setw(16) << current->serial << setw(16) << current->items << setw(16) << "$" <<  current->price << setw(16) << endl;
current=current->next;
}
}
void about()
{
	cout << endl << "***********************************************************************" << endl;
cout << "This program was designed by programmer: Mohammed Alzuwayyid." << endl << "2019." << endl;
	cout << endl << "***********************************************************************" << endl;
}

store* checkout(store* &ptr,string nameArr[number], int quanArr[number], double price[number], int &counter){
	
	store* head;
	store* temp;
	//head = Build ();
	head = ptr;
	string name;
	int quan;
	int x=0;
	/*while (head != NULL)
	{
	cout << head->items << endl;
	head = head->next;
	}*/

	
	cout << "******************************************************" << endl;
	cout << "To buy an item, write it's name and the quantity: "<< endl;
	cout <<"Write the name: ";
	cin >> name;
	cout << "How many quantities you need?";
	cin >> quan;
	cout << endl << endl;
	cout << "The entered item:  " << name << endl;
	cout << "The quantity:  " << quan << endl;
	cout << "******************************************************" << endl;
/*	while (head != NULL)
	{
quanArr[x] = quan;
nameArr[x] = name;
x++;
cout << nameArr[x] << "     " << quanArr[x] << endl;
head = head->next;
	}*/

search(head, name, quan);
	
cout << "   ";
while (head != NULL)
{
if (name == head->item_name)
{
quanArr[counter] = quan;
nameArr[counter] = name;
price[counter] = head->price;

counter++;

}
head = head->next;


}

//counter = counter - 2;
}
store* search(store* &ptr, string name, int quan)
{
	store* head = ptr;
	while (head != NULL)
	{
//	if ((head->item_name == name) && (head->items == quan))	
if (head->item_name == name)	
	{
	head->items = head->items - quan;
	}
	head = head->next;
	}	
}
void recipet(string nameArr[number], int quanArr[number],int counter,double price[number])
{
double calc;
int quant;
double tax = 0.08875;
double taxPrice;
double final;
cout << endl << "*******************************************************************************"<<endl;
cout << "The number of items ---------> " << counter << endl;
cout << "         Name:  " << "          Quantity:  " << "       Price:  " << endl;
for (int x=0; x < counter;x++)
{
cout << setw(16) << nameArr[x] << setw(16) << quanArr[x] <<setw(16) << price[x] <<  endl;
quant = quanArr[x] * price[x];
calc = quant + calc;
quant = 0;
}

taxPrice = calc*tax;
final = taxPrice + calc;
cout << setprecision(2) << fixed << showpoint << setw(10);
cout << setw(16) <<"The price before tax:" << "    " << "$"<<setw(2)<< calc <<  endl;
cout <<setw(16) << "The tax of your purchase:" <<" " <<" $"<< setw(1)<< taxPrice << endl;
cout <<setw(16) << "Your total price is:" << "    "  <<" $" << setw(2)<< final <<endl;
cout << endl << "*******************************************************************************"<<endl;
}
