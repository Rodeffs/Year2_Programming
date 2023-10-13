from enum import Enum # в Питоне нету enum class встроенного, для этого нужно подключить отдельно библиотеку

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

    def __init__(self, msg, x, y, color, size, template):
        self.msg = msg
        self.x = x
        self.y = y
        self.color = color
        self.size = size
        self.template = template

    def write(self):

        # Идея состоит в том, чтобы открывать файл, где храняться шаблоны для букв и вставлять их в нужное место. Перед каждым шаблоном идёт собственно сама буква, её высота в строках и ширина в столбцах

        # По факту здесь всё завязано на ANSI escape code, о нём можно почитать в интернете 

        if self.size == 1:
            print(f"\033[{Color[self.color].value}m\033[{self.y};{self.x}H{self.msg}\033[0m")
        
        else:

            X = self.x

            with open("font.txt") as file:
                fonts = file.read().split("\n")

            for i in range(0, len(self.msg)):
                letter = self.msg[i]
                
                line_index, letter_width = 0, 0 

                for line in fonts:
                    if f"{letter} {self.size}" in line:
                        line_index = fonts.index(line)  # это вернёт нам строку, где содержится шаблон для нужной буквы
                        letter_width = 1 + int(line.split()[-1])  # это вернёт длину буквы, единичку добавляем для того, чтобы буквы лучше читались
                        break

                if not letter_width:
                    print("Error, no such font available")
                    break

                for j in range(1, self.size+1):
                    layer_of_letter = fonts[line_index+j].replace("0", self.template)  # это как раз и применяет выбранный символ к шаблону
                    print(f"\033[{Color[self.color].value}m\033[{self.y+j};{X}H{layer_of_letter}\033[0m")

                X += letter_width



