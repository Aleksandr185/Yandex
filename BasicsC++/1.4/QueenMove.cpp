#include <iostream>

/*
Ход ферзя

  Шахматный ферзь ходит по диагонали, горизонтали или вертикали. Даны две различные клетки на
  шахматной доске без фигур. Определите, может ли ферзь попасть с первой клетки на вторую одним ходом.

Формат ввода

  Программа получает на вход четыре целых числа от 1 до 8. Первая пара чисел задаёт номер столбца и
номер строки для первой клетки. Вторая пара чисел аналогично задаёт вторую клетку.

Формат вывода

  Программа должна вывести YES, если из первой клетки ходом ферзя можно попасть во вторую, или NO в
  противном случае.
*/

int main()
{

  int c1, r1, c2, r2;
  std::cin >> c1 >> r1 >> c2 >> r2;

  bool result = (c1 == c2 || r1 == r2) || (c1 + r1 == c2 + r2) || (c1 - r1 == c2 - r2);
  std::cout << (result ? "YES" : "NO");

  return 0;
}
