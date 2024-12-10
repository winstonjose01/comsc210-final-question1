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
    string names[] = {"Alice", "John", "Bill", "Dianne", "Evan"};
    int rand_num = rand() % 5;
    return names[rand_num];
}

string getRandomOrder(string &type){
    int rand_num;
    if (type == "coffee"){
        string drinks[] = {"Latte","Cappucino","Expresso","Mocha","Americano"};
        rand_num = rand() % 5;
        return drinks[rand_num];
    }
    else if (type == "muffin"){
        string muffins[] = {"Blueberry","Chocolate Chip","Banana Nut","Lemon","Apple"};
        rand_num = rand() % 5;
        return muffins[rand_num];
    }
    else if (type == "bracelet"){
        string bracelets[] = {"Beaded","Leather","Gold","Silver","Woven"};
        rand_num = rand() % 5;
        return bracelets[rand_num];
    }
    else
        string gadgets[] = {"P","Leather","Gold","Silver","Woven"};
        rand_num = rand() % 5;
        return bracelets[rand_num];
}

int main(){
    srand(time(0));

    CoffeeNode * head = nullptr;
     
     // Coffee Booth - Linked List
     for (int i = 0; i < 3; ++i){
        queueCoffee(head, getRandomName(); getRandomOrder("coffee");)
     }


    return 0;
}