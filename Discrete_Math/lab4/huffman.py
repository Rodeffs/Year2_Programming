import math


def huffman(ls, group_codes):
    while len(ls) > 1:
        groups = list(ls.keys())

        new_str = groups[0] + groups[1]  # объединяем буквы в пару
        new_value = ls[groups[0]] + ls[groups[1]]  # их вхождения складываем

        # Т.к. отсортировали, то первые два символа (или пары) всегда наименьшие
        group_codes[groups[0]] = '0'
        group_codes[groups[1]] = '1'

        ls.pop(groups[0])
        ls.pop(groups[1])

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

    stat, group_codes, coded = {}, {}, {}
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
    print("2) Количество вхождений каждого символа:\n", stat)

    # Считываение по парам:
    file2 = []
    for i in range(0, len(file), 2):
        file2.append(file[i] + file[i+1])

    # Статистический анализ пар:
    stat2 = {}
    for i in range(0, len(file2)):
        if file2[i] not in stat2:
            stat2[file2[i]] = 1
        else:
            stat2[file2[i]] += 1
    stat2.pop("\n\n")

    # Частота пар:
    stat2 = dict(sorted(stat2.items(), key=lambda item: item[1]))
    print("3) Количество вхождений пар:\n", stat2)

    stat_groups = stat
    huffman(stat_groups, group_codes)

    # Кодировка каждого символа (если символ входит в пару, то добавляем слева код этой пары):
    letters = list(stat.keys())
    groups = list(group_codes.keys())
    for i in range(0, len(letters)):
        curlet = letters[i]
        coded[curlet] = ""
        for j in range(0, len(groups)):
            if curlet in groups[j]:
                coded[curlet] = group_codes[groups[j]] + coded[curlet]
    print("4) Код каждого символа:\n", coded)

    # После сжатия:
    size = symbol_count * 5
    avg = average(stat, coded, symbol_count)
    for i in range(0, len(letters)):
        new_size += stat[letters[i]] * len(coded[letters[i]])
    print(f"5) Изначальный размер текста был {size} бит, после кодировки стал {new_size} бит")
    print(f"6) Степень сжатия: {new_size/size}\n7) Коэф. сжатия: {size/new_size}\n8) Средняя длина символа: {avg}")

    # Применение формулы Шеннона:
    shan_val = shannon(stat, symbol_count)
    print("9) Количество информации по Шеннону равно:", shan_val)
    print("10) Отношение среднего размера символа кодов Хаффмана и количества информации из формулы Шеннона:", 1 - shan_val / avg)


if __name__ == '__main__':
    main()
