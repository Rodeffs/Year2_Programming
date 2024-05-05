"""
В данном алгоритме используется хэш-функция для поиска.
Для начала создаём хеш для искомого шаблона, используя такую хеш-функцию:
    l = длина шаблона
    p = простое число
    char = символ шаблона по порядку
    i = индекс этого символа
    base = случайное целое число от 0 до p-1

    hash(char) = (char * base ^ (l - i - 1)) % p

Получив значение хеш-функции для шаблона, теперь генерируем хеш для текста таким образом:
Генерируем хеш для первых l символов, затем проходимся по тексту последовательно, убирая
из хеша значение первого символа и добавляя в конец следующий, сравнивая с хешом для шаблона.
Когда будет совпадение - вхождение найдено

Формула для изменения хеша для текста из исходной получается такая:
    hash = (hash - (text[i - l] * base ^ (l - 1)) % p) * base + text[i]
"""

from random import uniform

def hash_func(pattern, base, prime, patlen):
    hash_value = 0
    
    for i in range(patlen):
        hash_value += (ord(pattern[i]) * base ** (patlen - 1 - i))
    
    return hash_value % prime


def recalculate(old, text, i, b, p, l):
    return ((old - (ord(text[i-l]) * b ** (l - 1)) % p) * b + ord(text[i])) % p 


def rabin_karp(pattern, text, col_check):
    prime = 2 ** 61 - 1 # простое число, лучше как можно больше во избежание коллизий
    base = int(uniform(0, prime - 1))  # случайное целое число от 0 до prime - 1
    patlen, textlen = len(pattern), len(text)
    
    hash_pattern = hash_func(pattern, base, prime, patlen)
    hash_text = hash_func(text[:patlen], base, prime, patlen)
    found_pattern = []

    for i in range(patlen-1, textlen):
        if i >= patlen: # чтобы не упустить вхождение в 0 индексе
            hash_text = recalculate(hash_text, text, i, base, prime, patlen)

        if hash_text == hash_pattern:
            if col_check == "y" or col_check == "Y":
                j = 0

                while j < patlen:
                    if pattern[j] != text[i - patlen + j + 1]:
                        break
                    j += 1

                if j == patlen:
                    found_pattern.append(i - patlen + 1)
            else:
                found_pattern.append(i - patlen + 1)

    return found_pattern


def main():
    with open("sample.txt") as f:
        file = f.read()
    
    col_check = input("Делать проверку коллизии (замедлит работу)? y/N ")

    pattern = input("Введите строку для поиска:\n")
    
    found_pattern = rabin_karp(pattern, file, col_check)

    if found_pattern:
        print(f"Индексы вхождения строки {pattern} в тексте:")
        for i in found_pattern:
            print(i)
    else:
        print(f"Строка {pattern} в текст не входит")
    

if __name__ == "__main__":
    main()
