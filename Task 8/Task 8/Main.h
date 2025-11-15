#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <variant>
#include <vector>
#include <string>

/**
 * @class Main
 * @brief Главный класс приложения для работы с векторами различных типов
 *
 * Класс предоставляет функционал для создания, заполнения и обработки векторов
 * различных типов данных с использованием std::variant.
 */
class Main {

public:
    /**
     * @brief Конструктор класса Main
     * @explicit Запрещает неявное преобразование типов
     */
    explicit Main();

    /**
     * @brief Деструктор класса Main
     * @default Использует стандартную реализацию
     */
    ~Main() = default;

    /**
     * @brief Основной метод программы
     *
     * Координирует выполнение всей программы: выбор типа вектора,
     * заполнение данными и обработку согласно алгоритму
     */
    void main();

private:
    /**
     * @brief Псевдоним типа для варианта векторов
     *
     * Объединяет векторы следующих типов:
     * - std::vector<int>
     * - std::vector<long>
     * - std::vector<double>
     * - std::vector<float>
     * - std::vector<char>
     * - std::vector<std::string>
     */
    using VectorVariant = std::variant<
        std::vector<int>,
        std::vector<long>,
        std::vector<double>,
        std::vector<float>,
        std::vector<char>,
        std::vector<std::string>>;

    /**
     * @brief Подсчитывает количество одинаковых соседей элемента.
     * @param vector Ссылка на вариант вектора для обработки
     *
     * Алгоритм: подсчитывает количество элементов вектора,
     * имеющих равные соседние элементы (предыдущий и следующий)
     *
     * @note Для работы требуется минимум 3 элемента в векторе
     */
    void processProgram(VectorVariant& vector);

    /**
     * @brief Предоставляет выбор типа вектора пользователю
     * @return VectorVariant Пустой вектор выбранного типа
     *
     * Отображает меню выбора типа данных и возвращает
     * соответствующий пустой вектор
     */
    Main::VectorVariant choiseVector();

    /**
     * @brief Заполняет вектор данными, введенными пользователем
     * @param vector Ссылка на вариант вектора для заполнения
     *
     * Запрашивает у пользователя количество элементов и их значения,
     * затем заполняет вектор введенными данными
     */
    void fillArray(VectorVariant& vector);

    /**
     * @brief Ввод и валидация целого положительного числа
     * @return int Валидное положительное целое число
     *
     * Обеспечивает защищенный ввод с обработкой ошибок:
     * - Проверка на корректный числовой формат
     * - Проверка на положительное значение
     * - Очистка буфера ввода при ошибках
     */
    int inputNumber();
};

/**
 * @brief Точка входа в программу
 * @return int Код возврата
 */
int main() {
    Main app;
    app.main();
    return 0;
}

#endif // MAIN_H