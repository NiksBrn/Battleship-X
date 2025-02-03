#ifndef SB_PROJECT_AI_H
#define SB_PROJECT_AI_H
#include <iostream>
#include "../../headers/BattleGround.h"
#include "../../headers/Ship.h"
#include "../../headers/ShipManager.h"
#include "../../headers/SkillInterface.h"
#include "../../headers/SkillManager.h"
#include "../../headers/SkillScan.h"
#include "SessionManager.h"

class AI {
public:
    AI(short bg_size_);
    AI(std::string save);
    std::pair<short, short> get_coords();
    void generate_coords(AttackResult, std::pair<short, short> tec);
    std::vector<std::pair<short, short>> generate_pos(short bg_size);
    Orientation generate_orientation();
    std::string back_up();
    ~AI() = default;
private:
    short bg_size;
    std::priority_queue<std::pair<short, std::pair<short, short>>> izi_win;
};
#endif //SB_PROJECT_AI_H
