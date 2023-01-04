#include <iostream>

/*
Прямоугольный треугольник

  Напишите программу, которая проверяет является ли треугольник прямоугольным.

Формат ввода
  На стандартный поток ввода подаётся три целых положительных числа — стороны треугольника.
  Числа не превосходят 30000.

Формат вывода
  Если полученный треугольник является прямоугольным, напечатайте YES. Если треугольник не является
  прямоугольным, напечатайте NO. Если с заданными сторонами невозможно построить треугольник,
  напечатайте UNDEFINED.
*/

int main()
{
  int a, b , c;
  std::cin >> a >> b >> c;

  const bool is_triangle = (a < b + c) && (b < a + c) && (c < b + a);
  if (is_triangle) {
    const int sqr_a = a * a;
    const int sqr_b = b * b;
    const int sqr_c = c * c;
    const int hypotenuse = std::max(sqr_c, std::max(sqr_a, sqr_b) );

    if ( hypotenuse == sqr_a && (sqr_a == sqr_b + sqr_c) )
      std::cout << "YES";
    else if ( hypotenuse == sqr_b && (sqr_b == sqr_a + sqr_c) )
      std::cout << "YES";
    else if ( sqr_c == sqr_a + sqr_b )
      std::cout << "YES";
    else
      std::cout << "NO";
  }
  else
    std::cout << "UNDEFINED";

  return 0;
}
