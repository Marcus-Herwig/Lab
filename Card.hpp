#include <string>

using namespace std;

class Card
{
    private:
        string name;
        int mana_cost;
        int attack;
        int defense;
        string type;
    
    public:
        Card(string name, int mana_cost, int attack, int defense, string Cardtype);
        void display();
        int getDefense();
};