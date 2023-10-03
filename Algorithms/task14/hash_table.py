def hash_table(arr, alphabet):
    hashed = [[] for i in alphabet]
    for i in range(0, len(arr)):
        first_letter = arr[i][0]
        for j in range(0, len(alphabet)):
            if first_letter == alphabet[j]:
                hashed[j].append(arr[i])
                break

    return hashed


if __name__ == "__main__":

    with open("input.txt", "r") as input_file:  # открываем файл вводных данных в режиме только для чтения
        inputs = [i.strip(",").strip(".").strip(":").strip(";").strip("!").strip("?") for i in input_file.read().split()]
    
    alphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZzАаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщъыьЭэЮюЯя"
    hashed = hash_table(inputs, alphabet)

    with open("output.txt", "a") as output_file:  # открываем (или создаём, если его нет) файл для вывода таблицы в режиме добавления
        j = 1
        for i in range(0, len(hashed)):
            if hashed[i]:
                output_file.write(f"{j} {alphabet[i]} | {hashed[i]}\n")
                output_file.write("----------------------------------------------------\n")
                j += 1
