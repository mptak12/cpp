#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;
using std::ostream;
//waluta bazowa to PLN
//kursy sa w zlotowkach

class currency {
    string name;
    string sname;
    double buy{}, sell{};
    
public:
    currency(string n, string sn, double b, double s) { //konstruktor
        name = n;
        sname = sn;
        buy = b;
        sell = s;
    }

    auto get_name() const { return name; }
    auto get_sn() const { return sname; }
    auto get_b() const { return buy; }
    auto get_s() const { return sell; }
};

ostream& operator<<(ostream& os, currency& d) {
    os << "Full name: " << d.get_name() << "\nShort name: " << d.get_sn();
    os << "\nBUY: " << d.get_b() << " SELL: " << d.get_s() << endl;
    return os;
}

auto change(double value, currency start, currency end) { //zmienia z jednej z 3 walut na inna
    double postv= value * start.get_b() / end.get_b();
    cout << value << start.get_sn() << " to " << postv << end.get_sn();
    return postv;
}

//void chngtxt(auto change) {
//    cout << change.value;// << start.get_sn() << " to " << postv << end.get_sn();
//}

int main()
{
    double val{ 1000 };
    currency dol("Dolar amerykanski", "USD" , 4.1535, 4.1829);
    currency eu("Euro", "EUR", 4.6585, 4.6886);
    currency funt("Funt", "GPB", 5.5155, 5.6269);
   // cout<<change(val, dol, eu);
   // cout << endl;
    //cout<<change(val, funt, eu);
    change(val, funt, eu);
    //cout << "\nPLN to USD change\nEnter value in PLN:\n";
    //cin >> val;
    //cout << plntousd(val, dol);
    //cout << "Do you want to buy or sell?\n";
   

}


