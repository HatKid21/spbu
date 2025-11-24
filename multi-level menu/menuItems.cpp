#include <cstddev>

#include "menuItems.hpp"
#include "menuFunctions.hpp"

const hatkid::MenuItem hatkid::ADD = {
	"1 - Хочу научиться складывать!", 
	hatkid::showContent,
	&hatkid::STUDY_ALGEBRA,
	nullptr,
	0,
	"Утешев Алексей Юрьевич> В общем случае у нас числа комплексные.\nВот тебе пример: (1+2i) + (5-3i) = 6-i\n\n"
};

const hatkid::MenuItem hatkid::SUBTRACT = {
	"2 - Хочу научиться вычитать!", 
	hatkid::showContent,
	&hatkid::STUDY_ALGEBRA,
	nullptr,
	0,
	"Утешев Алексей Юрьевич> В общем случае у нас числа комплексные.\nВот тебе пример: (1+2i) - (5-3i) = -4+5i\n\n"
};

const hatkid::MenuItem hatkid::MULTIPLY = {
	"3 - Хочу научиться умножать!", 
	hatkid::showContent,
	&hatkid::STUDY_ALGEBRA,
	nullptr,
	0,
	"Утешев Алексей Юрьевич> Там есть формула, но никто ее не запоминает. Легче как с обычными числами работать\nВот тебе пример: (1+2i) * (5-3i) =5-3i+10i-6i^2=11+7i\n\n"
};

const hatkid::MenuItem hatkid::DIVIDE = {
	"4 - Хочу научиться делить!", 
	hatkid::showContent,
	&hatkid::STUDY_ALGEBRA,
	nullptr,
	0,
	"Утешев Алексей Юрьевич> А вот тут не все так просто. Если мы делим на комплекное число, надо домножить числитель и знаменатель на комплексно сопряженное.\nВот тебе пример:""(1+2i) / (5-3i) = (-1+13i)/34=-1/34+13i/34\n\n"

};

const hatkid::MenuItem hatkid::SUBJECT_GO_BACK ={
	"0 - Вернуться к выбору предметов.",
	hatkid::subjectGoBack,
	&hatkid::STUDY
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
	"1 - Хочу изучать алгебру!", 
	hatkid::studyAlgebra, 
	&hatkid::STUDY, 
	algebraChildren, 
	algebraSize
};

const hatkid::MenuItem hatkid::DIFFERENTIAL = {
	"1 - Хочу изучать дифференциальное исчисление!", 
	hatkid::showContent, 
	&hatkid::STUDY_MATH_ANALYSIS,
	nullptr,
	0,
	"Бочкарёв Анатолий Олегович> Основные понятия в дифферециальном исчислении - производная и дифференциал\nПроизваодная - это отношение приращения функции на приращение аргумента\nДифференциал - это главная линейная часть приращения\n\n"

};

const hatkid::MenuItem hatkid::INTEGRAL = {
	"2 - Хочу изучать интегральное исчисление!", 
	hatkid::showContent, 
	&hatkid::STUDY_MATH_ANALYSIS,
	nullptr,
	0,
	"Бочкарёв Анатолий Олегович> А эта тема будет у нас на будущих лекциях. Не пропусти!\n\n"
};

namespace {
	
	const hatkid::MenuItem* const mathAnalysisChildren[] = {
		&hatkid::SUBJECT_GO_BACK,
		&hatkid::DIFFERENTIAL,
		&hatkid::INTEGRAL
	};

	const int mathAnalysisSize = sizeof(mathAnalysisChildren) / sizeof(mathAnalysisChildren[0]);

}


const hatkid::MenuItem hatkid::STUDY_MATH_ANALYSIS = {
	"2 - Хочу изучать математический анализ!", 
	hatkid::studyMathAnalysis, 
	&hatkid::STUDY, 
	mathAnalysisChildren,
	mathAnalysisSize
};

const hatkid::MenuItem hatkid::STUDY_GO_BACK = {
	"0 - Выйти в главное меню.", 
	hatkid::studyGoBack, 
	&hatkid::STUDY
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
	"1 - Хочу учиться математике!!", 
	hatkid::showMenu, 
	&hatkid::MAIN, 
	studyChildren, 
	studySize
};

const hatkid::MenuItem hatkid::EXIT = {
	"0 - Не сейчас...", 
	hatkid::exit, 
	&hatkid::MAIN
};

namespace {
	const hatkid::MenuItem* const mainChildren[] = {
		&hatkid::EXIT,
		&hatkid::STUDY
	};
	const int mainSize = sizeof(mainChildren) / sizeof(mainChildren[0]);
}

const hatkid::MenuItem hatkid::MAIN = {
	nullptr, 
	hatkid::showMenu,
	nullptr,
	mainChildren,
	mainSize
};
