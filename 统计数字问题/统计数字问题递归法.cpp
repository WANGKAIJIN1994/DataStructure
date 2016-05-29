#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

void countnumbers(int,int);
int count[10]= {0};

int main()
{
    ifstream infile("input.txt");
    if(!infile)
    {
        cerr << "please create a new file:input.txt,and enter the page number" << endl;
    }
    int n,m,o=0;
    double a;
    infile >> n;
    infile.close();
    m = log10(n) + 1;//n的位数
    countnumbers(n,m);
    for(int i=0; i<m; i++)
    {
        a = pow(10,i);
        o += int(a);//多计算的0
    }
    count[0] -= o;
    ofstream outfile("output.txt",ios::trunc);
    for(int i=0; i<10; i++)
    {
        outfile << count[i] << endl;
    }
    outfile.close();
}

void countnumbers(int n,int m)
{
    double x = pow(10,m-1);//区间的长度
    int h = n/int(x);//最高位数字
    double num = h*(m-1)*pow(10,m-2);//h个区间内每个数字的个数
    for(int i=0; i<10; i++)
    {
        count[i] += int(num);
    }
    for(int i=0; i<h; i++)
    {
        count[i] += int(x);//最高位上除了（最高位数字）的数字的次数
    }
    int y = n%int(x);//去掉最高位的数
    count[h] += (y+1);//最高位数字的次数
    if(m > 1) return countnumbers(y,m-1);//递归循环至一位数时跳出
}
