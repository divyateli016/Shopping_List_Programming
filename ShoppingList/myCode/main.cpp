// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include "Item.h"
#include "Food.h"
#include "ostream"
#include "fstream"
#include "ShoppingList.h"
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
std::string splitAt(std::string& remainder, char separator)
{
	auto pos = remainder.find(separator);
	auto sub = remainder.substr(0,pos);
	if(pos==std::string::npos)
	{
		string result = remainder;

		remainder.clear();
		return result;
	}

	remainder=remainder.substr(pos+1);
	return sub;

}
int main ()
{
    // TODO: Add your program code here
	cout << "ShoppingList started." << endl << endl;


	//Item i1("Bread","Kirana",2026);
	//std::string print = i1.toString();
	//std::cout<<print<<endl;
	//i1.save(cout);
	//Item *item = Item::restore("Item;Soap;DM;2026");
	//cout<<item->getName()<<" "<<item->getShop()<<" "<<item->getUntil()<<endl;

   /**
	Food F1("Bread","Bakery",2026,false);
	//std::string result = F1.toString();
	//cout<<F1.getNeedsCooling()<<endl;
	//cout<<result<<endl;
	F1.save(cout);
	Food *f1 = Food::restore("Food;Item;Soap;DM;2027;true");
	cout<<f1->getName()<<" "<<f1->getShop()<<" "<<f1->getUntil()<<" "<<f1->getNeedsCooling()<<endl;
	**/


	 ShoppingList list;
	Item *i1=new Item("Bread","Kirana",2026);
	Item *i2=new Item("Soap","DM",2026);
	Food* f1 = new Food("Milk","Dairy",2027,true);
	Food* f2 = new Food("Cheese","Dairy",2028,false);
	//ShoppingList list();
	list+=i1;
	list+=i2;
	list+=f1;
	list+=f2;

	list.print(2028);
	list.save(cout);

	ofstream file("data.txt");
	list.save(file);

	ifstream ifs("data.txt");

	list.load(ifs);




	return 0;
}
