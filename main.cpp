#include <iostream>
#include <string>

using namespace std;

class Package {
protected:
    string senderName;
    string senderAddress;
    string senderCity;
    string senderState;
    string senderZip;
    string recipientName;
    string recipientAddress;
    string recipientCity;
    string recipientState;
    string recipientZip;
    double weight;
    double costPerOunce;

public:
    Package(const string& senderName, const string& senderAddress, const string& senderCity,
            const string& senderState, const string& senderZip, const string& recipientName,
            const string& recipientAddress, const string& recipientCity, const string& recipientState,
            const string& recipientZip, double weight, double costPerOunce)
        : senderName(senderName), senderAddress(senderAddress), senderCity(senderCity),
          senderState(senderState), senderZip(senderZip), recipientName(recipientName),
          recipientAddress(recipientAddress), recipientCity(recipientCity), recipientState(recipientState),
          recipientZip(recipientZip), weight(max(weight, 0.0)), costPerOunce(max(costPerOunce, 0.0)) {}

    virtual double calculateCost() const {
        return weight * costPerOunce;
    }
};

class TwoDayPackage : public Package {
private:
    double flatFee;

public:
    TwoDayPackage(const string& senderName, const string& senderAddress, const string& senderCity,
                  const string& senderState, const string& senderZip, const string& recipientName,
                  const string& recipientAddress, const string& recipientCity, const string& recipientState,
                  const string& recipientZip, double weight, double costPerOunce, double flatFee)
        : Package(senderName, senderAddress, senderCity, senderState, senderZip, recipientName,
                  recipientAddress, recipientCity, recipientState, recipientZip, weight, costPerOunce),
          flatFee(flatFee) {}

    double calculateCost() const override {
        return Package::calculateCost() + flatFee;
    }
};

class OvernightPackage : public Package {
private:
    double additionalFeePerOunce;

public:
    OvernightPackage(const string& senderName, const string& senderAddress, const string& senderCity,
                     const string& senderState, const string& senderZip, const string& recipientName,
                     const string& recipientAddress, const string& recipientCity, const string& recipientState,
                     const string& recipientZip, double weight, double costPerOunce, double additionalFeePerOunce)
        : Package(senderName, senderAddress, senderCity, senderState, senderZip, recipientName,
                  recipientAddress, recipientCity, recipientState, recipientZip, weight, costPerOunce),
          additionalFeePerOunce(additionalFeePerOunce) {}

    double calculateCost() const override {
        return Package::calculateCost() + (weight * additionalFeePerOunce);
    }
};

int main() {
    // Testing the classes
    Package package("Sender Name", "Sender Address", "Sender City", "Sender State", "Sender Zip",
                    "Recipient Name", "Recipient Address", "Recipient City", "Recipient State", "Recipient Zip",
                    10, 0.5);

    cout << "Package Cost: $" << package.calculateCost() << endl;

    TwoDayPackage twoDayPackage("Sender Name", "Sender Address", "Sender City", "Sender State", "Sender Zip",
                                "Recipient Name", "Recipient Address", "Recipient City", "Recipient State", "Recipient Zip",
                                10, 0.5, 10);

    cout << "Two Day Package Cost: $" << twoDayPackage.calculateCost() << endl;

    OvernightPackage overnightPackage("Sender Name", "Sender Address", "Sender City", "Sender State", "Sender Zip",
                                      "Recipient Name", "Recipient Address", "Recipient City", "Recipient State", "Recipient Zip",
                                      10, 0.5, 1);

    cout << "Overnight Package Cost: $" << overnightPackage.calculateCost() << endl;

    return 0;
}
