#include "TerminalRender.h"


TerminalRenderer::TerminalRenderer()
{
}

void TerminalRenderer::renderInfo(std::string info)
{
    std::cout << info << std::endl;
}

void TerminalRenderer::renderPlayerView(const BattleGround& battle_ground_) const {
    renderBattleGround(battle_ground_, true);
}

void TerminalRenderer::renderOpponentView(const BattleGround& battle_ground_) const {
    renderBattleGround(battle_ground_, false);
}

void TerminalRenderer::renderBattleGround(const BattleGround& battle_ground_, bool isPlayerView) const {
    short size = battle_ground_.get_size();

    // Верхняя нумерация
    std::cout << "   ";
    for (short i = 0; i < size; ++i) {
        std::cout << i << (i < 10 ? "   " : "  ");
    }
    std::cout << "\n";

    // Горизонтальная линия
    std::cout << "  +" << std::string(size * 4 - 1, '-') << "+\n";

    for (short y = 0; y < size; ++y) {
        // Номер строки
        std::cout << y << (y < 10 ? " |" : "|");

        for (short x = 0; x < size; ++x) {
            bool isVisible;
            if (isPlayerView == true)isVisible = true;
            else isVisible = battle_ground_.is_visible(x, y);
             bool isShip = battle_ground_.get_status(x, y).first;
             std::string cellColor = getCellColor(isShip, isVisible, battle_ground_, x, y);
             std::cout << cellColor << "   " << RESET << "|";
        }

        // Горизонтальная линия
        std::cout << "\n  +" << std::string(size * 4 - 1, '-') << "+\n";
    }
}

std::string TerminalRenderer::getCellColor(bool isShip, bool isVisible, const BattleGround& battle_ground_, short x, short y) const {
    if (!isVisible) {
        return WHITE; // Клетка закрыта
    }

    if (isShip) {
        // Проверяем состояние сегмента корабля
        const SegmentStatus segment_status = battle_ground_.get_segment_status(x, y);
        if (segment_status == 2) {
            return GREEN; // Сегмент целый
        } else if (segment_status == 1) {
            return YELLOW; // Сегмент подбит
        } else {
            return RED; // Сегмент уничтожен
        }
    }

    // Если клетка пустая и открытая
    return TRANSPARENT;
}