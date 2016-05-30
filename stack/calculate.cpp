#include"linkedstack.h"
#include<iostream>
#include<fstream>
using namespace std;

ifstream infile("postfix.txt",ios::in);
LinkedStack<double> s;

bool readnum(char &c,double &numb){
    while((c = infile.get()) == 32);
    if(c >=48&&c<=57){
        infile.putback(c);
        infile >> numb;
        return true;
    }
    else
        return false;
}

bool opera(char &op){
    double nu1,nu2,result;
    s.pop(nu2);s.pop(nu1);
    cout << "operate:" << op;
    cout << " number1:" << nu1;
    cout << " number2:" << nu2;
    switch(op){
    case '+': result = nu1+nu2;s.push(result);break;
    case '-': result = nu1-nu2;s.push(result);break;
    case '*': result = nu1*nu2;s.push(result);break;
    case '/': if(nu2!=0){result = nu1/nu2;s.push(result);break;}
              else {cout << "divide by 0!"<<endl;s.makeEmpty();return false;}
    }
    cout << " result:" << result << endl;
    return true;
}

int main(){
    double number; char ope; bool flag = false;
    while(flag == false){
        if(readnum(ope,number)) {s.push(number);cout << number << "by push!"<<endl;}
        else if(ope == 35) {s.pop(number);cout << "the last result:" << number<<endl;flag = true;}
        else {if(!opera(ope)) flag = true;};
    };
    return 0;
}
