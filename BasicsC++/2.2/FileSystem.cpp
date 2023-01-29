#include <iostream>
#include <string>
#include <set>

/*
  Файловая система

  Дан список всех файлов в некоторой файловой системе. Необходимо вывести все непустые директории
  этой файловой системы в лексикографическом порядке.
  Гарантируется, что все пути начинаются от корня файловой системы. Все пути состоят из слешей (/),
  латинских символов, цифр и точек. Два слеша никогда не стоят подряд.

  Формат ввода:
    На вход подаются строки, описывающие пути ко всем файлам в системе. Каждый путь содержится в
    отдельной строке. Число строк не превосходит 10000.

  Формат вывода:
    Выведите все непустые директории в этой файловой системе в лексикографическом порядке. Каждый
    путь должен начинаться со слеша и заканчиваться слешом.

  Пример 1
    Ввод:
      /docs/README.txt
      /docs/LICENSE.txt
      /boot/grub
      /init
    Вывод:
      /
      /boot/
      /docs/

  Пример 2
    Ввод:
      /home/guest/homework/A/main.cpp
      /root/test.cpp
      /root/tests/01
      /root/tests/01.a
      /bin/bash
      /usr/bin/perl
    Вывод:
      /
      /bin/
      /home/
      /home/guest/
      /home/guest/homework/
      /home/guest/homework/A/
      /root/
      /root/tests/
      /usr/
      /usr/bin/

*/


int main()
{
    std::set<std::string> result;

    std::string path;

    while (std::cin >> path) {
        size_t slash_pos = path.find('/');
        while (slash_pos < path.size() - 1) {
            ++slash_pos;
            result.insert(path.substr(0, slash_pos));
            slash_pos = path.find('/', slash_pos);
        }
    }

    for (const auto& path : result) {
        std::cout << path << std::endl;
    }

    return 0;
}
