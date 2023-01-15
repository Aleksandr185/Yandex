
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

/*
Сортировка по убыванию

  Вам даны строки текстового файла. Отсортируйте набор этих строк по убыванию.

Формат ввода
  Количество строк не превосходит 1000. Каждая строка состоит из символов ASCII с кодами от 32
  до 126, длина строки не превосходит 100.

Формат вывода
  Напечатайте строки в отсортированном по убыванию порядке. Для сравнения строк друг с другом
  достаточно использовать стандартные операторы сравнения, определённые для std::string.

Пример
  Ввод:
    one
    two
    three
  Вывод:
    two
    three
    one

Примечание
  Компилятор не поддерживает std::ranges.

*/

int main(/*int argc, char** argv*/)
{
  std::string line;
  std::vector<std::string> lines;

  while (std::getline(std::cin, line)) {
    lines.push_back(line);
  }

  std::sort(lines.begin(), lines.end(), std::greater<std::string>());
  std::copy(lines.cbegin(), lines.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));

  return 0;
}
