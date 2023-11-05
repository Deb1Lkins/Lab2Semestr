#define _CRT_SECURE_NO_WARNINGS
#include "RPGamer.h"
#include <ctime>

int counter = 0;

RPGamer::RPGamer(): id(counter++), name(nullptr), condit(condition::normaly), race(species::human), move(true){}

RPGamer::RPGamer(char* name, condition condit, species race, bool move) :id(counter++), name(name), condit(condit), race(race), move(move) 
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

RPGamer::RPGamer(const RPGamer& other) : id(other.id), condit(other.condit), race(other.race), move(other.move)
{
	this->name = new char[strlen(other.name)+1];
	strcpy(this->name, other.name);
}

RPGamer::~RPGamer()
{
	if (name != nullptr)
	{
		delete[]name;
	}
	name = nullptr;
}

int RPGamer::GetId()
{
	return id;
}

char* RPGamer::GetName()
{
	char* temp = new char[strlen(name) + 1];
	strcpy(temp, name);
	return temp;
}

condition RPGamer::GetCondit()
{
	return condit;
}

species RPGamer::GetRace()
{
	return race;
}

bool RPGamer::GetMove()
{
	return move;
}

void RPGamer::SetName(char* name)
{
	if (strlen(this->name) < strlen(name))
	{
		delete[]this->name;
		this->name = new char[strlen(name)+1];
	}
	strcpy(this->name, name);
}

void RPGamer::SetCondit(condition condit)
{
	this->condit = condit;
}

void RPGamer::SetMove(bool move)
{
	this->move = move;
}

RPGamer& RPGamer::operator=(const RPGamer& other)
{
	if (this != &other)
	{
		this->SetName(other.name);
		const_cast<species&>(race) = other.race;
		condit = other.condit;
		move = other.move;
	}
	return *this;
}

bool RPGamer::operator==(const RPGamer& other)
{
	return _stricmp(name, other.name) == 0 && condit == other.condit && race == other.race && move == other.move;
}

void RPGamer::Print()
{
	cout << *this;
}

ostream& operator<<(ostream& out, RPGamer& other)
{
	int num = other.GetId();
	out << "ID: " << num << endl;
	char* temp = other.GetName();
	out << "Name: " << temp << endl
		<< "Species: ";
	species race = other.GetRace();
	switch (race)
	{
	case species::human:
		out << "human" << endl;
		break;
	case species::elf:
		out << "elf" << endl;
		break;
	case species::dwarf:
		out << "dwarf" << endl;
		break;
	}
	out << "Condit: ";
	condition condit = other.GetCondit();
	switch (condit)
	{
	case condition::normaly:
		out << "normaly" << endl;
		break;
	case condition::paralyzed:
		out << "paralyzed" << endl;
		break;
	case condition::dead:
		out << "dead" << endl;
		break;
	}
	bool move = other.GetMove();
	out << "Move: ";
	switch (move)
	{
	case true:
		out << "can";
		break;
	case false:
		out << "can't";
		break;
	}
	out << endl;
	return out;
}


