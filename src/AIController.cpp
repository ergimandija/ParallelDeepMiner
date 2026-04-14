#include "AIController.h"
#include <memory>

AIController::AIController()
{
    //ctor
}

AIController::~AIController()
{
    //dtor
}


char AIController::pickDirection(){
    int randomValue = rand()%4;
    switch(randomValue){
    case 0:
        return 'w';
        break;
    case 1:
        return 's';
        break;
    case 2:
         return 'd';
         break;
    default:
         return 'a';
         break;
    }


}
