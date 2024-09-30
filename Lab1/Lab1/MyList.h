#pragma once
#include <iostream>
#include <string_view>
#include "Film.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;


class MyList {
private:
	struct Node {
		std::shared_ptr <Film> film;
		std::shared_ptr <Node> next = nullptr;
		explicit Node(const string& new_value) : film(new Film(new_value)) {}
	};
	std::shared_ptr <Node> first = nullptr;
	std::shared_ptr <Node> last = nullptr;

public:
	explicit MyList() = default;

	MyList(const MyList& other) = delete;

	const MyList& operator=(const MyList& other) = delete;

	~MyList() {
		while (first) {
			remove_first();
		}
	}

	bool is_empty() {
		return first == nullptr;
	}

	void push_back(const string& value) {
		std::shared_ptr <Node> new_node = std::make_shared<Node>();
		if (is_empty()) {
			first = new_node;
			last = new_node;
			return;
		}
		last->next = new_node;
		last = new_node;
	}

	void print_list() {
		if (is_empty())
			return;
		std::shared_ptr <Node> current_node = first;
		while (current_node) {
			cout << "Name: " << current_node->film->get_name() << endl;
			current_node = current_node->next;
		}
	}

	std::shared_ptr <Node> search_node(std::string_view value) {
		if (is_empty())
			return nullptr;
		std::shared_ptr <Node> current_node = first;
		while (current_node && current_node->film->get_name() != value)
			current_node = current_node->next;
		return (current_node && current_node->film->get_name() == value) ? current_node : nullptr;
	}

private:
	void remove_first() {
		if (is_empty())
			return;
		std::shared_ptr <Node> temp = first;
		first = first->next;
	}

	void remove_last() {
		if (is_empty())
			return;
		if (first == last) {
			remove_first();
			return;
		}
		std::shared_ptr <Node> temp = first;
		while (temp->next != last)
			temp = temp->next;
		temp->next = nullptr;
		last = temp;
	}

public:
	void remove_node(std::string_view value) {
		if (is_empty())
			return;
		if (first->film->get_name() == value) {
			remove_first();
			return;
		}
		if (last->film->get_name() == value) {
			remove_last();
			return;
		}
		std::shared_ptr <Node> slow = first;
		std::shared_ptr <Node> fast = first->next;
		while (fast && fast->film->get_name() != value) {
			fast = fast->next;
			slow = slow->next;
		}
		if (!fast) {
			cout << "This element does not exist" << endl;
			return;
		}
		slow->next = fast->next;
	}
};