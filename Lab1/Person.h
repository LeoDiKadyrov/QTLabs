#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
class Person {
private:
    std::string last_name;
    std::string first_name;
    std::string patronimic;
public:
    Person() {}

    Person(std::string firstName, std::string lastName, std::string patronimic_) {
        first_name = firstName;
        last_name = lastName;
        patronimic = patronimic_;
    }

    Person(const Person& person) {
        last_name = person.getLastName();
        first_name = person.getFirstName();
        patronimic = person.getPatronimic();
    }

    Person &operator= (Person const& arg) {
        if(this != &arg) {
            first_name = arg.getFirstName();
            last_name = arg.getLastName();
            patronimic = arg.getPatronimic();
        }
        return *this;
    }

    ~Person() {}

    std::string getFullName() {
        std::string fullName;
        fullName.append(last_name).append(1, ' ')
                .append(first_name).append(1, ' ')
                .append(patronimic);
        return fullName;
    }

    const std::string getLastName() const { return last_name; }

    const std::string getFirstName() const { return first_name; }

    const std::string getPatronimic() const { return patronimic; }

    void setLastName(std::string namePart) {
        last_name = namePart;
    }

    void setFirstName(std::string namePart) {
        first_name = namePart;
    }

    void setPatronimic(std::string namePart) {
        patronimic = namePart;
    }
};
#endif // PERSON_H
