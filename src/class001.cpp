#include <cstr.hpp>
#include <iostream>

/**
 * Определить класс-строку:
 * - в класс включить два конструктора:
 * -- для определения класса строки строкой символов;
 * -- копирования другой строки (объекта класса строки);
 * - предусмотреть функции поиска слова в строке;
 * - добавление другой строки, начиная с позиции N
 */

int main() {
  std::cout << "homework-001" << std::endl;

  cstr *str001 = new cstr();

  std::string str;

  std::cin >> str;

  str001->setValue(str);

  std::cout << str001->getValue() << std::endl;

  cstr *str002 = new cstr("cstr002");

  std::cout << str002->getValue() << std::endl;

  return EXIT_SUCCESS;
}