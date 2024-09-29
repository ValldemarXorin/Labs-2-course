#include <iostream>
#include <string>
#include "Film.h"
#include "DatabaseFilms.h"
#include "MyList.h"
#include "locale.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


int main() {
	bool exit = true;
	int choose;
	DatabaseFilms* my_films = new DatabaseFilms;
	while (exit) {
		cout << "Choose function:\n1. Add film\n2. Check films list\n3. Update film\n4. Delete film" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			my_films->create_film();
			break;
		case 2:
			my_films->print_database();
			break;
		case 3:
			my_films->update_film();
			break;
		case 4:
			my_films->delete_film();
			break;
		}
		cout << "Do you want continue? If yes, enter 1, else 0" << endl;
		cin >> exit;
	}
	delete my_films;
	return 0;
}