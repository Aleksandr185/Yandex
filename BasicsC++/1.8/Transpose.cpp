
#include <string>
#include <vector>

/*

Транспонировать матрицу
  Дана прямоугольная матрица 'A' из 'm' строк и 'n' столбцов. Транспонированной матрицей 'A^T'
  называется матрица из 'n' строк и 'm' столбцов, в которой строки и столбцы поменялись ролями:
  элемент A^T_{ij} равен элементу A_{ji}.

  Напишите функцию, которая возвращает транспонированную матрицу:

  std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix);

Примечание
  Гарантируется, что вектор matrix непуст и все его элементы имеют равную ненулевую длину.
  Подключите необходимые заголовочные файлы и напишите только код функции Transpose.
  Мы скомпилируем решение с нашей функцией main.

*/

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix)
{
  const size_t m = matrix.size();
  const size_t n = matrix.front().size();

  std::vector<std::vector<int>> result(n, std::vector<int>(m));

  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n; ++j) {
      result[j][i] = matrix[i][j];
    }
  }

  return result;
}

int main(/*int argc, char** argv*/)
{
  return 0;
}
