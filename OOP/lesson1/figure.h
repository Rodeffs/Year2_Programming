#ifndef LESSON1_FIGURE_H
#define LESSON1_FIGURE_H

enum class Level{HIGH, MID, LOW};

class Figure {

public: // есть доступ для всех
    int x, y;
    Level level;

    void setX(int x); // сеттер

    int getX(); // геттер


protected: // есть доступ только для наследуемых классов

private: // есть доступ только в рамках этого класса
    int var;
};


#endif //LESSON1_FIGURE_H
