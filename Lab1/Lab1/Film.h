#pragma once
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Film {
private:
	string name;

public:
	explicit Film(const string& enter_name) : name(enter_name) {}

	void set_name(const string& new_name) {
		name = new_name;
	}

	string get_name() const {
		return name;
	}
};