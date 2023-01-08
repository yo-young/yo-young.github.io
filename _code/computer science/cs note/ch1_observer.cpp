#include <iostream>
#include <algorithm>
#include <vector>

class Observer;

class Subject {
public:
    virtual void registerObserver(Observer* obj) = 0;
    virtual void unregisterObserver(Observer* obj) = 0;
    virtual void notifyObservers() = 0;
    virtual std::string getUpdate(Observer* obj) = 0;
};

class Observer {
public:
    virtual void update() = 0;
};

class Topic : public Subject {
private:
    std::vector<Observer*> observers;
    std::string message;

public:
    Topic() {
        this->observers = std::vector<Observer*>();
        this->message = "";
    }

    void registerObserver(Observer* obj) {
        if (std::find(observers.begin(), observers.end(), obj) == observers.end()) {
            observers.push_back(obj);
        }
    }

    void unregisterObserver(Observer* obj) {
        observers.erase(std::remove(observers.begin(), observers.end(), obj), observers.end());
    }

    void notifyObservers() {
        std::for_each(observers.begin(), observers.end(), [](Observer* observer) { observer->update(); });
    }

    std::string getUpdate(Observer* obj) {
        return this->message;
    }

    void postMessage(std::string msg) {
        std::cout << "Message sended to Topic: " << msg << std::endl;
        this->message = msg;
        notifyObservers();
    }
};

class TopicSubscriber : public Observer {
private:
    std::string name;
    Subject* topic;

public:
    TopicSubscriber(std::string name, Subject* topic) {
        this->name = name;
        this->topic = topic;
    }

    void update() {
        std::string msg = topic->getUpdate(this);
        std::cout << name << ":: got message >> " << msg << std::endl;
    }
};

int main() {
    Topic topic = Topic();
    Observer* a = new TopicSubscriber("a", &topic);
    Observer* b = new TopicSubscriber("b", &topic);
    Observer* c = new TopicSubscriber("c", &topic);
    topic.registerObserver(a);
    topic.registerObserver(b);
    topic.registerObserver(c);

    topic.postMessage("amumu is op champion!!");

    return 0;
}