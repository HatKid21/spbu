#pragma once

#include "menu.hpp"

namespace hatkid {

	const MenuItem* showMenu(const MenuItem* current);

	const MenuItem* exit(const MenuItem* current);
	const MenuItem* study(const MenuItem* current);
	const MenuItem* studyClass(const MenuItem* current);
	const MenuItem* studyStruct(const MenuItem* current);
	const MenuItem* studyPointer(const MenuItem* current);
	const MenuItem* studyGoBack(const MenuItem* current);
}
