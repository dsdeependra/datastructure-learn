#include <iostream>
using namespace std;
class Test
{
public:
void Print(){ cout<<"Test";}
};
int main()
{
Test t[2];
for (int i=0; i<2; i++)
t[i].Print();
}
