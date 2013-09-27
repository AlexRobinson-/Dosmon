#include "UserAttributeHelper.h"

#include <cmath>

/* CON/DECON */

/**
 * UserAttributeHelper constructor
 *
 * @author Alex Robinson
 */
UserAttributeHelper::UserAttributeHelper()
{
    //ctor
}

/**
 * UserAttributeHelper destructor
 *
 * @author Alex Robinson
 */
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

/**
 * Generates the base maximum health for the User.
 *
 * This is a level based attribute, and produces the base maximum health. Stat points/items may increase or decrease this value.
 *
 * @param int level
 *
 * @return int
 *
 * @author Alex Robinson
 */
int UserAttributeHelper::calculateMaxHealth(int level)
{
    int health = 1.3 * (pow(level, 1.3)) * 10;
    return health;
}

/**
 * Generates the base maximum experience points required for the User to level up.
 *
 * This is a level based attribute, and produces the base maximum experience points needed to level up. Stat points/items may increase or decrease this value.
 *
 * @param int level
 *
 * @return int
 *
 * @author Alex Robinson
 */
int UserAttributeHelper::calculateMaxExperience(int level)
{
    int experience = floor(pow(1.4, level) * 3);
    return experience;
}

/**
 * Generates the stat points to be given to the User on level up.
 *
 * This is a level based attribute, and produces the base maximum experience points needed to level up. Stat points/items may increase or decrease this value.
 *
 * This method is under review, as 5 stat points may be given to User per level up, rather than generating an amount based on the User's
 * level.
 *
 * @param int level
 *
 * @return int
 *
 * @author Alex Robinson
 */
int UserAttributeHelper::calculateStatPoints(int level)
{
    int statPoints = 5;
    return statPoints;
}
