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
		std::shared_ptr <Film> film = std::make_shared<Film>();
		std::shared_ptr <Node> next = nullptr;
		Node() = default;
		explicit Node(const string& new_value) {
			film->set_name(new_value);
		}
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

	bool is_empty();
	void push_back(const string& value);
	void print_list();
	std::shared_ptr <Node> search_node(std::string_view value);

private:
	void remove_first();
	void remove_last();

public:
	void remove_node(std::string_view value);
};