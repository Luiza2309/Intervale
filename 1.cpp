#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
const int mx=20;
int n;
double x[mx];
void citire()
{
    ifstream f("interval.in");
    f>>n;
    for(int i=0; i<n; i++)
        f>>x[i];
}
void sortare()
{
    bool ok;
    do
    {
        ok=true;
        for(int i=0; i<=n-2; i++)
            if(x[i]>x[i+1])
            {
                ok=false;
                swap(x[i],x[i+1]);
            }
    } while(!ok);
}
void greedy()
{
    double a=x[0];
    for(int i=0; i<n; i++)
    {
        if(i==0)
            cout<<'['<<x[0]<<", "<<x[0]+1<<']'<<' ';
        else
            if(x[i]>(a+1))
            {
                a=x[i];
                cout<<'['<<x[i]<<", "<<x[i]+1<<']'<<' ';
            }
    }
}
int main()
{
    citire();
    sortare();
    greedy();
}
