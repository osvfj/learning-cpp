#include <iostream>

using namespace std;

int main()
{
    int edades[3][2] = {{1,2},{9,8},{14,21}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<edades[i][j]<<endl;
        }
    }
}
