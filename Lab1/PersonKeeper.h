#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include "Person.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>

/*Based on the Singleton pattern*/

class PersonKeeper {
protected:
    static PersonKeeper* personKeeper_;

public:
    //The static method that controls access to the instance
    static PersonKeeper* getInstance() {
        if (personKeeper_ == nullptr) {
            personKeeper_ = new PersonKeeper();
        }
        return personKeeper_;
    }

    //Read information about person
    Stack<Person> readPerson(std::string name) {
        Stack<Person> personStack;
        std::ifstream file(name);

        if(!file) {
            //throw EStackException("Error: CANNOT OPEN THE FILE!");
            throw "Error: CANNOT OPEN THE FILE!";
        }

        std::string firstName;
        std::string lastName;
        std::string patronimic;

        //Until the end of the file, full names pushed onto the stack
        while(!file.eof()) {
            file >> lastName >> firstName >> patronimic;
            Person person(firstName, lastName, patronimic);
            personStack.Push(person);
        }

        file.close();

        return personStack;
    }

    //Write the information from the stack onto the flow
    void writePerson(Stack<Person> personStack) {
        std::ofstream file("C:\\Tipo disc D\\Programming\\QT\\QTLabs\\Lab1\\writeFile.txt");
        Stack<Person> stackCopy(personStack);
        while(stackCopy.Size() > 0) {
            Person person = stackCopy.Pop();
            std::string fullName = person.getFullName();
            file << fullName << std::endl;
        }

        file.close();
    }

    //The Singleton's constuctor should be hidden from the client code
private:
    PersonKeeper() {}
    ~PersonKeeper() {}
    //No need realizations:
    PersonKeeper(PersonKeeper const&);
    PersonKeeper& operator= (PersonKeeper const&);
};

PersonKeeper* PersonKeeper::personKeeper_ = nullptr;

#endif // PERSONKEEPER_H
