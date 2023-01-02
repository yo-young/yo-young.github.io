#include <iostream>
#include <string>

using namespace std;

class Pizza {
    public:
        virtual void prepare() { };
        // virtual void bake() { };
        // virtual void cut() { };
        // virtual void box() { };
};

class CheesePizza  : public Pizza {
public:
    CheesePizza() {
        cout<<"cheese pizza!!"<<endl;
    }
    void prepare() {
        cout<<"prepare cheese pizza"<<endl;
    };
    void bake() {
        cout<<"baking cheese pizza"<<endl;
    }
};

class PepperoniPizza : public Pizza {
public:
    PepperoniPizza() {
        cout<<"Pepperoni pizza!!"<<endl;
    }
    void prepare() {
        cout<<"prepare Pepperoni pizza"<<endl;
    };
};

class ClamPizza : public Pizza {
public:
    ClamPizza() {
        cout<<"Clam pizza!!"<<endl;
    }
    void prepare() {
        cout<<"prepare ClamPizza pizza"<<endl;
    };
};

class SimplePizzaFactory
{
	public:
        Pizza createPizza(string type)
        {
            cout<<"create pizza!!"<<endl;
            Pizza *pizza;
            
            if( !type.compare("cheese") ) {
                pizza = new CheesePizza();
            }
            else if( !type.compare("pepperoni") ) {
                pizza = new PepperoniPizza();
            }
            else if( !type.compare("calm") ) {
                pizza = new ClamPizza();
            }
            
            return *pizza;
        }
};

class PizzaStore {
	SimplePizzaFactory factory;
    
    // PizzaStore 생성자의 파라미터로 factory 객체를 전달 받는다.
    public:
        Pizza orderPizza (string type) {
            Pizza pizza;
            
            pizza = factory.createPizza(type); // 팩토리를 써서 pizza 객체를 만든다.
            
            // pizza.prepare();
            // pizza.bake();
            // pizza.cut();
            // pizza.box();
            
            return pizza;
        };
};



int main()
{
    auto pizzaStore = new PizzaStore();
    auto cheesePizza = pizzaStore->orderPizza("cheese");
    cheesePizza.prepare();
    cheesePizza.bake();

	return 0;
}