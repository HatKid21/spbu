#include <iostream>

#include "menuItems.hpp"
#include "menuFunctions.hpp"
#include "menu.hpp" 

int main(){
	const hatkid::MenuItem* current = &hatkid::MAIN;
	while (true){
		current = current->func(current);
	}
}
