#include "Card.hpp"
#include "URL.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main(int argc, char** argv)
{
    URL* u1 = new URL("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
    string jsonString = u1->getContents();
    json parsedJson = json::parse(jsonString);
    Card* theCards[parsedJson.size()];
    Card* theMinionCards[0];
    int counter;
    if(parsedJson.is_array())
    {
        for(int i = 0; i < parsedJson.size(); i++)
        {
            json currValue = parsedJson[i];
            if(currValue.is_object())
            {
                string name = currValue.value("name", "N/A");
                int attack = currValue.value("attack", -1);
                int defense = currValue.value("health", -1);
                int manaCost = currValue.value("cost", -1);
                string cardType = currValue.value("type", "N/A");
                if(cardType == "MINION")
                {
                    theCards[i] = new Card(name, manaCost, attack, defense, cardType);
                    //theCards[i]->display();
                    counter++;
                }
                
            }
        }
    }
    int a;
    for(int i = 0; i<= parsedJson.size(); i++)
    {
       Card* temp = theCards[i];
       a = i -1;
    
        while(a >= 0 && theCards[a]->getDefense() > temp->getDefense())
        {
            theCards[a+1] = theCards[a];
            a = a -1;
        }
        theCards[a+1] = temp;
    }
   /* for(int i = 0; i< counter; i++)
    {
        theCards[i]->display();
    }*/
    cout << "Number of Minion cards: " << counter << endl;
    return 0;
}