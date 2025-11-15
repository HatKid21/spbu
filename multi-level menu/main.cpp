#include <clocale>
#include <iostream>

int main() {
	std::setlocale(LC_ALL, "");
	int userInput;
	do {
		std::cout << "Добро пожаловать в обучалку!" << std::endl;
		std::cout << "1 - Хочу учиться программированию!" << std::endl;
		std::cout << "0 - Не сайчас..." << std::endl;
		std::cout << "Обучалка > ";

		std::cin >> userInput;
		if (userInput == 1){
			//TODO
		} else if (userInput == 0){
			exit(0);
		}
		std::cout << std::endl;
	} while (true);
	return 0;
}
