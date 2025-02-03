#ifndef SB_PROJECT_TERMINALINPUT_H
#define SB_PROJECT_TERMINALINPUT_H
#include <string>
#include <map>
#include "fstream"
#include <conio.h>
#include "../../game_session/headers/state.h"

class TerminalInput{
public:
    TerminalInput();
    CommandType getInput();
    short inputDec();
    Orientation inputOrientation();
    bool check(std::map<char, CommandType> &new_commands);
    ~TerminalInput() = default;
private:
    std::string file_setings = "../setings.txt";
    std::map<char, CommandType> commands = {
        {'a', ATTACK},
        {'s', SKILL},
        {'c', CONTINUE},
        {'2', START_ROUND},
        {'1', START_GAME},
        {'z', SAVE},
        {'x', LOAD},
        {'p', EXIT},
};

};
#endif //SB_PROJECT_TERMINALINPUT_H
