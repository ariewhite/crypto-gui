#include "magiccube.h"
#include "ui_magiccube.h"

#include <QIcon>
#include <QDebug>
#include <QFile>
#include <QRandomGenerator>

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

QVector<QVector<int>> magiccube::magic_square = QVector<QVector<int>>(4, QVector<int>(4));

//--- check for magic square ---
bool magiccube::isMagicSquare(const QVector<QVector<int>>& square){
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


void magiccube::fill_square(const QVector<QVector<int>>& square){
    QString result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result += QString::number(square[i][j]) + " ";
        }
        result += "\n";
    }
    ui->min_out->setPlainText(result);
}

/*//--- generate magic square ---
QVector<QVector<int>> magiccube::generate_magic_square(){

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

    qInfo() << numbers;


    // создаем двумерный масси (двумерный вектор)
    // create 2D vector
    QVector<QVector<int>> magic_square(4, QVector<int>(4));
    int index {0};

    for (int i = 0; i < 4; i++){
        for (int j = 0;j < 4; j++){
            magic_square[i][j] = numbers[index++];
        }
    }

    // так как нет*(а может и есть) какого-либо определенного магического алгоритма позволяющего
    // с первого раза достоверно создать кубик, шафлим числа, до тех пор пока куб не станет маг.
    // shuffle while "square" --> "magic square"
    int x {0};
    while(!isMagicSquare(magic_square)){
        x++;

        qInfo() << x << " - " << isMagicSquare(magic_square);
        qInfo() << magic_square;
        std::shuffle(numbers.begin(), numbers.end(), g);

        index = 0;

        for (int i = 0; i < 4; i++){
            for (int j = 0;j < 4; j++){
                magic_square[i][j] = numbers[index++];
                qInfo() << magic_square[i][j];
            }
        }
    }

    return magic_square;
}*/


//--- create dialog window ---
void magiccube::create_dialog_window(){
    magiccube *mg = new magiccube;

    QIcon icon {":/icon/source/ico.ico"};

    mg->setWindowIcon(icon);
    mg->show();
}


QVector<QVector<int> > magiccube::get_square()
{
    qDebug() << "new rect";
    QFile * file = new QFile(":/icon/source/output.txt");

    if (!file->open(QIODevice::ReadOnly)){
        qWarning() << "File not open" << file->errorString();
        NULL;
    }

    QTextStream * in = new QTextStream(file);
    QString * line = new QString;
    QRandomGenerator *gen = QRandomGenerator::global();

    int x = gen->bounded(1, 7024);
    qDebug() << x;

    int current_line {0};

    while(!in->atEnd()){
        *line = in->readLine();
        ++current_line;
        if(current_line == x){
            break;
        }
    }


    file->close();

    QStringList value = line->split(" ");

    QVector<QVector<int>> square(4, QVector<int>(4));

    current_line = 0;

    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            square[i][j] = value[current_line++].toInt();
        }
    }

    qDebug() << square;

    return square;
}

QVector<QVector<int> > magiccube::getMagic_square()
{
    return magic_square;
}


//--- check cube ---
void magiccube::on_check_cube_clicked(){

}


//--- call new cube ---
void magiccube::on_gen_cube_clicked(){

    magic_square = get_square();

    fill_square(magic_square);

}
























