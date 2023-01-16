#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

/*
Палиндромы

  Дана строка из строчных латинских букв и пробелов. Проверьте, является ли она палиндромом
  без учета пробелов.

Формат ввода
  На вход подается одна строка. В строке могут быть пробелы. Подряд может идти произвольное число
  пробелов. Длина строки не превосходит 100.

Формат вывода
  Представьте, что из строки удалили все пробелы. Необходимо вывести YES, если полученная
  строка — палиндром, и NO в противном случае.

Пример 1
  Ввод: hello world
  Вывод: NO

Пример 2
  Ввод: never odd or even
  Вывод: YES

Примечание
  Пустая строка считается палиндромом.

*/


int main()
{
  std::string line;
  std::getline(std::cin, line);

  auto it = std::remove(line.begin(), line.end(), ' ');
  line.erase(it, line.end());


  bool is_palindrome = false;
  if (line.empty() || line.size() == 1) {
    is_palindrome = true;
  }
  else {
    is_palindrome = true;
    for (size_t i = 0, y = line.size() - 1; i < y; ++i, --y) {
      if (line[i] != line[y]) {
        is_palindrome = false;
        break;
      }
    }
  }

  std::cout << (is_palindrome ? "YES" : "NO") << std::endl;

  return 0;
}
