#include "../headers/session.h"
#include <fstream>
// #define clear_console system("cls");std::cout.flush();std::cin.clear()

Session::Session(){
}

void Session::new_game(){
    state.ship_manager_p1.clear();
    state.ship_manager_p2.clear();
}



void Session::initial_bg(short BG_size){
    state.battle_ground_p1 = BattleGround(BG_size);
}

void Session::add_ship_to_manager(std::pair<short, Orientation> ship){
    if(ship.second != LOST){
        state.ship_manager_p1.add_ship(ship.first, ship.second);
    }
}

Status Session::add_ship_to_bg(std::pair<short, short> coords, short i){
    return state.ship_manager_p1.add_ship_bg(&state.battle_ground_p1,i,coords.first, coords.second);
}
//
void Session::initial_p2(){ // AI
    short cnt_ships = state.ship_manager_p1.get_ships_num();
    state.ai_p = new AI(state.battle_ground_p1.get_size());
    state.ship_manager_p2.clear();
    state.battle_ground_p2 = BattleGround(state.battle_ground_p1.get_size());
    std::vector<std::pair<short, short>> pos = state.ai_p->generate_pos(state.battle_ground_p2.get_size());
    for(short i = 0; i < cnt_ships; i++){
        std::pair<short, Orientation> ship = std::make_pair(state.ship_manager_p1.get_len_ship(i),state.ai_p->generate_orientation());
        if(ship.second != LOST){
            state.ship_manager_p2.add_ship(ship.first, ship.second);
            short ai_i = 0;
            while(ai_i != pos.size() && state.ship_manager_p2.add_ship_bg(&state.battle_ground_p2,i,pos[ai_i].first, pos[ai_i].second) != Success){
                ai_i++;
            }
            if(ai_i == pos.size()){
                state.ship_manager_p2.del_ship();
            }
        }
    }
}

std::pair<GameCondition, AttackResult> Session::UseSkill()
{
    AttackResult result = state.skill_manager_p1.UseSkill(state.battle_ground_p2);
    GameCondition condition;
    if (state.battle_ground_p2.is_end()) condition = ending_game;
    else condition = continue_game;
    if (result == FULLDESTROED) state.skill_manager_p1.AddSkill();
    return std::make_pair(condition, result);
}

std::pair<GameCondition, AttackResult> Session::attack(short x, short y)
{
    AttackResult result = state.battle_ground_p2.attack(x,y);
    GameCondition condition;
    if (state.battle_ground_p2.is_end()) condition = ending_game;
    else condition = continue_game;
    if (result == FULLDESTROED)state.skill_manager_p1.AddSkill();
    return std::make_pair(condition, result);
}

std::pair<GameCondition, AttackResult> Session::move_ai() {
    std::pair<short, short> coords = state.ai_p->get_coords();
    AttackResult result = state.battle_ground_p1.attack(coords.first, coords.second);
    state.ai_p->generate_coords(result, coords);
    GameCondition condition;
    if (state.battle_ground_p1.is_end()) condition = ending_game;
    else condition = continue_game;
    return std::make_pair(condition, result);
}

Status Session::save(){
    return state.save();
}

Status Session::load(){
    return state.load();
}

BattleGround& Session::get_bg_p()
{
    return state.battle_ground_p1;
}

BattleGround& Session::get_bg_ai()
{
    return state.battle_ground_p2;
}

short Session::get_cnt_skills()
{
    return state.skill_manager_p1.GetSkillCnt();
}

SkillType Session::get_skill()
{
    return state.skill_manager_p1.GetSkillType();
}


//10
//4
//1
//v
//0
//0
//4
//h
//0
//2
//1
//v
//9
//9
//4
//h
//3
//6