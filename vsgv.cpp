#include <iostream>
#include <string>
using namespace std;

class Overcoat {
private:
    string type;  
    double price; 

public:
   
    Overcoat(string t = "Unknown", double p = 0.0) : type(t), price(p) {}

    
    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) { 
            type = other.type;
            price = other.price;
        }
        return *this;
    }

    
    bool operator==(const Overcoat& other) const {
        return type == other.type;
    }

    bool operator>(const Overcoat& other) const {
        return (type == other.type) && (price > other.price);
    }

    void display() const {
        cout << "Type: " << type << ", Price: " << price << " UAH\n";
    }
};

class Flat {
private:
    double area;  
    double price; 

public:
    
    Flat(double a = 0.0, double p = 0.0) : area(a), price(p) {}

   
    Flat& operator=(const Flat& other) {
        if (this != &other) {
            area = other.area;
            price = other.price;
        }
        return *this;
    }

    bool operator==(const Flat& other) const {
        return area == other.area;
    }

    bool operator>(const Flat& other) const {
        return price > other.price;
    }

    void display() const {
        cout << "Area: " << area << " m², Price: " << price << " UAH\n";
    }
};

int main() {
    Overcoat coat1("Coat", 2500);
    Overcoat coat2("Coat", 3000);

    cout << "Overcoat 1: "; coat1.display();
    cout << "Overcoat 2: "; coat2.display();

    cout << (coat1 == coat2 ? "Overcoat 1 and 2 are of the same type.\n" : "Overcoat 1 and 2 are of different types.\n");

    cout << (coat2 > coat1 ? "Overcoat 2 is more expensive than Overcoat 1.\n" : "Overcoat 2 is cheaper or the same price as Overcoat 1.\n");

    coat1 = coat2;
    cout << "After assignment, Overcoat 1: ";
    coat1.display();

    Flat flat1(50, 30000);
    Flat flat2(60, 35000);

    cout << "Flat 1: ";flat1.display();
    cout << "Flat 2: "; flat2.display();

    cout << (flat1 == flat2 ? "Flat 1 and 2 have the same area.\n" : "Flat 1 and 2 have different areas.\n");

    cout << (flat2 > flat1 ? "Flat 2 is more expensive than Flat 1.\n" : "Flat 2 is cheaper or the same price as Flat 1.\n");

    flat1 = flat2;
    cout << "After assignment, Flat 1: ";
    flat1.display();

    return 0;
}
