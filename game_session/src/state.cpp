#include "../headers/state.h"

std::ostream& operator<<(std::ostream& out, State& s){
    out << s.new_hash() << '\n';
    out << s.ship_manager_p1.back_up() << '\n';
    out << s.skill_manager_p1.back_up() << '\n';
    out << s.battle_ground_p1.back_up() << '\n';
    out << s.ship_manager_p2.back_up() << '\n';
    out << s.skill_manager_p2.back_up() << '\n';
    out << s.battle_ground_p2.back_up() << '\n';
    out << s.battle_ground_p1.back_up_coords()<< '\n';
    out << s.battle_ground_p2.back_up_coords() << '\n';
    out << s.ai_p->back_up() << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, State& s){
    std::string tmp;
    getline(in, tmp);
    s.input_save_hash(tmp);
    getline(in, tmp);
    s.input_back_up_Ship_Manager(tmp, P1);
    getline(in, tmp);
    s.input_back_up_Skill_Manager(tmp, P1);
    getline(in, tmp);
    s.input_back_up_Battle_Ground(tmp, P1);
    getline(in, tmp);
    s.input_back_up_Ship_Manager(tmp, P2);
    getline(in, tmp);
    s.input_back_up_Skill_Manager(tmp, P2);
    getline(in, tmp);
    s.input_back_up_Battle_Ground(tmp, P2);
    getline(in, tmp);
    s.input_back_up_coords(tmp, P1);
    getline(in, tmp);
    s.input_back_up_coords(tmp, P2);
    getline(in, tmp);
    s.input_back_up_ai(tmp);
    return in;
}

State::State(){
}

void State::input_back_up_Ship_Manager(std::string input, PLAYER player){
    if(player == P1){
        back_up_Ship_Manager_p1_ = input;
    }else back_up_Ship_Manager_p2_ = input;
}
void State::input_back_up_Skill_Manager(std::string input, PLAYER player){
    if(player == P1){
        back_up_Skill_Manager_p1_ = input;
    }else back_up_Skill_Manager_p2_ = input;
}
void State::input_back_up_Battle_Ground(std::string input, PLAYER player){
    if(player == P1){
        back_up_Battle_Ground_p1_ = input;
    }else back_up_Battle_Ground_p2_ = input;
}
void State::input_back_up_coords(std::string input, PLAYER player){
    if(player == P1){
        back_up_coords_p1_ = input;
    }else back_up_coords_p2_ = input;
}
void State::input_back_up_ai(std::string input){
    back_up_ai = input;
}
void State::input_save_hash(std::string input){
    save_hash_ = input;
}

Status State::load() {
    //std::ifstream in("../back_up.txt"); // RAII input stream
    try {
        FileRW in("../back_up.txt", READ);
        in >> *this;
        if (!Verify())return Fail;
        ship_manager_p1 = ShipManager(back_up_Ship_Manager_p1_);
        ship_manager_p2 = ShipManager(back_up_Ship_Manager_p2_);
        skill_manager_p1 = SkillManager(back_up_Skill_Manager_p1_);
        skill_manager_p2 = SkillManager(back_up_Skill_Manager_p2_);
        ship_manager_p1.add_ships(back_up_coords_p1_, battle_ground_p1);
        ship_manager_p2.add_ships(back_up_coords_p2_, battle_ground_p2);
        battle_ground_p1.update_from_back_up(back_up_Battle_Ground_p1_);
        battle_ground_p2.update_from_back_up(back_up_Battle_Ground_p2_);
        ai_p = new AI(back_up_ai);
        return Success;
    } catch (const std::exception& e) {
        return Fail;
    }
}

Status State::save() {
    //std::ofstream out("../back_up.txt"); // RAII output stream
    try {
        FileRW out("../back_up.txt", WRITE);
        out << *this;
        return Success;
    }catch (const std::exception& e) {
        return Fail;
    }
}

unsigned int State::Hash(std::string& str) {
    unsigned int hash = 0;
    for (char c : str) {
        hash += c;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

std::string State::new_hash(){
    std::string hash_s =
    ship_manager_p1.back_up()
    +skill_manager_p1.back_up()
    +battle_ground_p1.back_up()
    +ship_manager_p2.back_up()
    +skill_manager_p2.back_up()
    +battle_ground_p2.back_up()
    +battle_ground_p1.back_up_coords()
    +battle_ground_p2.back_up_coords()
    +ai_p->back_up();
    return std::to_string(Hash(hash_s));
}

bool State::Verify(){
    std::string hash_s =
    back_up_Ship_Manager_p1_
    +back_up_Skill_Manager_p1_
    +back_up_Battle_Ground_p1_
    +back_up_Ship_Manager_p2_
    +back_up_Skill_Manager_p2_
    +back_up_Battle_Ground_p2_
    +back_up_coords_p1_
    +back_up_coords_p2_
    +back_up_ai;
    unsigned int h = Hash(hash_s);
    if(std::to_string(h) == save_hash_) return true;
    return false;
}



FileRW::FileRW(std::string fileName, Mode mode){
    if(mode == READ){
        input.open(fileName);
        if(!input.is_open()) throw std::runtime_error("Unable to open file");
    }else{
        output.open(fileName);
        if(!output.is_open()) throw std::runtime_error("Unable to open file");
    }
}

void FileRW::read_state(State &state){
    input >> state;
}

FileRW::~FileRW(){
    if(input.is_open()) input.close();
    if(output.is_open()) output.close();
}

void FileRW::write_state(State &state) {
    output << state;
}

FileRW& FileRW::operator<<(State& state) {
    write_state(state);
    return *this;
}

FileRW &FileRW::operator>>(State &state) {
    read_state(state);
    return *this;
}

bool FileRW::read_settings(std::map<char, CommandType> &commands){
    char command;
    std::string type;
    while(!input.eof()){
        input>> command;
        input >> type;
        if(type == "ATTACK") {if(commands.contains(command))return false;commands[command] = ATTACK;}
        else if(type == "SKILL") {if(commands.contains(command))return false;commands[command] = SKILL;}
        else if(type == "START_ROUND") {if(commands.contains(command))return false;commands[command] = START_ROUND;}
        else if(type == "SAVE") { if(commands.contains(command))return false;commands[command] = SAVE; }
        else if(type == "LOAD") {if(commands.contains(command))return false;commands[command] = LOAD;}
        else if (type == "EXIT") {if(commands.contains(command))return false;commands[command] = EXIT;}
    }
    return true;
}
//n
//3
//1
//1
//v
//1
//1
