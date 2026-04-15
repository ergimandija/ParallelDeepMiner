#ifndef FIELD_H
#define FIELD_H


class Field
{
    public:
        Field(int value);
        virtual ~Field();
        int getValue();
        void setValue(int value);

    protected:

    private:
        int _value;
};

#endif // FIELD_H
