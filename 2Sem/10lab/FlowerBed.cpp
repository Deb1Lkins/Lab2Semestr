#include "FlowerBed.h"
ostream& operator << (ostream& out, const FlowerBed& right)
{
    out << "Номер клумбы: " << right.number << "\n";
    out << "Форма: " << right.form << "\n";
    out << "Цветы: ";
    for (auto data : right.flowers)
    {
        out << data << " ";
    }
    cout << "\n\n\n";

    return out;
}

void FlowerBed::Clone(const FlowerBed& right)
{
    number = right.number;
    form = right.form;
    flowers.clear();
    for (auto r : right.flowers)
    {
        flowers.push_back(r);
    }
}

FlowerBed::FlowerBed()
{
    number = -1;
    form = "Erorr";
    flowers.push_back("Erorr");
}

FlowerBed::FlowerBed(const FlowerBed& right)
{
    Clone(right);
}

FlowerBed::FlowerBed(size_t number_, string form_, list<string> flowers_) : number(number_), form(form_), flowers(flowers_)
{
}

FlowerBed::~FlowerBed()
{
    flowers.clear();
}

FlowerBed& FlowerBed::operator=(const FlowerBed& right)
{
    if (this != &right)
    {
        Clone(right);
    }
    return *this;
}

void FlowerBed::setNumber(size_t number_)
{
    this->number = number_;
}

void FlowerBed::setForm(std::string form_)
{
    this->form = form_;
}

void FlowerBed::setFlowers(std::list<std::string> lst)
{
    flowers.clear();
    for (auto fl : lst)
    {
        flowers.push_back(fl);
    }
}

size_t FlowerBed::getNumber() const
{
    return number;
}

string FlowerBed::getForm() const
{
    return form;
}

list<string> FlowerBed::getFlowers() const
{
    return flowers;
}
