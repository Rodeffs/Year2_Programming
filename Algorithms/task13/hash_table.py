# Лаба №13 “с наложением”
# С наложением значит, что если элемент по этому ключу занят, что мы ищем свободную ячейку в таблице куда записать этот элемент под этим же ключём, а если места не нашлось, то удваиваем размер массива и тогда точно место будет

def hash_table(arr, alphabet):
    hashed = [[] for i in alphabet]
    keys = len(alphabet)
    expanded = 0  # это нужно для того, чтобы зря не пробегаться по уже заполненым ячейкам

    for i in range(0, len(arr)):
        N = len(hashed)
        word = arr[i]
        word_key = alphabet.find(word[0])
        j = word_key + expanded

        while j < N:
            if not hashed[j]:
                hashed[j] = word
                break
            j += 1

        if j >= N:
            temp = [[] for k in alphabet]
            hashed = hashed + temp
            expanded += keys
            hashed[word_key + expanded] = word

    return hashed


if __name__ == "__main__":

    with open("input.txt", "r") as input_file:  # открываем файл вводных данных в режиме только для чтения
        inputs = [i.strip(".,:;!?-") for i in input_file.read().split()]

    alphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZzАаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщъыьЭэЮюЯя"
    hashed = hash_table(inputs, alphabet)

    with open("output.txt", "w") as output_file:  # открываем (или создаём, если его нет) файл для вывода таблицы в режиме добавления
        j = 1
        for i in range(0, len(hashed)):
            if hashed[i]:
                output_file.write(f"{j} {hashed[i][0]} | {hashed[i]}\n")
                output_file.write("----------------------------------------------------\n")
                j += 1
