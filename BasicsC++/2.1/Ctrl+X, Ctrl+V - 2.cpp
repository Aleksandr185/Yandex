#include <list>
#include <string>
#include <iostream>

/*
  Ctrl+X, Ctrl+V - 2

  Эта задача — продолжение предыдущей задачи Ctrl+X, Ctrl+V. В качестве основы вы можете взять
  код оттуда.

  Петя продолжает разработку своего текстового редактора. На этот раз добавилось еще одна операция:
  - зажать клавишу Shift (Shift). Операции Up и Down при зажатой клавише Shift выделяют строки в
   текстовом редакторе. Если курсор находится на строке 'n', то после операций Shift, Down, Down
  выделенными окажутся строки 'n' и 'n' + 1.
  Операция Ctrl+X вырезает выделенные строки из файла в буфер. Операция Ctrl+V копирует строки из
  буфера, заменяя выделенные строки в файле.
  Операции Ctrl+X и Ctrl+V сбрасывают выделение после исполнения и отпускают клавишу Shift. Если при
  исполнении этих операций в файле не выделена ни одна строка, поведение должно соответствовать
  предыдущей задаче Ctrl+X, Ctrl+V.

  Формат ввода:
    Программе на вход подаётся набор строк, разделённых переносом строки. Длина каждой строки не
    превышает 3000 символов. Последняя строка в файле является пустой. Она означает завершение ввода
    файла. Других пустых строк в файле быть не может.
    После этого и до окончания ввода программе подаются команды Down, Up, Ctrl+X, Ctrl-V, Shift.

  Формат вывода:
    Выведите получившийся файл построчно.

  Пример 1
    Ввод:
      My
      program
      is
      awful
      bad
      poor
      wrong
      awesome

      Down
      Down
      Down
      Shift
      Down
      Down
      Down
      Down
      Ctrl+X

    Вывод:
      My
      program
      is
      awesome

  Пример 2
    Ввод:
      a
      b
      c
      d
      e
      f
      g

      Down
      Shift
      Down
      Down
      Ctrl+X
      Down
      Shift
      Down
      Down
      Down
      Ctrl+V

    Вывод:
      a
      d
      b
      c

  Пример 3
    Ввод:
      program
      is awesome
      My
      is awful

      Down
      Down
      Down
      Ctrl+X
      Up
      Ctrl+X
      Up
      Up
      Ctrl+V

    Вывод:
      My
      program
      is awesome

  Примечание
  Для вырезания строк из файла в буфер удобно использовать функцию splice. Разберитесь самостоятельно
  по документации, как она устроена.
*/

int main(/*int argc, char** argv*/)
{
  using namespace std;

  list<string> file;
  list<string> buffer;

  // input file
  string line;
  while ( getline(cin, line) && !line.empty() ) {
    file.push_back(line);
  }

  auto cursor = file.begin();
  auto shift_cursor = file.end();
  bool shift = false;
  list<string>::difference_type shift_offcet = 0;

  // input commands
  while ( getline(cin, line) ) {
    if (line == "Down"s) {
      if (cursor != file.end()) {
        ++cursor;
        if (shift)
          ++shift_offcet;
      }
    }
    else if (line == "Up"s) {
      if (cursor != file.begin()) {
        --cursor;
        if (shift)
          --shift_offcet;
      }
    }
    else if (line == "Ctrl+X"s) {
      if (cursor != file.end()) {
        buffer.clear();
        if ( shift && (shift_offcet != 0) ) {
          auto start = (shift_offcet < 0) ? cursor : shift_cursor;
          auto end = (shift_offcet < 0) ? shift_cursor : cursor;
          buffer.splice(buffer.cbegin(), std::move(file), start, end);
          cursor = end;
        }
        else {
          auto next_pos = std::next(cursor);
          buffer.splice(buffer.cbegin(), std::move(file), cursor);
          cursor = next_pos;
        }
      }

      shift = false;
    }
    else if (line == "Ctrl+V") {
      if ( !buffer.empty() ) {
        if (shift && shift_offcet != 0) {
          auto start = (shift_offcet < 0) ? cursor : shift_cursor;
          auto end = (shift_offcet < 0) ? shift_cursor : cursor;
          cursor = file.erase(start, end);
        }
        file.insert(cursor, buffer.begin(), buffer.end());
      }

      shift = false;
    }
    else if (line == "Shift"s) {
      shift_cursor = cursor;
      shift = true;
      shift_offcet = 0;
    }
  }  // while

  // output
  for (const string& s : file) {
    cout << s << endl;
  }

  return 0;
}

