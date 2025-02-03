// #include "../headers/SessionManager.h"
// #include <iostream>
// #include <vector>
// #include <bits/stdc++.h>
// #define clear_console system("cls")
//
// void info_start(){
//     std::cout << "Welcome Captain"<<'\n';
//     std::cout << "Now you are in session with AI"<<'\n';
//     std::cout << "You want to load the game?"<<'\n';
// }
//
// short input_BG(){
//     short size;
//     std::cout << "input BG size: ";
//     std::cin >> size;
//     return size;
// }
//
// short input_cnt_ships(){
//     short cnt_ships;
//     std::cout << "input cnt_ships: ";
//     std::cin >> cnt_ships;
//     return cnt_ships;
// }
//
// std::vector<short> input_len_ships(short cnt_ships){
//     std::vector<short> ships;
//     for(int i = 0; i < cnt_ships; i++) {
//         std::cout << "input ship " << i+1 << " size: ";
//         short size;
//         std::cin >> size;
//         ships.push_back(size);
//     }
//     return ships;
// }
//
// GameMove input_move(short cnt_skills){
//     GameMove move;
//     char move_char;
//     std::cout << "You want Save or Load or Skip?[1/2/3]:\n";
//     std::cin >> move_char;
//     switch(move_char){
//         case '1':
//             move = Save;
//             return move;
//         case '2':
//             move = Load;
//             return move;
//         case '3':
//             break;
//         default:
//             move = Wrong;
//             break;
//     }
//     std::cout << "You have " << cnt_skills << " skills." << '\n';
//     std::cout << "input move[S/A]: ";
//     std::cin >> move_char;
//     switch(move_char){
//         case 'S':
//             move = UseSkill;
//             break;
//         case 'A':
//             move = Attack;
//             break;
//         default:
//             move = Wrong;
//             std::cout << "wrong move type, You're missing a move." << std::endl;
//             break;
//     }
//     return move;
// }
//
// std::pair<short, short> input_coords() {
//     std::cout << "enter the coordinates\n";
//     short x, y;
//     std:: cout << "X: ";
//     std::cin >> x;
//     std::cout << "Y: ";
//     std::cin >> y;
//     return std::make_pair(x, y);
// }
//
// void info(AttackResult result){
//     switch(result) {
//         case MISS:
//             std::cout << "Miss" << std::endl;
//             break;
//         case DESTROED:
//             std::cout << "Destroed" << std::endl;
//             break;
//         case FULLDESTROED:
//             std::cout << "FULLDESTROED" << std::endl;
//             break;
//         case DAMADGE:
//             std::cout << "DAMADGE" << std::endl;
//             break;
//         case FAILED:
//             std::cout << "FAILED" << std::endl;
//     }
// }
//
// void info_end(Winner player){
//     std::cout << "Session ended" << std::endl;
//     if(player == p1){
//         std::cout << "Player 1 won" << std::endl;
//     }else std::cout << "Player 2 won (ai)" << std::endl;
// }
//
// void print_info_skill(SkillManager& SM){
//     std::cout << "You used ";
//     switch(SM.GetSkillType()){
//         case DD:
//             std::cout << "Double Damage ";
//             break;
//         case SCAN:
//             std::cout << "Scan ";
//             break;
//         case SHRAPNEL:
//             std::cout << "Shrapnel ";
//             break;
//         case LAST:
//             std::cout << "None ";
//             break;
//     }
//     std::cout << "skill!" << std::endl;
// }
//
// void info_ai(){
//     std::cout << "AI is ready"<<'\n';
// }
//
//
// void info_cnt_ships(short cnt){
//     std::cout << "Number of ships: " << cnt<<'\n';
// }
//
// void print_result(AttackResult result){
//     switch(result) {
//         case DAMADGE:
//             std::cout << "Damage!" << std::endl;
//             break;
//         case MISS:
//             std::cout << "Miss!" << std::endl;
//             break;
//         case FULLDESTROED:
//             std::cout << "Full destroed!" << std::endl;
//             break;
//         case DESTROED:
//             std::cout << "Destroed!" << std::endl;
//             break;
//         case SCANFOUND:
//             std::cout << "Scan found!" << std::endl;
//             break;
//         case SCANNOTFOUND:
//             std::cout << "Scan not found!" << std::endl;
//             break;
//     }
// }
//
// std::vector<Orientation>input_orientation(short cnt){
//     std::vector<Orientation>ships_orient;
//     for(int i = 0; i < cnt; i++){
//         char ch = 0;
//         while(ch != 'v' && ch!= 'h') {
//             std::cout<< "Enter oriantation of ship № "<<i<<"\n[v\\h]";
//             std::cin >> ch;
//             switch (ch) {
//                 case 'v':
//                     ships_orient.emplace_back(VERTICAL);
//                     break;
//                 case 'h':
//                     ships_orient.emplace_back(HORIZONTAL);
//                     break;
//                 default:
//                     std::cout << "Wrong input! Try again!\n";
//                     break;
//             }
//         }
//         clear_console;
//     }
// }
//
// std::pair<short, Orientation> input_specifications_for_ship(){
//     short len;
//     std::cout << "Enter length of ship: ";
//     std::cin >> len;
//     char orientation;
//     std::cout << "Enter orientation of ship[v/h]: ";
//     std::cin >> orientation;
//     Orientation orientation_t;
//     switch (orientation) {
//         case 'v':
//             orientation_t = VERTICAL;
//             break;
//         case 'h':
//             orientation_t = HORIZONTAL;
//             break;
//         default:
//             orientation_t = LOST;
//             std::cout << "Apparently your ship got into the Bermuda triangle, I'm sorry, but you're his own ship!\n";
//             break;
//     }
//     return std::make_pair(len, orientation_t);
// }
//
// std::pair<short,short> input_coords_again(){
//     std::cout << "Wrong coordinates"<<'\n';
//     std::cout << "Try again!\n";
//     short x,y;
//     std::cout << "Enter x: ";
//     std::cin >> x;
//     std::cout << "Enter y: ";
//     std::cin >> y;
//     return std::make_pair(x,y);
// }
//
// void press_enter(){
//     std::cin.clear();
//     std::cout << "Press enter to continue...";
//     std::getchar();
// }
//
// what input_yes_no(){
//     char ch;
//     std::cout << "Yes/No[y/n]: ";
//     std::cin >> ch;
//     switch (ch) {
//         case 'y':
//             return YES;
//         case 'n':
//             return NO;
//         default:
//             std::cout << "Wrong input! Try again!\n";
//             return input_yes_no();
//     }
// }
//
// void print_fail_load() {
//     std::cout << "Failed to load!\n";
//     std::cout << "New game!\n";
// }
// void print_error_load(){
//     std::cout << "invalid checksum!\n";
// }
