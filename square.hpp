#include "figure.hpp"

class Square: public Figure{
private:
    std::pair<double, double> vertex[3];

public:
    Square(){}

    Square(std::pair<double, double> center, double side){
        this->center = center;
        vertex[0].first = center.first - side/2;
        vertex[0].second = center.second - side/2;
        vertex[1].first = center.first - side/2;
        vertex[1].second = center.second + side/2;
        vertex[2].first = center.first + side/2;
        vertex[2].second = center.second + side/2;
        vertex[3].first = center.first + side/2;
        vertex[3].second = center.second - side/2;
    }

    double Area() override{
        return (vertex[2].first - vertex[1].first)*
                (vertex[1].second - vertex[0].second);
    }

    void Print() override{
        std::cout << *this;
    }

    void Save(std::ofstream &f) override{
        int id = 3;
        f.write((char*) &id, sizeof(int));
        f.write((char*) &center.first,  sizeof(double));
        f.write((char*) &center.second, sizeof(double));
        f.write((char*) &vertex[0].first, sizeof(double));
        f.write((char*) &vertex[0].second, sizeof(double));
        f.write((char*) &vertex[1].first, sizeof(double));
        f.write((char*) &vertex[1].second, sizeof(double));
        f.write((char*) &vertex[2].first, sizeof(double));
        f.write((char*) &vertex[2].second, sizeof(double));
        f.write((char*) &vertex[3].first, sizeof(double));
        f.write((char*) &vertex[3].second, sizeof(double));
    }

     friend std::ostream& operator<<(std::ostream& cout, const Square& t){
        cout << "Square:\t\t";
        cout << "(" << t.vertex[0].first << ", " << t.vertex[0].second << ")";
        cout << "(" << t.vertex[1].first << ", " << t.vertex[1].second << ")";
        cout << "(" << t.vertex[2].first << ", " << t.vertex[2].second << ")";
        cout << "(" << t.vertex[3].first << ", " << t.vertex[3].second << ")";
        return cout;
    }
};
