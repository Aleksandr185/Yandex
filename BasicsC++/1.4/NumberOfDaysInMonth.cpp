#include <iostream>

/*
Количество дней в месяце

Напишите программу, выводящую количество дней в месяце по заданному номеру месяца и году.

Формат ввода
  На вход программе подается два целых положительных числа: номер месяца (от 1 до 12) и
  четырёхзначный год.

Формат вывода
  Необходимо вывести одно число — количество дней в заданном месяце.

Пример 1
  Ввод: 1 2001
  Вывод: 31

Пример 2
  Ввод: 2 2001
  Вывод: 28

Примечание
  Рекомендуется сначала решить задачу «Високосный год» и использовать её решение для вывода
  количества дней в феврале.
*/

bool isLeapYear(int year)
{
  if (year%400 == 0)
    return true;
  else if (year%100 != 0 && year%4 == 0)
    return true;
  else
    return false;
}

// Number of days in a month
int numberDays(int month, int year)
{
  switch (month) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
  case 2:
    return isLeapYear(year) ? 29 : 28;
  case 4:
  case 6:
  case 9:
  case 11:
    return 30;

  default:
    return -1;
  }
}

int main()
{
  int month, year;
  std::cin >> month >> year;
  std::cout << numberDays(month, year);

  return 0;
}
