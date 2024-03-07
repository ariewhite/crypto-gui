#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool alphabet {false};
private slots:


    void on_switch_btn_clicked();

    void on_plain_text_textChanged();

    void on_switch_lg_btn_clicked();

    void on_crypted_text_textChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
