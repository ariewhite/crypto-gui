#include "magiccube.h"
#include "ui_magiccube.h"

#include <QIcon>

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


void magiccube::create_dialog_window(){
    magiccube *mg = new magiccube;

    QIcon icon {":/icon/source/ico.ico"};

    mg->setWindowIcon(icon);
    mg->show();
}
