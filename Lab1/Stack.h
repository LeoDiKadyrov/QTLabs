#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <functional>
#include <EStackEmpty.h>
#include <EStackException.h>

template<class T>
class Stack {
private:
    struct NodeStack {
        const T item_;
        NodeStack *pointPrevious_; //Указатель на предыдущее звено стека
    };
    NodeStack *pointBottom_; // Указатель на последний элемент стека
    int size_ = 0;


public:
    ~Stack() {Clear();}
    
    void Clear() {
        while(pointBottom_ != nullptr) { // Пока в стеке все ещё есть элементы
            NodeStack *tmp = pointBottom_;
            pointBottom_ = pointBottom_->pointPrevious_;
            delete tmp;
        }

    }

    void Push(const T &item) {
        NodeStack *node = new NodeStack{item, pointBottom_}; // Новое звено

        if(node == nullptr) {
            throw EStackException("No memory!");
        }

        pointBottom_ = node; //Делаем новое звено последним
        size_++;
    }

    const T Pop() {
        if(pointBottom_ == nullptr) { // Если стек пустой, выбрасываем исключение
            throw EStackEmpty();
        }

        const T item = pointBottom_->item_; //Сохраняем значение
        NodeStack *tmp = pointBottom_;
        pointBottom_ = pointBottom_->pointPrevious_; //Конец стека теперь на предпоследнем элементе
        delete tmp;
        size_--;
        return item;
    }

    int Size() {
        return size_;
    }

};

#endif // STACK_H
