#ifndef SB_PROJECT_BATTLEGROUND_H
#define SB_PROJECT_BATTLEGROUND_H
#include "Ship.h"
#include <cstdint>
#include <algorithm>
#include <random>
#include "../exception/headers/ShipCollisionException.h"
#include "../exception/headers/OutOfRangeBG.h"
class BattleGround {
public:
    BattleGround();
    BattleGround(short size);
    BattleGround(const BattleGround& other);
    BattleGround& operator=(const BattleGround& other);
    BattleGround(BattleGround && other);
    BattleGround& operator=(BattleGround && other);
    ~BattleGround();
    Status add_ship(Ship* ship, short x, short y);
    AttackResult attack(short x, short y, bool is_skill = false);
    short get_size() const;
    std::pair <bool, bool> get_status(short x, short y) const;
    SegmentStatus get_segment_status(short x, short y) const;
    bool is_visible(short x, short y) const;
    void print_battle_ground();
    void print_battle_ground_opponent();
    bool check_collision(short x, short y, short length,  Orientation orientation);
    std::pair<short,short> get_coords();
    bool is_end();
    std::string back_up();
    std::string back_up_coords();
    void update_size(short size);
    void update_from_back_up(std::string save);
private:
    std::string data_coords = "";
    short bg_size;
    struct bg_cell{
        bool is_ship;
        bool is_visible;
        Ship* ship;
        int segment;
    };
    std::vector<std::vector<bg_cell>> battle_ground;
};
#endif //SB_PROJECT_BATTLEGROUND_H
