
#include <string>
#include <vector>
#include <iostream>


/*

	E. Анаграммы

		Ограничение времени	1 секунда
		Ограничение памяти	20Mb
		Ввод	стандартный ввод или input.txt
		Вывод	стандартный вывод или output.txt


	Даны две строки, состоящие из строчных латинских букв. Требуется определить, являются ли эти строки 
	анаграммами, т. е. отличаются ли они только порядком следования символов.

	Формат ввода:
		Входной файл содержит две строки строчных латинских символов, каждая не длиннее 100 000 символов. 
		Строки разделяются символом перевода строки.

	Формат вывода:
		Выходной файл должен содержать единицу, если строки являются анаграммами, и ноль в противном случае.

*/

bool isAnagramma(const std::string& str1, const std::string& str2)
{
  using namespace std;

  if (str1.size() != str2.size()) {
    return false;
  }
  else {
    vector<int> alphabet('z' - 'a' + 1);
    for (size_t i = 0; i < str1.size(); ++i) {
      alphabet[str1[i] - 'a'] += 1;
      alphabet[str2[i] - 'a'] -= 1;
    }

    for (int i = 0; i < alphabet.size(); ++i) {
      if (alphabet[i] != 0)
        return false;
    }
  }

  return true;
}

int main(/*int argc, char** argv*/)
{
  using namespace std;

  string str1, str2;
  cin >> str1 >> str2;

  cout << (isAnagramma(str1, str2) ? 1 : 0) << endl;

  return 0;
}