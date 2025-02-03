#ifndef TRACER_H
#define TRACER_H
#include "../headers/Ship.h"
#include <iostream>
#include <vector>


#include "../headers/BattleGround.h"
#include "../headers/Ship.h"
#include "../headers/ShipManager.h"
#include "../headers/SkillInterface.h"
#include "../headers/SkillManager.h"
#include "../headers/SkillScan.h"
#include "../render/Render.h"
#define clear_console system("cls");std::cout.flush();std::cin.clear()
enum GameMove{
    UseSkill,
    Attack,
    Wrong,
    Save,
    Load,
};

enum Winner{
    p1,
    p2,
    ai,
    None
};

enum what{
    YES,
    NO
};

class Tracer
{
    public:
    Tracer();
    ~Tracer() = default;
    void show_BG_player(BattleGround& bg);
    void show_BG_ai(BattleGround& bg);
    void info_start();
    void input_BG();
    short input_Ship();
    void input_cnt_ships();
    void input_len_ship();
    void input_orientation();
    void input_x();
    void input_y();
    void info_ai();
    void round_start();
    void new_round();
    void info_save_status(Status save_status);
    void info_load_status(Status load_status);
    void win();
    void los();
    void last_action(AttackResult last_result);
    void info_skills(short cnt);
    void info_use_skill(SkillType st);
    std::vector<short> input_len_ships(short cnt_ships);
    GameMove input_move(short snt_skills);
    std::pair<short,short> input_coords();
    void info(AttackResult result);
    void info_end(Winner);
    void info_cnt_ships(short cnt);
    void print_info_skill(SkillManager& SM);
    void print_result(AttackResult result);
    std::vector<Orientation>input_orientation(short cnt);
    std::pair<short, Orientation> input_specifications_for_ship();
    std::pair<short,short> input_coords_again();
    void press_enter();
    void print_fail_load();
    what input_yes_no();
    void print_error_load();
    bool isStartSession;
    bool isInitial;
    bool isStartRound;
private:
    Render<TerminalRenderer> render;

};
#endif //TRACER_H
