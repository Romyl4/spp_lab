#include <iostream>
#include <vector>
#include <string>

class Product {
protected:
    std::string name;
    double weight;
    double price;
    int quantity;

public:
    Product(const std::string& n, double w, double p, int q)
        : name(n), weight(w), price(p), quantity(q) {}

    virtual ~Product() {}

    virtual void display() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Weight: " << weight << " kg" << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
    }

    void setName(const std::string& n) {
        name = n;
    }

    void setWeight(double w) {
        weight = w;
    }

    void setPrice(double p) {
        price = p;
    }

    void setQuantity(int q) {
        quantity = q;
    }
};

class SpecializedProduct : public Product {
private:
    std::string category;
    std::string manufacturer;

public:
    SpecializedProduct(const std::string& n, double w, double p, int q,
        const std::string& cat, const std::string& man)
        : Product(n, w, p, q), category(cat), manufacturer(man) {}

    void display() const override {
        Product::display();
        std::cout << "Category: " << category << std::endl;
        std::cout << "Manufacturer: " << manufacturer << std::endl;
    }
};

class Database {
private:
    std::vector<Product*> products;

public:
    ~Database() {
        for (auto product : products) {
            delete product;
        }
    }

    void addProduct(Product* product) {
        products.push_back(product);
    }

    void removeProduct(int index) {
        if (index >= 0 && index < products.size()) {
            delete products[index];
            products.erase(products.begin() + index);
        }
    }

    void displayAll() const {
        for (const auto& product : products) {
            product->display();
            std::cout << "-----------------------" << std::endl;
        }
    }

    void addProductFromInput() {
        std::string name, category, manufacturer;
        double weight, price;
        int quantity;

        std::cout << "Enter product name: ";
        std::cin >> name;
        std::cout << "Enter product weight (kg): ";
        std::cin >> weight;
        std::cout << "Enter product price ($): ";
        std::cin >> price;
        std::cout << "Enter product quantity: ";
        std::cin >> quantity;
        Product* product = new Product(name, weight, price, quantity);
        addProduct(product);
    }

    void removeProductByIndex() {
        int index;
        std::cout << "Enter index of product to remove: ";
        std::cin >> index;
        removeProduct(index);
    }
};

int main() {
    Database db;

    char choice;
    do {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Add a product" << std::endl;
        std::cout << "2. Remove a product" << std::endl;
        std::cout << "3. Display all products" << std::endl;
        std::cout << "4. Quit" << std::endl;

        std::cin >> choice;

        switch (choice) {
        case '1':
            db.addProductFromInput();
            break;
        case '2':
            db.removeProductByIndex();
            break;
        case '3':
            db.displayAll();
            break;
        case '4':
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice! Please choose again." << std::endl;
        }
    } while (choice != '4');

    return 0;
}
