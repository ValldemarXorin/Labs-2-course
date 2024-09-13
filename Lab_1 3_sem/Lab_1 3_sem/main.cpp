#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int size_arr = 0;

class Film {
private:
	string name;
	int year;

public:
	//constructor
	Film(const string& enter_name = "", int enter_year = 0) : name(enter_name), year(enter_year)
		{}

	string get_name() {
		return name;
	}

	int get_year() {
		return year;
	}

	void set_name(string enter_name) {
		name = enter_name;
	}

	void set_year(int enter_year) {
		year = enter_year;
	}
};

class DatabaseFilms {
private:
	Film* base_films;
	int enter_size;

public:
	DatabaseFilms(int e_size) : enter_size(e_size)
	{
		base_films = new Film[size_arr + enter_size];
	}

	~DatabaseFilms() {
		delete[] base_films;
	}

	void check_year(int& c_year) {
		while (c_year <= 1960) {
			cout << "Pls, enter year equal or more than 1960: " << endl;
			cin >> c_year;
		}
	}

	void create_film(string enter_name, int enter_year) {
		check_year(enter_year);
		base_films[size_arr] = Film(enter_name, enter_year);
		size_arr++;
	}

	void read_films() {
		for (int i = 0; i < size_arr; i++) {
			cout << "Name, Year: " << base_films[i].get_name() << " " << base_films[i].get_year() << endl;
		}
	}

	void update_film(string old_name, int old_year) {
		check_year(old_year);
		for (int i = 0; i < size_arr + 1; i++) {
			if (old_name == base_films[i].get_name() && old_year == base_films[i].get_year()) {
				string new_name;
				int new_year;
				cout << "Enter new name of film: " << endl;
				cin >> new_name;
				cout << "Enter new name of film: " << endl;
				cin >> new_year;
				check_year(new_year);
				base_films[i].set_name(new_name);
				base_films[i].set_year(new_year);
				return;
			}
		}
		cout << "This film is not situated in our collection. Enter 1 if you want to add this film: " << endl;
		int add_film;
		cin >> add_film;
		if (add_film == 1) {
			create_film(old_name, old_year);
		}
	}

	void delete_film(string name_film, int year_film) {
		check_year(year_film);
		Film* temp = new Film[size_arr];
		for (int i = 0; i < size_arr; i++) {
			if (base_films[i].get_name() != name_film || base_films[i].get_year() != year_film) {
				temp[i] = base_films[i];
			}
		}
		size_arr--;
		delete[] base_films;
		base_films = new Film[size_arr];
		for (int i = 0; i < size_arr; i++) {
			base_films[i] = temp[i];
		}
		delete[] temp;
	}
};

int main() {
	int size;
	cout << "Enter size of pool films" << endl;
	cin >> size;
	DatabaseFilms* database_films = new DatabaseFilms(size);
	int choose_menu;
	string name_film;
	int year_film;
	bool exit = true;
	while (exit) {
		cout << "Choose:" << endl << "1. Add film" << endl << "2. Check films" << endl
			<< "3. Update film" << endl << "4. Delete film" << endl;
		cin >> choose_menu;
		switch (choose_menu) {
		case 1:
			cout << "Enter name and year of film: " << endl << "Name: ";
			rewind(stdin);
			getline(cin, name_film);
			cout << endl << "Year: ";
			cin >> year_film;
			database_films->create_film(name_film, year_film);
			break;
		case 2:
			database_films->read_films();
			break;
		case 3:
			cout << "Enter name and year of film: " << endl << "Name: ";
			rewind(stdin);
			getline(cin, name_film);
			cout << endl << "Year: ";
			cin >> year_film;
			database_films->update_film(name_film, year_film);
			break;
		case 4:
			cout << "Enter name and year of film: " << endl << "Name: ";
			rewind(stdin);
			getline(cin, name_film);
			cout << endl << "Year: ";
			cin >> year_film;
			database_films->delete_film(name_film, year_film);
			break;
		}
		cout << "Do you want to get another try? Send 1. If nope, send 0" << endl;
		cin >> exit;
	}
	return 0;
}

//ссылки посмотреть глубже и добавить