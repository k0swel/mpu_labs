#include "is_palindrom.h"

bool is_palindrom(std::string& text) {
	Deque<char> my_dequee;
	for (auto el : text) {
		my_dequee.push_front(el);
	}

	while (!my_dequee.is_empty()) {
		if (my_dequee.back()->value == my_dequee.front()->value) {
			my_dequee.pop_back();
			my_dequee.pop_front();
			continue;
		}
		return false;
	}
	return true;
}
