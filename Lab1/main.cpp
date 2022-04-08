#include <QCoreApplication>
#include "Person.h"
#include "PersonKeeper.h"
#include <iostream>
#include <string>
#include <fstream>
#include <EStackEmpty.h>
#include <EStackException.h>
#include <Stack.h>

int main() {
    //Stack
    /*
    Stack<int> Stack;
    Stack.Push(1);
    Stack.Push(2);
    Stack.Push(3);
    Stack.Push(4);
    Stack.Push(5);

    std::cout << Stack.Size() << std::endl;

    int d = Stack.Pop();

    std::cout << d << std::endl;
    std::cout << Stack.Size() << std::endl;

    Stack.Push(5);
    int bib = Stack.Pop();
    std::cout << bib << std::endl;
    std::cout << Stack.Size() << std::endl; */


    //Part Two
    PersonKeeper* keeper = PersonKeeper::getInstance();

    Stack<Person> personStack = keeper->readPerson("C:\\Tipo disc D\\Programming\\QT\\QTLabs\\Lab1\\file.txt");

    //Check last person on the stack
    Person lastPerson = personStack.Pop();

    std::cout << lastPerson.getFullName() << std::endl;

    keeper->writePerson(personStack);

    return 1;
}
