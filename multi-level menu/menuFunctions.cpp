#include <cstdlib>
#include <iostream>

#include "menu.hpp"
#include "menuFunctions.hpp"

const hatkid::MenuItem* hatkid::showMenu(const hatkid::MenuItem* current){

	for (int i = 1; i < current->childrenCount; i++){
		std::cout << current->children[i]->title << std::endl;
	}
	std::cout << current->children[0]->title << std::endl;
	std::cout << "Обучалка > ";

	int userInput;
	std::cin >> userInput;
	std::cout << std::endl;

	return current->children[userInput];
}


const hatkid::MenuItem* hatkid::exit(const MenuItem* current){
	std::exit(0);
	return current->parent;
}

const hatkid::MenuItem* hatkid::studyClass(const MenuItem* current){
	return current->parent;
}

const hatkid::MenuItem* hatkid::studyPointer(const MenuItem* current){
	return current->parent;
}

const hatkid::MenuItem*  hatkid::studyStruct(const MenuItem* current){
	return current->parent;
}

const hatkid::MenuItem*  hatkid::studyGoBack(const MenuItem* current){
	return current->parent->parent;
}
