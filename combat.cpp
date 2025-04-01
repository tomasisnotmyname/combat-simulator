#include "combat.hh"
#include <random>
#include <iostream>
#include <algorithm>

void attack(shared_ptr<Unit>& attacker, shared_ptr<Unit>& defender, mt19937 gen)
{
    uniform_int_distribution<> dist(1, attacker->getDamage());
    int damage = dist(gen);
    defender->takeDamage(damage);
    cout << attacker->getName() << " inflicted " << damage << " damage to "
         << defender->getName() << " (" << defender->getHealthString() << ')' << endl;
}

struct
{
    bool operator()(const shared_ptr<Unit>& u1, const shared_ptr<Unit>& u2) const
    {
        return u1->getSpeed() > u2->getSpeed();
    }
}
battleLess;

void battle(vector<shared_ptr<Unit>>& units, int round_limit)
{
    mt19937 gen(0);
    shuffle( units.begin(), units.end(), gen );

    sort( units.begin(), units.end(), battleLess);

    int rounds = 0;
    // end_battle allows to ensure battle ends if there is no one alive.
    bool end_battle = false;

    uniform_int_distribution<> dist(0, units.size()-1);
    while( rounds++ != round_limit && end_battle != true )
    {
        end_battle = true;

        cout << "Round " << rounds << "------" << endl;
        for ( vector<Unit>::size_type i = 0 ; i < units.size() ; i++ )
        {
            shared_ptr<Unit> attacker = units[i];
            if( attacker->isAlive() && units.size() != 1)
            {
                end_battle = false;
                shared_ptr<Unit> defender;
                unsigned int random_i = dist(gen);

                // Prevents units attacking themselves.
                if( (defender = units[random_i]) == attacker )
                {
                    random_i++;
                    if( random_i >= units.size() )
                    {
                        random_i = 0;
                    }
                }
                // Searches for an alive unit.
                while( not (defender = units[random_i])->isAlive() )
                {
                    random_i++;
                    if( random_i >= units.size() )
                    {
                        random_i = 0;
                    }
                }
                // If the only alive unit is the attacker, battle ends.
                if( (defender = units[random_i]) == attacker )
                {
                    cout << attacker->getName() << " is the only one left alive." << endl;
                    end_battle = true;
                    break;
                }
                else
                {
                    attack(attacker,defender, gen);
                }
            }
        }
    }
    cout << "Battle has concluded.\n" << endl;
}
