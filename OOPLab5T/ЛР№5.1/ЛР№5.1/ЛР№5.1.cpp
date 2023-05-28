#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
class Animal {
public:
    Animal(string classification, int limbs, int offspring)
        : classification_(classification), limbs_(limbs), offspring_(offspring) {}

    virtual ~Animal() {}

    void print() const {
        cout << "Classification: " << classification_ << endl;
        cout << "Limbs: " << limbs_ << endl;
        cout << "Offspring: " << offspring_ << endl;
    }

protected:
    string classification_;
    int limbs_;
    int offspring_;
};

class DomesticAnimal : public Animal {
public:
    DomesticAnimal(string classification, int limbs, int offspring, string name)
        : Animal(classification, limbs, offspring), name_(name) {}

    ~DomesticAnimal() {}

    void print() const {
        Animal::print();
        cout << "Name: " << name_ << endl;
    }

    void rename(const string& new_name) {
        name_ = new_name;
    }

    void set_offspring(int offspring) {
        offspring_ = offspring;
    }

private:
    string name_;
};

int main() {
    SetConsoleOutputCP(1251);
    DomesticAnimal dog("Mammal", 4, 6, "Archie");
    dog.print();


    cout << "Enter the new name: ";
    string new_name;
    cin >> new_name;
    dog.rename(new_name);

    cout << "Enter the new number of offspring: ";
    int new_offspring;
    cin >> new_offspring;
    dog.set_offspring(new_offspring);

    dog.print();

    return 0;
}
