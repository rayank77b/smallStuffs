#include <iostream>
#include <queue> 
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

int main(){
    queue<int> q;

    q.push(3);
    q.push(23);

    queue<int> q2(q);

    std::cout<<"queue size: "<<q.size()<<std::endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop(); // pop dont return data!!!!
    }

    // differnce between emplace and push
    // emplace create object. push need a created object
    queue<Node> qn;
    Node n1(23);
    qn.push(n1);   // added object
    qn.emplace(23); // added integer, then it will create Node Object
                    // similar to push(Node(23))

    stack<int> si;

    si.push(23);
    si.push(40);
    si.push(2344);
    cout<<"stack.pop: "<<si.top()<<endl;
    return 0;
}