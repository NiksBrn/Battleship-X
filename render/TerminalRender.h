#ifndef RENDER_H_
#define RENDER_H_
#include "../headers/BattleGround.h"
#include "iostream"


// Цветовые коды ANSI
#define RESET "\033[0m"
#define WHITE "\033[47m"      // Белый фон
#define RED "\033[41m"        // Красный фон
#define YELLOW "\033[43m"     // Желтый фон
#define GREEN "\033[42m"      // Зеленый фон
#define TRANSPARENT "\033[40m" // Прозрачный фон (черный)


class TerminalRenderer {
public:
    explicit TerminalRenderer();
    void renderInfo(std::string info);
    void renderPlayerView(const BattleGround& battle_ground_) const;
    void renderOpponentView(const BattleGround& battle_ground_) const;
private:
    void renderBattleGround(const BattleGround& battle_ground_,bool isPlayerView) const;
    std::string getCellColor(bool isShip, bool isVisible, const BattleGround& battle_ground_, short x, short y) const;
};

#endif //RENDER_H
