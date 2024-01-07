#include <iostream>
#include <iterator>
#include <vector>
 
void print(int id, const std::vector<int>& container)
{
    std::cout << id << ". ";
    for (const int x : container)
        std::cout << x << ' ';
    std::cout << '\n';
}
 
int main ()
{
    std::vector<int> c1(2, 100);
    print(1, c1);
	
}