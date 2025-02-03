#include <map>
#include "../headers/TerminalInput.h"
TerminalInput::TerminalInput() {
    try
    {
        FileRW file(file_setings, READ);
        std::map<char, CommandType>  new_commands;
        if(file.read_settings(new_commands));
        if(check(new_commands)) commands = new_commands;
        std::cout << "File settings load success\n" << std::endl;
    }
    catch (...)
    {
        std::cout << "Default settings\n";
    }
}

bool TerminalInput::check(std::map<char, CommandType> &new_commands){
    std::vector<CommandType> commands_list;
    for(auto it:new_commands){
        commands_list.push_back(it.second);
    }
    std::sort(commands_list.begin(), commands_list.end());
    std::vector<CommandType> tec = {ATTACK,
    START_ROUND,
    START_GAME,
    SAVE,
    LOAD,
    EXIT,
    SKILL,
    CONTINUE
    };
    if (tec != commands_list)return false;
    return true;
}

CommandType TerminalInput::getInput() {
    try
    {
        char input = getch();
        return commands.at(input);
    }catch (...)
    {
        std::cout << "Error, try again!\n";
        return getInput();
    }
}

short TerminalInput::inputDec()
{
    short input;
    std::cin>>input;
    return input;
}

Orientation TerminalInput::inputOrientation()
{
    char orientation;
    std::cin >> orientation;
    Orientation orientation_t;
    switch (orientation) {
    case 'v':
        orientation_t = VERTICAL;
        break;
    case 'h':
        orientation_t = HORIZONTAL;
        break;
    default:
        orientation_t = LOST;
        break;
    }
    return orientation_t;
}
