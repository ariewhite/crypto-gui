#include "cryptoutils.h"
#include <QString>


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






