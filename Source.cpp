#include <iostream>
using namespace std;
class Date {
public:
    Date(int day = 1, int month = 1, int year = 1900) : day(day), month(month), year(year) {}
    void addDay() {
        day++;
        if (day > 30) { 
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
    Date& operator++() {
        addDay();
        return *this;
    }
    Date& operator+=(int days) {
        for (int i = 0; i < days; ++i) {
            addDay();
        }
        return *this;
    }
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }
    bool operator!=(const Date& other) const {
        return !(*this == other);
    }
    friend ostream& operator<<(ostream& os, const Date& date);
    friend istream& operator>>(istream& is, Date& date);
private:
    int day, month, year;
};
ostream& operator<<(ostream& os, const Date& date) {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}
istream& operator>>(istream& is, Date& date) {
    is >> date.day >> date.month >> date.year;
    return is;
}
int main() {
    Date today(22, 1, 2024);
    cout << "Today: " << today << endl;
    ++today;
    cout << "Tomorrow: " << today << endl;
    today += 5;
    cout << "Five days later: " << today << endl;
    return 0;
}