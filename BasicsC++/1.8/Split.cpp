
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

/*

Функция Split
  Вам требуется написать функцию со следующим заголовком:

  std::vector<std::string> Split(const std::string& str, char delimiter);
  Функция должна вернуть вектор строк, полученный разбиением строки str на части по указанному
  символу-разделителю delimiter. Если разделитель встретился в начале или в конце строки str, то в
  начале (соответственно, в конце) вектора с результатом должна быть пустая строка. Если два
  разделителя встретились рядом, то пустая строка между ними тоже должна попасть в ответ.
  Для пустой строки надо вернуть пустой вектор.

  Например, Split("What_is_your_name?", '_') должна вернуть вектор из строк What, is, your и name?.

Пример 1
  Ввод:
    What_is_your_name?
    _
  Вывод:
    What
    is
    your
    name?

Пример 2
  Ввод:
    13-24--08-11-2014
    -
  Вывод:
    13
    24

    08
    11
    2014

Примечание
  Подключите необходимые заголовочные файлы и напишите только код функции Split.
  Мы скомпилируем решение с нашей функцией main.

*/

std::vector<std::string> Split(const std::string& str, char delimiter)
{
  std::vector<std::string> result;

  // use index
  size_t start = 0;
  for (size_t i = 0; i < str.size(); ++i) {
    if (str[i] == delimiter) {
      result.push_back( str.substr(start, i - start) );
      start = i + 1;
    }
  }

  result.push_back( str.substr(start) );

  return result;
}

int main(/*int argc, char** argv*/)
{
  std::string str;
  char del;
  std::getline(std::cin, str);
  std::cin >> del;

  std::vector<std::string> result_of_split = Split(str, del);
  std::copy(result_of_split.cbegin(), result_of_split.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));

  return 0;
}
