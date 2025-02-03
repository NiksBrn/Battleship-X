#include "../headers/BattleGround.h"
#include <iostream>
#include <sstream>
#define clear_console system("cls")
#define sleep getchar();


BattleGround::BattleGround(){
    this->bg_size = 10;
    battle_ground.resize(this->bg_size);
    for(int i = 0; i < this->bg_size; i++){
        battle_ground[i].resize(this->bg_size, {false,false,nullptr, 0});
    }
}

BattleGround::BattleGround(short size){
    if (size == 0) size = 1;
    this->bg_size = size;
    data_coords = "";
    battle_ground.resize(this->bg_size);
    for(int i = 0; i < this->bg_size; i++){
        battle_ground[i].resize(this->bg_size, {false,false,nullptr, 0});
    }
}

BattleGround::BattleGround(const BattleGround& other):bg_size(other.bg_size), battle_ground(other.battle_ground.size()){
    std::copy(other.battle_ground.begin(), other.battle_ground.end(), battle_ground.begin());
}

BattleGround &BattleGround::operator=(const BattleGround &other) {
    BattleGround temp(other);
    std::swap(temp.bg_size, this->bg_size);
    std::swap(temp.battle_ground, this->battle_ground);
    std::swap(temp.data_coords, this->data_coords);
    return *this;
}

BattleGround::BattleGround(BattleGround &&other):bg_size(0), battle_ground(0){
    std::swap(other.bg_size, this->bg_size);
    std::swap(other.battle_ground, this->battle_ground);
    std::swap(other.data_coords, this->data_coords);
}
BattleGround &BattleGround::operator=(BattleGround &&other) {
    if(this!= &other){
        std::swap(other.bg_size, this->bg_size);
        std::swap(other.battle_ground, this->battle_ground);
        std::swap(other.data_coords, this->data_coords);
    }
    return *this;
}

Status BattleGround::add_ship(Ship *ship, short x, short y) {
    try {
        this->check_collision(x, y, ship->get_length(), ship->get_orientation());
        for (short i = 0; i < ship->get_length(); i++) {
            if (ship->get_orientation() == VERTICAL) {
                battle_ground[y + i][x] = {true, false, ship, i};
            } else {
                battle_ground[y][x + i] = {true, false, ship, i};
            }
        }
        data_coords+= std::to_string(x) + " " + std::to_string(y)+" ";
        return Success;
    }
    catch (ShipCollisionException &e) {
        return Fail;
    }
}

void BattleGround::print_battle_ground(){
    std::cout << "+";
    for(int i = 0; i < this->bg_size; i++){ std::cout << "-";}
    std::cout << "+" << std::endl;
    for(int i = 0; i < this->bg_size; i++){
        std::cout << "|";
        for(int j = 0; j < this->bg_size; j++){
            if(battle_ground[i][j].is_ship){
                if(battle_ground[i][j].ship->get_segmentStatus(battle_ground[i][j].segment) == DEAD){
                    std::cout << "\x1b[31mX\x1b[0m";
                }else if(battle_ground[i][j].ship->get_segmentStatus(battle_ground[i][j].segment) == DAMAGED){
                    std::cout << "\x1b[34mO\x1b[0m";
                }else{
                    std::cout << "\x1b[32mO\x1b[0m";
                }
            }else{
                std::cout << " ";
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "+";
    for(int i = 0; i < this->bg_size; i++){ std::cout << "-";}
    std::cout << "+" << std::endl;
//    sleep;
//    clear_console;
}

void BattleGround::print_battle_ground_opponent(){
    std::cout << "+";
    for(int i = 0; i < this->bg_size; i++){ std::cout << "-";}
    std::cout << "+" << std::endl;
    for(int i = 0; i < this->bg_size; i++){
        std::cout << "|";
        for(int j = 0; j < this->bg_size; j++){
            if(!battle_ground[i][j].is_visible)
                std::cout<< "?";
            else{
                if(battle_ground[i][j].is_ship){
                    if(battle_ground[i][j].ship->get_segmentStatus(battle_ground[i][j].segment) == DEAD){
                        std::cout << "\x1b[31mX\x1b[0m";
                    }else if(battle_ground[i][j].ship->get_segmentStatus(battle_ground[i][j].segment) == DAMAGED){
                        std::cout << "\x1b[34mO\x1b[0m";
                    }else{
                        std::cout << "\x1b[32mO\x1b[0m";
                    }
                }else{
                    std::cout << " ";
                }
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "+";
    for(int i = 0; i < this->bg_size; i++){ std::cout << "-";}
    std::cout << "+" << std::endl;
//    sleep;
//    clear_console;
}
AttackResult BattleGround::attack(short x, short y, bool is_skill){
    try{
        if(x >= 0 && y >= 0 && x < this->bg_size && y < this->bg_size) {
            if(!is_skill)battle_ground[y][x].is_visible = true;
            if (battle_ground[y][x].is_ship) {
                return battle_ground[y][x].ship->damage(battle_ground[y][x].segment);
            }return MISS;
        }else{
            throw OutOfRangeBG();
        }
    }
    catch (OutOfRangeBG &e) {
        std::cout << e.what() << std::endl;
        return MISS;
    }
}

bool BattleGround::check_collision(short x, short y, short length, Orientation orientation) {
    std::vector<std::pair<short, short> > collision_points = {{0,0}, {0,1}, {0, - 1}, { 1, 0}, {0, 1}, { 1, 1}, { -1, - 1}, { - 1,  1},{ 1, - 1}};
    bool collision = false;
    for (int i = 0; i < length; i++) {

        if (orientation == HORIZONTAL && i != 0) {
            x ++;
        }
        else if (orientation == VERTICAL && i!= 0) {
            y ++;
        }
        if (x >= 0 && y >= 0 && x < this->bg_size && y < this->bg_size) {
            if (battle_ground[y][x].is_ship) {
                throw ShipCollisionException();
            }else{
                for(auto g:collision_points){
                    if(y+ g.first >= 0 && y + g.first < this->bg_size && x + g.second >= 0 && x + g.second < this->bg_size)
                    if(battle_ground[y+ g.first][x+g.second].is_ship) {
                        throw ShipCollisionException();
                        collision = true;
                        break;
                    }
                }
            }
        }else throw ShipCollisionException();
            //collision = true;
    }
    return collision;
}

short BattleGround::get_size() const {
    return this->bg_size;
}

std::pair<bool, bool> BattleGround::get_status(short x, short y) const {
    //std::cout << battle_ground[y][x].ship->get_segmentStatus(battle_ground[y][x].segment)<<'\n';
    if(battle_ground[y][x].is_ship)return std::make_pair(true, battle_ground[y][x].ship->get_segmentStatus(battle_ground[y][x].segment) != DEAD);
    return std::make_pair(false, false);
}

SegmentStatus BattleGround::get_segment_status(short x, short y) const
{
    return battle_ground[y][x].ship->get_segmentStatus(battle_ground[y][x].segment);
}

bool BattleGround::is_visible(short x, short y) const
{
    return battle_ground[y][x].is_visible;
}


//bool BattleGround::check_collision(short x, short y, bool last_or_first, Orientation orientation) {
////    std::vector<std::pair<short, short> > collision_points_f = {{x,y}, {x, y + 1}, {x, y - 1}, {x + 1, y}, {x - 1, y}, {x + 1, y + 1}, {x - 1, y - 1}, {x - 1, y + 1},{x + 1, y - 1}};
////    std::vector<std::pair<short, short> > collision_points_h = {{x,y}, {x, y + 1}, {x, y - 1}};
////    std::vector<std::pair<short, short> > collision_points_v = {{x,y}, {x + 1, y}, {x - 1, y}};
////    std::vector<std::pair<short, short> > collision_points_vh = {{x,y}, {x + 1, y}, {x - 1, y}};
//
//    if (x >= 0 && y >= 0 && x < this->bg_size && y < this->bg_size) {
//        if( !battle_ground[y][x].is_ship){
//
//        }else return false;
//
//    } else {
//        return false;
//    }
//}

std::pair<short, short> BattleGround::get_coords() {
    std::cout << "enter the coordinates\n";
    short x, y;
    std:: cout << "X: ";
    std::cin >> x;
    std::cout << "Y: ";
    std::cin >> y;
    return std::make_pair(x, y);
}

bool BattleGround::is_end(){
    for(auto i:battle_ground){
        for(auto j:i){
            if(j.is_ship){
                if(j.ship->get_segmentStatus(j.segment) != DEAD){
                    return false;
                }
            }
        }
    }
    return true;
}

std::string BattleGround::back_up() {
    std::string data = std::to_string(bg_size)+" ";
    for(auto i:battle_ground) {
        for (auto j: i) {
            data += std::to_string(j.is_visible) + " ";
        }
    }
    return data;
}

std::string BattleGround::back_up_coords() {
    return std::to_string(bg_size) + " " + data_coords;
}

BattleGround::~BattleGround(){
    battle_ground.clear();
}

void BattleGround::update_from_back_up(std::string save){
    std::istringstream ss(save);
    ss>> bg_size;
    for(int i = 0;i < bg_size; i++){
        for(int j = 0; j < bg_size; j++){
            short temp;
            ss >> temp;
            battle_ground[i][j].is_visible = temp;
        }
    }
}

void BattleGround::update_size(short size) {
    data_coords = "";
    this->bg_size = size;
    battle_ground.resize(this->bg_size);
    for(int i = 0; i < this->bg_size; i++){
        battle_ground[i].resize(this->bg_size);
    }
    for(int i = 0; i < this->bg_size; i++){
        for(int j = 0; j < this->bg_size; j++){
            battle_ground[i][j] = {false,false,nullptr, 0};
        }
    }

}