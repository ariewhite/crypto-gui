#ifndef MAGICCUBE_H
#define MAGICCUBE_H

#include <QDialog>

namespace Ui {
class magiccube;
}

class magiccube : public QDialog
{
    Q_OBJECT

public:
    explicit magiccube(QWidget *parent = nullptr);
    ~magiccube();
    static void create_dialog_window();
private slots:
    QVector<QVector<int>> generate_magic_square();
    bool isMagicSquare(const QVector<QVector<int>>& square);
    void on_gen_cube_clicked();

    void on_check_cube_clicked();

    QVector<QVector<int>> generateMagicSquare();

private:
    Ui::magiccube *ui;

};

#endif // MAGICCUBE_H
