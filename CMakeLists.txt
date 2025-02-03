cmake_minimum_required(VERSION 3.30)
project(sb_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(sb_project main.cpp
        exception/headers/OutOfRangeBG.h
        exception/headers/ShipCollisionException.h
        exception/headers/SkillQueueException.h
        exception/src/OutOfRangeBG.cpp
        exception/src/ShipCollisionException.cpp
        exception/src/SkillQueueException.cpp
        game_session/headers/Ai.h
        game_session/headers/session.h
        game_session/headers/SessionManager.h
        game_session/headers/state.h
        game_session/src/Ai.cpp
        game_session/src/session.cpp
        game_session/src/SessionManager.cpp
        game_session/src/state.cpp
        headers/BattleGround.h
        headers/Ship.h
        headers/ShipManager.h
        headers/SkillDD.h
        headers/SkillInterface.h
        headers/SkillManager.h
        headers/SkillScan.h
        headers/SkillShrapnel.h
        input/headers/TerminalInput.h
        input/src/TerminalInput.cpp
        render/Render.h
        render/TerminalRender.h
        render/TerminalRender.cpp
        src/BattleGround.cpp
        src/Ship.cpp
        src/Shipmanager.cpp
        src/SkillDD.cpp
        src/SkillScan.cpp
        src/SkillShrapnel.cpp
        src/SkillManager.cpp
        src/SkillInterface.cpp
        controller/Controller.h
        controller/Tracer.h
        controller/Tracer.cpp)
