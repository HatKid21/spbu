#include <cstdlib>
#include <iostream>
#include <limits>

#include "artAssets.hpp"
#include "menu.hpp"
#include "menuFunctions.hpp"

const hatkid::MenuItem* hatkid::showMenu(const hatkid::MenuItem* current) {

	for (int i = 1; i < current->childrenCount; i++) {
		std::cout << current->children[i]->title << std::endl;
	}
	std::cout << current->children[0]->title << std::endl;
	std::cout << "Обучалка > ";

	int userInput;
	std::cin >> userInput;
	std::cout << std::endl;

	return current->children[userInput];
}

const hatkid::MenuItem* hatkid::showContent(const hatkid::MenuItem* current) {
	std::cout << current->content;
	std::cout << "Нажмите ENTER чтобы продолжить:";

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');	

	std::cin.get();
	return current->parent;
}

const hatkid::MenuItem* hatkid::subjectGoBack(const MenuItem* current) {
	return current->parent;
}

const hatkid::MenuItem* hatkid::exit(const MenuItem* current) {
	std::exit(0);
	return current->parent;
}

const hatkid::MenuItem* hatkid::studyAlgebra(const MenuItem* current) {
	std::cout << hatkid::UAY;
	std::cout << "Утешев Алексей Юрьевич>";
	std::cout << "Чтож... критическая масса из 1-го человека собралась...";
	std::cout << "Чему хочешь научиться сегодня?" << std::endl;
	return showMenu(current);
}

const hatkid::MenuItem*  hatkid::studyMathAnalysis(const MenuItem* current) {
	std::cout << hatkid::BAO;
	std::cout << "Бочкарёв Анатолий Олегович>";
	std::cout << "Здравствуй. Чему ты хочешь сегодня научиться?" << std::endl;
	return showMenu(current);
}

const hatkid::MenuItem*  hatkid::studyGoBack(const MenuItem* current) {
	return current->parent->parent;
}
