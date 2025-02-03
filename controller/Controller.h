#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Tracer.h"
#include "../game_session/headers/session.h"
#include "Tracer.h"
#include "../game_session/headers/session.h"

template <typename TypeInput>
class Controller
{
public:
    Controller(Session& session): session(session) {};
    ~Controller() = default;
    void start()
    {
        tracer.info_start();
        bool exit_flag = false;
        while (!exit_flag)
        {
            if (tracer.isStartRound)
            {
                tracer.show_BG_player(session.get_bg_p());
                tracer.show_BG_ai(session.get_bg_ai());
                tracer.last_action(last_action);
                tracer.info_skills(session.get_cnt_skills());
            }
            switch (input.getInput())
            {
            case START_GAME:
                if(!tracer.isStartSession)
                {
                    session.new_game();

                    tracer.input_BG();
                    session.initial_bg(input.inputDec());
                    tracer.show_BG_player(session.get_bg_p());

                    tracer.input_cnt_ships();
                    short cnt_ships = input.inputDec();

                    for (short i = 0; i < cnt_ships; i++)
                    {
                        tracer.input_len_ship();
                        short data_length = input.inputDec();
                        tracer.input_orientation();
                        Orientation data_orientation = input.inputOrientation();
                        tracer.input_y();
                        short x = input.inputDec();
                        tracer.input_x();
                        short y = input.inputDec();
                        session.add_ship_to_manager(std::make_pair(data_length, data_orientation));
                        session.add_ship_to_bg(std::make_pair(x,y), i);
                        tracer.show_BG_player(session.get_bg_p());
                    }
                    session.initial_p2();
                    tracer.info_ai();
                    tracer.show_BG_player(session.get_bg_p());
                    tracer.show_BG_ai(session.get_bg_ai());
                }
                break;
            case START_ROUND:
                if(tracer.isStartSession)
                tracer.round_start();
                // triger + flag
                break;
            case CONTINUE:
                if (!tracer.isStartRound && tracer.isStartSession)
                {
                    tracer.new_round();
                    session.initial_p2();
                    tracer.info_ai();
                    tracer.show_BG_player(session.get_bg_p());
                    tracer.show_BG_ai(session.get_bg_ai());
                }
                break;
            case SAVE:
                {
                    if(tracer.isStartRound)
                    {
                        Status save_status_ = session.save();
                        tracer.info_save_status(save_status_);
                    }
                    break;
                }
            case LOAD:
                {
                    Status load_status_ = session.load();
                    tracer.info_load_status(load_status_);
                    break;
                }
            case SKILL:
                if (tracer.isStartRound)
                {
                    SkillType skill_type = session.get_skill();
                    tracer.info_use_skill(skill_type);
                    std::pair<GameCondition, AttackResult> res;
                    res = session.UseSkill();
                    if (res.first == ending_game){tracer.win();break;}
                    last_action = res.second;
                    if (session.move_ai().first == ending_game){tracer.los();break;}
                }
                break;
            case ATTACK:
                if (tracer.isStartRound)
                {
                    tracer.input_x();
                    short x = input.inputDec();
                    tracer.input_y();
                    short y = input.inputDec();
                    std::pair<GameCondition, AttackResult> res;
                    res = session.attack(x,y);
                    if (res.first == ending_game){tracer.win(); break;}
                    last_action = res.second;
                    if (session.move_ai().first == ending_game){tracer.los();break;}

                }
                break;
            case EXIT:
                exit_flag = true;
                break;
            default:
                break;
            }
        }

    };


private:
    Session& session;
    TypeInput input;
    Tracer tracer;
    AttackResult last_action;
};
#endif //CONTROLLER_H
