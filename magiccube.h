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
private:
    Ui::magiccube *ui;

};

#endif // MAGICCUBE_H
