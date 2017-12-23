#include "animal.h"
Animal::Animal()
    {
        name = "Bilbo";
        health = 5000+ (rand() % 1000);
        happiness = 5000 + (rand() % 1000);
        food = 5000 + (rand() % 1000);
    }
    Animal::~Animal() {}
    void Animal::feed()
    {
        food += 1000;
    }
    void Animal::play() {
        happiness += 1000;
    }

    void Animal::wash() {
        health += 1000;
    }
    bool Animal::isAlive(){
        if ((food <= 0) || (happiness <= 0) || (health <= 0))
            return false;
        return true;
    }

    void Animal::tick()
    {
        food-=100;
        happiness-=100;
        health-=100;
    }
