#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menuFunctions.hpp"
#include "menuItems.hpp"

int main() {
	const hatkid::MenuItem* current = &hatkid::MAIN;

	do {
		current = current->func(current);
	} while (true);

	return 0;
}
