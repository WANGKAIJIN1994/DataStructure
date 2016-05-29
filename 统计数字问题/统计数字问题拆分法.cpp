#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int n,x;
    int count[10] = {0};
    ifstream infile("input.txt");
    if(!infile)
    {
        cerr << "please create a new file:input.txt,and enter the page number" << endl;
    }
    infile >> n;
    infile.close();
    for(int i = n;i>0;i--)
    {
        x = i;
        while(x)
        {
            count[x%10]++;
            x /= 10;
        }
    }
    ofstream outfile("output.txt",ios::trunc);
    for(int i = 0; i < 10;i++)
    outfile << count[i] << endl;
    outfile.close();
}
