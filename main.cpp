/* Project: Combat Simulator
 * File: main.cpp
 *
 * Description:
 *  Incredibly simple prototype that allows creating
 * many units of different types, and seeing them battle,
 * choosing random enemies and dealing random damage.
 *  User can create new types of units giving them a name,
 * max health, damage, and speed, then this information is stored,
 * and each unit of the type remembers where.
 *  As there might be many many units of the same type, having
 * them all store the same information is inefficient, and
 * this implementation avoids that by using smart pointers.
 *  Original implementation included complex initiative
 * and targetting systems, but was too messy to share.
 *
 * Author: Tomás Henrique Strotsjak Barata
 */

#include "unit.hh"
#include "combat.hh"
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

using namespace std;


void print_units( const vector<shared_ptr<Unit>>& units )
{
    cout << setw(10) << "UNITS"
         << setw(5) << "HP"
         << setw(9) << " DAMAGE "
         << setw(6) << "SPEED" << endl;

    for( const shared_ptr<Unit>& u_ptr : units )
    {
        u_ptr->print();
    }
    cout << endl;
}


int main()
{
    //"type name", {max health,damage,speed}
    Unit::addType("Paladin", {5, 4, 4});
    Unit::addType("Peasant", {2, 2, 5});
    Unit::addType("Ghoul", {2, 7, 7});

    vector<shared_ptr<Unit>> units;
    units.push_back(make_shared<Unit>(Unit("Paladin")));
    units.push_back(make_shared<Unit>(Unit("Paladin")));
    units.push_back(make_shared<Unit>(Unit("Paladin")));
    units.push_back(make_shared<Unit>(Unit("Peasant")));
    units.push_back(make_shared<Unit>(Unit("Ghoul")));
    units.push_back(make_shared<Unit>(Unit("Ghoul")));
    units.push_back(make_shared<Unit>(Unit("Ghoul")));
    units.push_back(make_shared<Unit>(Unit("Ghoul")));
    print_units(units);

    battle(units, 5);
    print_units(units);

    return 0;
}
