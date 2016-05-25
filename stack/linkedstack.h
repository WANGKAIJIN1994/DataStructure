#include<iostream>
using namespace std;

template<class T>
class LinkedNode{
public:
    T data;
    LinkedNode<T> *link;
    LinkedNode(){link = NULL;};
    LinkedNode(T t,LinkedNode *linkednode):data(t),link(linkednode){};
};

template<class T>
class LinkedStack{
public:
    LinkedStack(){top = NULL;};
    ~LinkedStack(){makeEmpty();};
    void push(const T& d);
    bool pop(T& d);
    bool getTop(T& d)const;
    bool IsEmpty()const {return (top == NULL)? true:false;}
    int getSize()const;
    void makeEmpty();
    template<class CT>friend ostream& operator<<(ostream& output,const LinkedStack<CT>& sta);
private:
    LinkedNode<T> *top;
};

template<class T>
void LinkedStack<T>::makeEmpty(){
    LinkedNode<T> *tem;
    while(top!=NULL){
        tem = top;
        top = top->link;
        delete tem;
    }
};

template<class T>
void LinkedStack<T>::push(const T& d){
    top = new LinkedNode<T>(d,top);
}

template<class T>
bool LinkedStack<T>::pop(T& d){
    if(true==IsEmpty()) return false;
    d = top->data;
    LinkedNode<T> *tem = top;
    top = top->link;
    delete tem;
    return true;
};

template<class T>
bool LinkedStack<T>::getTop(T& d)const{
    if(true==IsEmpty()) return false;
    d = top->data;
    return true;
};

template<class T>
int LinkedStack<T>::getSize()const{
    LinkedNode<T> *tem = top;
    int number = 0;
    while(tem != NULL){
        number++;
        tem = tem->link;
    }
    return number;
};

template<class CT>
ostream& operator <<(ostream& output,const LinkedStack<CT>& sta){
    LinkedNode<CT> *tem = sta.top;
    while(tem != NULL){
        output << tem->data << " ";
        tem = tem->link;
    }
    return output;
};

