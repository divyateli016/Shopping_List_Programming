/*
 * ShoppingList.h
 *
 *  Created on: Apr 7, 2025
 *      Author: divya
 */

#ifndef SHOPPINGLIST_H_
#define SHOPPINGLIST_H_
#include "Item.h"
#include <map>
#include <vector>
#include <memory>
#include <string>
#include <iostream>

class ShoppingList
{
private:
 std::map<std::string,std::vector<std::unique_ptr<Item>>>items;
public:
	ShoppingList();
	/*
	 * Adds the given item to the shopping list. The item must have been
	 * allocated on the heap. The shopping list is
	 * responsible for removing it from the heap when it goes out of the
	 * existence
	 */
	ShoppingList& operator+=(Item *item);
	/*
	 * Print all item from the shopping list which must be brouught until the
	 * given time. The output is grouped by the shops,At the end of the output
	 * all collected notes are printed.
	 */
	void print(int until)const;
	/*
	 * Writes to the given ostream all items by invoking their save methos
	 */
	void save(std::ostream& to);
	/*
	 * Reads from the given istream all items by invoking the
	 * different types restores methods until a valid pointer to an object
	 * is returned
	 */
	void load(std::istream& from);
	virtual ~ShoppingList();
};

#endif /* SHOPPINGLIST_H_ */
