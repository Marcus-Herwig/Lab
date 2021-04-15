#include "Card.hpp"
#include <iostream>

using namespace std;

Card::Card(string name, int mana_cost, int attack, int defense, string Cardtype)
{
    this->name = name;
    this->mana_cost = mana_cost;
    this->attack = attack;
    this->defense = defense;
    this->type = Cardtype;
}

void Card::display()
{
    cout << "Name: " << this->name << endl;
    cout << "Cost: " << this->mana_cost << endl;
    cout << "Attack: " << this->attack << endl;
    cout << "Defense: " << this->defense << endl;
    cout << "Type: " << this->type << endl;
}

int Card::getDefense()
{
    return this->defense;
}