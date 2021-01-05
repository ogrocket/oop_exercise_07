#pragma once

#include <cmath>
#include<iostream>
#include "fstream"

class Figure{
protected:
    std::pair<double, double> center;

public:
    Figure(){}

    Figure(std::pair<double, double> center){
        this->center = center;
    }

    virtual double Area() = 0;

    virtual void Print() = 0;

    virtual void Save(std::ofstream &out) = 0;

    std::pair<double, double> Center(){
        return center;
    }
};

// id: 1 - triangle, 2 - rectangle, 3 - square
