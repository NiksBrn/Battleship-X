#include "../headers/ShipCollisionException.h"

const char *ShipCollisionException::what() const noexcept {
    return "Captain, pay attention, you almost lost your ship!!!\nTry again!";
}