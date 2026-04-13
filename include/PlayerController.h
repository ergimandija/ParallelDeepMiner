#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H
#include "IController.h"
#include <iostream>
class PlayerController: public IController
{
    public:
        PlayerController();
        virtual ~PlayerController();
        char pickDirection() override;

    protected:

    private:
};

#endif // PLAYERCONTROLLER_H
