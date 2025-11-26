#include "menuFunctions.hpp"
#include "menuItems.hpp"

const hatkid::MenuItem hatkid::MAIN_MENU = {
	"0 Выйти в главное меню",
	hatkid::mainMenu,
	&hatkid::MAIN
};

const hatkid::MenuItem hatkid::GO_BACK = {
	"0 Вернуться в предыдущее меню",
	hatkid::goBack,
	&hatkid::QUESTION
};

const hatkid::MenuItem hatkid::RUSSIAN = {
	"1 Русский язык",
	hatkid::blank,
	&hatkid::FIRST_GRADE
};

const hatkid::MenuItem hatkid::LITERATURE ={
	"2 Русская литература",
	hatkid::blank,
	&hatkid::FIRST_GRADE
};

const hatkid::MenuItem hatkid::MATH = {
	"3 Математика",
	hatkid::blank,
	&hatkid::FIRST_GRADE
};

const hatkid::MenuItem hatkid::PC = {
	"4 Я люблю физкультуру",
	hatkid::blank,
	&hatkid::FIRST_GRADE
};


namespace {
	
	const hatkid::MenuItem* const firstGradeChildren[] = {
		&hatkid::GO_BACK,
		&hatkid::RUSSIAN,
		&hatkid::LITERATURE,
		&hatkid::MATH,
		&hatkid::PC	
	};
	const int firstGradeSize = sizeof(firstGradeChildren) / sizeof(firstGradeChildren[0]);

}

const hatkid::MenuItem hatkid::FIRST_GRADE = {
	"1 Изучать предметы 1-го класса",
	hatkid::thirdLevelMenu,
	&hatkid::MAIN,
	firstGradeChildren,
	firstGradeSize
};

const hatkid::MenuItem hatkid::SECOND_GRADE = {
	"2 Изучать предметы 2-го класса",
	hatkid::blank,
	&hatkid::MAIN
};

const hatkid::MenuItem hatkid::THIRD_GRADE = {
	"3 Изучать предметы 3-го класса",
	hatkid::blank,
	&hatkid::MAIN
};

namespace {
	
	const hatkid::MenuItem* questionChildren[] = {
		&hatkid::MAIN_MENU,
		&hatkid::FIRST_GRADE,
		&hatkid::SECOND_GRADE,
		&hatkid::THIRD_GRADE	
	};
	const int questionSize = sizeof(questionChildren) / sizeof(questionChildren[0]);

}

const hatkid::MenuItem hatkid::QUESTION = {
	"1 Предметы какого класса школы вы хотите изучить?",
	hatkid::secondLevelMenu,
	&hatkid::MAIN,
	questionChildren,
	questionSize

};

const hatkid::MenuItem hatkid::EXIT = {
	"0 Я уже закончил школу и всё знаю",
	hatkid::exit
};

namespace {
	const hatkid::MenuItem* mainChildren[] = {
		&hatkid::EXIT,
		&hatkid::QUESTION
	};	
	const int mainSize = sizeof(mainChildren) / sizeof(mainChildren[0]);
}

const hatkid::MenuItem hatkid::MAIN = {
	nullptr,
	hatkid::firstLevelMenu,
	nullptr,
	mainChildren,
	mainSize
};
