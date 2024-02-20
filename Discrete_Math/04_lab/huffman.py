import math


def huffman(stat, char_groups_codes):
    while len(stat) > 1:
        char_groups = list(stat.keys())
        left_char = char_groups[0]
        right_char = char_groups[1]

        # Объединяем два символа в один, а их веса складываем
        new_str = left_char + right_char
        new_value = stat[left_char] + stat[right_char]

        # Т.к. отсортирован, то у первых двух символов всегда наименьшие веса
        char_groups_codes[left_char] = '0'
        char_groups_codes[right_char] = '1'

        # Заменяем старые символы их слиянием
        stat.pop(left_char)
        stat.pop(right_char)
        stat[new_str] = new_value

        # Сортируем снова (из-за этого коды слегка отличаются, но той же длины)
        stat = dict(sorted(stat.items(), key=lambda item: item[1]))


def average(stat, coded, size):  # средняя длина слова
    characters = list(stat.keys())
    avg = 0

    for i in range(0, len(characters)):
        cur_char = characters[i]
        avg += len(coded[cur_char]) * stat[cur_char] / size

    return avg


def shannon(stat, size):  # формула Шеннона
    characters = list(stat.keys())
    shan = 0

    for i in range(0, len(characters)):
        prob = stat[characters[i]] / size
        shan -= prob * math.log(prob, 2)

    return shan


def encode_huffman(stat, char_groups_codes, coded):
    characters = list(stat.keys())
    char_group = list(char_groups_codes.keys())
    for i in range(0, len(characters)):
        cur_char = characters[i]
        coded[cur_char] = ""
        for j in range(0, len(char_group)):
            if cur_char in char_group[j]:
                coded[cur_char] = char_groups_codes[char_group[j]] + coded[cur_char]


def encode_huffman2(stat, char_groups_codes, coded):
    characters = list(stat.keys())
    char_group = list(char_groups_codes.keys())
    for i in range(0, len(characters)):
        cur_char = characters[i]
        coded[cur_char] = ""
        for j in range(0, len(char_group)):
            string = char_group[j]
            split_string = []
            for k in range(1, len(string), 2):
                split_string.append(string[k-1]+string[k])
            if cur_char in split_string:
                coded[cur_char] = char_groups_codes[char_group[j]] + coded[cur_char]


def count(stat):
    char_count = 0
    values = list(stat.values())
    for i in range(0, len(values)):
        char_count += values[i]
    return char_count


def main():
    with open("sample.txt", "r") as f:
        file = f.read()

    stat, char_groups_codes, coded, stat2,  char_pairs_codes, coded2 = {}, {}, {}, {}, {}, {}
    new_size, new_size2 = 0, 0

    # Статистический анализ:
    for i in range(0, len(file)):
        cur_char = file[i]
        if cur_char not in stat:
            stat[cur_char] = 1
        else:
            stat[cur_char] += 1
    stat.pop("\n")

    # Подсчёт количества символов:
    char_count = count(stat)
    print("1) Изначальное количество символов в тексте:", char_count)

    # Сортировка по частоте:
    stat = dict(sorted(stat.items(), key=lambda item: item[1]))
    print("2) Количество вхождений каждого символа:\n", stat)

    # Считываение по парам:
    file2 = []
    for i in range(0, len(file), 2):
        file2.append(file[i] + file[i+1])

    # Статистический анализ пар:
    for i in range(0, len(file2)):
        cur_char = file2[i]
        if cur_char not in stat2:
            stat2[cur_char] = 1
        else:
            stat2[cur_char] += 1
    stat2.pop("\n\n")

    # Частота пар:
    stat2 = dict(sorted(stat2.items(), key=lambda item: item[1]))
    print("3) Количество вхождений пар:\n", stat2)

    # Кодировка каждого символа (если символ входит в пару, то добавляем слева код этой пары):
    stat_copy = dict(stat)  # нужно вызвать именно конструктор копирования
    huffman(stat_copy, char_groups_codes)
    encode_huffman(stat, char_groups_codes, coded)
    print("4.1) Код каждого символа:\n", coded)

    # Кодировка пар:
    stat2_copy = dict(stat2)
    huffman(stat2_copy, char_pairs_codes)
    encode_huffman2(stat2, char_pairs_codes, coded2)
    print("4.2) Код пар:\n", coded2)

    # После сжатия:
    size = char_count * 5
    avg = average(stat, coded, char_count)
    characters = list(stat.keys())
    for i in range(0, len(characters)):
        new_size += stat[characters[i]] * len(coded[characters[i]])
    print(f"5) Изначальный размер текста был {size} бит, после кодировки стал {new_size} бит")
    print(f"6) Степень сжатия: {new_size/size}\n7) Коэф. сжатия: {size/new_size}\n8) Средняя длина слова: {avg}")

    # Применение формулы Шеннона:
    shan_val = shannon(stat, char_count)
    print("9) Количество информации по Шеннону равно:", shan_val)
    print("10) Отношение среднего размера символа кодов Хаффмана и количества информации из формулы Шеннона:", 1 - shan_val / avg)

    # Для пар:
    print("\nДля пар:")
    pair_count = count(stat2)
    avg2 = average(stat2, coded2, pair_count)
    pairs = list(stat2.keys())
    for i in range(0, len(pairs)):
        new_size2 += stat2[pairs[i]] * len(coded2[pairs[i]])
    print(f"11) Изначальный размер текста был {size} бит, после кодировки стал {new_size2} бит")
    print(f"12) Степень сжатия: {new_size2/size}\n13) Коэф. сжатия: {size/new_size2}\n14) Средняя длина слова: {avg2}")

    shan_val2 = shannon(stat2, pair_count)
    print("15) Количество информации по Шеннону равно:", shan_val2)
    print("16) Отношение среднего размера символа кодов Хаффмана и количества информации из формулы Шеннона:", 1 - shan_val2 / avg2)


if __name__ == '__main__':
    main()
