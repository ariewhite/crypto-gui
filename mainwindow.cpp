#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "cryptoutils.h"
#include "magiccube.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->magic_frame->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}




//--- switch state ---
void MainWindow::on_switch_btn_clicked()
{
    switch (state) {
    case 1:
        ui->magic_frame->hide();
        ui->atbash_frame->show();
        ui->switch_btn->setText("Atbash");
        state = 2;

        break;
    case 2:
        ui->atbash_frame->hide();
        ui->magic_frame->show();
        ui->switch_btn->setText("Magic Square");
        state = 1;

        break;

    default:
        ui->atbash_frame->show();
        ui->magic_frame->hide();
        state = 1;

        break;
    }
}

void MainWindow::extracted()
{
    NULL;
}


//--- atbash crypting ---
void MainWindow::on_plain_text_textChanged()
{
    if (state == 2){
        ui->crypted_text->blockSignals(true);

        QString value {ui->plain_text->toPlainText()};

        QString alphabet {ui->alphabet_line->text()};

        value = CryptoUtils::atbash_crypto(value, alphabet);

        ui->crypted_text->setPlainText(value);

        ui->crypted_text->blockSignals(false);
    }
}


//--- atbash decrypt ---
void MainWindow::on_crypted_text_textChanged()
{
    if (state == 2){
        ui->plain_text->blockSignals(true);

        QString value {ui->crypted_text->toPlainText()};

        QString alphabet {ui->alphabet_line->text()};

        value = CryptoUtils::atbash_decrypto(value, alphabet);

        ui->plain_text->setPlainText(value);

        ui->plain_text->blockSignals(false);
    }
}


//--- change alphabet ---
void MainWindow::on_switch_lg_btn_clicked()
{
    QString current_alphabet {};

    if (alphabet) {
        current_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
        alphabet = false;
    }
    else {
        current_alphabet = "abcdefghijklmnopqrstuvwxyz";
        alphabet = true;
    }
    ui->alphabet_line->setText(current_alphabet);
}


//--- change magic cube ---
void MainWindow::on_magic_btn_clicked()
{
    magiccube::create_dialog_window();
    qInfo() << "window created";

}


//--- magic crypto ---
void MainWindow::on_mcrypt_btn_clicked()
{
    ui->crypted_text->blockSignals(true);

    QString value = ui->plain_text->toPlainText();
    QVector<QVector<int>> square = magiccube::getMagic_square();
    QString result;

    if (square[0][0] == 0){
        QMessageBox msg;
        msg.setText("Сначала сгенерируйте магический квадрат!");
        msg.setFixedSize(300, 200);
        msg.exec();
        return;
    } else {
        if (value.size() <= 16){
            value = value.leftJustified(16, ' ');

            result = CryptoUtils::magic_crypto(value, square);

        } else {
            int iter = value.size() / 16;

            for (int i = 0; i < iter + 1; ++i) {
                QString chunk = value.mid(i * 16, 16);
                if(chunk.length() <= 16){
                    chunk = chunk.leftJustified(16, ' ');
                }
                chunk = CryptoUtils::magic_crypto(chunk, square);

                result.append(chunk);
            }
        }
    }

    ui->crypted_text->setText(result);

    ui->crypted_text->blockSignals(false);

}


//--- magic decrypto ---
void MainWindow::on_pushButton_clicked()
{
    ui->plain_text->blockSignals(true);

    QString value = ui->crypted_text->toPlainText();
    QVector<QVector<int>> square = magiccube::getMagic_square();
    QString result;

    if (square[0][0] == 0){
        QMessageBox msg;
        msg.setText("Сначала сгенерируйте магический квадрат!");
        msg.setFixedSize(300, 200);
        msg.exec();
        return;
    } else {
        if (value.size() <= 16){
            value = value.leftJustified(16, ' ');

            result = CryptoUtils::magic_decrypto(value, square);

        } else {
            int iter = value.size() / 16;

            for (int i = 0; i < iter + 1; ++i) {
                QString chunk = value.mid(i * 16, 16);
                if(chunk.length() <= 16){
                    chunk = chunk.leftJustified(16, ' ');
                }
                chunk = CryptoUtils::magic_decrypto(chunk, square);

                result.append(chunk);
            }
        }
    }

    ui->plain_text->setText(result);

    ui->crypted_text->blockSignals(false);

}









