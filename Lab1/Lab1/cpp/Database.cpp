#include "\Work\Lab1\Lab1\Lab1\h\DatabaseFilms.h"

void DatabaseFilms::create_film() {
	DatabaseFilms::cont = true;
	string name;
	while (cont) {
		cout << "Enter film name:" << endl;
		rewind(stdin);
		getline(cin, name);
		DatabaseFilms::database->push_back(name);
		cout << "If you're want to add another one enter 1, else 0" << endl;
		cin >> cont;
	}
}

void DatabaseFilms::print_database() {
	DatabaseFilms::database->print_list();
}

void DatabaseFilms::update_film() {
	DatabaseFilms::cont = true;
	string new_name, old_name;
	while (cont) {
		cout << "Enter film name:" << endl;
		rewind(stdin);
		getline(cin, old_name);
		if (DatabaseFilms::database->search_node(old_name)) {
			cout << "Enter new film name:" << endl;
			getline(cin, new_name);
			DatabaseFilms::database->search_node(old_name)->film->set_name(new_name);
		}
		else
			cout << "This film does not exist" << endl;
		cout << "If you're want to update another one enter 1, else 0" << endl;
		cin >> DatabaseFilms::cont;
	}
}

void DatabaseFilms::delete_film() {
	DatabaseFilms::cont = true;
	string name;
	while (DatabaseFilms::cont) {
		cout << "Enter film name:" << endl;
		rewind(stdin);
		getline(cin, name);
		database->remove_node(name);
		cout << "If you're want to delete another one enter 1, else 0" << endl;
		cin >> DatabaseFilms::cont;
	}
}
