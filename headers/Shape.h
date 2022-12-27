#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

class Shape{
    public:
        virtual double getPerimeter() = 0;
        virtual double getArea() = 0;
        virtual std::string whoAmI() = 0;
};


#endif // SHAPE_H_INCLUDED
