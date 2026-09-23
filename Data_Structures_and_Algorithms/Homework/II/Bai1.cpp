#include <iostream>
#include <iomanip>

using namespace std;

class Time {
	private:
	    int hour, minute, second;
	
	public:
	    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s){}
		void input();
		void display();
	    void setHour(int h);
	    void setMinute(int m);
	    void setSecond(int s);
	    int getHour();
	    int getMinute();
	    int getSecond();
};


void Time::input() {
    cout << "Nhap gio: ";
    cin >> hour;
    cout << "Nhap phut: ";
    cin >> minute;
    cout << "Nhap giay: ";
    cin >> second;
}

void Time::display() {
    cout << setfill('0')
         << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second << endl;
}

void Time::setHour(int h) {
    hour = h;
}

void Time::setMinute(int m) {
    minute = m;
}

void Time::setSecond(int s) {
    second = s;
}

int Time::getHour() {
    return hour;
}

int Time::getMinute() {
    return minute;
}

int Time::getSecond() {
    return second;
}


int main() {
    Time t;

    t.input();
    cout << "Thoi gian vua nhap: ";
    t.display();

    t.setHour(1);
    t.setMinute(12);
    t.setSecond(3);

    cout << "Thoi gian sau khi set (01:12:03): ";
    t.display();

    cout << "Gio hien tai: "  << t.getHour()   << endl;
    cout << "Phut hien tai: " << t.getMinute() << endl;
    cout << "Giay hien tai: " << t.getSecond() << endl;

    return 0;
}
