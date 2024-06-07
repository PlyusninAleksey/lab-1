#pragma once
#include <iostream>
#include <string>

class Monom
{
public:
	double coef = 0;
    int degreeX = 0;
    int degreeY = 0;
    int degreeZ = 0;
    Monom(){}
    Monom(double coef, int degreeX, int degreeY, int degreeZ)
    {
        this->coef = coef;
        this->degreeX = degreeX;
        this->degreeY = degreeY;
        this->degreeZ = degreeZ;
    }

    Monom operator*(const Monom& obj) const {
        Monom res(coef * obj.coef, degreeX + obj.degreeX, degreeY + obj.degreeY, degreeZ + obj.degreeZ);
        return res;
    }

    bool operator==(const Monom& obj) const
    {
        if (degreeX == obj.degreeX && degreeY == obj.degreeY && degreeZ == obj.degreeZ)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    friend std::ostream& operator<<(std::ostream& stream, const Monom& obj)
    {
        stream << obj.coef << "*x^" << obj.degreeX << "*y^" << obj.degreeY << "*z^" << obj.degreeZ;
        return stream;
    }
};

