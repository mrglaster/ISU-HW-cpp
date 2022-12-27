#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Shape.h"


class Polygon : public Shape{

    private:
        std::vector<Point> points;
        std::string name = "Polygon";
        size_t pointsAmount;

    public:

        /**Constructor by vector of points*/
        Polygon(std::vector<Point> _points){
            points = _points;
            pointsAmount = points.size();
            points.resize(pointsAmount + 1);
            points[pointsAmount] = points[0];
        }

        /**Constructor by data from file*/
        Polygon(char* filename){
            std::ifstream in;
            in.open(filename, std::ios::in);
            if (in.is_open()) {
                std::string line;
                std::getline(in, line);
                std::stringstream sstream(line);
                size_t str_size;
                sstream >> str_size;
                pointsAmount = str_size;
                points.resize(pointsAmount+1);
                int i = 0;
                while (i!=pointsAmount+1) {
                    int x, y;
                    in >> x >> y;
                    points[i] = Point(x, y);
                    i++;
                }

              }else{
                throw std::invalid_argument("Given input file not found!");
            }
        }

    /**Returns the name of the figure*/
    std::string whoAmI() override{
        return name;
    }

    /**Perimeter calculating method override*/
    double getPerimeter() override {
        double sum = 0;
        for (int i = 0; i < pointsAmount; i++) sum += points[i].distToPoint(points[i+1]);
        return sum;
    }

    /**Square finding method override*/
    double getArea() override {
        int sum=0;
        for(int i = 1; i < pointsAmount; i++) sum+= points[i].pointVecMul(points[i-1]);
        return abs((double)sum/2);
    }
};

#endif // POLYGON_H_INCLUDED
