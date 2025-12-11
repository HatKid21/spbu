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

	const MenuItem* showAddContent(const MenuItem* current);
	const MenuItem* showSubtractContent(const MenuItem* current);
	const MenuItem* showMultiplyContent(const MenuItem* current);
	const MenuItem* showDivideContent(const MenuItem* current);
	const MenuItem* showIntegralContent(const MenuItem* current);
	const MenuItem* showDifferentialContent(const MenuItem* current);
}
