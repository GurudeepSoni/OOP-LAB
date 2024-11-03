#include <iostream>

using namespace std;

class Product {
protected:
    int productID;
    string name;
    float price;
public:
    Product(int pid, string name, float price) : productID(pid), name(name), price(price) {}

    virtual void displayProductDetails() const {
        cout << "Product Info: ID = " << productID << ", Name = " << name << ", Price = " << price;
    }
    virtual ~Product() {}
};
class Electronics : public Product {
private:
    int warrantyPeriod;

public:
    Electronics(int pid, string name, float price, int warranty) : Product(pid, name, price), warrantyPeriod(warranty) {}

    void displayProductDetails() const override {
        Product::displayProductDetails();
        cout << ", Warranty = " << warrantyPeriod << " years" << endl;
    }
};

class Furniture : public Product {
private:
    string materialType;

public:
    Furniture(int pid, string name, float price, string material) : Product(pid, name, price), materialType(material) {}

    void displayProductDetails() const override {
        Product::displayProductDetails();
        cout << ", Material = " << materialType << endl;
    }
};

int main() {
    Product* products[2];

    products[0] = new Electronics(101, "Smartphone", 500.00, 2);
    products[1] = new Furniture(201, "Sofa", 300.00, "Wood");

    for (int i = 0; i < 2; ++i) {
        if (auto* e = dynamic_cast<Electronics*>(products[i])) {
            e->displayProductDetails();
        } else if (auto* f = dynamic_cast<Furniture*>(products[i])) {
            f->displayProductDetails();
        }
    }
    for (int i = 0; i < 2; ++i) {
        delete products[i];
    }
    return 0;
}