#include <iostream>
#include <string>
using namespace std;

// Step 1 - Select # Print Color (1 - 5) //
// Step 2 - 1 sided or 2 sided (2 sided is +3.00) //
// Step 3 - Select How Many [5 Ranges: 12-24, 25-49, 50-199, 200-299, else 300] //
// Step 4 - Size (3 Ranges: Youth, Adult S-XL, Adult 2XL-5XL)

int main() { 
  
  int shirtPrintColor;
  int shirtSided;
  int shirtNumber;
  string shirtSize;
  double shirtPrice;
  
  // prompts user to input values //
  cout << "1. Enter number of colors in the print (1 - 5): ";
  cin >> shirtPrintColor;
  if (shirtPrintColor < 1 || shirtPrintColor > 5) {
    cout << "Please enter a valid number of print colors between 1 and 5." << endl;
    return 0;
  }
  
  cout << "2. 1-sided or 2-sided (1 or 2): ";
  cin >> shirtSided;
  if (shirtSided < 1 || shirtSided > 2) {
    cout << "Please enter 1 or 2 for the 1 or 2 sided shirts option." << endl;
    return 0;
  }
  
  cout << "3. Number of shirts (12 - 299, contact us for 300+): ";
  cin >> shirtNumber;
  if (shirtNumber < 12) {
    cout << "A minimum of 12 shirts is required in order to make a purchase." << endl;
    return 0;
  } else if (shirtNumber >= 300) {
    cout << "For orders of 300 and over, please contact us for a custom quote." << endl;
    return 0;
  }
  
  cout << "4. Size (Youth, Adult, Adult+): ";
  cin >> shirtSize;
  if (shirtSize != "Youth" && shirtSize != "Adult" && shirtSize != "Adult+") {
    cout << "For sizes, please choose between Youth, Adult, or Adult+ (case sensitive)." << endl;
    return 0;
  }
  
  // Verify user input //
  cout << endl;
  cout << "You entered: " << endl;
  cout << "Number of colors in the print: " << shirtPrintColor << endl;
  cout << "Number of sides: " << shirtSided << endl;
  cout << "Number of shirts: " << shirtNumber << endl;
  cout << "Size of shirts: " << shirtSize << endl;
  
  // Calculate the price based on user input
  double basePrice = 0.0;
  
  if (shirtSize == "Youth") {
    if (shirtNumber >= 12 && shirtNumber <= 24) basePrice = 19.69;
    else if (shirtNumber >= 25 && shirtNumber <= 49) basePrice = 9.69;
    else if (shirtNumber >= 50 && shirtNumber <= 199) basePrice = 7.70;
    else if (shirtNumber >= 200 && shirtNumber <= 299) basePrice = 6.70;
  } else if (shirtSize == "Adult") {
    if (shirtNumber >= 12 && shirtNumber <= 24) basePrice = 19.99;
    else if (shirtNumber >= 25 && shirtNumber <= 49) basePrice = 9.99;
    else if (shirtNumber >= 50 && shirtNumber <= 199) basePrice = 8.00;
    else if (shirtNumber >= 200 && shirtNumber <= 299) basePrice = 7.00;
  } else if (shirtSize == "Adult+") {
    if (shirtNumber >= 12 && shirtNumber <= 24) basePrice = 21.64;
    else if (shirtNumber >= 25 && shirtNumber <= 49) basePrice = 11.64;
    else if (shirtNumber >= 50 && shirtNumber <= 199) basePrice = 9.65;
    else if (shirtNumber >= 200 && shirtNumber <= 299) basePrice = 8.65;
  }
  
  shirtPrice = basePrice + (shirtPrintColor - 1);
  
  if (shirtSided == 2) {
    shirtPrice += 3.00;
  }
  
  shirtPrice *= shirtNumber;
  
  cout << endl;
  // Final cost of single shirt option order
  cout << "Total Cost is: $" << shirtPrice << endl;

  return 0; 
}