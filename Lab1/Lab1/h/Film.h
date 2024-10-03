#pragma once
#include <iostream>
#include <string>
#include <string_view>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Film {
private:
	string name;

public:
	Film() = default;

	explicit Film(const string& enter_name) : name(enter_name) {}

	void set_name(std::string_view new_name);

	string get_name() const;
};