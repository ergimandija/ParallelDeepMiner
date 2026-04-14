#ifndef FIELD_H
#define FIELD_H


class Field
{
    public:
        Field(int value);
        virtual ~Field();
        int getValue();
        void setValue(int value);
        int mine();
        bool isMined() const;
    protected:

    private:
        int _value;
        bool _isMined;
};

#endif // FIELD_H
