#include <deque>
#include <string>
#include <iostream>
#include <iterator>

/*
  Вагоны
    Вы — машинист. Вам поручено реализовать функцию void MakeTrain(), чтобы сформировать поезд
    из набора вагонов.
    У каждого вагона есть номер (помещается в int). Номера вагонов внутри состава могут повторяться.
    Изначально путь, на котором формируется состав, пустой. Вы должны уметь выполнять следующие
    команды, которые поступают в отдельных строках на входе:
      +left W — добавить вагон с номером 'W' слева
      +right W — добавить вагон с номером 'W' справа
      -left N — отцепить и убрать 'N' вагонов слева
      -right N — отцепить и убрать 'N' вагонов справа

    В последних двух командах 'N' может быть больше текущей длины состава — в этом случае надо убрать
    весь состав целиком. Отцеплять вагоны по одному может быть долго: постарайтесь сразу отцеплять
    по 'N' штук. Напечатайте через пробел номера вагонов получившегося состава, если смотреть на них
    слева направо. В самом конце напечатайте перевод строки.
    На вход подаются строки с командами в указанном формате. Всего будет не более 1 млн команд.
    Оформите ваше решение в функции void MakeTrain(). Эта функция должна читать данные со
    стандартного потока ввода и печатать их в стандартный поток вывода. Подключите все необходимые
    библиотеки. В вашем решении не должно быть функции main.

  Пример
    Ввод:
      +left 1
      +right 2
      +left 3
      -right 1

    Вывод:
      3 1
*/

void MakeTrain()
{
  using namespace std;

  deque<int> train;

  string line;
  while(cin >> line) {
    size_t n = 0;
    cin >> n;

    if (line.empty())
      continue;

    const bool is_minus = line.front() == '-';
    string_view command(line.data() + 1);
    const bool is_left = (command == "left"s);
    const bool is_right = !is_left && (command == "right"s);

    if ( !is_left && !is_right )
      continue;

    if (is_minus && !train.empty()) {
      if ( n > train.size()) {
        train.clear();
      }
      else {
        auto start = is_left ? train.begin()       : std::prev(train.end(), n);
        auto end   = is_left ? std::next(start, n) : train.end();
        train.erase(start, end);
      }
    }
    else {
      if (is_left)
        train.push_front(n);
      else
        train.push_back(n);
    }
  } // while

  copy(train.cbegin(), train.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main(/*int argc, char** argv*/)
{
  using namespace std;

  MakeTrain();



  return 0;
}

