#include "Field.h"

Field::Field(int value)
{

    _isMined = false;
    _value = value;
}

Field::~Field()
{
    //dtor
}

int Field::getValue(){
    return _value;
}

void Field::setValue(int value){
        _value = value;
    }

int Field::mine(){
    if(!_isMined){
    _isMined = true;
    return _value;
    }
    return 0;
}

bool Field::isMined() const{
    return _isMined;
}
