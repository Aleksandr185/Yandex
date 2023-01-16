
#include <string>
#include <vector>
#include <iostream>

/*
Сапёр
  Вам необходимо построить поле для игры «Сапёр» по его конфигурации — высоте, ширине и
  координатам расставленных на нем мин.

  Вкратце напомним правила построения поля для игры «Сапёр»:
    - поле состоит из клеток с минами и пустых клеток;
    - клетки с миной обозначаются символом *;
    - пустые клетки содержат число от 0 до 8 — количество мин на соседних клетках.

Формат ввода
  В первой строке содержатся три числа:
    - число m от 1 до 100 — количество строк на поле;
    - число n от 1 до 100 — количество столбцов на поле;
    - число k от 0 до m x n — количество мин на поле.
  В следующих k строках содержатся пары чисел с координатами мин (номерами строки и столбца).
  Нумерация ведётся с единицы.

Формат вывода
  Выведите построенное поле, разделяя строки поля символом \n, а столбцы — пробелом.

Пример
  Ввод:
    3 2 2
    1 1
    2 2
  Вывод:
    * 2
    2 *
    1 1

*/

void printField(const std::vector< std::vector<int> >& field)
{
  for (auto r = field.cbegin(); r != field.cend(); ++r) {
    const std::vector<int>& row = *r;
    for (auto c = row.cbegin(); c != row.cend(); ++c) {
      if (*c >= 0)
        std::cout << *c;
      else
        std::cout << '*';

       std::cout << ' ';
    }
    std::cout << std::endl;
  } // for r
}

int main(/*int argc, char** argv*/)
{
  int row_count;
  int column_count;
  int bomb_count;
  std::cin >> row_count >> column_count >> bomb_count;

  std::vector< std::vector<int> > field(row_count, std::vector<int>(column_count, 0));

  for (int i = 0; i < bomb_count; ++i) {
    int y; // row
    int x; // column
    std::cin >> y >> x;
    --y;
    --x;

    for (int row_index = y - 1; row_index <= y + 1; ++row_index) {
      if (row_index < 0 || row_index >= static_cast<int>(field.size()) )
        continue;

      std::vector<int>& row = field[row_index];
      for (int column_index = x - 1; column_index <= x + 1; ++column_index) {
        if (column_index < 0 || column_index >= static_cast<int>(row.size()) )
          continue;

        if (row_index == y && column_index == x){
          row[column_index] = -1;  // set bomb
        }
        else if (row[column_index] >= 0) {
          row[column_index] += 1;  // increase the number of bombs in neighboring cells
        }
      }  // for column_index
    }  // for row_index
  }  // for i

  printField(field);

  return 0;
}
