/* Project: Combat Simulator
 * File: combat.hh
 *
 * Description:
 *  This module contains all logic and functions required for randomized battling.
 * Could be modified into having two sides in each conflict, and less
 * randomized targetting, as well as more complex initiative system,
 * allowing very fast units to act more than once per round.
 */

#ifndef COMBAT_HH
#define COMBAT_HH

#include "unit.hh"
#include <vector>

// Random damage (based on Attacker's attribute) is inflicted on defender,
// and the numbers are printed.
void attack(shared_ptr<Unit>& attacker, shared_ptr<Unit>& defender);

// Each round starting from fastest unit, each unit attacks random other unit,
// until everyone is dead, or when rounds == round_limit.
void battle ( vector<shared_ptr<Unit>>& units, int round_limit );

#endif // COMBAT_HH
