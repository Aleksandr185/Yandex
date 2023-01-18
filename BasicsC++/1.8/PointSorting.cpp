
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

/*

Сортировка точек
  Вам даны координаты точек на плоскости. Выведите эти точки в порядке возрастания расстояний
  до начала координат.

Формат ввода
  Сначала задано количество точек 'n'. Затем идет последовательность из 'n' строк, каждая из которых
  содержит два целых числа — координаты точки. Величина 'n' не превосходит 100. Координаты точек по
  модулю также не превосходят 100.

Формат вывода
  Выведите через пробел кординаты точек в порядке возрастания расстояний до начала координат.
  После каждой пары координат печатайте перевод строки.

Пример
  Ввод
    2
    2 3
    1 2
  Вывод
    1 2
    2 3

*/

struct Point
{
  inline Point()
  {}
  inline Point(int _x, int _y)
    : x(_x), y(_y)
  {}

  int x = 0;
  int y = 0;

  inline int length() const
  {
    return /*std::sqrt(*/ std::pow(std::abs(x), 2) + std::pow(std::abs(y), 2) /*)*/;
  }
};

inline bool operator < (const Point& lhs, const Point& rhs) {
    return lhs.length() < rhs.length();
}

int main(/*int argc, char** argv*/)
{
  int n;
  std::cin >> n;
  std::vector<Point> points(n);

  for (int i = 0; i < n; ++i) {
    int x;
    int y;
    std::cin >> x >> y;
    points[i].x = x;
    points[i].y = y;
  }

  std::sort(points.begin(), points.end());

  for (int i = 0; i < n; ++i) {
    std::cout << points[i].x << ' ' << points[i].y << std::endl;
  }

  return 0;
}
