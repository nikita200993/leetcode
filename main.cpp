#include <iostream>
#include <vector>
#include "rotate_array.h"

using std::vector;

using rotate_array::Solution;

template<typename T>
void print(const vector<T> &vec);

class A {
public:
    A() {
        std::cout << "created" << std::endl;
    }

    ~A() {
        std::cout << "goodbye" << std::endl;
    }
};

template<typename Type>
class TD;

template<typename A, size_t B>
int size(A(&)[B]) {
    return B;
}


class Kek {
    friend void swap(Kek &l, Kek &r);

public:
    Kek() = delete;

    Kek(Kek &&kek) noexcept: a(kek.a), moved(false) {
        std::cout << "move constructor" << std::endl;
        kek.moved = true;
    };

    Kek(int a) : a(a) {
        std::cout << "int constructor" << std::endl;
    };

    Kek &operator=(Kek &&kek) noexcept {
        std::cout << "move assign" << std::endl;
        this->a = kek.a;
        kek.moved = true;
        this->moved = false;
        return *this;
    };

    Kek &operator=(const Kek &kek) noexcept {
        std::cout << "copy assign" << std::endl;
        this->a = kek.a;
        return *this;
    };

    ~Kek() {
        if (!this->moved) {
            std::cout << "kek destructor" << std::endl;
        }
    }

    [[nodiscard]] int getA() const {
        return this->a;
    }

private:
    int a;
    bool moved{false};
};

void swap(Kek &l, Kek &r) {
    std::cout << "swap" << std::endl;
    std::swap(l.a, r.a);
    std::swap(l.moved, r.moved);
}

class Base {
public:
    virtual ~Base() {
        std::cout << "base destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        std::cout << "derived destructor" << std::endl;
    };

    Derived() {};

    Derived(Derived &&rhs) {

    };
};


int main() {
    auto a = Derived{};
    auto b = std::move(a);
}

template<typename T>
void print(const vector<T> &vec) {
    for (auto &element: vec) {
        std::cout << element << std::endl;
    }
}



