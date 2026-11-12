
#include <bits/stdc++.h>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart {
private:
    vector<Product> products;

public:
    void addProduct(Product p) {
        products.push_back(p);
    }

    const vector<Product>& getProducts() const {
        return products;
    }

    double calculateTotal() const {
        double total = 0;

        for (const auto& p : products) {
            total += p.price;
        }

        return total;
    }
};

class SaveToDB {
public:
    void save(ShoppingCart* cart) {
        cout << "Saved with amount: "
             << cart->calculateTotal() << endl;
    }
};

int main() {
    Product p1("Laptop", 50000);
    Product p2("Mouse", 1000);
    Product p3("Keyboard", 2000);

    ShoppingCart cart;

    cart.addProduct(p1);
    cart.addProduct(p2);
    cart.addProduct(p3);

    cout << "Total amount: "
         << cart.calculateTotal() << endl;

    SaveToDB db;
    db.save(&cart);

    return 0;
}
