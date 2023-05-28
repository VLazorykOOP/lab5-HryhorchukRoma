#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
class Tail {
public:
    Tail(int length) : length_(length) {}

    int get_length() const {
        return length_;
    }

private:
    int length_;
};

class Dog {
public:
    Dog(int tail_length, const string& color, int age)
        : tail_(tail_length), color_(color), age_(age) {}

    virtual ~Dog() {}

    const Tail& get_tail() const {
        return tail_;
    }

    const string& get_color() const {
        return color_;
    }

    int get_age() const {
        return age_;
    }

protected:
    Tail tail_;
    string color_;
    int age_;
};

class DomesticDog : public Dog {
public:
    DomesticDog(int tail_length, const string& color, int age, const string& name)
        : Dog(tail_length, color, age), name_(name) {}

    ~DomesticDog() {}

    void print() const {
        cout << "Кличка: " << name_ << endl;
        cout << "Колір: " << get_color() << endl;
        cout << "Вік: " << get_age() << endl;
        cout << "Довжина хвоста (см): " << get_tail().get_length() << endl;
    }

private:
    string name_;
};

int main() {
    SetConsoleOutputCP(1251);
    DomesticDog dog(7, "чорний", 5, "Арчі");
    dog.print();

    return 0;
}
