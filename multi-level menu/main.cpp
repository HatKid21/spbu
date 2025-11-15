#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menuFunctions.hpp"

int main() {
	std::setlocale(LC_ALL, "");

	hatkid::MenuItem study = {"1 - Хочу учиться программированию.",hatkid::study};
	hatkid::MenuItem exit = {"2 - Не сейчас...", hatkid::exit};

	hatkid::MenuItem* mainChildren[] {&exit, &study};
	const int mainSize = sizeof(mainChildren) / sizeof(mainChildren[0]);

	int userInput;

	do {
		std:: cout << "Добро пожаловать в обучалку!" << std::endl;
		for (int i = 1; i < mainSize; i++){
			std::cout << mainChildren[i]->title << std::endl;
		}
		std::cout << mainChildren[0]->title << std::endl;
		std::cout << "Обучалка > ";

		std::cin >> userInput;
		mainChildren[userInput]->func();

		std::cout << std::endl;

	} while (true);
	return 0;
}
