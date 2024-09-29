#pragma once
#include <iostream>
#include <string>
#include "Film.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;



class MyList {
private:
	struct Node {
		Film* film;
		Node* next;
		Node(const string& new_value) : film(new Film(new_value)), next(nullptr){}
	};
	Node* first;
	Node* last;

public:
	MyList() : first(nullptr), last(nullptr) {}

	~MyList() {
		while (first) {
			remove_first();
		}
	}

	bool is_empty() {
		return first == nullptr;
	}

	void push_back(const string& value) {
		Node* new_node = new Node(value);
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
		Node* current_node = first;
		while (current_node) {
			cout << "Name: " << current_node->film->get_name() << endl;
			current_node = current_node->next;
		}
	}

	Node* search_node(const string& value) {
		if (is_empty())
			return nullptr;
		Node* current_node = first;
		while (current_node && current_node->film->get_name() != value)
			current_node = current_node->next;
		return (current_node && current_node->film->get_name() == value) ? current_node : nullptr;
	}

private:
	void remove_first() {
		if (is_empty())
			return;
		Node* temp = first;
		first = first->next;
		delete temp;
	}

	void remove_last() {
		if (is_empty())
			return;
		if (first == last) {
			remove_first();
			return;
		}
		Node* temp = first;
		while (temp->next != last)
			temp = temp->next;
		temp->next = nullptr;
		delete last;
		last = temp;
	}

public:
	void remove_node(const string& value) {
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
		Node* slow = first;
		Node* fast = first->next;
		while (fast && fast->film->get_name() != value) {
			fast = fast->next;
			slow = slow->next;
		}
		if (!fast) {
			cout << "This element does not exist" << endl;
			return;
		}
		slow->next = fast->next;
		delete fast;
	}
};