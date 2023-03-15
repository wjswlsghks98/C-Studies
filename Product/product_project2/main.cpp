#include <iostream>
#include "Product.h"
using namespace std;

// This is the main method
int main(){
    // Construct an object of the product class
    Product product1;
    
    // Multiply 11 and 3 and store the result in a variable
    int output = product1.calculate(11, 3);

    // Display the result
    cout << "Output = " << output << endl;
    return 0;
}