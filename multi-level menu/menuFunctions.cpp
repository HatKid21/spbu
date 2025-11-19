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

const hatkid::MenuItem* hatkid::differential(const MenuItem* current){
	return current->parent;
}

const hatkid::MenuItem* hatkid::integral(const MenuItem* current){
	return current->parent;
}

const hatkid::MenuItem* hatkid::subjectGoBack(const MenuItem* current){
	return current->parent;
}

const hatkid::MenuItem* hatkid::add(const MenuItem* current){
	std::cout << "Утешев Алексей Юрьевич>";
	std::cout << "В общем случае у нас числа комплексные. " << std::endl;
	std::cout << "Вот тебе пример: (1+2i) + (5-3i) = 6-i" << std::endl;
	return current->parent;
}

const hatkid::MenuItem* hatkid::subtract(const MenuItem* current){
	return current->parent;
}

const hatkid::MenuItem* hatkid::multiply(const MenuItem* current){
	return current->parent;
}

const hatkid::MenuItem* hatkid::divide(const MenuItem* current){
	return current->parent;
}

const hatkid::MenuItem* hatkid::exit(const MenuItem* current){
	std::exit(0);
	return current->parent;
}

const hatkid::MenuItem* hatkid::studyAlgebra(const MenuItem* current){
	std::cout << "Утешев Алексей Юрьевич> Критическая масса из 1 человека собралась...";
	std::cout << "Чему хочешь научиться сегодня?" << std::endl;
	return showMenu(current);
}

const hatkid::MenuItem*  hatkid::studyMathAnalysis(const MenuItem* current){
	std::cout << "Бочкарёв Анатолий Олегович> Здравствуй. Что ты сегодня хочешь повторить?" << std::endl;
	return showMenu(current);
}

const hatkid::MenuItem*  hatkid::studyGoBack(const MenuItem* current){
	return current->parent->parent;
}
