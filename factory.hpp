#pragma once
//#include "triangle.hpp"
//#include "rectangle.hpp"
//#include "square.hpp"
#include <memory>

struct Factory{
    static std::shared_ptr<Figure> Create(int id){ 	//console factory
        switch(id){
            case 1:{	//triangle
                std::pair<double, double> center;
                double h, l;
                std::cout << "Input center coordinates, height and base of triangle:";
                std::cin >> center.first >> center.second >> h >> l;
                return std::make_shared<Triangle>(center, h, l);
            }

            case 2:{	//rectangle
                std::pair<double, double> center;
                double h, l;
                std::cout << "Input center coordinates, height and base of rectangle:";
                std::cin >> center.first >> center.second >> h >> l;
                return std::make_shared<Rectangle>(center, h, l);
            }

            case 3:{	//square
                std::pair<double, double> center;
                double side;
                std::cout << "Input center coordinates and side of square:";
                std::cin >> center.first >> center.second >> side;
                return std::make_shared<Square>(center, side);
            }
        }
    }

    static std::shared_ptr<Figure> Create(int id, std::ifstream &in){	//file factory
        switch (id){
            case 1:{	//triangle
                std::pair<double, double> center;
                double h, l;
                in.read((char *) &center.first, sizeof(double));
                in.read((char *) &center.second, sizeof(double));
                in.read((char *) &h, sizeof(double));
                in.read((char *) &l, sizeof(double));
                return std::make_shared<Triangle>(center, h, l);
            }

            case 2:{	//rectangle
                std::pair<double, double> center;
                double h, l;
                in.read((char *) &center.first, sizeof(double));
                in.read((char *) &center.second, sizeof(double));
                in.read((char *) &h, sizeof(double));
                in.read((char *) &l, sizeof(double));
                return std::make_shared<Rectangle>(center, h, l);
            }

            case 3:{
                std::pair<double, double> center;
                double side;
                in.read((char *) &center.first, sizeof(double));
                in.read((char *) &center.second, sizeof(double));
                in.read((char *) &side, sizeof(double));
                return std::make_shared<Square>(center, side);
            }
        }
    }
};
