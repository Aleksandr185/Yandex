
#include <string>
#include <iostream>


/*

  A. Камни и украшения
  
		Ограничение времени	1 секунда
		Ограничение памяти	64Mb
		Ввод	стандартный ввод или input.txt
		Вывод	стандартный вывод или output.txt
		
	Даны две строки строчных латинских символов: строка J и строка S. Символы, входящие в строку J, — «драгоценности», 
	входящие в строку S — «камни». Нужно определить, какое количество символов из S одновременно являются 
	«драгоценностями». Проще говоря, нужно проверить, какое количество символов из S входит в J.

	Формат ввода:
		На двух первых строках входного файла содержатся две строки строчных латинских символов: строка J и строка S. 
		Длина каждой не превосходит 100 символов.
	
	Формат вывода:
		Выходной файл должен содержать единственное число — количество камней, являющихся драгоценностями.
*/


int main(/*int argc, char** argv*/)
{
  using namespace std;

  string J, S;

  cin >> J >> S;

  vector<int> alphabet('z' - 'a' + 1);

  for (char ch : J) {
    alphabet[ch - 'a'] = 1;
  }

  int count = 0;
  for (char ch : S) {
    if (alphabet[ch - 'a'] != 0)
      ++count;
  }

  cout << count << endl;

  return 0;
}
