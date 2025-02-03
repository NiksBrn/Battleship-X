#ifndef RENDER_H
#define RENDER_H
#include "TerminalRender.h"
template <typename RenderType>
class Render
{
public:
    Render() = default;
    ~Render() = default;
    void render_info(std::string info){render.renderInfo(info);}
    void renderPlayerView(BattleGround& battle_ground_){render.renderPlayerView(battle_ground_);}
    void renderOpponentView(BattleGround& battle_ground_){render.renderOpponentView(battle_ground_);};
private:
    RenderType render;
};
#endif //RENDER_H
