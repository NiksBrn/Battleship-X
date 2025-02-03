#include "../headers/SkillScan.h"
AttackResult SkillScan::skill_use(BattleGround &bg) {
    std::pair<int,int> coord = bg.get_coords();
    for(int ix = 0; ix<2; ++ix){
        for (int iy = 0; iy<2; ++iy){
            if(bg.get_status(coord.first+ix, coord.second+iy).second){
                return SCANFOUND;
            }
        }
    }
    return SCANNOTFOUND;
}
