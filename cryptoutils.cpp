#include "cryptoutils.h"
#include "qdebug.h"
#include <QString>
#include <QVector>
#include <QList>

CryptoUtils::CryptoUtils() {


}

QString CryptoUtils::atbash_crypto(QString value, QString alphabet){
    /*

    atbash sipher w/ case sensitive
    custom alphabet.

    */

    int index {0};

    for (int i = 0; i < value.length(); i++ ){

        bool isUpper{false};

        isUpper = value[i].isLower() ? false : true;

        QChar cur_char = value[i].toLower();

        index = alphabet.indexOf(cur_char);

        if (index != -1){
            QChar mirror_char = alphabet[alphabet.length() - index - 1];
            if (isUpper){
                value[i] = mirror_char.toUpper();
            } else {value[i] = mirror_char;}

        } else {value[i] = cur_char;}

    }

    return value;
}

QString CryptoUtils::atbash_decrypto(QString value, QString alphabet){
    /*
    param:
    QString value - crypted text for decrypt
    QString alphabet - alphabet for decrypt

    atbash decrypto w/ case sensitive
    custom alphabet
    */

    int index {0};

    for (int i = 0; i < value.length(); i++ ){

        bool isUpper{false};

        isUpper = value[i].isLower() ? false : true;

        QChar cur_char = value[i].toLower();

        index = alphabet.indexOf(cur_char);

        if (index != -1){
            QChar mirror_char = alphabet[alphabet.length() - index - 1];
            if (isUpper){
                value[i] = mirror_char.toUpper();
            } else {value[i] = mirror_char;}

        } else {value[i] = cur_char;}

    }

    return value;
}


//--- magic sqaure sipher ---
QString CryptoUtils::magic_crypto(QString value, QVector<QVector<int>> & square)
{
    QVector<int> numbers = convert_to_QVector(square);


    int index{0};
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            square[i][j] = numbers[index++];
        }
    }

    QList<QPair<QString, int>> value_string;

    for(int i = 1; i <= value.size(); i++){
        value_string.push_back(qMakePair(QString(value[i-1]), i));
    }

    QString result;
    for (int number : numbers) {
        for (auto pair : value_string) {
            if (pair.second == number) {
                result += pair.first;
                break;
            }
        }
    }

    qDebug() << "magic crypto - " << result;

    return result;
}


QString CryptoUtils::magic_decrypto(QString value, QVector<QVector<int>> & square)
{

    QVector<int> magic_numbers = convert_to_QVector(square);
    QString result;

    for (int i = 1; i < value.size() + 1; ++i) {
        for (int j = 0; j < magic_numbers.size(); ++j){
            if(i == magic_numbers[j]){
                result.append(value[j]);
            }
        }
    }

    qDebug() << "magic decrypto - " << result;

    return result;
}

QVector<int> CryptoUtils::convert_to_QVector(const QVector<QVector<int> > &nestedList)
{
    QVector<int> result;
    for (const QList<int>& innerList : nestedList) {
        result.reserve(result.size() + innerList.size());
        for (int value : innerList) {
            result.append(value);
        }
    }
    return result.toVector();
}





