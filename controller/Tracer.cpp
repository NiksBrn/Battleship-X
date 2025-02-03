#include "Tracer.h"

Tracer::Tracer()
{
    isStartRound = false;
    isInitial = false;
    isStartSession = false;
}

void Tracer::show_BG_player(BattleGround& bg)
{
    clear_console;
    render.renderPlayerView(bg);
}

void Tracer::show_BG_ai(BattleGround& bg)
{
    render.renderOpponentView(bg);
}


void Tracer::info_start(){
    render.render_info("Welcome Captain");
    render.render_info("Now you are in session with AI");
    render.render_info("You want to load or start new game?");
}

void Tracer::input_BG(){
    render.render_info("input_BG_size: ");
    isStartSession = true;
}

void Tracer::input_cnt_ships(){
    render.render_info("Number of ships: ");
}

void Tracer::input_len_ship()
{
    render.render_info("Enter length of ship: ");
}

void Tracer::input_orientation()
{
    render.render_info("Enter orientation of ship[v/h]: ");
}

void Tracer::input_x()
{
    render.render_info("Enter x: ");
}

void Tracer::input_y()
{
    render.render_info("Enter y: ");
}

void Tracer::info_ai(){
    isStartRound = true;
    render.render_info("AI is ready");
}

void Tracer::round_start()
{
    isStartRound = true;
    render.render_info("Starting round");
}

void Tracer::new_round()
{
    isStartRound = true;
    render.render_info("New round");
}

void Tracer::info_save_status(Status save_status)
{
    if (save_status == Success)render.render_info("Suscces");
    else render.render_info("Fail");
}

void Tracer::info_load_status(Status load_status)
{
    if (load_status == Success)
    {
        isStartRound = true;
        isStartSession = true;
        render.render_info("Loading succes");
    }
    else render.render_info("Fail");
}

void Tracer::win()
{
    isStartRound = false;
    isStartSession = true;
    render.render_info("You Win!!!");
    render.render_info("Continue?");
}

void Tracer::los()
{
    render.render_info("You Lose!!!");
    isStartSession = false;
    isStartRound = false;
    render.render_info("Continue?");

}

void Tracer::last_action(AttackResult last_result)
{
    switch(last_result) {
    case DAMADGE:
        std::cout << "Damage!" << std::endl;
        break;
    case MISS:

        std::cout << "Miss!" << std::endl;
        break;
    case FULLDESTROED:
        std::cout << "Full destroed!" << std::endl;
        break;
    case DESTROED:
        std::cout << "Destroed!" << std::endl;
        break;
    case SCANFOUND:
        std::cout << "Scan found!" << std::endl;
        break;
    case SCANNOTFOUND:
        render.render_info("Scan Not Found!");
        break;
    }
}

void Tracer::info_skills(short cnt)
{
    std::string out = "You have " + std::to_string(cnt) + " skills";
    render.render_info(out);
}

void Tracer::info_use_skill(SkillType st){
    switch(st){
    case DD:
        render.render_info("You have Double Damage skills");
        break;
    case SCAN:
        render.render_info("You have Scan Skills");
        break;
    case SHRAPNEL:
        render.render_info("You have Shrapnel Skills");
        break;
    case LAST:
        render.render_info("You have none Skills");
        break;
    }
}



// std::pair<short, Orientation> Tracer::input_specifications_for_ship(){
//     short len;
//     std::cout << "Enter length of ship: ";
//     std::cin >> len;
//     char orientation;
//     std::cout << "Enter orientation of ship[v/h]: ";
//     std::cin >> orientation;
//     Orientation orientation_t;
//     switch (orientation) {
//     case 'v':
//         orientation_t = VERTICAL;
//         break;
//     case 'h':
//         orientation_t = HORIZONTAL;
//         break;
//     default:
//         orientation_t = LOST;
//         std::cout << "Apparently your ship got into the Bermuda triangle, I'm sorry, but you're his own ship!\n";
//         break;
//     }
//     return std::make_pair(len, orientation_t);
// }


std::vector<short> Tracer::input_len_ships(short cnt_ships){
    std::vector<short> ships;
    for(int i = 0; i < cnt_ships; i++) {
        std::cout << "input ship " << i+1 << " size: ";
        short size;
        std::cin >> size;
        ships.push_back(size);
    }
    return ships;
}

GameMove Tracer::input_move(short cnt_skills){
    GameMove move;
    char move_char;
    std::cout << "You want Save or Load or Skip?[1/2/3]:\n";
    std::cin >> move_char;
    switch(move_char){
        case '1':
            move = Save;
            return move;
        case '2':
            move = Load;
            return move;
        case '3':
            break;
        default:
            move = Wrong;
            break;
    }
    std::cout << "You have " << cnt_skills << " skills." << '\n';
    std::cout << "input move[S/A]: ";
    std::cin >> move_char;
    switch(move_char){
        case 'S':
            move = UseSkill;
            break;
        case 'A':
            move = Attack;
            break;
        default:
            move = Wrong;
            std::cout << "wrong move type, You're missing a move." << std::endl;
            break;
    }
    return move;
}

std::pair<short, short> Tracer::input_coords() {
    std::cout << "enter the coordinates\n";
    short x, y;
    std:: cout << "X: ";
    std::cin >> x;
    std::cout << "Y: ";
    std::cin >> y;
    return std::make_pair(x, y);
}

void Tracer::info(AttackResult result){
    switch(result) {
        case MISS:
            std::cout << "Miss" << std::endl;
            break;
        case DESTROED:
            std::cout << "Destroed" << std::endl;
            break;
        case FULLDESTROED:
            std::cout << "FULLDESTROED" << std::endl;
            break;
        case DAMADGE:
            std::cout << "DAMADGE" << std::endl;
            break;
        case FAILED:
            std::cout << "FAILED" << std::endl;
    }
}

void Tracer::info_end(Winner player){
    std::cout << "Session ended" << std::endl;
    if(player == p1){
        std::cout << "Player 1 won" << std::endl;
    }else std::cout << "Player 2 won (ai)" << std::endl;
}

void Tracer::print_info_skill(SkillManager& SM){
    std::cout << "You used ";
    switch(SM.GetSkillType()){
        case DD:
            std::cout << "Double Damage ";
            break;
        case SCAN:
            std::cout << "Scan ";
            break;
        case SHRAPNEL:
            std::cout << "Shrapnel ";
            break;
        case LAST:
            std::cout << "None ";
            break;
    }
    std::cout << "skill!" << std::endl;
}


void Tracer::info_cnt_ships(short cnt){
    std::cout << "Number of ships: " << cnt<<'\n';
}

void Tracer::print_result(AttackResult result){
    switch(result) {
        case DAMADGE:
            std::cout << "Damage!" << std::endl;
            break;
        case MISS:
            std::cout << "Miss!" << std::endl;
            break;
        case FULLDESTROED:
            std::cout << "Full destroed!" << std::endl;
            break;
        case DESTROED:
            std::cout << "Destroed!" << std::endl;
            break;
        case SCANFOUND:
            std::cout << "Scan found!" << std::endl;
            break;
        case SCANNOTFOUND:
            std::cout << "Scan not found!" << std::endl;
            break;
    }
}

std::vector<Orientation>Tracer::input_orientation(short cnt){
    std::vector<Orientation>ships_orient;
    for(int i = 0; i < cnt; i++){
        char ch = 0;
        while(ch != 'v' && ch!= 'h') {
            std::cout<< "Enter oriantation of ship № "<<i<<"\n[v\\h]";
            std::cin >> ch;
            switch (ch) {
                case 'v':
                    ships_orient.emplace_back(VERTICAL);
                    break;
                case 'h':
                    ships_orient.emplace_back(HORIZONTAL);
                    break;
                default:
                    std::cout << "Wrong input! Try again!\n";
                    break;
            }
        }
        clear_console;
    }
}

std::pair<short,short> Tracer::input_coords_again(){
    std::cout << "Wrong coordinates"<<'\n';
    std::cout << "Try again!\n";
    short x,y;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;
    return std::make_pair(x,y);
}

void Tracer::press_enter(){
    std::cin.clear();
    std::cout << "Press enter to continue...";
    std::getchar();
}

what Tracer::input_yes_no(){
    char ch;
    std::cout << "Yes/No[y/n]: ";
    std::cin >> ch;
    switch (ch) {
        case 'y':
            return YES;
        case 'n':
            return NO;
        default:
            std::cout << "Wrong input! Try again!\n";
            return input_yes_no();
    }
}

void Tracer::print_fail_load() {
    std::cout << "Failed to load!\n";
    std::cout << "New game!\n";
}
void Tracer::print_error_load(){
    std::cout << "invalid checksum!\n";
}