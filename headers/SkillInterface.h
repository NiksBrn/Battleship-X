//
// Created by nikit on 15.10.2024.
//

#ifndef SB_PROJECT_SKILLINTERFACE_H
#define SB_PROJECT_SKILLINTERFACE_H
#include <vector>
#include <iostream>
#include "BattleGround.h"
class SkillInterface{
public:
    virtual AttackResult skill_use(BattleGround& bg) = 0;
};
#endif //SB_PROJECT_SKILLINTERFACE_H
