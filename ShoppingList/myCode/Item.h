/*
 * Item.h
 *
 *  Created on: Apr 6, 2025
 *      Author: divya
 */


#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>
#include <string>
#include <set>
#include <memory>
#include <algorithm>

class Item
{
private:
	std::string name;
	std::string shop;
	int until;//just for practice consider year
public:
	Item(std::string name, std::string shop,int until);
	std::string getName()const;
	std::string getShop()const;
	int getUntil()const;
	virtual std::set<std::string>getNotes();
	virtual std::string toString()const;
	virtual void save(std::ostream& to)const;
	static Item* restore(std::string line);
	virtual ~Item();
};
std::string splitAt(std::string& remainder, char separator);
std::ostream& operator<<(std::ostream& lhs, const Item& item);
#endif /* ITEM_H_ */
