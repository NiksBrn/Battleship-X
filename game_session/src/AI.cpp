#include "../headers/AI.h"
#include <random>
#include <sstream>


AI::AI(short bg_size_){
    bg_size = bg_size_;
    srand(time(NULL));
    int seed = rand();
    std::default_random_engine generator(seed);
    std::vector<std::pair<short, short>> v;
    for(short i = 0; i < bg_size; i++){
        for(short j = 0; j < bg_size; j++){
            v.push_back(std::make_pair(i, j));
        }
    }
    shuffle(v.begin(), v.end(), generator);
    for(auto g: v){
        //std::cout << g.first << " " << g.second << std::endl;
        izi_win.push(std::make_pair(0, g));
    }

}

AI::AI(std::string save){
    std::stringstream ss(save);
    ss >> bg_size;
    int n;
    ss >> n;
    while(!izi_win.empty())izi_win.pop();
    for(int i =0; i < n; ++i){
        short a,b,c;
        ss >> a >> b >> c;
        izi_win.push(std::make_pair(a, std::make_pair(b,c)));
    }
}

std::pair <short, short> AI::get_coords() {
    std::pair <short, short> coords = izi_win.top().second;
    izi_win.pop();
    return coords;
}

void AI::generate_coords(AttackResult result, std::pair<short, short> tec) {
    if(result == DAMADGE) {
        izi_win.push(std::make_pair(2, tec));
        for (short i = -1; i <= 1; i++) {
            for (short j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                izi_win.push(std::make_pair(1, std::make_pair(tec.first + i, tec.second + j)));
            }
        }
    }
}

std::vector<std::pair<short, short>> AI::generate_pos(short bg_size){
    int seed = rand();
    std::vector<std::pair<short, short>> pos;
    for(short i = 0; i < bg_size; i++){
        for(short j = 0; j < bg_size; j++) {
            pos.push_back(std::make_pair(i, j));
        }
    }
    std::default_random_engine generator(seed);
    shuffle(pos.begin(), pos.end(), generator);
    return pos;
}
Orientation AI::generate_orientation(){
    srand(time(NULL));
    if(rand() % 2== 0){return HORIZONTAL;}
    return VERTICAL;
}

std::string AI::back_up() {
    std::string back_up_ = "";
    back_up_ += std::to_string(bg_size) + " ";
    back_up_ += std::to_string(izi_win.size()) + " ";
    std::priority_queue<std::pair<short, std::pair<short, short>>> izi_win_copy = izi_win;
    while (!izi_win_copy.empty()) {
        back_up_ += std::to_string(izi_win_copy.top().first) + " " + std::to_string(izi_win_copy.top().second.first)
                    + " " + std::to_string(izi_win_copy.top().second.second) + " ";
        izi_win_copy.pop();
    }
    return back_up_;
}
