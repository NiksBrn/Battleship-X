#include "../headers/Ship.h"
#include "../headers/ShipManager.h"
#include <iostream>
#include <sstream>
#define clear_console system("cls")

ShipManager::ShipManager(){
    this->ships_num = 0;
    ships.reserve(100000);
}

ShipManager::ShipManager(std::string save){
    std::stringstream ss(save);
    ss >> ships_num;
    ships.clear();
    ships.reserve(100000);
    for(int i = 0; i < ships_num; i++){
        short len;
        Orientation orientation;
        ss >> len;
        std::vector<SegmentStatus> segments(len);
        short x;
        char xi;
        ss >> xi;
        if(xi == 'V')orientation = VERTICAL;
        else orientation = HORIZONTAL;
        for(int j = 0; j < len; j++){
            ss >> x;
            switch (x) {
                case 0:
                    segments[j] = DEAD;
                    break;
                case 1:
                    segments[j] = DAMAGED;
                    break;
                case 2:
                    segments[j] = FULL;
                    break;
            }
        }
        ships.emplace_back(len, orientation, segments);
    }
}

ShipManager::~ShipManager(){
    this->ships.clear();

}
void ShipManager::add_ship(short len, Orientation orientation) {
    ships_num ++;
    ships.emplace_back(len, orientation);
}

void ShipManager::del_ship(){
    ships_num --;
    ships.pop_back();
}


Status ShipManager::add_ship_bg(BattleGround* bg, short num, short x, short y){
    return bg->add_ship(&ships[num], x, y);
}

void ShipManager::add_ships(std::string save, BattleGround& bg){
    std::istringstream ss(save);
    short bg_size;
    ss >> bg_size;
    bg.update_size(bg_size);
    for(int i = 0; i < ships_num; ++i){
        short x = 0, y = 0;
        ss >> x >> y;
        bg.add_ship(&ships[i], x, y);
    }
}

std::string ShipManager::back_up(){
    std::string data = std::to_string(ships_num)+" ";
    for(int i = 0; i < this->ships_num; i++) {
        data+= ships[i].back_up() +" ";
    }
    return data;
}

short ShipManager::get_len_ship(short num){
    return ships[num].get_length();
}

short ShipManager::get_ships_num(){
    return ships.size();
}

void ShipManager::clear(){
    ships.clear();
    ships_num = 0;
}