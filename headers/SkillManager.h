#ifndef SB_PROJECT_SKILLMANAGER_H
#define SB_PROJECT_SKILLMANAGER_H
#include <queue>
#include "SkillInterface.h"
#include "SkillDD.h"
#include "SkillScan.h"
#include "SkillShrapnel.h"
#include <random>
#include "BattleGround.h"

enum SkillType{
    DD,
    SCAN,
    SHRAPNEL,
    LAST
};


class SkillManager {
public:
    SkillManager();
    SkillManager(std::string);
    std::pair<SkillInterface*, SkillType> GenerateSkill();
    void AddSkill();
    AttackResult UseSkill(BattleGround& bg);
    SkillType GetSkillType();
    short GetSkillCnt();
    std::string back_up();
    ~SkillManager() = default;
private:
    std::queue<std::pair<SkillInterface*, SkillType>> skills;
};
#endif //SB_PROJECT_SKILLMANAGER_H
