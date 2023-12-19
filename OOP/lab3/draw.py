from enum import Enum  # в Питоне нету enum class встроенного, для этого нужно подключить отдельно библиотеку


class Color(Enum):
    BLACK = 30
    RED = 31
    GREEN = 32
    YELLOW = 33
    BLUE = 34
    MAGENTA = 35
    CYAN = 36
    WHITE = 37


class Draw_Console:

    def __init__(self, msg, x, y, color, size, template):  # в Питоне нету приватных переменных, разве что __такие
        self.__msg = msg
        self.__x = x
        self.__y = y
        self.__color = color
        self.__size = size
        self.__template = template

    def setMsg(self, msg):
        self.__msg = msg

    def getMsg(self):
        return self.__msg

    def setX(self, x):
        self.__x = x

    def getX(self):
        return self.__x

    def setY(self, y):
        self.__y = y

    def getY(self):
        return self.__y

    def setColor(self, color):
        self.__color = color

    def getColor(self):
        return self.__color

    def setSize(self, size):
        self.__size = size

    def getSize(self):
        return self.__size

    def setTemplate(self, template):
        self.__template = template

    def getTemplate(self):
        return self.__template

    def write(self):

        # Идея состоит в том, чтобы открывать файл, где храняться шаблоны для букв и вставлять их в нужное место. Перед каждым шаблоном идёт собственно сама буква, её высота в строках и ширина в столбцах

        # По факту здесь всё завязано на ANSI escape code, о нём можно почитать в интернете 

        if self.__size == 1:
            print(f"\033[{Color[self.__color].value}m\033[{self.__y};{self.__x}H{self.__msg}\033[0m")

        else:

            X = self.__x

            try:

                with open("font.txt") as file:
                    fonts = file.read().split("\n")

                for i in range(0, len(self.__msg)):
                    letter = self.__msg[i]
                    line_index, letter_width = 0, 0

                    for line in fonts:
                        if f"{letter} {self.__size}" in line:
                            line_index = fonts.index(line)  # это вернёт нам строку, где содержится шаблон для нужной буквы
                            letter_width = 1 + int(line.split()[-1])  # это вернёт длину буквы, единичку добавляем для того, чтобы буквы лучше читались
                            break

                    if not letter_width:
                        print("Error, no such font available")
                        break

                    for j in range(1, self.__size+1):
                        layer_of_letter = fonts[line_index+j].replace("0", self.__template)  # это как раз и применяет выбранный символ к шаблону
                        print(f"\033[{Color[self.__color].value}m\033[{self.__y+j};{X}H{layer_of_letter}\033[0m")

                    X += letter_width

            except Exception:
                print("Error, file font.txt not found")
