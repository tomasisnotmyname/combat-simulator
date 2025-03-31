/* Project: Combat Simulator
 * File: unit.hh
 *
 * Description:
 *  Class Unit is very simple, but allows for easy modifications to
 * have way more information and attributes that can make the game
 * more like a game.
 */

#ifndef UNIT_HH
#define UNIT_HH

#include <string>
#include <unordered_map>
#include <memory>

using namespace std;

// Struct for easy passing of unit attribute information.
struct Attributes
{
    int max_health = 5;
    int damage = 5;
    int speed = 5;
};

class Unit
{
public:
    // Constructor. Also stores pointer to Unit's type.
    Unit(const string& type_key);

    // Add new type, if name is unique, or overrides old one, if not.
    static void addType(const string& type_name, const Attributes& type_attributes);

    // Simple getter methods.
    string getName() const;
    bool isAlive() const;
    int getMaxHealth() const;
    int getHealth() const;
    int getDamage() const;
    int getSpeed() const;

    // Returns health in format "hp/max_hp".
    string getHealthString() const;

    // Methods to modify unit current health in different ways.
    void setHealth( int health );
    void takeDamage( int damage );

    // Simply prints Units individual attributes and its type's attributes.
    void print() const;

private:
    static unordered_map<string,shared_ptr<Attributes>> types_;

    shared_ptr<Attributes> type_;
    string name_;
    int health_;
};

#endif // UNIT_HH
