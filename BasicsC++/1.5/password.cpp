
#include <iostream>
#include <string>
#include <cctype>

/*
Пароли

  Пароль от некоторого сервиса должен удовлетворять таким ограничениям:
    - состоять из символов таблицы ASCII с кодами от 33 до 126;
    - быть не короче 8 символов и не длиннее 14;
    - из 4 классов символов — большие буквы, маленькие буквы, цифры, прочие символы — в пароле
      должны присутствовать не менее трёх любых.

Напишите программу, которая проверит, что введённый пароль подходит под эти ограничения.

Формат ввода
  На входе дана одна строка с паролем.

Формат вывода
  Выведите YES, если пароль удовлетворяет требованиям, и NO в противном случае.

Пример
  Ввод: Vasya123
  Вывод: YES

Примечание
  Вы можете воспользоваться функциями из заголовочного файла cctype или реализовать
  самостоятельно их аналоги.

*/

bool checkPass(const std::string& password)
{
  // 1. lenght
  if ( (password.size() < 8) || (password.size() > 14) )
    return false;

  bool has_upper = false;
  bool has_lower = false;
  bool has_digits = false;
  bool has_other = false;

  std::locale c_locale("C");

  for (auto it = password.cbegin(); it != password.cend(); ++it) {
    const char ch = *it;
    if ((ch < 33) || (ch > 126) ) {
      return false;
    }

    if ( std::isupper(ch, c_locale) ) {
      has_upper = true;
    }
    else if ( std::islower(ch, c_locale) ) {
      has_lower = true;
    }
    else if ( std::isdigit(ch, c_locale) ) {
      has_digits = true;
    }
    else {
      has_other = true;
    }
  }  // for

  int group_count = 0;
  if (has_upper)
    ++group_count;
  if (has_lower)
    ++group_count;
  if (has_digits)
    ++group_count;
  if (has_other)
    ++group_count;

  return group_count >= 3;
}

int main(int argc, char** argv)
{
  std::string password;
  std::cin >> password;

  std::cout << (checkPass(password) ? "YES" : "NO") << std::endl;

  return 0;
}
