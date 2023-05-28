#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
class Education {
public:
    Education(const string& institution, const string& degree, int year=0)
        : institution_(institution), degree_(degree), year_(year) {}

    virtual ~Education() {}

    virtual void print() const {
        cout << "Навчальний заклад: " << institution_ << endl;
        cout << "Ступінь: " << degree_ << endl;
        cout << "Рік закінчення: " << year_ << endl;
    }

    friend ostream& operator<<(ostream& os, const Education& education) {
        os << "Навчальний заклад: " << education.institution_ << endl;
        os << "Ступінь: " << education.degree_ << endl;
        os << "Рік закінчення: " << education.year_ << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Education& education) {
        cout << "Введіть навчальни заклад: ";
        getline(is, education.institution_);
        cout << "Введіть ступінь: ";
        getline(is, education.degree_);
        cout << "Введіть рік закінчення: ";
        is >> education.year_;
        return is;
    }

    Education(const Education& other) {
        institution_ = other.institution_;
        degree_ = other.degree_;
        year_ = other.year_;
    }

    Education& operator=(const Education& other) {
        if (this != &other) {
            institution_ = other.institution_;
            degree_ = other.degree_;
            year_ = other.year_;
        }
        return *this;
    }

protected:
    string institution_;
    string degree_;
    int year_;
};

class HigherEducation : public Education {
public:
    HigherEducation(const string& institution, const string& degree, int year, const string& specialization)
        : Education(institution, degree, year), specialization_(specialization) {}

    ~HigherEducation() {}

    void print() const override {
        Education::print();
        cout << "Спеціалізація: " << specialization_ << endl;
    }

    friend ostream& operator<<(ostream& os, const HigherEducation& education) {
        os << static_cast<const Education&>(education);
        os << "Спеціалізація: " << education.specialization_ << endl;
        return os;
    }

    friend istream& operator>>(istream& is, HigherEducation& education) {
        is >> static_cast<Education&>(education);
        cout << "Введіть спеціалізацію: ";
        std::getline(is, education.specialization_);
        return is;
    }

    HigherEducation(const HigherEducation& other) : Education(other) {
        specialization_ = other.specialization_;
    }

    HigherEducation& operator=(const HigherEducation& other) {
        if (this != &other) {
            Education::operator=(other);
            specialization_ = other.specialization_;
        }
        return *this;
    }

private:
    string specialization_;
};

int main() {
    SetConsoleOutputCP(1251);
    Education education("Університет", "Бакалавр", 2020);
    cout << education << endl;
    cin >> education;
    cout << education << endl;

    HigherEducation higher_education("Університет", "Магістр", 2022, "Інформаційні технології");
    cout << higher_education << endl;
    cin >> higher_education;
    cout << higher_education << endl;

    return 0;
}
