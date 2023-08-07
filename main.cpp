#include <iostream>
#include <vector>
#include "candy.h"

using std::vector;

template<typename Type>
class TD;


class Field {
public:
    int b;
};

class Mov {
public:

    Mov() = default;

    Mov(Mov &&mov) {
        std::cout << "move constr" << std::endl;
    }

    Mov &operator=(Mov &&mov) {
        std::cout << "move assign" << std::endl;
    }
};

std::ostream &operator<<(std::ostream &stream, const Mov &mov) {
    return stream << "mov";
}

template<class Cl>
class E {
public:
    explicit E(Cl &&cl) : ref(std::forward<Cl>(cl)) {
    };

    decltype(auto) head() {
        return std::move(ref[0]);
    }

private:
    Cl &&ref;
};

template<class A>
void lol(A a) {
    TD<A> b;
}

template<typename Container>
decltype(auto) head(Container &&ref) {
    return std::forward<Container>(ref)[0];
}

int main() {
    int x = 3;
    auto &&a = head(vector<int>{1, 2, 3});

}

template<typename T>
void print(const vector<T> &vec) {
    for (auto &element: vec) {
        std::cout << element << std::endl;
    }
}



