#include "Main.h"

// Конструктор класса Main.
Main::Main() {}

// Основной метод программы.
void Main::main() {
    auto vector = choiseVector();
    fillArray(vector);
    processProgram(vector);
}

// Подсчитывает количество одинаковых соседей элемента.
void Main::processProgram(VectorVariant& vector) {
    std::visit([](auto&& arg) {
        int counter = 0;

        if (arg.size() < 3) {
            std::cout << "Not enough elements in vector (need at least 3)" << std::endl;
            return;
        }

        for (size_t i = 1; i < arg.size() - 1; i++) {
            if (arg[i - 1] == arg[i + 1]) {
                std::cout << "The elements with indexes " << (i - 1) << " (" << arg[i - 1]
                    << ") and " << (i + 1) << " (" << arg[i + 1]
                    << ") are the same" << std::endl;
                counter++;
            }
        }

        std::cout << "Identical neighbors: " << counter << std::endl;
        }, vector);
}

// Предоставляет выбор типа вектора пользователю.
Main::VectorVariant Main::choiseVector() {
	std::cout << "Select the type of vector:" << std::endl;
	std::cout << "1. int" << std::endl;
	std::cout << "2. long" << std::endl;
	std::cout << "3. double" << std::endl;
	std::cout << "4. float" << std::endl;
	std::cout << "5. char" << std::endl;
	std::cout << "6. std::string" << std::endl;
	std::cout << "Enter choice: ";

    int choise = inputNumber();
    switch (choise) {
    case 1: return std::vector<int>();
    case 2: return std::vector<long>();
    case 3: return std::vector<double>();
    case 4: return std::vector<float>();
    case 5: return std::vector<char>();
    case 6: return std::vector<std::string>();
    default:
        std::cout << "Not the right choice. By default, the string type is selected";
        return std::vector<std::string>();
    }
}

// Заполняет вектор данными, введенными пользователем.
void Main::fillArray(VectorVariant& vector) {
    std::cout << "Enter the number of elements: ";

    int len = inputNumber();
    std::visit([len](auto&& arg) {
        using T = typename std::decay_t<decltype(arg)>::value_type;

        std::cout << "Enter " << len << " values:" << std::endl;

        for (int i = 0; i < len; i++) {
            T value;
            std::cout << "Value " << (i + 1) << ": ";

            if constexpr (std::is_same_v<T, std::string>) {
                if (i == 0) {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::getline(std::cin, value);
            }
            else if constexpr (std::is_same_v<T, char>) {
                std::cin >> value;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                std::cin >> value;
            }

            arg.push_back(value);
        }
        }, vector);
}

// Ввод и валидация целого положительного числа.
int Main::inputNumber() {
    int number;
    while (true) {
        std::cin >> number;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "ERROR: INCORRECT DATA ENTERED" << std::endl;
            std::cout << "Please try again" << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (number <= 0) {
            std::cout << "ERROR: YOU NEED TO ENTER AN POSITIVE" << std::endl;
            std::cout << "Please try again" << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return number;
    }
}