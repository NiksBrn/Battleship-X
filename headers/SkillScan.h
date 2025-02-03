#ifndef SB_PROJECT_SKILLSCAN_H
#define SB_PROJECT_SKILLSCAN_H
#include "SkillInterface.h"
class SkillScan: public SkillInterface{
public:
    SkillScan() = default;
    virtual AttackResult skill_use(BattleGround& bg) override;
    ~SkillScan() = default;
};

#endif //SB_PROJECT_SKILLSCAN_H
