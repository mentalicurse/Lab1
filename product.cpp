#include <iostream>
using namespace std;

class Product
{
    int price;
public:
    Product(int p) { price = p;}
    ~Product() {};
    int getPrice() { return price;}
};

class Validation {
public:
    virtual bool ProductValid(int product) = 0;
};

class CustomService : public Validation
{
public:
    bool ProductValid(int product) override {
        return product > 100000;
    }
};

class BasicValid : public Validation
{
public:
    bool ProductValid(int product) override {
        return product > 0;
    }
};

int main() {
    Product product(200000);
    CustomService customvalid;
    BasicValid basicvalid;
    if (customvalid.ProductValid(product.getPrice())) cout << "product(customsevice) is valid" << endl; else
        cout << "product(customsevice) is not valid" << endl;
    if (basicvalid.ProductValid(product.getPrice())) cout << "product(basic) is valid" << endl; else
        cout << "product(basic) is not valid" << endl;
    return 0;
}
