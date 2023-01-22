
#include <string>
#include <iostream>
#include <vector>

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

class BracketSequencesGenerator
{
public:
  const std::vector<std::string>& generate(int N);

private:
  std::vector<std::string> m_result;
  int m_n;

  void generateImp(const std::string& current, int open_bracket_count, int closed_bracket_count);
};

const std::vector<std::string> &BracketSequencesGenerator::generate(int N)
{
  m_result.clear();
  m_n = N;

  if (m_n > 0)
    generateImp("(", 1, 0);

  return m_result;
}

void BracketSequencesGenerator::generateImp(const std::string& current, int open_bracket_count, int closed_bracket_count)
{
  // breack recursion
  if (current.size() == m_n * 2) {
    m_result.push_back(current);
    return;
  }

  if (open_bracket_count < m_n) {
    generateImp(current + '(', open_bracket_count + 1, closed_bracket_count);
  }

  if (closed_bracket_count < open_bracket_count) {
    generateImp(current + ')', open_bracket_count, closed_bracket_count + 1);
  }

}


int main(/*int argc, char** argv*/)
{
  using namespace std;

  // 0 ≤ n ≤ 11
  uint32_t N = 0;
  cin >> N;

  BracketSequencesGenerator sequences_generator;
  const vector<string>& result = sequences_generator.generate(N);
  for (const string& str: result) {
    cout << str << endl;
  }

  return 0;
}
