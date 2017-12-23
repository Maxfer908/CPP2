#ifndef ANIMAL_H
#define ANIMAL_H
#include <QString>

class Animal
{
public:
    Animal();
    ~Animal();
    QString name;
    void feed();
    void wash();
    void play();
    bool isAlive();
    void tick();
    int health;
    int happiness;
    int food;
    int last_action;

};

#endif // ANIMAL_H
