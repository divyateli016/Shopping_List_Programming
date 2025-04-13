/*
 * ShoppingList.cpp
 *
 *  Created on: Apr 7, 2025
 *      Author: divya
 */

#include "ShoppingList.h"
#include "Food.h"
#include "Item.h"

ShoppingList::ShoppingList()
{
	// TODO Auto-generated constructor stub

}

ShoppingList::~ShoppingList()
{
	// TODO Auto-generated destructor stub
}

ShoppingList& ShoppingList::operator +=(Item *item)
{
	std::unique_ptr<Item>toadd = std::unique_ptr<Item>(item);
	auto findshop = items.find(item->getShop());
	if(findshop!=items.end())
	{
		findshop->second.push_back(std::move(toadd));
	}
	else
	{
		std::vector<std::unique_ptr<Item>>add;
		add.push_back(move(toadd));
		this->items.insert(make_pair(item->getShop(),move(add)));
	}
	std::cout<<"Size after adding is "<<items.size()<<std::endl;

	return *this;
}

void ShoppingList::print(int until) const
{
	for (auto &pair : items)
	{
		std::cout << pair.first << ":" << std::endl;
		for (const auto &item : pair.second)
		{
			if (item.get()->getUntil() <= until)
			{
				Item *ip = item.get();
				Food *fp = dynamic_cast<Food*>(ip);
				if (fp)
				{
					std::string result = fp->toString();
					std::cout << fp->toString() << std::endl;
				}
				else
				{

					std::cout << ip->toString() << std::endl;
				}

			}
		}
	}

}

void ShoppingList::save(std::ostream &to)
{
	for(const auto &pair : items)
	{
		for(const auto &item:pair.second)
		{
			Food *fp = dynamic_cast<Food*>(item.get());
			if(fp)
			{
				fp->save(to);
			}
			else
			{
				item.get()->save(to);
				to<<std::endl;
			}
		}
	}
}

void ShoppingList::load(std::istream &from)
{
	std::string data;
	std::string first;
	Item*  ip;
	Food *fp;
	while(getline(from,data))
	{
		auto pos = data.find(';');
		first = data.substr(0,pos);
		if(first == "Item")
		{
			ip = Item::restore(data);
			std::cout<<std::endl;
			//std::cout<<ip->getName()<<" "<<ip->getShop()<<" "<<ip->getUntil();
			std::cout<<ip->toString();
		}
		else if(first == "Food")
		{
			fp= Food::restore(data);
			std::cout<<std::endl;
			//std::cout<<fp->getName()<<" "<<fp->getShop()<<" "<<fp->getUntil()<<" "<<fp->getNeedsCooling();
			std::cout<<fp->toString();
		}

	}

}
