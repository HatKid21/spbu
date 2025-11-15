#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menuFunctions.hpp"

int main() {
	std::setlocale(LC_ALL, "");

	hatkid::MenuItem studyPointers = {"1 - Хочу изучать указатели!", hatkid::studyPointer};
	hatkid::MenuItem studyStructs = {"2 - Хочу изучать структуры!", hatkid::studyStruct};
	hatkid::MenuItem studyClasses = {"3 - Хочу изучать классы!", hatkid::studyClass};
       	hatkid::MenuItem studyGoBack = {"0 - Хочу домой...", hatkid::studyGoBack};

	hatkid::MenuItem* studyChildren[] = {
		&studyGoBack,
		&studyPointers,
		&studyStructs,
		&studyClasses,
	};

	const int studySize = sizeof(studyChildren) / sizeof(studyChildren[0]);

	hatkid::MenuItem study = {"1 - Хочу учиться программированию.",hatkid::showMenu,studyChildren,studySize};
	hatkid::MenuItem exit = {"0 - Не сейчас...", hatkid::exit};

	hatkid::MenuItem* mainChildren[] {&exit, &study};
	const int mainSize = sizeof(mainChildren) / sizeof(mainChildren[0]);
	
	hatkid::MenuItem mainMenu = {nullptr, hatkid::showMenu, mainChildren,mainSize};

	studyGoBack.parent = &study;
	studyPointers.parent = &study;
	studyStructs.parent = &study;
	studyClasses.parent = &study;

	study.parent = &mainMenu;
      	exit.parent = &mainMenu;	



	const hatkid::MenuItem* current = &mainMenu;
	do {
		current = current->func(current);
	} while (true);
	return 0;
}
