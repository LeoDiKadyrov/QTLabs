#ifndef ESTACKEXCEPTION_H
#define ESTACKEXCEPTION_H
#include <cstring>

class EStackException {
private:
    char* _message;

public:
    //конструктор
    EStackException(const char* message) {
        //выделяем память под сообщение
        _message = new char[strlen(message) + 1];
        //сохраняем данные об ошибке
        strcpy(_message, message);
    }

    //конструктор копирования
    EStackException(const EStackException &object) {
        _message = new char[strlen(_message) + 1];
        strcpy(_message, object._message);
    }

    ~EStackException() {
        delete _message;
    }

    const char* what() const {
        return _message;
    }
};

#endif // ESTACKEXCEPTION_H
