#include "../headers/SkillShrapnel.h"
AttackResult SkillShrapnel::skill_use(BattleGround &bg) {
    int random_base = bg.get_size();
    srand(time(NULL));
    int seed = rand();
    std::default_random_engine generator(seed);
    std::vector<std::pair<short, short>> random_ship;
    for(short x = 0; x < random_base; x++){
        for(short y = 0; y < random_base; y++){
            std::pair<bool, bool> status = bg.get_status(x, y);
            if(!status.first) continue;
            else {
                if (status.second) {
                    random_ship.emplace_back(x, y);
                }
            }
        }
    }
    shuffle(random_ship.begin(), random_ship.end(), generator);
    return bg.attack(random_ship[0].first, random_ship[0].second, true);
}
