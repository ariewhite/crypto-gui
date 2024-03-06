#ifndef CRYPTOUTILS_H
#define CRYPTOUTILS_H

#include <QString>

class CryptoUtils
{
public:
    CryptoUtils();
    static QString atbash_crypto(QString value, QString alphabet);
};

#endif // CRYPTOUTILS_H
