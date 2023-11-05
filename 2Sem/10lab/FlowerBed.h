#ifndef FLOWERBED_H
#define FLOWERBED_H
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
class FlowerBed
{
private:
	size_t number;
	string form;
	list<string> flowers;
	void Clone(const FlowerBed&);
public:
	FlowerBed();
	FlowerBed(const FlowerBed&);
	FlowerBed(size_t number_, string form_, list<string> flowers_);
	~FlowerBed();

	FlowerBed& operator = (const FlowerBed&);

	void setNumber(size_t number_);
	void setForm(std::string form_);
	void setFlowers(std::list<std::string> lst);


	size_t getNumber() const;
	std::string getForm() const;
	std::list<std::string> getFlowers() const;
	friend ostream& operator << (ostream& out, const FlowerBed& right);

};
#endif

