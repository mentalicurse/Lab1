#include <iostream>
using namespace std;

class Product
 {
 public:
 int price;
 Product(int p) { price = p; }
 };
 
 class Validation {
 public:
     virtual bool ProductValid(Product &product)=0;
 };

class CustomService: public Validation
{
    public:
    bool ProductValid(Product& product) override {
        return product.price > 100000;
    }
};

class BasicValid: public Validation
{
    public:
    bool ProductValid(Product& product) override {
        return product.price > 0;
    }
};

int main(){
    Product product(10000000);
    CustomService customvalid;
    BasicValid basicvalid;
    if (customvalid.ProductValid(product)) cout<<"valid"<<endl; else
    cout<<"not valid"<<endl;
    if (basicvalid.ProductValid(product)) cout<<"valid"<<endl; else
    cout<<"not valid"<<endl;
    return 0;
}
