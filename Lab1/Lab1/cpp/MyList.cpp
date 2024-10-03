#include "MyList.h"

bool MyList::is_empty() {
	return first == nullptr;
}

void MyList::push_back(const string& value) {
	auto new_node = std::make_shared<MyList::Node>();
	new_node->film->set_name(value);
	if (is_empty()) {
		first = new_node;
		last = new_node;
		return;
	}
	last->next = new_node;
	last = new_node;
}

void MyList::print_list() {
	if (is_empty())
		return;
	std::shared_ptr <MyList::Node> current_node = MyList::first;
	while (current_node) {
		cout << "Name: " << current_node->film->get_name() << endl;
		current_node = current_node->next;
	}
}

std::shared_ptr <MyList::Node> MyList::search_node(std::string_view value) {
	if (is_empty())
		return nullptr;
	std::shared_ptr <MyList::Node> current_node = MyList::first;
	while (current_node && current_node->film->get_name() != value)
		current_node = current_node->next;
	return (current_node && current_node->film->get_name() == value) ? current_node : nullptr;
}

void MyList::remove_first() {
	if (is_empty())
		return;
	std::shared_ptr <MyList::Node> temp = MyList::first;
	first = first->next;
}

void MyList::remove_last() {
	if (is_empty())
		return;
	if (MyList::first == MyList::last) {
		remove_first();
		return;
	}
	std::shared_ptr <MyList::Node> temp = MyList::first;
	while (temp->next != MyList::last)
		temp = temp->next;
	temp->next = nullptr;
	MyList::last = temp;
}

void MyList::remove_node(std::string_view value) {
	if (is_empty())
		return;
	if (first->film->get_name() == value) {
		remove_first();
		return;
	}
	if (last->film->get_name() == value) {
		remove_last();
		return;
	}
	std::shared_ptr <MyList::Node> slow = MyList::first;
	std::shared_ptr <MyList::Node> fast = MyList::first->next;
	while (fast && fast->film->get_name() != value) {
		fast = fast->next;
		slow = slow->next;
	}
	if (!fast) {
		cout << "This element does not exist" << endl;
		return;
	}
	slow->next = fast->next;
}