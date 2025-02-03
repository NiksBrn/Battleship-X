#ifndef SB_PROJECT_SHIPMANAGER_H
#define SB_PROJECT_SHIPMANAGER_H

#include "Ship.h"
#include "BattleGround.h"

class ShipManager {
public:
    ShipManager();
    ShipManager(short cnt, std::vector<short> ships_len, std::vector<Orientation> ship_orient);
    ShipManager(std::string save);
    ~ShipManager();
    void add_ship(short len, Orientation orientation);
    void del_ship();
    short get_len_ship(short num);
    Status add_ship_bg(BattleGround* bg, short num, short x, short y);
    void add_ships(std::string save, BattleGround& bg);
    std::string back_up();
    short get_ships_num();
    void clear();
    //        void print_ships();
private:
    short ships_num;
    std::vector<Ship> ships;
};
#endif //SB_PROJECT_SHIPMANAGER_H
