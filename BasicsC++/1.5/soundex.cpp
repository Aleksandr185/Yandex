
#include <iostream>
#include <string>
#include <cassert>

/*
Soundex

  Известный алгоритм Soundex определяет, похожи ли два английских слова по звучанию. На вход он
  принимает слово и заменяет его на некоторый четырёхсимвольный код. Если коды двух слов совпадают,
  то слова, как правило, звучат похоже.

Вам требуется реализовать этот алгоритм. Он работает так:

  Первая буква слова сохраняется.
  В остальной части слова буквы a, e, h, i, o, u, w и y удаляются;
  Оставшиеся буквы заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
  b, f, p, v: 1
  c, g, j, k, q, s, x, z: 2
  d, t: 3
  l: 4
  m, n: 5
  r: 6

  Любая последовательность идущих подряд одинаковых цифр сокращается до одной такой цифры.
  Итоговая строка обрезается до первых четырёх символов.
  Если длина строки получилась меньше четырёх символов, в конце добавляются нули.

Примеры:

  аmmonium → ammnm → a5555 → a5 → a500.

  implementation → implmnttn → i51455335 → i514535 → i514.

Формат ввода
  На вход подаётся одно непустое слово из строчных латинских букв. Длина слова не превосходит
  20 символов.

Формат вывода
  Напечатайте четырёхбуквенный код, соответствующий слову.

Пример 1
  Ввод: ammonium
  Вывод: a500

Пример 2
  Ввод: implementation
  Вывод: i514

*/

std::string soundex(const std::string& word)
{
  std::string result;
  result.push_back(word[0]);

  for (std::string::size_type i = 1; i < word.size(); ++i) {
    const char ch = word[i];
    const char last_ch = result[result.size() - 1];

    switch (ch) {
    case 'b': case 'f': case 'p': case 'v':
      if (last_ch != '1') {
        result.push_back('1');
      }
      break;
    case 'c': case 'g': case 'j': case 'k': case 'q': case 's': case 'x': case 'z':
      if (last_ch != '2') {
        result.push_back('2');
      }
      break;
    case 'd': case 't':
      if (last_ch != '3') {
        result.push_back('3');
      }
      break;
    case 'l':
      if (last_ch != '4') {
        result.push_back('4');
      }
      break;
    case 'm': case 'n':
      if (last_ch != '5') {
        result.push_back('5');
      }
      break;
    case 'r':
      if (last_ch != '6') {
        result.push_back('6');
      }
      break;
    default:
      break;
    }
  }

  if (result.size() < 4) {
    result.append(4 - result.size(), '0');
  }
  else if (result.size() > 4) {
    result.erase(4);
  }

  return result;
}

int main(/*int argc, char** argv*/)
{
/*
  {
    std::string r1 = soundex("ammonium");
    assert(r1 == "a500");
  }

  {
    std::string r1 = soundex("implementation");
    assert(r1 == "i514");
  }
*/

  std::string word;
  std::cin >> word;
  std::cout << soundex(word);
  return 0;
}
