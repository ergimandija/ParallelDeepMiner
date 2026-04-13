#include "Field.h"

Field::Field(int value)
{
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
