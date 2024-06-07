#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Monom.h"
#include "List.h"


class Polynomial {
public:

    List<Monom> monoms;
    std::string infix;

    Polynomial() {}
    Polynomial(std::string infix_) :infix(infix_) {}
    Polynomial(const Polynomial& obj) :monoms(obj.monoms) {}

    bool ValidCheck() {
        for (char symbol : infix) {
            if (!std::isdigit(symbol) && !std::isalpha(symbol) && symbol != '-' && symbol != '+' && symbol != '*' && symbol != '^' && symbol != '.' && symbol != ' ') { return false; }
        }
        return true;
    }

    void push(Monom& obj)
    {
        bool flag = false;

        for (auto it = monoms.begin(); it != monoms.end(); it++)
        {
            if (*it == obj)
            {
                it->coef += obj.coef;
                if (it->coef == 0)
                {
                    monoms.deleteNode(it);
                }
                flag = true;
                break;
            }

        }
        if (flag != true && obj.coef != 0)
        {
            monoms.pushBack(obj);
        }
    }

    void toPolynom()
    {
        if (ValidCheck() == true)
        {
            std::stringstream ss(infix);
            std::string term;
            while (ss >> term)
            {
                if (term == "+")
                {
                    continue;
                }
                double coef;
                int degreeX, degreeY, degreeZ;
                sscanf_s(term.c_str(), "%lf*x^%d*y^%d*z^%d", &coef, &degreeX, &degreeY, &degreeZ);
                monoms.pushBack(Monom(coef, degreeX, degreeY, degreeZ));
            }
        }
        else
        {
            throw std::exception("Valid infix");
        }
    }
    friend std::ostream& operator<<(std::ostream& stream, const Polynomial& obj)
    {
        stream << obj.monoms.getNode(0)->data;
        if (obj.monoms.begin() != obj.monoms.end())
        {
            auto it = obj.monoms.begin();
            ++it;
            for (; it != obj.monoms.end(); ++it)
            {
                stream << " + " << *it;
            }
        }
        return stream;
    }
    Polynomial operator*(const Polynomial& obj) {
        Polynomial res;
        for (auto it1 = monoms.begin(); it1 != monoms.end(); it1++) {
            for (auto it2 = obj.monoms.begin(); it2 != obj.monoms.end(); it2++) {
                Monom comp = (*it1) * (*it2);
                res.push(comp);
            }
        }
        return res;
    }

    Polynomial operator+(const Polynomial& obj)
    {
        Polynomial res(*this);
        for (auto it = obj.monoms.begin(); it != obj.monoms.end(); ++it)
        {
            res.push(*it);
        }
        return res;
    }
    
};