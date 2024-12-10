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
    else{
        string gadgets[] = {"Phone Charger","USB Drive","Speakers","Headphones","Power Banks"};
        rand_num = rand() % 5;
        return gadgets[rand_num];
    }

}

void queueCoffee (CoffeeNode* &head, const string& name, const string&order){
    CoffeeNode* newNode = new CoffeeNode{name, order, nullptr};
    if (!head) {
        head = newNode;
    } else {
        CoffeeNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void dequeueCoffee(CoffeeNode*& head) {
    if (head) {
        CoffeeNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void displayCoffeeQueue(CoffeeNode* head) {
    while (head) {
        cout << head->customerName << " (" << head->drinkOrder << ") ";
        head = head->next;
    }
}

int main(){
    srand(time(0));

    CoffeeNode * head = nullptr;
     
     // Coffee Booth - Linked List
     for (int i = 0; i < 3; ++i){
        queueCoffee(head, getRandomName(), getRandomOrder("coffee"));
     }

    deque<Customer> muffinQueue;
    for (int i = 0; i < 3; ++i) {
        muffinQueue.push_back({getRandomName(), getRandomOrder("muffin")});
    }

    vector<Customer> braceletQueue;
    for (int i = 0; i < 3; ++i) {
        braceletQueue.push_back({getRandomName(), getRandomOrder("bracelet")});
    }

    deque<Customer> gadgetQueue;
    for (int i = 0; i < 3; ++i) {
        gadgetQueue.push_back({getRandomName(), getRandomOrder("gadget")});
    }

    for (int round = 1; round <= 10; ++round){
        cout << "\n=== Round " << round << " ===\n";

        // Coffee Booth
    cout << "Coffee Booth: ";
        if (head) {
            std::cout << "Serving " << head->customerName << " (" << head->drinkOrder << ")\n";
            dequeueCoffee(head);
        } else {
            std::cout << "No customers to serve\n";
        }

        if (rand() %2 == 0) queueCoffee(head, getRandomName(),getRandomOrder("coffee"))

    }

    return 0;
}