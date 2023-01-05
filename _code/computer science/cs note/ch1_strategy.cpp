#include <iostream>
#include <algorithm>
#include <list>

class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
};

class KAKAOCardStrategy : public PaymentStrategy {
private:
    std::string name;
    std::string cardNumber;
    std::string cvv;
    std::string dateOfExpiry;

public:
    KAKAOCardStrategy(std::string nm, std::string ccNum, std::string cvv, std::string expiryDate) {
        this->name = nm;
        this->cardNumber = ccNum;
        this->cvv = cvv;
        this->dateOfExpiry = expiryDate;
    }

    void pay(int amount) {
        std::cout << amount << " paid using KAKAOCard." << std::endl;
    }
};

class LUNACardStrategy : public PaymentStrategy {
private:
    std::string emailId;
    std::string password;

public:
    LUNACardStrategy(std::string email, std::string pwd) {
        this->emailId = email;
        this->password = pwd;
    }

    void pay(int amount) {
        std::cout << amount << " paid using LUNACard." << std::endl;
    }
};

class Item {
private:
    std::string name;
    int price;

public:
    Item(std::string name, int cost) {
        this->name = name;
        this->price = cost;
    }

    std::string getName() {
        return name;
    }

    int getPrice() {
        return price;
    }
};

class ShoppingCart {
private:
    std::list<Item> items;

public:
    ShoppingCart() {
        this->items = std::list<Item>();
    }

    void addItem(Item item) {
        this->items.push_back(item);
    }

    // list의 삭제는 pop_front, pop_back 또는 erase(iterator)
    // void removeItem(Item item) {
    //     this->items.remove(item);
    // }

    int calculateTotal() {
        int sum = 0;
        for (Item item : items) {
            sum += item.getPrice();
        }
        return sum;
    }

    void pay(PaymentStrategy* paymentMethod) {
        int amount = calculateTotal();
        paymentMethod->pay(amount);
    }
};

int main() {
    ShoppingCart cart = ShoppingCart();

    Item A = Item("kundolA", 100);
    Item B = Item("kundolB", 300);

    cart.addItem(A);
    cart.addItem(B);

    // pay by LUNACard
    cart.pay(new LUNACardStrategy("kundol@example.com", "pukubababo"));
    // pay by KAKAOBank
    cart.pay(new KAKAOCardStrategy("Ju hongchul", "123456789", "123", "12/01"));

    return 0;
}