#include "../headers/SkillDD.h"
AttackResult SkillDD::skill_use(BattleGround& bg) {
    std::pair<short,short> coord = bg.get_coords();
    AttackResult ship_is_dead;
    ship_is_dead = bg.attack(coord.first, coord.second, false);
    if(ship_is_dead != FULLDESTROED)ship_is_dead = bg.attack(coord.first, coord.second, true);
    return ship_is_dead;
}
