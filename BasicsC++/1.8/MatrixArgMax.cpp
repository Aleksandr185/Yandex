
#include <string>
#include <vector>
#include <iostream>

/*
 *
ArgMax в матрице
  Вам требуется написать на C++ функцию со следующим заголовком:

  std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix);
  Функция должна вернуть пару из индексов максимального элемента в матрице. Если максимальных
  элементов несколько, то нужно вернуть наименьшую такую пару.

Пример 1
  Ввод:
    3 4
    0 3 2 4
    2 3 5 5
    5 1 2 3
  Вывод:
    1 2

Пример 2
Ввод:
  1 1
  1
Вывод:
  0 0

Пример 3
  Ввод:
    3 5
    1 2 3 4 5
    6 7 8 9 10
    11 12 13 14 15
  Вывод:
    2 4

Примечание
  Считайте, что матрица задана корректно: все строки одинаковой длины, пустых строк нет.
  В матрице всегда есть хотя бы один элемент.

  Подключите необходимые заголовочные файлы и напишите только код функции MatrixArgMax.
  Мы скомпилируем решение с нашей функцией main.

*/

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix)
{
  std::pair<size_t, size_t> pos(0, 0);
  int max_value = matrix[0][0];
  for (size_t r = 0; r < matrix.size(); ++r) {
    for (size_t c = 0; c < matrix[r].size(); ++c) {
      if (max_value < matrix[r][c]){
        max_value = matrix[r][c];
        pos.first = c;
        pos.second = r;
      }
    } // for c
  } // for r

  return pos;
}

int main(/*int argc, char** argv*/)
{
  int row_count;
  int column_count;
  std::cin >> row_count >> column_count;

  std::vector< std::vector<int> > matrix(row_count, std::vector<int>(column_count, 0));

  for (int r = 0; r < row_count; ++r) {
    for (int c = 0; c < column_count; ++c) {
      int v;
      std::cin >> v;
      matrix[r][c] = v;
    }
  } // for r

  const std::pair<size_t, size_t> max_pos = MatrixArgMax(matrix);
  std::cout << max_pos.first << ' ' << max_pos.second << std::endl;

  return 0;
}
