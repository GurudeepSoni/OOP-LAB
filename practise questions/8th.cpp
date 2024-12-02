#include <iostream>
#include <string>
using namespace std;

class vehicle{
    string brand;
    string model;
    int year;
    double rental_price;
    
    public:
        vehicle(string b, string m, int y, double price):brand(b),model(m),year(y),rental_price(price){}

        double get_rentalprice(int days){
            return rental_price*days;
        }
};

class car : public vehicle{
    private:
        int no_ofdoors;
    public:
        car(string b, string m, int y, double price, int doors):vehicle(b,m,y,price), no_ofdoors(doors){}

     double get_rentalprice(int days){
        double cost = vehicle::get_rentalprice(days);
        if (days > 7) {
            cost *= 0.95; // Apply 5% discount
        }
        return cost;
    }
};

class Motorcycle : public vehicle {
private:
    int engine_displacement;

public:
    Motorcycle(string b, string m, int y, double price, int displacement)
        : vehicle(b, m, y, price), engine_displacement(displacement) {}
    double get_rentalprice(int days){
        double cost = vehicle::get_rentalprice(days);
        if (days < 3) {
            cost *= 0.90; 
        }
        return cost;
    }
};

class Bicycle : public Motorcycle {
private:
    string frame_material;

public:
    Bicycle(string b, string m, int y, int displacement, string material)
        : Motorcycle(b, m, y, 200, displacement), frame_material(material) {}

    double get_rentalprice(int days) {
        return 200 * days; 
    }
};

// Main function
int main() {
  
    car car("Hyundai", "Grand i10", 2021, 500, 4);
    cout << "Car rental cost for 10 days: Rs " << car.get_rentalprice(10) << endl;

    Motorcycle motorcycle("Honda", "CBR", 2020, 300, 500);
    cout << "Motorcycle rental cost for 2 days: Rs " << motorcycle.get_rentalprice(2) << endl;

    Bicycle bicycle("Hero", "Ranger", 2022, 0, "Aluminium");
    cout << "Bicycle rental cost for 5 days: Rs " << bicycle.get_rentalprice(5) << endl;

    return 0;
}