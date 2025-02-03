#ifndef SB_PROJECT_SKILLDD_H
#define SB_PROJECT_SKILLDD_H
#include "SkillInterface.h"
class SkillDD: public SkillInterface{
public:
    SkillDD() = default;
    virtual AttackResult skill_use(BattleGround& bg) override;
    ~SkillDD() = default;
};
#endif //SB_PROJECT_SKILLDD_H
