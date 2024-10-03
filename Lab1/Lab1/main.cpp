#include <iostream>
#include <string>
#include ".\h\DatabaseFilms.h"
#include ".\h\Film.h"
#include ".\h\MyList.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


int main() {
	bool exit = true;
	int choose;
	auto my_films = std::make_shared<DatabaseFilms>();
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
		default:
			cout << "This is not a function";
		}
		cout << "Do you want continue? If yes, enter 1, else 0" << endl;
		cin >> exit;
		system("cls");
	}
	return 0;
}