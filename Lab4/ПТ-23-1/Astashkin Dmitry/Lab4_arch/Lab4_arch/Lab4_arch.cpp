#include <iostream>
#include <filesystem>
#include <Windows.h>
namespace fs = std::filesystem;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Путь к каталогу
    std::string path = "C:\\Users\\User\\Lab3\\ПТ-23-1\\Astashkin Dmitry\\Var 2";

    try {
        // Проверяем, существует ли каталог и является ли он каталогом
        if (fs::exists(path) && fs::is_directory(path)) {
            // Счетчик файлов
            int file_count = 0;

            // Проходимся по файлам и подкаталогам
            for (const auto& entry : fs::directory_iterator(path)) {
                // Проверяем, является ли текущий элемент файлом
                if (fs::is_regular_file(entry.path())) {
                    file_count++;
                }
            }

            std::cout << "Количество файлов в каталоге: " << file_count << std::endl;
        }
        else {
            std::cerr << "Каталог не существует или не является каталогом!" << std::endl;
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Ошибка файловой системы: " << e.what() << std::endl;
    }

    return 0;
}
