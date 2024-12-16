
#include <iostream>
#include <string>
using namespace std;

int main() {
    string ingredients[5] = {"Salt", "Pepper", "Sugar", "Flour"};
    int size = 5;
    
    cout << "Current ingredients:" << endl;
    for(int i = 0; i < size; i++) {
        cout << ingredients[i] << " ";
    }
    cout << endl;
    
    string newIngredient;
    cout << "Enter a new ingredient to prepend: ";
    cin >> newIngredient;
    
    // Shift elements right and remove last one
    for(int i = size - 1; i > 0; i--) {
        ingredients[i] = ingredients[i-1];
    }
    ingredients[0] = newIngredient;
    
    cout << "Updated ingredients:" << endl;
    for(int i = 0; i < size; i++) {
        cout << ingredients[i] << " ";
    }
    cout << endl;
    
    return 0;
}