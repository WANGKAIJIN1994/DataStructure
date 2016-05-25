#include"linkedstack.h"

int main()
{
    //测试结点类
    LinkedNode<int> *i;
    i = new LinkedNode<int>;
    i->data = 100;
    LinkedNode<int> linkedNode(5,i);
    LinkedNode<int> linkedNode1(6,&linkedNode);
    LinkedNode<int> *p = &linkedNode1;
    while(p != NULL){
        cout << p->data << endl;
        p = p->link;}
    //测试栈类
    LinkedStack<int> linkstack;
    LinkedStack<char> linkstack1; char x;
    linkstack.push(1);linkstack.push(2);linkstack.push(3);linkstack.push(4);linkstack.push(5);
    linkstack1.push('a');linkstack1.push('2');linkstack1.push('s');linkstack1.push('g');linkstack1.push('h');linkstack1.pop(x);
    cout << linkstack.getSize() << endl;
    cout << linkstack1.getSize() << x << endl;
    cout << linkstack << "\n" << linkstack1 << "\n";
    linkstack1.makeEmpty();
    cout << linkstack1.getSize() << linkstack1.pop(x);
}
