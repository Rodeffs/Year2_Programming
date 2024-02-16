import math


def huffman(ls, pair_codes):
    while len(ls) > 1:
        pairs = list(ls.keys())

        new_str = pairs[0] + pairs[1]  # объединяем буквы в пару
        new_value = ls[pairs[0]] + ls[pairs[1]]  # их вхождения складываем

        # Т.к. отсортировали, то первые два символа (или пары) всегда наименьшие
        pair_codes[pairs[0]] = '0'
        pair_codes[pairs[1]] = '1'

        ls.pop(pairs[0])
        ls.pop(pairs[1])

        ls[new_str] = new_value
        ls = dict(sorted(ls.items(), key=lambda item: item[1]))  # сортируем


def average(stat, coded, size):  # средняя длина слова
    letters = list(stat.keys())
    avg = 0

    for i in range(0, len(letters)):
        curlet = letters[i]
        avg += len(coded[curlet]) * stat[curlet] / size

    return avg


def shannon(stat, size):
    letters = list(stat.keys())
    shan = 0

    for i in range(0, len(letters)):
        prob = stat[letters[i]] / size
        shan += prob * math.log(1/prob, 2)

    return shan


def main():
    with open("sample.txt", "r") as f:
        file = f.read()

    stat, pair_codes, coded = {}, {}, {}
    symbol_count, new_size = 0, 0

    # Статистический анализ:
    for i in range(0, len(file)):
        if file[i] not in stat:
            stat[file[i]] = 1
        else:
            stat[file[i]] += 1
    stat.pop("\n")

    # Подсчёт количества символов:
    values = list(stat.values())
    for i in range(0, len(values)):
        symbol_count += values[i]
    print("1) Изначальное количество символов в тексте:", symbol_count)

    # Сортировка по частоте:
    stat = dict(sorted(stat.items(), key=lambda item: item[1]))
    stat_pairs = stat
    print("2) Количество вхождений каждого символа:\n", stat)

    huffman(stat_pairs, pair_codes)

    # Кодировка каждого символа (если символ входит в пару, то добавляем слева код этой пары):
    letters = list(stat.keys())
    pairs = list(pair_codes.keys())
    for i in range(0, len(letters)):
        curlet = letters[i]
        coded[curlet] = ""
        for j in range(0, len(pairs)):
            if curlet in pairs[j]:
                coded[curlet] = pair_codes[pairs[j]] + coded[curlet]
    print("3) Код каждого символа:\n", coded)

    # После сжатия:
    size = symbol_count * 5
    avg = average(stat, coded, symbol_count)
    for i in range(0, len(letters)):
        new_size += stat[letters[i]] * len(coded[letters[i]])
    print(f"4) Изначальный размер текста был {size} бит, после кодировки стал {new_size} бит")
    print(f"5) Степень сжатия: {new_size/size}\n6) Коэф. сжатия: {size/new_size}\n7) Средняя длина символа: {avg}")

    # Применение формулы Шеннона:
    shan_val = shannon(stat, symbol_count)
    print("8) Количество информации по Шеннону равно:", shan_val)
    print("9) Разность среднего размера символа кодов Хаффмана и количества информации из формулы Шеннона:", 1 - shan_val / avg)


if __name__ == '__main__':
    main()
