#include <iostream>
#include <vector>
using namespace std;

int Jacobsthal(int n)
{
    
    if (n == 0)
        return 0;
 
 
    if (n == 1)
        return 1;
 
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

int main() {
    
    int last = 1;
    for (size_t i = 2; i < 8; i++)
    {
        int jacob = Jacobsthal(i);
        cout << jacob << " ";
        for (size_t j = jacob - 1; j > last; j--)
        {
            cout  << j << " ";
        }
        last = jacob;
        
    }
    cout << endl;
    
    return 0;
}
