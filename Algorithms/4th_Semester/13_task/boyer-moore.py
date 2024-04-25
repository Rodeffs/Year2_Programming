# В этом алгоритме есть две эвристики: плохой символ и хороший суффикс.
# Здесь представлена первая эвристика
# Суть в том, что сравниваем искомую строку и текст с конца. Как только
# нашли несовпадение - сдвигаем искомую строку к символу, где было несовпадение
# при этом нужно чтобы теперь несовпавший символ совпал с последним входом
# этого символа в исходной строке. Если такого символа в исходной строке нет,
# то всю строку перемещаем за этот символ

def bad_character(pattern):
    bad_character_array = [-1 for i in range(256)]  # используем ASCII

    for i in range(len(pattern)):
        bad_character_array[ord(pattern[i])] = i

    return bad_character_array


def bm_algo(pattern, text):
    bad_character_array = bad_character(pattern)
    found_pattern = []
    P, T = len(pattern), len(text)
    shift = 0

    while shift <= T - P:
        i = P - 1  # как говорилось, идём с конца

        while i >= 0 and pattern[i] == text[shift+i]:
            i -= 1

        if i < 0:
            found_pattern.append(shift)

            if shift + P < T:
                shift += (P - bad_character_array[ord(text[shift+P])])
            else:
                shift += 1
        else:
            shift += max(1, i - bad_character_array[ord(text[shift+i])])

    return found_pattern


def main():
    with open("sample.txt") as f:
        file = f.read()

    pattern = input("Введите строку для поиска:\n")

    found_pattern = bm_algo(pattern, file)

    if found_pattern:
        print(f"Индексы вхождения строки {pattern} в тексте:")
        for i in found_pattern:
            print(i)
    else:
        print(f"Строка {pattern} в текст не входит")


if __name__ == "__main__":
    main()
