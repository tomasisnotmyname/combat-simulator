#include "unit.hh"

#include <iostream>
#include <iomanip>
#include <string>


Unit::Unit(const string& type_name)
{
    if( types_.find(type_name) == types_.end() )
    {
        addType(type_name, Attributes{} );
    }
    type_ = types_[type_name];

    // More or less ensures unique names in a very simple way.
    name_ = type_name + ' ' + to_string(type_.use_count() - 1);
    setHealth ( type_->max_health );
}

void Unit::addType(const string &type_name,const Attributes& type_attributes)
{
    if( types_.find(type_name) == types_.end() )
    {
        types_[type_name] = make_shared<Attributes>(type_attributes);
    }
    else
    {
        *types_[type_name] = type_attributes;
    }
}

string Unit::getName() const
{
    return name_;
}

bool Unit::isAlive() const
{
    return health_ > 0;
}

int Unit::getMaxHealth() const
{
    return type_->max_health;
}

int Unit::getHealth() const
{
    return health_;
}

string Unit::getHealthString() const
{
    return to_string(health_) + '/' + to_string(getMaxHealth());
}

void Unit::setHealth(int health)
{
    health_ = health;
}

void Unit::takeDamage(int damage)
{
    health_ -= damage;
}

int Unit::getDamage() const
{
    return type_->damage;
}

int Unit::getSpeed() const
{
    return type_->speed;
}

void Unit::print() const
{
    cout << setw(10) << name_
         << setw(6)  << getHealthString()
         << setw(6) << getDamage()
         << setw(8)  << getSpeed() << endl;
}

unordered_map<string,shared_ptr<Attributes>> Unit::types_;
