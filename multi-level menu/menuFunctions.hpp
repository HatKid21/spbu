#pragma once

#include "menu.hpp"

namespace hatkid {

	const MenuItem* showMenu(const MenuItem* current);

	const MenuItem* exit(const MenuItem* current);
	const MenuItem* study(const MenuItem* current);
	const MenuItem* studyMathAnalysis(const MenuItem* current);
	const MenuItem* studyAlgebra(const MenuItem* current);
	const MenuItem* studyGoBack(const MenuItem* current);

	const MenuItem* subjectGoBack(const MenuItem* current);

	const MenuItem* showContent(const MenuItem* current);
}

