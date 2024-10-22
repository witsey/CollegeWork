#include <iostream>
#include <memory>

class Object {
public:
    Object() {
        std::cout << "Object constructed." << std::endl;
    }

    ~Object() {
        std::cout << "Object destructed." << std::endl;
    }

    void DoSomething() {
        std::cout << "Object is doing something." << std::endl;
    }
};

class Owner {
private:
    std::shared_ptr<Object> ownedObject;

public:
    Owner() {
        ownedObject = std::make_shared<Object>();
        std::cout << "Owner constructed." << std::endl;
    }

    ~Owner() {
        std::cout << "Owner destructed." << std::endl;
    }

    void DoSomethingWithObject() {
        if (ownedObject) {
            ownedObject->DoSomething();
        } else {
            std::cout << "No object to do something with." << std::endl;
        }
    }
};




int main() {
    Owner* ownerPtr = new Owner();
    ownerPtr->DoSomethingWithObject();

    // Delete the owner object
    delete ownerPtr;
    ownerPtr = nullptr;

    // Attempt to access the object after the owner is deleted
    std::cout << "Trying to access the object after owner is deleted..." << std::endl;
    std::shared_ptr<Object> objectPtr = std::make_shared<Object>();
    objectPtr->DoSomething(); // This will cause an error since the object has been deleted

    return 0;
}



