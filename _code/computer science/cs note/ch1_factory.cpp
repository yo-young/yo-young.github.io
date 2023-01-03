#include <iostream>
#include <string>

using namespace std;


class Pizza {
public:
    void getType() {
        cout<<"type : "<<pizzaType<<endl;
    }
public:
    string pizzaType = "";
};

class CheesePizza : public Pizza {
public:
    CheesePizza() {
        pizzaType = "cheese";
    }
};

class PepperoniPizza : public Pizza  {
public:
    PepperoniPizza() {
        pizzaType = "Pepperoni";
    }
};

class ClamPizza : public Pizza  {
public:
    ClamPizza() {
        pizzaType = "Clam";
    }
};

class PizzaFactory
{
public:
    Pizza* createPizza(string type) {
        Pizza* pizza;
        if(!type.compare("cheese")) pizza = new CheesePizza;
        if(!type.compare("pepperoni")) pizza = new PepperoniPizza;
        if(!type.compare("clam")) pizza = new ClamPizza;
        return pizza;
    }
};

int main()
{
    PizzaFactory factory;
    Pizza* cheesePizza = factory.createPizza("cheese");
    Pizza* pepperoni = factory.createPizza("pepperoni");
    cheesePizza->getType();
    pepperoni->getType();

	return 0;
}