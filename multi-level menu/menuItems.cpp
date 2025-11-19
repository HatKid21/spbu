#include "menuItems.hpp"

#include <cstddef>

#include "menuFunctions.hpp"

const hatkid::MenuItem hatkid::ADD = {
	"1 - Хочу научиться складывать!", hatkid::add,&hatkid::STUDY
};

const hatkid::MenuItem hatkid::SUBTRACT = {
	"2 - Хочу научиться вычитать!", hatkid::subtract,&hatkid::STUDY
};

const hatkid::MenuItem hatkid::MULTIPLY = {
	"3 - Хочу научиться умножать!", hatkid::multiply,&hatkid::STUDY
};

const hatkid::MenuItem hatkid::DIVIDE = {
	"4 - Хочу научиться делить!", hatkid::divide,&hatkid::STUDY
};

const hatkid::MenuItem hatkid::SUBJECT_GO_BACK ={
	"0 - Вернуться к выбору предметов.",hatkid::subjectGoBack,&hatkid::STUDY
};

namespace {
	const hatkid::MenuItem* const algebraChildren[] = {
		&hatkid::SUBJECT_GO_BACK,
		&hatkid::ADD,
		&hatkid::SUBTRACT,
		&hatkid::MULTIPLY,
		&hatkid::DIVIDE
	};
	const int algebraSize = sizeof(algebraChildren) / sizeof(algebraChildren[0]);
}

const hatkid::MenuItem hatkid::STUDY_ALGEBRA = {
	"1 - Хочу изучать алгебру!", hatkid::showMenu, &hatkid::STUDY, algebraChildren, algebraSize
};

const hatkid::MenuItem hatkid::STUDY_MATH_ANALYSIS = {
	"2 - Хочу изучать математический анализ!", hatkid::studyMathAnalysis, &hatkid::STUDY
};

const hatkid::MenuItem hatkid::STUDY_GO_BACK = {
	"0 - Выйти в главное меню.", hatkid::studyGoBack, &hatkid::STUDY
};

namespace {

	const hatkid::MenuItem* const studyChildren[] = {
		&hatkid::STUDY_GO_BACK,
		&hatkid::STUDY_ALGEBRA,
		&hatkid::STUDY_MATH_ANALYSIS,
	};
	const int studySize = sizeof(studyChildren) / sizeof(studyChildren[0]);
}


const hatkid::MenuItem hatkid::STUDY = {
	"1 - Хочу учиться математике!!", hatkid::showMenu, &hatkid::MAIN, studyChildren, studySize
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
