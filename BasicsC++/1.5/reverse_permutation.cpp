
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <cassert>

/*
Обратная перестановка

  На мероприятие приглашены nn гостей. Им предлагают занять места с номерами от 1 до nn в зале.
  Гости занимают эти места в произвольном порядке. Известно, на каком месте сел очередной гость.
  Выпишите для каждого очередного места номер гостя, который на него сел.

Формат ввода

  Дано число n, а затем n различных чисел a1, a2, ..., an от 1 до n. Число ak — это номер места, на
  которое сел k-й гость.
  Число n не превосходит 20000.

Формат вывода
  Выведите n чисел b1, b2, ..., bn от 1 до n. Число bk должно обозначать номер гостя, который сел
  на k-е место.

Пример 1
  Ввод:
      5
      1 2 3 5 4
  Вывод:
      1 2 3 5 4

Пример 2
  Ввод
      11
      11 6 8 2 10 9 4 7 3 1 5
  Вывод
      10 4 9 7 11 2 8 3 6 5 1

Примечание
  Если говорить математическим языком, то вам дана перестановка и для неё требуется вычислить
  обратную перестановку.

*/

std::vector<int> reversePermutation(const std::vector<int>& v)
{
  std::vector<int> result(v.size());

  for(size_t i = 0; i < v.size(); ++i) {
    result[v[i] - 1] = i + 1;
  }

  return result;
}

int main(/*int argc, char** argv*/)
{
/*
  {
    std::vector<int> v = {1, 2, 3, 5, 4};
    std::vector<int> result = reversePermutation(v);
    std::vector<int> answer = {1, 2, 3, 5, 4};
    assert(result == answer);
  }

  {
    std::vector<int> v = {11, 6, 8, 2, 10, 9, 4, 7, 3, 1, 5};
    std::vector<int> result = reversePermutation(v);
    std::vector<int> answer = {10, 4, 9, 7, 11, 2, 8, 3, 6, 5, 1};
    assert(result == answer);
  }
*/

  int n;
  std::cin >> n;
  std::vector<int> v(n);
  std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), v.begin());
  std::vector<int> result = reversePermutation(v);
  std::copy(result.cbegin(), result.cend(), std::ostream_iterator<int>(std::cout, " "));

  return 0;
}
