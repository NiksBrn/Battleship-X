// #ifndef SB_PROJECT_SESSIONMANAGER_H
// #define SB_PROJECT_SESSIONMANAGER_H
// #include <iostream>
// #include <vector>
// #include "../../headers/BattleGround.h"
// #include "../../headers/Ship.h"
// #include "../../headers/ShipManager.h"
// #include "../../headers/SkillInterface.h"
// #include "../../headers/SkillManager.h"
// #include "../../headers/SkillScan.h"
//
// enum GameMove{
//     UseSkill,
//     Attack,
//     Wrong,
//     Save,
//     Load,
// };
//
// enum Winner{
//     p1,
//     p2,
//     ai,
//     None
// };
//
// enum GameCondition{
//     continue_game,
//     ending_game,
//     end,
// };
//
// enum what{
//     YES,
//     NO
// };
//
// void info_start();
// short input_BG();
// short input_Ship();
// short input_cnt_ships();
// void info_ai();
// std::vector<short> input_len_ships(short cnt_ships);
// GameMove input_move(short snt_skills);
// std::pair<short,short> input_coords();
// void info(AttackResult result);
// void info_end(Winner);
// void info_cnt_ships(short cnt);
// void print_info_skill(SkillManager& SM);
// void print_result(AttackResult result);
// std::vector<Orientation>input_orientation(short cnt);
// std::pair<short, Orientation> input_specifications_for_ship();
// std::pair<short,short> input_coords_again();
// void press_enter();
// void print_fail_load();
// what input_yes_no();
// void print_error_load();
//
// #endif //SB_PROJECT_SESSIONMANAGER_H
