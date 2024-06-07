#include <iostream>
#include "list.h"
#include "monom.h"
#include "polynomial.h"
#include <string>

int main()
{
	List<int> list;
	list.pushBack(1);
	list.pushBack(2);
	list.pushBack(3);
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it;
	}
	std::cout << std::endl;

	Polynomial polynom1("1*x^2*y^2*z^2 + -1*x^3*y^1*z^3"); //¬ мономоме пробелов не делать, ставить все знаки умножени€.  аждый моном раздел€ть " + ".
	polynom1.toPolynom();
	std::cout << polynom1 << std::endl;
	auto it1 = polynom1.monoms.begin();
	++it1;
	polynom1.monoms.deleteNode(it1);
	std::cout << polynom1 << std::endl;

	Polynomial polynom2("3*x^4*y^4*z^4 + -3*x^5*y^6*z^7");
	polynom2.toPolynom();
	std::cout << polynom2 << std::endl;

	std::cout << polynom1 * polynom2 << std::endl;
	std::cout << polynom1 + polynom2 << std::endl;
	return 0;
}