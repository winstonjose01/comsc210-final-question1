# include <iostream>
# include <string>
# include <deque>
# include <vector>
# include <queue>
# include <ctime>
using namespace std;


struct CoffeeNode {
    string customerName;
    string drinkOrder;
    CoffeeNode* next;
};

struct Customer {
    string customerName;
    string order;
};

string getRandomName() {
    string names[] = {"Alice", "John", "Bill", "Dianne", "Evan", "Lily"};
    int rand_num = rand() % 5;
    return names[rand_num];
}

string getRandomOrder(){
    if ()
}

int main(){
    srand(time(0));

    CoffeeNode * head = nullptr;
     
     // Coffee Booth

    return 0;
}