#include <cstdlib>
#include <iostream>

#include "menu.hpp"
#include "menuFunctions.hpp"
#include "artAssets.hpp"

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
	std::cout << "Бочкарёв Анатолий Олегович>";
	std::cout << "Основные понятия в дифферециальном исчислении - производная и дифференциал" << std::endl;
	std::cout << "Произваодная - это отношение приращения функции на приращение аргумента" << std::endl;
	std::cout << "Дифференциал - это главная линейная часть приращения" << std::endl;
	std::cout << std::endl;
	return current->parent;
}

const hatkid::MenuItem* hatkid::integral(const MenuItem* current){
	std::cout << "Бочкарёв Анатолий Олегович>";
	std::cout << "А эта тема будет у нас на будущих лекциях. Не пропусти!" << std::endl;
	std::cout << std::endl;
	return current->parent;
}

const hatkid::MenuItem* hatkid::subjectGoBack(const MenuItem* current){
	return current->parent;
}

const hatkid::MenuItem* hatkid::add(const MenuItem* current){
	std::cout << "Утешев Алексей Юрьевич>";
	std::cout << "В общем случае у нас числа комплексные." << std::endl;
	std::cout << "Вот тебе пример: (1+2i) + (5-3i) = 6-i" << std::endl;
	std::cout << std::endl;
	return current->parent;
}

const hatkid::MenuItem* hatkid::subtract(const MenuItem* current){
	std::cout << "Утешев Алексей Юрьевич>";
	std::cout << "В общем случае у нас числа комплексные." << std::endl;
	std::cout << "Вот тебе пример: (1+2i) - (5-3i) = -4+5i" << std::endl;
	std::cout << std::endl;
	return current->parent;
}

const hatkid::MenuItem* hatkid::multiply(const MenuItem* current){
	std::cout << "Утешев Алексей Юрьевич>";
	std::cout << "Там есть формула, но никто ее не запоминает. Легче как с обычными числами работать" << std::endl;
	std::cout << "Вот тебе пример: (1+2i) * (5-3i) =5-3i+10i-6i^2=11+7i" << std::endl;
	std::cout << std::endl;
	return current->parent;
}

const hatkid::MenuItem* hatkid::divide(const MenuItem* current){
	std::cout << "Утешев Алексей Юрьевич>";
	std::cout << "А вот тут не все так просто. Если мы делим на комплекное число, надо домножить числитель и знаменатель на комплексно сопряженное." << std::endl;
	std::cout << "Вот тебе пример:";
	std::cout << "(1+2i) / (5-3i) = (-1+13i)/34=-1/34+13i/34" << std::endl;
	std::cout << std::endl;
	return current->parent;
}

const hatkid::MenuItem* hatkid::exit(const MenuItem* current){
	std::exit(0);
	return current->parent;
}

const hatkid::MenuItem* hatkid::studyAlgebra(const MenuItem* current){
	std::cout << hatkid::UAY;
	std::cout << "Утешев Алексей Юрьевич>";
	std::cout << "Чтож... критическая масса из 1-го человека собралась...";
	std::cout << "Чему хочешь научиться сегодня?" << std::endl;
	return showMenu(current);
}

const hatkid::MenuItem*  hatkid::studyMathAnalysis(const MenuItem* current){
	std::cout << hatkid::BAO;
	std::cout << "Бочкарёв Анатолий Олегович>";
	std::cout << "Здравствуй. Чему ты хочешь сегодня научиться?" << std::endl;
	return showMenu(current);
}

const hatkid::MenuItem*  hatkid::studyGoBack(const MenuItem* current){
	return current->parent->parent;
}
