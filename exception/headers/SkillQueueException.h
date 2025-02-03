#ifndef SB_PROJECT_SKILLQUEUEEXCEPTION_H
#define SB_PROJECT_SKILLQUEUEEXCEPTION_H
#include <exception>
class SkillQueueException: public std::exception{
public:
    const char* what() const noexcept override;
};
#endif //SB_PROJECT_SKILLQUEUEEXCEPTION_H
