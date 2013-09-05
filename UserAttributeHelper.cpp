#include "UserAttributeHelper.h"

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
    int health = level * 10;
    return health;
}

int UserAttributeHelper::calculateMaxExperience(int level)
{
    int experience = level * 10;
    return level;
}
