
#include <string>
#include <vector>

/*

Функция Join
  Вам требуется написать функцию Join со следующим заголовком:

  std::string Join(const std::vector<std::string>& tokens, char delimiter);
  Функция должна вернуть строку, полученную склейкой элементов вектора через указанный разделитель.
  Например, Join({"What", "is", "your", "name?"}, '_') должна вернуть строку "What_is_your_name?".

Примечание
  Если вектор tokens пустой, то функция должна вернуть пустую строку. Если в векторе tokens ровно
  один элемент, то он и должен вернуться в ответе.

  Подключите необходимые заголовочные файлы и напишите только код функции Join.
  Мы скомпилируем решение с нашей функцией main.

*/

std::string Join(const std::vector<std::string>& tokens, char delimiter)
{
  std::string result;

  if ( !tokens.empty() ) {
    for (size_t i = 0; i < tokens.size() - 1; ++i) {
      result += tokens[i];
      result += delimiter;
    }

    result += tokens.back();
  }

  return result;
}

int main(/*int argc, char** argv*/)
{
  return 0;
}
