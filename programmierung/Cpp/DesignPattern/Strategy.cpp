// Kapselt austauschbare Algorithmen in Klassen und 
// macht sie untereinander austauschbar.
//

#include <iostream>
#include <memory>
#include <vector>

struct Strategy {
    virtual int execute(int a, int b) const = 0;
    virtual ~Strategy() = default;
};

struct AddStrategy : Strategy {
    int execute(int a, int b) const override { return a + b; }
};

struct SubStrategy : Strategy {
    int execute(int a, int b) const override { return a - b; }
};
struct MulStrategy : Strategy {
    int execute(int a, int b) const override { return a * b; }
};
struct DivStrategy : Strategy {
    int execute(int a, int b) const override { return a / b; }
};

struct Context {
    Context(std::unique_ptr<Strategy> s) : strat(std::move(s)) {}
    int doIt(int a, int b) const { return strat->execute(a,b); }
private:
    std::unique_ptr<Strategy> strat;
};

int main() {
    Context ctxAdd(std::make_unique<AddStrategy>());
    std::cout << "5+3=" << ctxAdd.doIt(5,3) << "\n";
    Context ctxSub(std::make_unique<SubStrategy>());
    std::cout << "5-3=" << ctxSub.doIt(5,3) << "\n";

    std::vector<Context>  cs;
    cs.push_back(Context(std::make_unique<AddStrategy>()));
    cs.push_back(Context(std::make_unique<SubStrategy>()));
    cs.push_back(Context(std::make_unique<MulStrategy>()));
    cs.push_back(Context(std::make_unique<DivStrategy>()));

    for (const Context& c : cs)  {
        std::cout << "5 x 3 = " << c.doIt(5,3) << "\n";
    }

}

