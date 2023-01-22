
#include <string>
#include <forward_list>
#include <iostream>

/*

Шаблонный Print

  Вам надо написать функцию Print, которая умеет печатать в поток std::cout элементы переданного
  контейнера через указанную строку-разделитель. Первый аргумент функции — контейнер.
  Гарантируется, что по этому контейнеру можно проитерироваться с помощью стандартного цикла
  range-based for, и что элементы контейнера можно напечатать в поток std::cout с помощью
  стандартного оператора <<. Второй аргумент функции — строка-разделитель, которую надо печатать
  между элементами. В конце необходимо напечатать перевод строки \n.

Пример вызова:
    int main() {
        std::vector<int> data = {1, 2, 3};
        Print(data, ", ");  // 1, 2, 3
    }

Примечание
  В вашем решении должен быть только код функции Print без функции main. Подключите все необходимые
  для реализации библиотеки. Используйте константные ссылки для получения параметров и при итерации
  в цикле, чтобы избежать лишних копирований: если этого не сделать, то программа не скомпилируется.

*/

template <class T, class D>
void Print(const T& container, const D& delimiter)
{
  bool first = true;
  for(auto it = container.cbegin(); it != container.cend(); ++it) {
    if (!first)
      std::cout << delimiter;

    std::cout << *it;
    first = false;
  }

  std::cout << std::endl;
}

int main(/*int argc, char** argv*/)
{
  using namespace std;

  std::forward_list<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  list.push_front(5);

  Print(list, "-"s);

  return 0;
}
