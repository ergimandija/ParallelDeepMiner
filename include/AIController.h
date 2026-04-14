#ifndef AICONTROLLER_H
#define AICONTROLLER_H
#include "IController.h"

class AIController: public IController
{
    public:
        AIController();
        virtual ~AIController();
        char pickDirection() override;

    protected:

    private:
};

#endif // AICONTROLLER_H
