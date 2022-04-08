#ifndef ESTACKEMPTY_H
#define ESTACKEMPTY_H
#include "EStackException.h"

class EStackEmpty : public EStackException {
public:
    //конструктор
    EStackEmpty() : EStackException("Unfortunately, your stack is empty.") {

    }

    //конструктор копирования
    EStackEmpty(const EStackEmpty &object) : EStackException(object) {

    }
};

#endif // ESTACKEMPTY_H
