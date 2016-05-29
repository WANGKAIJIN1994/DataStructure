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
    m = log10(n) + 1;//n��λ��
    countnumbers(n,m);
    for(int i=0; i<m; i++)
    {
        a = pow(10,i);
        o += int(a);//������0
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
    double x = pow(10,m-1);//����ĳ���
    int h = n/int(x);//���λ����
    double num = h*(m-1)*pow(10,m-2);//h��������ÿ�����ֵĸ���
    for(int i=0; i<10; i++)
    {
        count[i] += int(num);
    }
    for(int i=0; i<h; i++)
    {
        count[i] += int(x);//���λ�ϳ��ˣ����λ���֣������ֵĴ���
    }
    int y = n%int(x);//ȥ�����λ����
    count[h] += (y+1);//���λ���ֵĴ���
    if(m > 1) return countnumbers(y,m-1);//�ݹ�ѭ����һλ��ʱ����
}
