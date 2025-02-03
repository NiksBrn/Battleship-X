#ifndef SB_PROJECT_SHIP_H
#define SB_PROJECT_SHIP_H

#include <vector>
#include <string>

enum Orientation{
    HORIZONTAL,
    VERTICAL,
    LOST,
};

enum SegmentStatus{
    DEAD,
    DAMAGED,
    FULL
};

enum AttackResult{
    NOATTACK,
    MISS,
    DESTROED,
    FULLDESTROED,
    DAMADGE,
    SCANFOUND,
    SCANNOTFOUND,
    FAILED,
};

enum Status{
    Success,
    Fail
};


class Ship {
public:
    Ship(short length, Orientation orientation);
    Ship(short length, Orientation orientation, std::vector<SegmentStatus>segments);
    ~Ship();
    short get_length();
    Orientation get_orientation();
    SegmentStatus get_segmentStatus(short segment);
    AttackResult damage(short segment);
    std::string back_up();
private:
    short ship_length;
    Orientation ship_orientation;
    std::vector<SegmentStatus> ship_segments;
};
#endif //SB_PROJECT_SHIP_H
