#ifndef SB_PROJECT_OUTOFRANGEBG_H
#define SB_PROJECT_OUTOFRANGEBG_H
#include <exception>
class OutOfRangeBG: public std::exception{
public:
    const char* what() const noexcept override;
};
#endif //SB_PROJECT_OUTOFRANGEBG_H