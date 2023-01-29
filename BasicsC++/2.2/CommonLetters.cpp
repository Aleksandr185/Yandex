#include <iostream>
#include <array>
#include <unordered_set>

/*
Общие буквы

  Вам даны слова. Выведите в алфавитном порядке список общих букв всех слов.

  Формат ввода:
    На вход поступают слова (по одному в строке), состоящие из маленьких латинских букв алфавита.
    Длина слов не превосходит 100 символов, а количество слов не превосходит 1000.

  Формат вывода:
    Выведите в алфавитном порядке без пробелов список букв, которые присутствуют в каждом слове.

  Пример 1
    Ввод:
      apple
      peach
    Вывод:
      aep

  Пример 2
    Ввод:
      alpha
      beta
      gamma
    Вывод:
      a

  Пример 3
    Ввод:
      alpha
      beta
      gamma
      delta
      epsilon
    Вывод:

*/

int main()
{
    const size_t alphabet_size = 'z' - 'a' + 1;

    std::array<size_t, alphabet_size> alphabet{};
    size_t word_count = 0;
    std::unordered_set<char> current_word_letters;
    std::string word;

    while (std::cin >> word) {
        ++word_count;

        current_word_letters.reserve(alphabet_size);

        for (char ch : word) {
            auto [it, is_inserted] = current_word_letters.insert(ch);
            if (is_inserted)
                ++alphabet[ch - 'a'];
        }

        current_word_letters.clear();
    }


    if (word_count > 0) {
        for (size_t i = 0; i < alphabet.size() - 1; ++i)
        {
            if (alphabet[i] == word_count)
                std::cout << static_cast<char>(i + 'a');
        }
    }

    return 0;
}
