#ifndef GLUTTONROBOT_H
#define GLUTTONROBOT_H
#include "Robot.h"

class GluttonRobot: public Robot
{
    public:
        GluttonRobot(std::unique_ptr<IController> controller, int xBorder, int yBorder);
        virtual ~GluttonRobot();
        void dismantle(std::vector<std::vector<std::vector<std::unique_ptr<Field>>>>& fields) override;

    protected:

    private:
};

#endif // GLUTTONROBOT_H
