#include <string>
#include <iostream>

struct Person {
    int age;
    std::string name;

    Person(std::string name, int age = 0) {
        std::cout << "My name is " << name << std::endl;
        this->name = name;
    }
};

struct Student: virtual Person {
    int group;
    std::string department;

    Student(std::string name, std::string department): Person(name) {
        this->department = department;
        std::cout << "I am " << department << " student" << std::endl;
    }
};

struct Teacher: virtual Person {
    int group;
    std::string subject;
    std::string department;

    Teacher(std::string name, std::string subject, std::string department, int group = 0): Person(name) {
        std::cout << "I am " << subject << " teacher at the department " << department << std::endl;
        this->subject = subject;
        this->department = department;
    }
};

struct Karim: Student, Teacher {
    Karim(): Person("Karim"), Student("Karim", "ФРКТ"), Teacher("Karim Maratovich", "С++", "ФЭФМ") {}
};

int main() {
    Karim karim;
    std::cout << karim.Student::name << std::endl;
    std::cout << karim.Teacher::name << std::endl;
}

