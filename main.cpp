// COMS210 | Final Exam Question 1 | Winston Jose

# include <iostream>
# include <string>
# include <deque>
# include <vector>
# include <queue>
# include <ctime>
using namespace std;
 
// functin prototypes
string getRandomName();
string getRandomOrder(const string& type);
void queueCoffee(CoffeeNode*& head, const string& name, const string& order);
void dequeueCoffee(CoffeeNode*& head);
void displayCoffeeQueue(CoffeeNode* head);

struct CoffeeNode {
    string customerName;
    string drinkOrder;
    CoffeeNode* next; // Pointer to the next node in the linked list
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

string getRandomOrder(const string &type){
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

// Add a customer to the end of the coffee queue
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

// Remove the customer at the front of the coffee queue
void dequeueCoffee(CoffeeNode*& head) {
    if (head) {
        CoffeeNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Display all customers in the coffee queue
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

    // Muffin Booth: Deque 
    deque<Customer> muffinQueue;
    for (int i = 0; i < 3; ++i) {
        muffinQueue.push_back({getRandomName(), getRandomOrder("muffin")});
    }

    // Bracelet Booth: Vector queue
    vector<Customer> braceletQueue;
    for (int i = 0; i < 3; ++i) {
        braceletQueue.push_back({getRandomName(), getRandomOrder("bracelet")});
    }

    // Gadget Booth: Deque queue
    deque<Customer> gadgetQueue;
    for (int i = 0; i < 3; ++i) {
        gadgetQueue.push_back({getRandomName(), getRandomOrder("gadget")});
    }

    for (int round = 1; round <= 10; ++round){
        cout << "\n=== Round " << round << " ===\n";

        // Coffee Booth logics
        cout << "Coffee Booth: ";
        if (head) {
            cout << "Serving " << head->customerName << " (" << head->drinkOrder << ")\n";
            dequeueCoffee(head);
        } else {
            cout << "No customers to serve\n";
        }

        if (rand() %2 == 0) queueCoffee(head, getRandomName(),getRandomOrder("coffee"));
        

        // Muffin Booth logic
        cout << "Muffin Booth: ";
        if (!muffinQueue.empty()) {
            cout << "Serving " << muffinQueue.front().customerName << " (" << muffinQueue.front().order << ")\n";
            muffinQueue.pop_front();
        } else {
            cout << "No customers to serve\n";
        }
        if (rand() % 2 == 0) muffinQueue.push_back({getRandomName(), getRandomOrder("muffin")});

         // Bracelet Booth logic
        cout << "Bracelet Booth: ";
        if (!braceletQueue.empty()) {
            cout << "Serving " << braceletQueue.front().customerName << " (" << braceletQueue.front().order << ")\n";
            braceletQueue.erase(braceletQueue.begin());
        } else {
            cout << "No customers to serve\n";
        }
        if (rand() % 2 == 0) braceletQueue.push_back({getRandomName(), getRandomOrder("bracelet")});

        // Gadget Booth logic
        cout << "Gadget Booth: ";
        if (!gadgetQueue.empty()) {
            cout << "Serving " << gadgetQueue.front().customerName << " (" << gadgetQueue.front().order << ")\n";
            gadgetQueue.pop_front();
        } else {
            cout << "No customers to serve\n";
        }
        if (rand() % 2 == 0) gadgetQueue.push_back({getRandomName(), getRandomOrder("gadget")});
    }

    while (head) dequeueCoffee(head);

    return 0;
}