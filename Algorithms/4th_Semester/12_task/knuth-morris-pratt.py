# Алгоритм КМП опирается на префикс-функцию. Эта функция для элемента i
# из исходной строки S определяет длину наибольшей подстроки, заканчивающейся
# и начинающийся на одни и те же символы. Т.е. вот дана строка AABCDAAG.
# Значения префикс-функции для элемента с индексом 6 (предпоследний элемент)
# будет равно 2, т.к. S[0]S[1] = S[6][5].

# Обозначим префикс-функцию как F() и предположим, что F(S,i) = P
# У префикс функции также есть важные свойства:
# 1) Если S[i+1] = S[P+1], то F(S,i+1) = P+1
# 2) Для строки S[0]...S[i] строка S[0]...S[F(S,P)] является суффиксом
# 3) Для любого j из k < j < i, строка S[0]...S[j] не является суффиксом
# строки S[0]...S[i]

# На основе этих свойств строим алгоритм:
# 1) Если S[i+1] = S[P+1], то F(S,i+1) = P+1
# 2) Иначе, в случае P = 0, то F(S,i+1) = 0
# 3) Иначе, переопределяем P как: P = F(S,P) и в пункт 1)
def prefix(pattern):  # префикс-функция для КМП
    chars = len(pattern)
    prefix_array = [0 for i in range(chars)]
    prefix_value = 0

    for i in range(1, chars):
        if pattern[prefix_value] == pattern[i]:
            prefix_value += 1
            prefix_array[i] = prefix_value

        elif prefix_value != 0:
            prefix_value = prefix_array[prefix_value - 1]

        else:
            prefix_array[i] = 0

    return prefix_array


# Далее, строим сам алгоритм КМП:
# Полагаем prefix_value = 0, i = 0, S - искомый шаблон, T - исходный текст.
# Аналогично префикс-функции проверяем, что S[prefix_value] = T[i]
# Если это так, что prefix_value += 1. При этом, в случае prefix_value равно
# длине S, то индекс вхождения (его конец) найден.
# Если это не так, то prefix_value = F(prefix_value-1) и всё заново
def kmp(pattern, text):
    prefix_array = prefix(pattern)
    i, j = 0, 0
    found_pattern = []

    while (len(text) - i) >= (len(pattern) - j):
        if pattern[j] == text[i]:
            i += 1
            j += 1

        if j == len(pattern):
            found_pattern.append(i - len(pattern))
            j = prefix_array[j - 1]

        elif i < len(text) and pattern[j] != text[i]:
            if j != 0:
                j = prefix_array[j - 1]
            else:
                i += 1

    return found_pattern


def main():
    with open("sample.txt") as f:
        file = f.read()

    pattern = input("Введите строку для поиска:\n")

    found_pattern = kmp(pattern, file)

    if found_pattern:
        print(f"Индексы вхождения строки {pattern} в тексте:")
        for i in found_pattern:
            print(i)
    else:
        print(f"Строка {pattern} в текст не входит")


if __name__ == "__main__":
    main()
