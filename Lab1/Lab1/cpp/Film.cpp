#include "Film.h"

void Film::set_name(std::string_view new_name) {
	Film::name = new_name;
}

string Film::get_name() const {
	return Film::name;
}