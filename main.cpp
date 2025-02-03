#include <iostream>
#include "headers/BattleGround.h"
#include "headers/Ship.h"
#include "headers/ShipManager.h"
#include "headers/SkillInterface.h"
#include "headers/SkillManager.h"
#include "headers/SkillScan.h"
#include "game_session/headers/session.h"
#include "input/headers/TerminalInput.h"
#include "controller/Controller.h"
#include <conio.h>
// #define clear_console system("cls")

int main(){
    Session session;
    Controller<TerminalInput> controller(session);
    controller.start();
    return 0;
}