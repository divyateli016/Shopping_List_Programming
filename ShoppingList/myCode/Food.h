/*
 * Food.h
 *
 *  Created on: Apr 6, 2025
 *      Author: divya
 */

#ifndef FOOD_H_
#define FOOD_H_
#include "Item.h"

class Food: public Item
{
private:
	bool needsCooling;
public:
	Food(std::string name, std::string shop,int until, bool needsCooling);
	bool getNeedsCooling()const;
	std::set<std::string>getNotes()const;
	std::string toString()const override;
	void save(std::ostream& to)const;
	static Food* restore(std::string line);
	virtual ~Food();
};
std::string splitAt(std::string& remainder, char separator);

#endif /* FOOD_H_ */
