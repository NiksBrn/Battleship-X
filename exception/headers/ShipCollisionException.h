#ifndef SB_PROJECT_SHIPCOLLISIONEXCEPTION_H
#define SB_PROJECT_SHIPCOLLISIONEXCEPTION_H
#include <exception>
class ShipCollisionException: public std::exception{
public:
    const char* what() const noexcept override;
};
#endif //SB_PROJECT_SHIPCOLLISIONEXCEPTION_H
