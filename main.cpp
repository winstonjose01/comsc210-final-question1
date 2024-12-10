# include <iostream>
# include <string>
# include <deque>
# include <vector>
# include <queue>
using namespace std;


struct CoffeeNode {
    string customerName;
    string drinkOrder;
    CoffeeNode* next;
};