#include <iostream>

/*
Сумма цифр

  Вычислите сумму цифр неотрицательного целого числа.

Формат ввода
  На вход подаётся одно неотрицательное целое число, не превосходящее 109109.

Формат вывода
  Выведите сумму цифр этого числа.

Пример
  Ввод: 59
  Вывод: 14

*/

int SumOfDigits(int number)
{
  int sum = 0;
  int n = number;

  while (n >= 10) {
    sum += n%10;
    n /= 10;
  }

  sum += n;

  return sum;
}

int main()
{
  int n;
  std::cin >> n;
  std::cout << SumOfDigits(n);

  return 0;
}
