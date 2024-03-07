#include "magiccube.h"
#include "ui_magiccube.h"

#include <QIcon>
#include <QCoreApplication>>
#include <QDebug>
#include <algorithm>
#include <random>

magiccube::magiccube(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::magiccube)
{
    ui->setupUi(this);
}

magiccube::~magiccube()
{
    delete ui;
}


//--- check for magic square ---
bool isMagicSquare(const QVector<QVector<int>>& square){
    int n = square.size();
    int magicSum = n * (n * n + 1) / 2;

    // строка | line
    for (int i = 0; i < n; ++i) {
        int rowSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += square[i][j];
        }
        if (rowSum != magicSum) return false;
    }

    // столбец | row
    for (int j = 0; j < n; ++j) {
        int colSum = 0;
        for (int i = 0; i < n; ++i) {
            colSum += square[i][j];
        }
        if (colSum != magicSum) return false;
    }

    // диагональ | diagonal
    int diagSum = 0;
    for (int i = 0; i < n; ++i) {
        diagSum += square[i][i];
    }
    if (diagSum != magicSum) return false;

    // диагональ обратная | 2nd diagonal
    diagSum = 0;
    for (int i = 0; i < n; ++i) {
        diagSum += square[i][n - i - 1];
    }
    if (diagSum != magicSum) return false;

    return true;
}


//--- generate magic square ---
QVector<QVector<int>> generate_magic_square(){

    // тут я распишу, ибо имхо читать даже свои алгоритмы тяжело

    // fill vector w/ natural numbers
    QVector<int> numbers(16);
    for (int i = 0; i < numbers.length(); i++){
        numbers[i] = i + 1;
    }

    // дальше генируем рандомные числы используя Вихрь Мерсенна
    // для криптографии этот метод НЕ ПОДХОДИТ, т.к не является криптостойким
    // Mersenne twister - change to another PRNG

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(numbers.begin(), numbers.end(), g);


    // создаем двумерный масси (двумерный вектор)
    // create 2D vector
    QVector<QVector<int>> magic_square(4, QVector<int>(n, 4));
    int index {0};

    for (int i = 0; i < 4; i++){
        for (int j = 0;j < 4; j++){
            magic_square[i][j] = numbers[index++];
        }
    }

    // так как нет*(а может и есть) какого-либо определенного магического алгоритма позволяющего
    // с первого раза достоверно создать кубик, шафлим числа, до тех пор пока куб не станет маг.
    // shuffle while "square" --> "magic square"

    while(!isMagicSquare(magic_square)){
        std::shuffle(numbers.begin(), numbers.end(), g);

        index = 0;

        for (int i = 0; i < 4; i++){
            for (int j = 0;j < 4; j++){
                magic_square[i][j] = numbers[index++];
            }
        }
    }

    return magic_square;
}


//--- create dialog window ---
void magiccube::create_dialog_window(){
    magiccube *mg = new magiccube;

    QIcon icon {":/icon/source/ico.ico"};

    mg->setWindowIcon(icon);
    mg->show();
}


//--- call new cube ---
void magiccube::on_gen_cube_clicked(){

}


//--- check cube ---
void magiccube::on_check_cube_clicked(){

}





