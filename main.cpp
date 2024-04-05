#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Package {
private:
    string s_name;
    string s_address;
    string s_city;
    string s_state;
    string s_ZIPcode;
    string r_name;
    string r_address;
    string r_city;
    string r_state;
    string r_ZIPcode;
    double weight;
    double costperounce;

public:
    Package(string s_n, string s_addr, string s_cy, string s_st, string s_ZIP,
            string r_n, string r_addr, string r_cy, string r_st, string r_ZIP,
            double w, double cost) {
        s_name = s_n;
        s_address = s_addr;
        s_city = s_cy;
        s_state = s_st;
        s_ZIPcode = s_ZIP;
        r_name = r_n;
        r_address = r_addr;
        r_city = r_cy;
        r_state = r_st;
        r_ZIPcode = r_ZIP;
        if (w > 0.0 && cost > 0.0) {
            weight = w;
            costperounce = cost;
        } else {
            weight = 0.0;
            costperounce = 0.0;
        }
    }

    string getsender_name();
    string getsender_address();
    string getSendCity();
    string getsender_state();
    string getsender_ZIP();
    string getrecipient_name();
    string getrecipient_address();
    string getrecipient_city();
    string getrecipient_state();
    string getrecipient_ZIP();
    double getweight();
    double getcostperounce();
    double calculateCost();
};

string Package::getsender_name() { return s_name; }
string Package::getsender_address() { return s_address; }
string Package::getSendCity() { return s_city; }
string Package::getsender_state() { return s_state; }
string Package::getsender_ZIP() { return s_ZIPcode; }
string Package::getrecipient_name() { return r_name; }
string Package::getrecipient_address() { return r_address; }
string Package::getrecipient_city() { return r_city; }
string Package::getrecipient_state() { return r_state; }
string Package::getrecipient_ZIP() { return r_ZIPcode; }
double Package::getweight() { return weight; }
double Package::getcostperounce() { return costperounce; }

double Package::calculateCost() {
    double result;
    result = weight * costperounce;
    return result;
}

class TwoDayPackage : public Package {
private:
    double flat_fee;
public:
    TwoDayPackage(string s_n, string s_addr, string s_cy, string s_st, string s_ZIP,
                  string r_n, string r_addr, string r_cy, string r_st, string r_ZIP,
                  double w, double cost, double f_fee) : Package(s_n, s_addr, s_cy, s_st, s_ZIP, r_n,
                  r_addr, r_cy, r_st, r_ZIP, w, cost), flat_fee(f_fee) {}
    double calculateCost();
};

double TwoDayPackage::calculateCost() {
    double result;
    result = Package::calculateCost() + flat_fee;
    return result;
}

class OvernightPackage : public Package {
private:
    double additional_fee;
public:
    OvernightPackage(string s_n, string s_addr, string s_cy, string s_st, string s_ZIP,
                      string r_n, string r_addr, string r_cy, string r_st, string r_ZIP,
                      double w, double cost, double addl_fee) : Package(s_n, s_addr, s_cy, s_st, s_ZIP, r_n,
                      r_addr, r_cy, r_st, r_ZIP, w, cost), additional_fee(addl_fee) {}
    double calculateCost();
};

double OvernightPackage::calculateCost() {
    double result;
    result = (getcostperounce() + additional_fee) * getweight();
    return result;
}

int main() {
    string sname, saddr, scity, sstate, szip, rname, raddr, rcity, rstate, rzip;
    double w;
    cout << "Enter the sender Name: ";
    getline(cin, sname);
    cout << "Enter the sender Address: ";
    getline(cin, saddr);
    cout << "Enter the sender's city: ";
    getline(cin, scity);
    cout << "Enter the sender's state: ";
    getline(cin, sstate);
    cout << "Enter the sender ZIP code: ";
    getline(cin, szip);
    cout << "Enter the package weight: ";
    cin >> w;
    cin.ignore(); // to clear the newline character from the input buffer
    cout << "Enter the Receiver's Name: ";
    getline(cin, rname);
    cout << "Enter the Receiver's Address: ";
    getline(cin, raddr);
    cout << "Enter the Receiver's city: ";
    getline(cin, rcity);
    cout << "Enter the Receiver's state: ";
    getline(cin, rstate);
    cout << "Enter the Receiver's ZIP code: ";
    getline(cin, rzip);

    TwoDayPackage item2 = TwoDayPackage(sname, saddr, scity, sstate, szip, rname, raddr, rcity, rstate, rzip, w, 1.5, 1.10);
    OvernightPackage item1 = OvernightPackage(sname, saddr, scity, sstate, szip, rname, raddr, rcity, rstate, rzip, w, 1.5, 2.20);

    cout << fixed << setprecision(2);
    cout << endl;
    cout << "Overnight Delivery\n";
    cout << endl;
    cout << "Sender " << item1.getsender_name() << "\n";
    cout << " " << item1.getsender_address() << "\n";
    cout << " " << item1.getSendCity() << " " << item1.getsender_state() << " " << item1.getsender_ZIP() << "\n";
    cout << "\n";
    cout << "Recipient " << item1.getrecipient_name() << "\n";
    cout << " " << item1.getsender_address() << "\n";
    cout << " " << item1.getrecipient_city() << " " << item1.getrecipient_state() << " " << item1.getrecipient_ZIP() << "\n";
    cout << "Cost $ " << item1.calculateCost() << "\n";

    cout << "\n\n";
    cout << endl;
    cout << "2 Day Delivery\n";
    cout << "Sender " << item2.getsender_name() << "\n";
    cout << " " << item2.getsender_address() << "\n";
    cout << " " << item2.getSendCity() << " " << item2.getsender_state() << " " << item2.getsender_ZIP() << "\n";
    cout << "\n";
    cout << "Recipient " << item2.getrecipient_name() << "\n";
    cout << " " << item2.getsender_address() << "\n";
    cout << " " << item2.getrecipient_city() << " " << item2.getrecipient_state() << " " << item2.getrecipient_ZIP() << "\n";
    cout << "Cost $ " << item2.calculateCost() << "\n";
    cout << endl;

    return 0;
}
