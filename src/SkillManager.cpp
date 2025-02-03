#include "../headers/SkillManager.h"
#include "../exception/headers/SkillQueueException.h"
#include <sstream>


SkillManager::SkillManager(){
    std::vector<std::pair<SkillInterface*, SkillType>> startSkills = {{new SkillDD, SkillType::DD}, {new SkillShrapnel, SkillType::SHRAPNEL}, {new SkillScan, SkillType::SCAN}};
    srand(time(NULL));
    int seed = rand();
    std::default_random_engine generator(seed);
    shuffle(startSkills.begin(), startSkills.end(), generator);
    skills.push(startSkills[0]);
    skills.push(startSkills[1]);
    skills.push(startSkills[2]);
}

SkillManager::SkillManager(std::string save){
    std::istringstream ss(save);
    short x;
    while(!skills.empty())skills.pop();
    while (ss >> x) {
        switch (x) {
            case 1:
                skills.push(std::make_pair(new SkillDD(), SkillType::DD));
                break;
            case 2:
                skills.push(std::make_pair(new SkillScan(), SkillType::SCAN));
                break;
            case 3:
                skills.push(std::make_pair(new SkillShrapnel(), SkillType::SHRAPNEL));
                break;
        }
    }
}

void SkillManager::AddSkill() {
    skills.push(GenerateSkill());
}

std::pair <SkillInterface*, SkillType> SkillManager::GenerateSkill() {
    srand(time(NULL));
    SkillType newSkill= static_cast<SkillType>(rand() % LAST);
    switch (newSkill) {
        case DD:
            return(std::make_pair(new SkillDD(), DD));
        case SCAN:
            return (std::make_pair(new SkillScan(), SCAN));
        case SHRAPNEL:
            return (std::make_pair(new SkillShrapnel(), SHRAPNEL));
    }
}

AttackResult SkillManager::UseSkill(BattleGround& bg) {
    try{
        if(skills.empty()) throw SkillQueueException();
        AttackResult result = skills.front().first->skill_use(bg);
        if(result == FULLDESTROED)AddSkill();
        skills.pop();
        return result;
    }
    catch(SkillQueueException& e){
        std::cout << e.what() << std::endl;
        return FAILED;
    }
}

SkillType SkillManager::GetSkillType(){
    if(skills.empty()) return LAST;
    return skills.front().second;
}

short SkillManager::GetSkillCnt(){
    return skills.size();
}

std::string SkillManager::back_up(){
    std::string data = "";
    std::queue<std::pair <SkillInterface*, SkillType>> skill_copy = skills;
    while(!skill_copy.empty()){
        switch (skill_copy.front().second) {
            case DD:
                data += "1 ";//DD
                break;
            case SCAN:
                data += "2 "; //SCAN
                break;
            case SHRAPNEL:
                data += "3 "; //SHRAPNEL
                break;
        }
        skill_copy.pop();
    }
    return data;
}