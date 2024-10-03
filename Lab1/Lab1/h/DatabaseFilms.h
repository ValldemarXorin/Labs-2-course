#pragma once
#include <iostream>
#include <string>
#include "Film.h"
#include "MyList.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class DatabaseFilms {
private:
	std::shared_ptr <MyList> database = std::make_shared<MyList>();
	bool cont = true;
public:
	DatabaseFilms() = default;

	DatabaseFilms(const DatabaseFilms& other) = delete;

	const DatabaseFilms& operator=(const DatabaseFilms& other) = delete;

	void create_film();
	void print_database();
	void update_film();
	void delete_film();
};