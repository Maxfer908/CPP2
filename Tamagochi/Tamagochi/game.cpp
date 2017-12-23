#include <string>

using namespace std;

string Name()
{
            string names[29] = { "Abby", "Angel", "Annie", "Baby", "Bailey", "Bandit", "Bear", "Bella", "Bob", "Boo",
            "Boots", "Bubba", "Buddy", "Buster", "Cali", "Callie", "Casper", "Charlie",
            "Chester", "Chloe", "Cleo", "Coco", "Cookie", "Cuddles", "Daisy", "Dusty", "Felix",
            "Fluffy", "Garfield" };
            return names[rand() % 29];
}




class Game
{
    void print(int id) {
        cout << "Name: " <<
            animals[id].getName() << endl << "Health: " << animals[id].getHealth() <<
            endl << "Happiness: " <<
            animals[id].getHappiness() << endl <<
            "Food: " << animals[id].getFood() << endl
            << endl;
    }
public:
    Game(int _amount) {
        for (int i = 0; i < _amount; i++){
            Animal a;
            animals[i] = a;
        }
        amount = _amount;
    }
    ~Game() {}

    void stats() {
        for (int i = 0; i < amount; i++){
            cout<<animals[i].getName() << endl << "Health: " << animals[i].getHealth() <<
                endl << "Happiness: " <<
                animals[i].getHappiness() << endl <<
                "Food: " << animals[i].getFood() << endl
                << endl;
        }
    }
    bool command(string action, int id) {
        if (id < amount)
        {
            if (action == "feed")
                animals[id].feed();
            if (action == "wash")
                animals[id].wash();
            if (action == "play")
                animals[id].play();
            return true;
        }
        else return false;
    }
    bool step() {
        for (int i = 0; i < amount; i++)
            animals[i].tick();
        for (int i = 0; i <= amount; i++)
            if (animals[i].isAlive())
                return false;
        return true;

    }

};


