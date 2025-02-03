#ifndef SB_PROJECT_SKILLSHRAPNEL_H
#define SB_PROJECT_SKILLSHRAPNEL_H
#include "SkillInterface.h"
class SkillShrapnel: public SkillInterface{
public:
    SkillShrapnel() = default;
    virtual AttackResult skill_use(BattleGround& bg) override;
    ~SkillShrapnel() = default;
};
#endif //SB_PROJECT_SKILLSHRAPNEL_H
