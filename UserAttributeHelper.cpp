#include "UserAttributeHelper.h"

#include <cmath>

UserAttributeHelper::UserAttributeHelper()
{
    //ctor
}

UserAttributeHelper::~UserAttributeHelper()
{
    //dtor
}

/**
Generates the max health for the user which is dependent on their level

This is an incomplete class

Things to consider/do:
    - Proper algorithm for generating max health
        - This may or may not use a random number, this is dependant on how we decide to make this work
    - Ability to pass in positions that increase max health
*/
int UserAttributeHelper::calculateMaxHealth(int level)
{
    int health = 1.3 * (pow(level, 1.3)) * 10;
    return health;
}

int UserAttributeHelper::calculateMaxExperience(int level)
{
    int experience = floor(pow(1.4, level) * 3);
    return experience;
}

int UserAttributeHelper::calculateStatPoints(int level)
{
    int statPoints = 5;
    return statPoints;
}
