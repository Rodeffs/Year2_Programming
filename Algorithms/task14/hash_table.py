def hash_table(arr, alphabet):
    hashed = [[] for i in alphabet]  # создаём массив для хеша, размер которого равен кол-ву символов в алфавите
    for i in range(0, len(arr)):
        for j in range(0, len(alphabet)):
            if arr[i][0] == alphabet[j]:  # затем заносим в хеш элементы из файла по принципу: индекс элемента равен первой букве слова (т.е. для A индекс 0, для a - 1 и т.д.)
                hashed[j].append(arr[i])  # т.к. это хеш функция со списками, то слова с такой же первой буквой просто добавляем к остальным
                break

    return hashed


if __name__ == "__main__":

    with open("input.txt", "r") as input_file:  # открываем файл вводных данных в режиме только для чтения
        inputs = [i.strip(",.:;!?") for i in input_file.read().split()]
    
    alphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZzАаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщъыьЭэЮюЯя"
    hashed = hash_table(inputs, alphabet)

    with open("output.txt", "a") as output_file:  # открываем (или создаём, если его нет) файл для вывода таблицы в режиме добавления
        for i in range(0, len(hashed)):
            if hashed[i]:
                output_file.write(f"{i+1} {alphabet[i]} | {hashed[i]}\n")
                output_file.write("----------------------------------------------------\n")
