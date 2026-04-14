#ifndef ICONTROLLER_H
#define ICONTROLLER_H

enum ControllerType {
    AI, PLAYER
};
class IController
{
    public:
        virtual ~IController();
        virtual char pickDirection()=0;
    protected:

    private:
};

#endif // ICONTROLLER_H
