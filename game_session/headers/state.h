#ifndef SB_PROJECT_STATE_H
#define SB_PROJECT_STATE_H
#include "../../headers/BattleGround.h"
#include "../../headers/Ship.h"
#include "../../headers/ShipManager.h"
#include "../../headers/SkillInterface.h"
#include "../../headers/SkillManager.h"
#include "../../headers/SkillScan.h"
//#include "../../input/headers/TerminalInput.h"
#include "fstream"
#include <map>
#include "AI.h"
enum PLAYER{
    P1,
    P2
};
enum CommandType{
    ATTACK = 0,
    START_ROUND = 1,
    START_GAME = 2,
    SAVE = 3,
    LOAD = 4,
    EXIT = 5,
    SKILL = 6,
    CONTINUE = 7,
    LAST_COMMAND = 8,
};
class State{
public:
    ShipManager ship_manager_p1;
    BattleGround battle_ground_p1;
    SkillManager skill_manager_p1;
    ShipManager ship_manager_p2;
    BattleGround battle_ground_p2;
    SkillManager skill_manager_p2;
    AI* ai_p;
    State();
    ~State() = default;
    Status load();
    Status save();
    unsigned int Hash(std::string& str);
    std::string new_hash();
    bool Verify();
    void input_back_up_Ship_Manager(std::string input, PLAYER player);
    void input_back_up_Skill_Manager(std::string input, PLAYER player);
    void input_back_up_Battle_Ground(std::string input, PLAYER player);
    void input_back_up_coords(std::string input, PLAYER player);
    void input_back_up_ai(std::string input);
    void input_save_hash(std::string input);
    friend std::ostream& operator<<(std::ostream& out, State& s);
    friend std::istream& operator>>(std::istream& in, State& s);
private:
    std::string back_up_Ship_Manager_p1_;
    std::string back_up_Ship_Manager_p2_;
    std::string back_up_Skill_Manager_p1_;
    std::string back_up_Skill_Manager_p2_;
    std::string back_up_Battle_Ground_p1_;
    std::string back_up_Battle_Ground_p2_;
    std::string back_up_Skill_pos_p1_;
    std::string back_up_Skill_pos_p2_;
    std::string back_up_coords_p1_;
    std::string back_up_coords_p2_;
    std::string back_up_ai;
    std::string save_hash_;
};

enum Mode{
    READ,
    WRITE
};
class FileRW{
private:
    std::ifstream input;
    std::ofstream output;
public:
    FileRW(std::string filename, Mode mode);
    void read_state(State& state);
    void write_state(State& state);
    bool read_settings(std::map<char, CommandType> &commands);
    FileRW& operator<<(State& state);
    FileRW& operator >>(State& state);
    ~FileRW();
};

#endif //SB_PROJECT_STATE_H
