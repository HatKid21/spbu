#include <iostream>

#include "menuFunctions.hpp"
#include "menu.hpp"

namespace {
	
	const hatkid::MenuItem* showElements(const hatkid::MenuItem* current){
		for (int i = 1; i < current->childrenCount; i++){
			std::cout << current->children[i]->title << std::endl;
		}
		std::cout << current->children[0]->title << std::endl;
		int userInput;
		std::cin >> userInput;
		return current->children[userInput];		
	}

}

const hatkid::MenuItem* hatkid::secondLevelMenu(const hatkid::MenuItem* current){
	std::cout << "Второй уровень меню:" << std::endl;
	return showElements(current);
}


const hatkid::MenuItem* hatkid::firstLevelMenu(const hatkid::MenuItem* current){
	std::cout << "Главное меню:" << std::endl;
	return showElements(current);
}

const hatkid::MenuItem* hatkid::thirdLevelMenu(const hatkid::MenuItem* current){
	std::cout << "Третий уровень меню:" << std::endl;
	return showElements(current);
}

const hatkid::MenuItem* hatkid::exit(const hatkid::MenuItem* current){
	std::exit(0);
	return current;
}

const hatkid::MenuItem* hatkid::goBack(const hatkid::MenuItem* current){
	return current->parent;
}

const hatkid::MenuItem* hatkid::mainMenu(const hatkid::MenuItem* current){
	return current->parent;
}

const hatkid::MenuItem* hatkid::blank(const hatkid::MenuItem* current){
	return current->parent;
}
