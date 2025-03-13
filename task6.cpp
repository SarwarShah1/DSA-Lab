#include <iostream>
using namespace std;

class carbonfootprint {
public:
    virtual double getcarbonfootprint() = 0;
    virtual ~carbonfootprint() {}
};

class electricity : public carbonfootprint {
    double bill, months, price_per_kwh, emissions_factor;
public:
    electricity(double b, double m) : bill(b), months(m),price_per_kwh(8.0),emissions_factor(1.37) {}
    double getcarbonfootprint() {
        return (bill / price_per_kwh) * emissions_factor * months;
    }
};

class naturalgas : public carbonfootprint {
    double bill, months, price_per_cubic_feet, emissions_factor;
public:
    naturalgas(double b, double m) : bill(b), months(m),price_per_cubic_feet(3.0),emissions_factor(120.61) {}
    double getcarbonfootprint() {
        return (bill / price_per_cubic_feet) * emissions_factor * months;
    }
};

class vehicle : public carbonfootprint {
    double miles, weeks, fuel_eff, co2_per_gallon, other_emissions;
public:
    vehicle(double m, double w, double f, double c, double o)
        : miles(m), weeks(w), fuel_eff(f), co2_per_gallon(c), other_emissions(o) {}
    
    double getcarbonfootprint() {
        return ((miles * weeks) / fuel_eff) * co2_per_gallon * other_emissions;
    }
};

void display(carbonfootprint* obj) {
    cout << "carbon footprint: " << obj->getcarbonfootprint() << " pounds of co2\n";
}

int main() {
    electricity e(2000, 12);
    naturalgas n(1500, 12);
    vehicle v(200, 52, 25, 19.6, 1.05);

    display(&e);
    display(&n);
    display(&v);
    
    return 0;
}
