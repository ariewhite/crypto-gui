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

    QVector<QVector<int>> get_square();

    bool isMagicSquare(const QVector<QVector<int>>& square);

    void fill_square(const QVector<QVector<int>>& square);



private slots:

    void on_gen_cube_clicked();

    void on_check_cube_clicked();

private:
    Ui::magiccube *ui;

};

#endif // MAGICCUBE_H
