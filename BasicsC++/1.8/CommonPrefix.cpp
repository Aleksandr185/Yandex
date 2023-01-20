
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

/*

Общий префикс

  Напишите функцию для вычисления наибольшего общего префикса строк, переданных в векторе words:

  std::string CommonPrefix(const std::vector<std::string>& words);
  Например, для пустого вектора функция должна вернуть пустую строку, а для вектора из строк
  "apple", "apricot" и "application" — строку "ap".

Примечание
  В решении не должно быть функции main: она будет в нашей тестирующей программе.
  Подключите необходимые библиотеки и напишите код функции CommonPrefix.

*/

size_t posNotEqualChar(const std::string& str1, const std::string& str2)
{
  const size_t min_size = std::min(str1.size(), str2.size());
  for (size_t i = 0; i < min_size; ++i) {
    if (str1[i] != str2[i])
      return i;
  }

  return min_size;
}


std::string CommonPrefix(const std::vector<std::string>& words)
{
  using namespace std;

  string result;

  size_t pos = words.size() > 1 ? posNotEqualChar(words[0], words[1]) : string::npos;
  for (size_t i = 2; i < words.size(); ++i) {
    pos = min(pos, posNotEqualChar(words[i - 1], words[i]));
  }

  if (!words.empty())
    result = words.back().substr(0, pos);

  return result;
}

int main(/*int argc, char** argv*/)
{
  using namespace std;

  vector<string> words = {"apple"s, "apricot"s, "application"s};
  cout << CommonPrefix(words) << endl;

  return 0;
}
