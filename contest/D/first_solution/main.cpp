
#include <string>
#include <iostream>
#include <list>

/*

	D. Генерация скобочных последовательностей

		Ограничение времени	1 секунда
		Ограничение памяти	20Mb
		Ввод	стандартный ввод или input.txt
		Вывод	стандартный вывод или output.txt

	Дано целое число n. Требуется вывести все правильные скобочные последовательности длины 2 ⋅ n, 
	упорядоченные лексикографически (см. https://ru.wikipedia.org/wiki/Лексикографический_порядок).
	В задаче используются только круглые скобки.
	Желательно получить решение, которое работает за время, пропорциональное общему количеству 
	правильных скобочных последовательностей в ответе, и при этом использует объём памяти, пропорциональный n.

	Формат ввода:
		Единственная строка входного файла содержит целое число n, 0 ≤ n ≤ 11

	Формат вывода:
		Выходной файл содержит сгенерированные правильные скобочные последовательности, упорядоченные лексикографически.

*/


std::list<std::string> GenerateBracketSequences(int N, const std::string& current = std::string(),
                                                  int open_bracket_count = 0, int closed_bracket_count = 0)
{
  using namespace std;

  list<string> result;

  // special case
  if (N == 0)
    return result;

  if (current.empty()) {
    result.splice(result.end(), GenerateBracketSequences(N, "("s, open_bracket_count + 1, closed_bracket_count) );
    return result;
  }

  // breack recursion
  if (current.size() == N * 2) {
    result.push_back(current);
    return result;
  }

  const bool can_add_opened_bracket = open_bracket_count < N;
  if (can_add_opened_bracket) {
    result.splice(result.end(), GenerateBracketSequences(N, current + '(', open_bracket_count + 1, closed_bracket_count) );
  }

  if (closed_bracket_count < open_bracket_count)
    result.splice(result.end(), GenerateBracketSequences(N, current + ')', open_bracket_count, closed_bracket_count + 1) );

  return result;
}

int main(/*int argc, char** argv*/)
{
  using namespace std;

  // 0 ≤ n ≤ 11
  uint32_t N = 0;
  cin >> N;

  list<string> result = GenerateBracketSequences(N);

  for (const string& str: result) {
    cout << str << endl;
  }

  return 0;
}
