#include <iostream>
#include <iomanip>

using namespace std;

class Complex {
private:
    union {
        double re, im;
        Complex* next;
    };
    static Complex* headOfFreelist;
    static const int BSIZ = 256;
public:
    static void* operator new(size_t size);
    static void operator delete(void* deadobj, size_t size);
    // ...
};

Complex* Complex::headOfFreelist = 0;
const int Complex::BSIZ;

void* Complex::operator new(size_t size) {
    if (size != sizeof(Complex)) return ::operator new(size);

    Complex* p = headOfFreelist;

    if (p) {
        headOfFreelist = p->next;
    } else {
        Complex* newBlk = (Complex *)::operator new(BSIZ * sizeof(Complex));

        if (newBlk == 0) return 0;

        for (int i = 1; i < BSIZ - 1; ++i) newBlk[i].next = &newBlk[i + 1];

        newBlk[BSIZ - 1].next = 0;

        p = newBlk;
        headOfFreelist = &newBlk[1];
    }

    return p;
}

void Complex::operator delete(void* deadobj, size_t size) {
    if (deadobj == 0) return;

    if (size != sizeof(Complex)) {
        ::operator delete(deadobj);
        return;
    }

    Complex* dead = (Complex*)deadobj;
    dead->next = headOfFreelist;
    headOfFreelist = dead;
}

ostream& general(ostream& ostr) {
    ostr.setf(ios_base::fmtflags(0), ios_base::floatfield);
    return ostr;
}

void test00() {
    double pi = 3.1415;
    int i = 12345;
    double d = 3.1415;

    cout << pi << endl;
    cout << scientific << pi << endl;
    cout << pi << endl;
    cout << general << pi << endl;

    cout << setfill('_') << showbase;
    cout << setw(10) << dec << i;
    cout << setw(10) << oct << i;
    cout << setw(10) << hex << i << endl;
    cout << setprecision(3);
    cout << general << d << " ";
    cout << scientific << d << " ";
    cout << fixed << d << endl;
}

int main(){
    test00();

    return 0;
}