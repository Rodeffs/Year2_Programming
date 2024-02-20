import math


def encode(stat_original):  # кодирование групп символов (пар)
    stat = dict(stat_original)  # чтобы не изменить оригинал
    group_codes = {}

    while len(stat) > 1:
        groups = list(stat.keys())
        left_group = groups[0]
        right_group = groups[1]

        # Объединяем два символа в один, а их веса складываем
        new_str = left_group + right_group
        new_value = stat[left_group] + stat[right_group]

        # Т.к. отсортирован, то у первых двух символов всегда наименьшие веса
        group_codes[left_group] = '0'
        group_codes[right_group] = '1'

        # Заменяем старые символы их слиянием
        stat.pop(left_group)
        stat.pop(right_group)
        stat[new_str] = new_value

        # Сортируем снова (из-за этого коды слегка отличаются, но той же длины)
        stat = dict(sorted(stat.items(), key=lambda item: item[1]))

    return group_codes


def average(stat, coded, size):  # средняя длина символа (пары)
    characters = list(stat.keys())
    avg = 0

    for i in range(0, len(characters)):
        current = characters[i]
        avg += len(coded[current]) * stat[current] / size

    return avg


def shannon(stat, size):  # формула Шеннона
    characters = list(stat.keys())
    shan = 0

    for i in range(0, len(characters)):
        probability = stat[characters[i]] / size
        shan -= probability * math.log(probability, 2)

    return shan


def huffman(stat, string_codes):  # коды Хаффмана для символов
    characters = list(stat.keys())
    char_group = list(string_codes.keys())
    coded = {}

    for i in range(0, len(characters)):
        cur_char = characters[i]
        coded[cur_char] = ""
        for j in range(0, len(char_group)):
            if cur_char in char_group[j]:
                coded[cur_char] = string_codes[char_group[j]] + coded[cur_char]

    return coded


def huffman2(stat, string_codes):  # коды Хаффмана для пар
    pairs = list(stat.keys())
    pair_group = list(string_codes.keys())
    coded = {}

    for i in range(0, len(pairs)):
        cur_pair = pairs[i]
        coded[cur_pair] = ""
        for j in range(0, len(pair_group)):
            string = pair_group[j]
            split_string = []
            for k in range(1, len(string), 2):  # делим строку на пары
                split_string.append(string[k-1]+string[k])
            if cur_pair in split_string:
                coded[cur_pair] = string_codes[string] + coded[cur_pair]

    return coded


def count(stat):
    char_count = 0
    values = list(stat.values())
    for i in range(0, len(values)):
        char_count += values[i]
    return char_count


def compress(stat, coded):
    new_size = 0
    characters = list(stat.keys())
    for i in range(0, len(characters)):
        new_size += stat[characters[i]] * len(coded[characters[i]])
    return new_size


def analysis(file):
    stat = {}
    for i in range(0, len(file)):
        cur_char = file[i]
        if cur_char not in stat:
            stat[cur_char] = 1
        else:
            stat[cur_char] += 1

    return stat


def main():
    with open("sample.txt", "r") as f:
        file = f.read()

    print("Для отдельных символов:")

    # Статистический анализ:
    stat = analysis(file)
    stat.pop("\n")

    # Подсчёт количества символов:
    char_count = count(stat)
    print("1) Изначальное количество символов в тексте:", char_count)

    # Сортировка по частоте:
    stat = dict(sorted(stat.items(), key=lambda item: item[1]))
    print("2) Количество вхождений каждого символа:\n", stat)

    # Кодировка каждого символа (если символ входит в пару, то добавляем слева код этой пары):
    char_groups_codes = encode(stat)
    coded = huffman(stat, char_groups_codes)
    print("3) Код каждого символа:\n", coded)

    # Сжатие:
    size = char_count * 5
    avg = average(stat, coded, char_count)
    new_size = compress(stat, coded)
    print(f"4) Изначальный размер текста был {size} бит, после кодировки стал {new_size} бит")
    print(f"5) Степень сжатия: {new_size/size}\n6) Коэф. сжатия: {size/new_size}\n7) Средняя длина слова: {avg}")

    # Применение формулы Шеннона:
    shan_val = shannon(stat, char_count)
    print("8) Количество информации по Шеннону равно:", shan_val)
    print("9) Разность среднего размера символа кодов Хаффмана и количества информации из формулы Шеннона:", 1 - shan_val / avg)

    # ---------------------------------------------------------------------

    print("\nДля пар символов:")

    # Считываение по парам:
    file2 = []
    for i in range(1, len(file), 2):
        file2.append(file[i-1] + file[i])

    # Статистический анализ пар:
    stat2 = analysis(file2)
    stat2.pop("\n\n")

    # Подсчёт количества пар:
    pair_count = count(stat2)
    print("10) Изначальное количество пар символов в тексте:", pair_count)

    # Сортировка по частоте:
    stat2 = dict(sorted(stat2.items(), key=lambda item: item[1]))
    print("11) Количество вхождений пар:\n", stat2)

    # Кодировка пар:
    char_pairs_codes = encode(stat2)
    coded2 = huffman2(stat2, char_pairs_codes)
    print("12) Код пар:\n", coded2)

    # Сжатие:
    avg2 = average(stat2, coded2, pair_count)
    new_size2 = compress(stat2, coded2)
    print(f"13) Изначальный размер текста был {size} бит, после кодировки стал {new_size2} бит")
    print(f"14) Степень сжатия: {new_size2/size}\n15) Коэф. сжатия: {size/new_size2}\n16) Средняя длина пары: {avg2}")

    # Применение формулы Шеннона для пар:
    shan_val2 = shannon(stat2, pair_count)
    print("17) Количество информации по Шеннону равно:", shan_val2)
    print("18) Разность среднего размера символа кодов Хаффмана и количества информации из формулы Шеннона:", 1 - shan_val2 / avg2)


if __name__ == '__main__':
    main()
