#include "PlayerController.h"

PlayerController::PlayerController()
{
    //ctor
}

PlayerController::~PlayerController()
{
    //dtor
}

char PlayerController::pickDirection(){

    char input;
    while(1){
    std::cout<< "Enter directions(w-> Forward, s->Backward, d->Right, a->Left, .->Don't move)" << std::endl;
    std::cin>> input;
    if(input == 'w' || input== 's' || input == 'd' || input== 'a' || input=='.'){
        return input;
    }
    std::cout << "Input invalid try again" << std::endl;


    }
}
