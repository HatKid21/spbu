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
namespace {
	const hatkid::MenuItem* waitForUser(const hatkid::MenuItem* current) {
		std::cout << "Нажмите ENTER чтобы продолжить:";

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');	

		std::cin.get();
		return current->parent;
	}
}
const hatkid::MenuItem* hatkid::showAddContent(const hatkid::MenuItem* current) {
	std::cout <<  "Утешев Алексей Юрьевич> В общем случае у нас числа комплексные.\nВот тебе пример: (1+2i) + (5-3i) = 6-i\n\n";
	return waitForUser(current);
}

const hatkid::MenuItem* hatkid::showSubtractContent(const hatkid::MenuItem* current) {
	std::cout << "Утешев Алексей Юрьевич> В общем случае у нас числа комплексные.\nВот тебе пример: (1+2i) - (5-3i) = -4+5i\n\n";
	return waitForUser(current);
}

const hatkid::MenuItem* hatkid::showMultiplyContent(const hatkid::MenuItem* current) {
	std::cout << "Утешев Алексей Юрьевич> Там есть формула, но никто ее не запоминает. Легче как с обычными числами работать\nВот тебе пример: (1+2i) * (5-3i) =5-3i+10i-6i^2=11+7i\n\n";
	return waitForUser(current);
}

const hatkid::MenuItem* hatkid::showDivideContent(const hatkid::MenuItem* current) {
	std::cout << "Утешев Алексей Юрьевич> А вот тут не все так просто. Если мы делим на комплекcное число, надо домножить числитель и знаменатель на комплексно сопряженное.\nВот тебе пример:""(1+2i) / (5-3i) = (-1+13i)/34=-1/34+13i/34\n\n";
	return waitForUser(current);
}

const hatkid::MenuItem* hatkid::showIntegralContent(const hatkid::MenuItem* current) {
	std::cout << "Бочкарёв Анатолий Олегович> А эта тема будет у нас на будущих лекциях. Не пропусти!\n\n";
	return waitForUser(current);
}

const hatkid::MenuItem* hatkid::showDifferentialContent(const hatkid::MenuItem* current) {
	std::cout << "Бочкарёв Анатолий Олегович> Основные понятия в дифферециальном исчислении - производная и дифференциал\nПроизводная - это предел отношения приращения функции к приращению аргумента при стремлении приращения аргумента к нулю\nДифференциал - это главная линейная часть приращения\n\n";
	return waitForUser(current);
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
