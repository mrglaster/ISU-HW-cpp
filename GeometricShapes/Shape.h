#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

class Shape{
    public:
        virtual double getSquare() = 0;
        virtual double getPerimeter() = 0;
        virtual void showFigureType()= 0;
};


#endif // SHAPE_H_INCLUDED
