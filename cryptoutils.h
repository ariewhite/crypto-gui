#ifndef CRYPTOUTILS_H
#define CRYPTOUTILS_H

#include <QString>

class CryptoUtils
{

friend class maggicube;

public:
    CryptoUtils();
    static QString atbash_crypto(QString value, QString alphabet);
    static QString atbash_decrypto(QString value, QString alphabet);
    static QString magic_crypto(QString value, QVector<QVector<int>> & square);
    static QString magic_decrypto(QString value, QVector<QVector<int>> & square);
    static QVector<int> convert_to_QVector(const QVector<QVector<int>> & nestedList);
    //static QVector<int> invertQVector(const QVector<int> & nestedList);
};

#endif // CRYPTOUTILS_H
