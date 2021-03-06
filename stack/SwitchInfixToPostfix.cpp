#include"linkedstack.h"
#include<fstream>

ifstream infile("infix.txt",ios::in);
ofstream outfile("postfix.txt",ios::out);

bool isdigit(char c,int &number){
    if(c >=48&&c<=57){
        infile.putback(c);
        infile >> number;
        return true;
    }
    else
        return false;
}

void igspaget(char &c){//跳过空过读取下一个字符
    while((c = infile.get()) == 32);
}

int isp(char c){
    switch(c){
        case '#': return 0;
        case '(': return 1;
        case '*':
        case '/':
        case '%': return 5;
        case '+':
        case '-': return 3;
        case ')': return 6;
    }
}

int icp(char c){
    switch(c){
        case '#': return 0;
        case '(': return 6;
        case '*':
        case '/':
        case '%': return 4;
        case '+':
        case '-': return 2;
        case ')': return 1;
    }
}

int main(){//启动函数
    LinkedStack<char> sta;sta.push('#');
    char ic,is;int number;igspaget(ic);
    while(sta.IsEmpty()== false || ic!='#'){
        if(isdigit(ic,number)) {outfile << " " << number;igspaget(ic);}
        else {
            sta.getTop(is);
            if(icp(ic)>isp(is)) {sta.push(ic);igspaget(ic);}
            else if(icp(ic)<isp(is)){sta.pop(is);outfile << " " << is;}
            else{sta.pop(is);if(is == '(') igspaget(ic);}
        }
    }
    outfile << '#' << "\n\n/*请在第一行输入后缀表达式，以#结尾！或者用SwitchInfixToPostfix.cpp生成后缀表达式*/";
    return 0;
}
