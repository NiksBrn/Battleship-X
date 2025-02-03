#ifndef SB_PROJECT_SESSION_H
#define SB_PROJECT_SESSION_H
#include <iostream>
#include "../../headers/BattleGround.h"
#include "../../headers/Ship.h"
#include "../../headers/ShipManager.h"
#include "../../headers/SkillInterface.h"
#include "../../headers/SkillManager.h"
#include "../../headers/SkillScan.h"
#include "SessionManager.h"
#include "state.h"
#include "../../render/TerminalRender.h"
#include "../../render/Render.h"
#include "AI.h"
#include "../../render/Render.h"
enum GameCondition{
    continue_game,
    ending_game,
    end,
};

class Session{
public:
    Session();
    void new_game();
    void initial_bg(short BG_size);
    void add_ship_to_manager(std::pair<short, Orientation> ship);
    Status add_ship_to_bg(std::pair<short, short> coords, short i);
    void initial_p2();
    std::pair<GameCondition, AttackResult> UseSkill();
    std::pair<GameCondition, AttackResult> attack(short x, short y);
    std::pair<GameCondition, AttackResult> move_ai();
    Status save();
    Status load();
    void clear();
    BattleGround& get_bg_p();
    BattleGround& get_bg_ai();
    short get_cnt_skills();
    SkillType get_skill();
    ~Session() = default;
private:
    State state;
    short cnt_ships;
};
#endif //SB_PROJECT_SESSION_H
