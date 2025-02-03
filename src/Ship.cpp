
#include "../headers/Ship.h"
#include <iostream>

Ship::Ship(short length, Orientation orientation){
    if(length > 4) length = 4;
    if(length < 1) length = 1;
    this->ship_length = length;
    this->ship_orientation = orientation;
    this->ship_segments = std::vector<SegmentStatus>(this->ship_length, FULL);
}
Ship::Ship(short length, Orientation orientation, std::vector<SegmentStatus>segments){
    if(length > 4) length = 4;
    if(length < 1) length = 1;
    this->ship_length = length;
    this->ship_orientation = orientation;
    this->ship_segments = segments;
}

Ship::~Ship(){
    this->ship_segments.clear();
}

short Ship::get_length(){
    return this->ship_length;
}
Orientation Ship::get_orientation(){
    return this->ship_orientation;
}
AttackResult Ship::damage(short segment){
    switch (this->ship_segments[segment]){
    case FULL:
        this->ship_segments[segment] = DAMAGED;
        break;
    case DAMAGED:
        this->ship_segments[segment] = DEAD;
        break;
    case DEAD:
        return MISS;
    }
    if(this->ship_segments[segment] == DAMAGED){
        return DAMADGE;
    }
    bool ship_is_dead = true;
    for(auto g: this->ship_segments){
        if(g != DEAD) ship_is_dead = false;
    }
    if (ship_is_dead)return FULLDESTROED;
    else return DESTROED;
}

SegmentStatus Ship::get_segmentStatus(short segment) {
    return this->ship_segments[segment];
}

std::string Ship::back_up() {
    std::string data = std::to_string(ship_length)+" ";
    if(ship_orientation == VERTICAL) data += "V ";
    else data += "H ";
    for(int i = 0; i < ship_length; i++){
        data += std::to_string(ship_segments[i]) + " ";
    }
    return data;
}