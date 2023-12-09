#include <iostream>
#include <string>
#include <list>
#include <ctime>

using namespace std;

class SaleItem {
    private:
        int id;
        double price;
        string description;
        int quantity;
    
    public:
        SaleItem(): id(0), price(0.0), description(""), quantity(1) {

        }

        ~SaleItem() = default;

        bool create(string new_description) {
            // generate a random id for this instance between 1 - 100
            id = rand() % 100 + 1;
            description = new_description;

            return true;
        }

        int getId() { return id; }
        double getPrice() { return price; }
        int getQuantity() { return quantity; }
        string getDescription() { return description; }

        void setPrice(double new_price) {
            price = new_price;
        }
        void setQuantity(double new_quantity) {
            quantity = new_quantity;
        }

        void purchase(int new_quantity) {
            quantity = quantity - new_quantity;
        }
};

int main () {
    // cout << "Cupcake point-of-sale system\n";
    list<SaleItem> inventory;
    list<SaleItem>::iterator it;
    string version = "v2.02";
    char input_option;
    double tax_rate = 0.0;

    srand(time(NULL));

    inventory.clear();

    // SaleItem test1;
    // test1.create("Vanilla");
    // test1.setPrice(4.95);
    // test1.setQuantity(5);
    // inventory.push_back(test1);

    while(1) {
        system("cls");
        cout << endl << endl;
        cout << "Cupcake POS - " << version << endl;
        cout << endl << endl;

        cout << "id | description | price | quantity in stock" << endl;
        for (it = inventory.begin(); it != inventory.end(); it++) {
            cout 
                << it -> getId() << " | "
                << it -> getDescription() << " | "
                << it  -> getPrice() << " | "
                << it -> getQuantity() << " | "
                << endl;            
        }

        if(inventory.empty()) {
            cout << "Add a new cupcake!" << endl;
        }
        
        cout << endl << endl;

        cout << "Tax Rate: " << tax_rate << "%" << endl;
        cout << "=================================" << endl;

        cout << "[a]dd a new cupcake" << endl;
        cout << "[c]omplete a cupcake purchase" << endl;
        cout << "[n]ew tax rate" << endl;
        cout << "[u]pdate cupcake quantity" << endl;
        cout << "[p]rice update of cupcake" << endl;
        cout << "[q]uit" << endl;

        cout << "choice: ";

        cin >> input_option;
        if(input_option == 'q') {
            cout << "Have a great day now!" << endl;
            break;
        }
        else if(input_option == 'a') {
            string new_description;
            double new_price;

            cout << "Enter new cupcake description: ";
            cin.clear();
            cin.ignore();
            getline(cin, new_description);

            cout << "Set new cupcake price: ";
            cin >> new_price;

            SaleItem item;
            item.create(new_description);
            item.setPrice(new_price);
            inventory.push_back(item);
        }
        else if(input_option == 'c') {
            int checkout_id, checkout_quantity;
            double total_amount, total_tax;

            cout << "Enter id of cupcake to purchase: ";
            cin >> checkout_id;

            for (it = inventory.begin(); it != inventory.end(); it++) {
                if(checkout_id == it -> getId())    {
                    cout << "Enter new quantity: ";
                    cin >> checkout_quantity;

                    if(checkout_quantity > it -> getQuantity()) {
                        cout << "Sorry not enough in stock" << endl;
                        system("pause");
                    }
                    else {
                        it -> purchase(checkout_quantity);

                        total_amount = checkout_quantity * it -> getPrice();
                        total_tax = total_amount * (tax_rate * 0.01);

                        cout << "Total Amount: " << total_amount << endl;
                        cout << "Tax: " << total_tax << endl;
                        cout << "Total Sale: " << total_amount + total_tax << endl;

                        system("pause");
                    }
                    break;
                }     
            }
        }
        else if (input_option == 'n') {
            cout << "Enter new tax rate: ";
            cin >> tax_rate;
        }
        else if(input_option == 'u') {
            int stock_id;
            int stock_quantity;

            cout << "Enter id of cupcake to update: ";
            cin >> stock_id;

            for (it = inventory.begin(); it != inventory.end(); it++) {
                if(stock_id == it -> getId())    {
                    cout << "Enter new quantity: ";
                    cin >> stock_quantity;

                    it -> setQuantity(stock_quantity);
                    break;
                }     
            }
        }
        else if(input_option == 'p') {
            int stock_id;
            double stock_price;

            cout << "Enter id of cupcake to update: ";
            cin >> stock_id;

            for (it = inventory.begin(); it != inventory.end(); it++) {
                if(stock_id == it -> getId())    {
                    cout << "Enter new price: ";
                    cin >> stock_price;

                    it -> setPrice(stock_price);
                    break;
                }     
            }
        }
    }

    return 0;
}