#include "List.h"
#include <gtest.h>

TEST(Node, can_create_node) {
	ASSERT_NO_THROW(Node<int> obj);
}

TEST(Node, is_node_comparison_valid) {
	Node<int> node1;
	Node<int> node2;
	node1.data = 1;
	node2.data = 1;
	EXPECT_TRUE(node1 == node2);
}

TEST(Node, is_node_comparison_unequal_valid) {
	Node<int> node1;
	Node<int> node2;
	node1.data = 1;
	node2.data = 2;
	EXPECT_TRUE(node1 != node2);
}

TEST(Node, can_copy_existing_node) {
	Node<int> obj1;
	obj1.data = 2;
	ASSERT_NO_THROW(Node<int> obj2(obj1));
}

TEST(Node, can_copy_existing_node_by_operator) {
	Node<int> obj1;
	Node<int> obj2;
	obj1.data = 3;
	ASSERT_NO_THROW(obj2 = obj1);
}

TEST(List, can_create_empty_list) {
	ASSERT_NO_THROW(List<int> obj);
}

TEST(List, can_create_list_with_size) {
	ASSERT_NO_THROW(List<int> list(1));
}

TEST(List, can_add_new_element) {;
	List<int> obj;
	ASSERT_NO_THROW(obj.pushBack(2));
}

TEST(List, can_add_many_elements)
{
	List<int> obj;
	obj.pushBack(1);
	obj.pushBack(2);
	ASSERT_NO_THROW(obj.pushBack(3));
}

TEST(List, can_add_value) {
	List<int> obj;
	ASSERT_NO_THROW(obj.pushBack(1));
}

TEST(List, can_copy_existing_list) {;
	List<int> src(1);
	ASSERT_NO_THROW(List<int> obj(src));
}

TEST(List, is_list_erase_valid) {
	List<int> obj;
	obj.pushBack(1);
	obj.pushBack(2);
	obj.pushBack(3);
	Iterator<int> it(obj.begin());
	it++;
	ASSERT_NO_THROW(obj.deleteNode(it));
}

TEST(Iterator, can_create_iterator) {
	Node<int> node;
	ASSERT_NO_THROW(Iterator<int> it(node));
}

TEST(Iterator, can_copy_existing_iterator) {
	Node<int> node;
	Iterator<int> obj(node);
	ASSERT_NO_THROW(Iterator<int> it(obj));
}

TEST(Iterator, can_get_data_from_iterator) {
	Node<int> node;
	Iterator<int> obj(node);
	ASSERT_NO_THROW(*obj);
}

TEST(Iterator, is_data_from_iterator_valid) {
	Node<int> node;
	node.data = 1;
	Iterator<int> obj(node);
	EXPECT_EQ(*obj, 1);
}

TEST(Iterator, can_get_begin_of_list) {
	List<int> obj;
	ASSERT_NO_THROW(Iterator<int> it(obj.begin()));
}

TEST(Iterator, is_increment_iterator_valid) {
	List<int> obj;
	obj.pushBack(1);
	obj.pushBack(2);
	obj.pushBack(3);
	Iterator<int> it(obj.begin());
	it++;
	it++;
	EXPECT_EQ(*it, 3);
}