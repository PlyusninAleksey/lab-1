#include "Polynomial.h"
#include <gtest.h>

TEST(Monom, can_create_empty_monom) {
	ASSERT_NO_THROW(Monom obj);
}

TEST(Monom, can_create_monom) {
	ASSERT_NO_THROW(Monom obj(1,1,1,1));
}

TEST(Monom, is_comparison_operator_valid) {
	Monom m1(1,1,1,1);
	Monom m2(1,1,1,1);
	EXPECT_TRUE(m1 == m2);
}


TEST(Monom, is_assign_operator_valid) {
	Monom m1(1,1,1,1);
	Monom m2 = m1; 
	EXPECT_TRUE(m2 == m1);
}

TEST(Monom, can_multiply_monoms)
{
	EXPECT_TRUE(Monom(1, 1, 1, 1) * Monom(2, 2, 2, 2) == Monom(2, 3, 3, 3));
}

TEST(Polynomial, can_create_empty_polinomial) {
	ASSERT_NO_THROW(Polynomial obj);
}

TEST(Polynomial, can_copy_Polymonomial)
{
	Polynomial obj1;
	ASSERT_NO_THROW(Polynomial obj2(obj1));
}

TEST(Polynomial, can_create_with_infix)
{
	ASSERT_NO_THROW(Polynomial obj("1*x^2*y^2*z^2"));
}

TEST(Polynomial, can_check_wrong_infix)
{
	Polynomial obj("2/x");
	EXPECT_FALSE(obj.ValidCheck());
}

TEST(Polynomial, can_right_transform)
{
	Polynomial obj("1*x^2*y^2*z^2");
	obj.toPolynom();
	EXPECT_TRUE(obj.monoms.getNode(0)->data == Monom(1, 2, 2, 2));
}

TEST(Polynomial, can_add_new_monom) {
	Monom m1(1,1,1,1);

	Polynomial obj;

	ASSERT_NO_THROW(obj.push(m1));
}

TEST(Polynomial, cend_add_many_monom)
{
	Polynomial obj;
	obj.push(Monom(1, 1, 1, 1));
	obj.push(Monom(1, 1, 1, 1));
	EXPECT_NO_THROW(obj.push(Monom(1, 1, 1, 1)));
}


TEST(Polynomial, can_addition_polynomials) {
	Monom m1(1,1,1,1);
	Monom m2(2,2,2,2);

	Polynomial obj1;
	Polynomial obj2;

	obj1.push(m1);
	obj2.push(m2);
	ASSERT_NO_THROW(obj1 + obj2);
}

TEST(Polynomial, can_multiply_polynomials) {
	Monom m1(1,1,1,1);
	Polynomial obj1;

	Monom m2(2,2,2,2);
	Polynomial obj2;

	obj1.push(m1);
	obj2.push(m2);
	ASSERT_NO_THROW(obj1 * obj2);
}



