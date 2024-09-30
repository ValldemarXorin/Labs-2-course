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

	void create_film() {
		cont = true;
		string name;
		while (cont) {
			cout << "Enter film name:" << endl;
			rewind(stdin);
			getline(cin, name);
			database->push_back(name);
			cout << "If you're want to add another one enter 1, else 0" << endl;
			cin >> cont;
		}
	}

	void print_database() {
		database->print_list();
	}

	void update_film() {
		cont = true;
		string new_name, old_name;
		while (cont) {
			cout << "Enter film name:" << endl;
			rewind(stdin);
			getline(cin, old_name);
			if (database->search_node(old_name)) {
				cout << "Enter new film name:" << endl;
				getline(cin, new_name);
				database->search_node(old_name)->film->set_name(new_name);
			}
			else
				cout << "This film does not exist" << endl;
			cout << "If you're want to update another one enter 1, else 0" << endl;
			cin >> cont;
		}
	}

	void delete_film() {
		cont = true;
		string name;
		while (cont) {
			cout << "Enter film name:" << endl;
			rewind(stdin);
			getline(cin, name);
			database->remove_node(name);
			cout << "If you're want to delete another one enter 1, else 0" << endl;
			cin >> cont;
		}
	}
};