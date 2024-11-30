#include <iostream>
#include <memory>
#include <string>


class State {
public:
    virtual void handle() = 0;
    virtual ~State() = default;
};


class VendingMachine {
private:
    std::shared_ptr<State> currentState;

public:
    void setState(std::shared_ptr<State> state) {
        currentState = state;
    }

    void request() {
        if (currentState) {
            currentState->handle();
        }
        else {
            std::cout << "Стан не встановлений!" << std::endl;
        }
    }
};


class WaitingForCoin : public State {
public:
    void handle() override {
        std::cout << "Автомат чекає монету..." << std::endl;
    }
};


class SelectingProduct : public State {
public:
    void handle() override {
        std::cout << "Будь ласка, виберіть товар..." << std::endl;
    }
};


class DispensingProduct : public State {
public:
    void handle() override {
        std::cout << "Видаємо товар, дякуємо за покупку!" << std::endl;
    }
};


int main() {
    VendingMachine machine;

    auto waitingForCoin = std::make_shared<WaitingForCoin>();
    auto selectingProduct = std::make_shared<SelectingProduct>();
    auto dispensingProduct = std::make_shared<DispensingProduct>();


    machine.setState(waitingForCoin);
    machine.request();

    machine.setState(selectingProduct);
    machine.request();

    machine.setState(dispensingProduct);
    machine.request();

    return 0;
}
