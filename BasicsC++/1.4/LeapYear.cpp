#include <iostream>

bool isLeapYear(int year)
{
  if (year%400 == 0)
    return true;
  else if (year%100 != 0 && year%4 == 0)
    return true;
  else
    return false;
}

int main()
{
  int year;
  std::cin >> year;

  const bool result = isLeapYear(year);
  std::cout << (result ? "YES" : "NO");

  return 0;
}
