#include "menuItems.hpp"

#include <cstddef>

#include "menuFunctions.hpp"


const hatkid::MenuItem hatkid::STUDY_POINTER = {
	"1 - Хочу изучать указатели!", hatkid::studyPointer, &hatkid::STUDY
};

const hatkid::MenuItem hatkid::STUDY_STRUCT = {
	"2 - Хочу изучать структуры!", hatkid::studyStruct, &hatkid::STUDY
};

const hatkid::MenuItem hatkid::STUDY_CLASS = {
	"3 - Хочу изучать классы!", hatkid::studyClass, &hatkid::STUDY
};

const hatkid::MenuItem hatkid::STUDY_GO_BACK = {
	"0 - Хочу домо...", hatkid::studyGoBack, &hatkid::STUDY
};

namespace {

	const hatkid::MenuItem* const studyChildren[] = {
		&hatkid::STUDY_GO_BACK,
		&hatkid::STUDY_POINTER,
		&hatkid::STUDY_STRUCT,
		&hatkid::STUDY_CLASS
	};
	const int studySize = sizeof(studyChildren) / sizeof(studyChildren[0]);
}


const hatkid::MenuItem hatkid::STUDY = {
	"1 - Хочу изучать программирование!", hatkid::showMenu, &hatkid::MAIN, studyChildren, studySize
};

const hatkid::MenuItem hatkid::EXIT = {
	"0 - Не сейчас...", hatkid::exit, &hatkid::MAIN
};

namespace {
	const hatkid::MenuItem* const mainChildren[] = {
		&hatkid::EXIT,
		&hatkid::STUDY
	};
	const int mainSize = sizeof(mainChildren) / sizeof(mainChildren[0]);
}

const hatkid::MenuItem hatkid::MAIN = {
	nullptr, hatkid::showMenu,nullptr,mainChildren,mainSize
};
