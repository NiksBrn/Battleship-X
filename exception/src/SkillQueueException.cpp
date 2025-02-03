#include "../headers/SkillQueueException.h"
const char *SkillQueueException::what() const noexcept{
    return "Captain, the skill set of abilities has run out!(";
}