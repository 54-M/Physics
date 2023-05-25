#include <bits/stdc++.h>
#include <windows.h>

#include "../includes/functions.hpp"

using namespace std;

void main_scr() {
  cout << "\n===================================================" << '\n';
  cout << "Welcome to the Number Systems Conversion and Logic Gates Program!" << '\n';
  cout << "===================================================" << '\n';
  cout << "Please select an option:" << '\n';
  cout << "1. Number Systems Conversion" << '\n';
  cout << "2. Logic Gates" << '\n';
  cout << "3. Complement Function" << '\n';
  cout << "4. Exit" << '\n';
  cout << "===================================================" << '\n';
}

void nsc_scr() {
  cout << "\n==================================" << '\n';
  cout << "Number Systems Conversion" << '\n';
  cout << "==================================" << '\n';
  cout << "Please select the base:" << '\n';
  cout << "1. Binary" << '\n';
  cout << "2. Decimal" << '\n';
  cout << "3. Octal" << '\n';
  cout << "4. Hexadecimal" << '\n';
  cout << "5. Go back to the main menu" << '\n';
  cout << "==================================" << '\n';
}

void conv_tool(int b1, int b2) {
  nsc conv;
  string number;

  cout << "Enter the number you want to convert: ";
  cin >> number;

  switch (b1) {
    case 1:  // Binary
      switch (b2) {
        case 2:  // Binary to Decimal
          cout << "Result: " << conv.binToDec(number) << '\n';
          break;
        case 3:  // Binary to Octal
          cout << "Result: " << conv.binToOct(number) << '\n';
          break;
        case 4:  // Binary to Hexadecimal
          cout << "Result: " << conv.binToHex(number) << '\n';
          break;
        default:
          cout << "Invalid base selection!" << '\n';
          break;
      }
      break;
    case 2:  // Decimal
      switch (b2) {
        case 1:  // Decimal to Binary
          cout << "Result: " << conv.decToBin(number) << '\n';
          break;
        case 3:  // Decimal to Octal
          cout << "Result: " << conv.decToOct(number) << '\n';
          break;
        case 4:  // Decimal to Hexadecimal
          cout << "Result: " << conv.decToHex(number) << '\n';
          break;
        default:
          cout << "Invalid base selection!" << '\n';
          break;
      }
      break;
    case 3:  // Octal
      switch (b2) {
        case 1:  // Octal to Binary
          cout << "Result: " << conv.octToBin(number) << '\n';
          break;
        case 2:  // Octal to Decimal
          cout << "Result: " << conv.octToDec(number) << '\n';
          break;
        case 4:  // Octal to Hexadecimal
          cout << "Result: " << conv.octToHex(number) << '\n';
          break;
        default:
          cout << "Invalid base selection!" << '\n';
          break;
      }
      break;
    case 4:  // Hexadecimal
      switch (b2) {
        case 1:  // Hexadecimal to Binary
          cout << "Result: " << conv.hexToBin(number) << '\n';
          break;
        case 2:  // Hexadecimal to Decimal
          cout << "Result: " << conv.hexToDec(number) << '\n';
          break;
        case 3:  // Hexadecimal to Octal
          cout << "Result: " << conv.hexToOct(number) << '\n';
          break;
        default:
          cout << "Invalid base selection!" << '\n';
          break;
      }
      break;
    default:
      cout << "Invalid base selection!" << '\n';
      break;
  }

  Sleep(1000);  // Pause for 1 second
}

void gates_src() {
  cout << "\n===================" << '\n';
  cout << "Logic Gates" << '\n';
  cout << "===================" << '\n';
  cout << "Please select a logic gate:" << '\n';
  cout << "1. AND" << '\n';
  cout << "2. OR" << '\n';
  cout << "3. NOT" << '\n';
  cout << "4. XOR" << '\n';
  cout << "5. NAND" << '\n';
  cout << "6. NOR" << '\n';
  cout << "7. XNOR" << '\n';
  cout << "8. Implication" << '\n';
  cout << "9. Go back to the main menu" << '\n';
  cout << "===================" << '\n';
}

void gates_tool(int n) {
  gates gate;
  bool a, b, r;

  cout << "Enter input 1 (0 or 1): ";
  cin >> a;
  cout << "Enter input 2 (0 or 1): ";
  cin >> b;

  switch (n) {
    case 1:  // AND gate
      r = gate._and(a, b);
      cout << "Result: " << r << '\n';
      break;
    case 2:  // OR gate
      r = gate._or(a, b);
      cout << "Result: " << r << '\n';
      break;
    case 3:  // NOT gate
      r = gate._not(a);
      cout << "Result: " << r << '\n';
      break;
    case 4:  // XOR gate
      r = gate._xor(a, b);
      cout << "Result: " << r << '\n';
      break;
    case 5:  // NAND gate
      r = gate._nand(a, b);
      cout << "Result: " << r << '\n';
      break;
    case 6:  // NOR gate
      r = gate._nor(a, b);
      cout << "Result: " << r << '\n';
      break;
    case 7:  // XNOR gate
      r = gate._xnor(a, b);
      cout << "Result: " << r << '\n';
      break;
    case 8:  // Implication gate
      r = gate._imp(a, b);
      cout << "Result: " << r << '\n';
      break;
    default:
      cout << "Invalid gate selection!" << '\n';
      break;
  }

  Sleep(1000);  // Pause for 1 second
}

void complement_tool() {
  string s;
  cout << "Enter the function you want to complement: ";
  getline(cin, s);

  cout << "Complement: " <<  << '\n';
  Sleep(1000);  // Pause for 1 second
}

int main() {
  int choice;
  int b1, b2;
  // for exit from the program
  bool flag = false;

  while (!flag) {
    main_scr();
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:  // Number Systems Conversion
        while (true) {
          Sleep(1000);  // Pause for 1 second
          nsc_scr();
          cout << '\n';
          cout << '\n';
          cout << "Enter the base you want to convert from or press 5 to return to the main menu: ";
          cin >> b1;
          if (b1 == 5) break;  // Go back to the main menu

          cout << "Enter the base you want to convert to: ";
          cin >> b2;

          conv_tool(b1, b2);
          Sleep(1000);  // Pause for 1 second

          cout << "Do you want to continue? (Y/N): ";
          char cont;
          cin >> cont;
          if (cont != 'Y' && cont != 'y') {
            Sleep(700);
            break;
          }
        }
        break;
      case 2:  // Logic Gates
        while (true) {
          gates_src();
          cout << "Enter your choice: ";
          cin >> choice;

          if (choice == 9) {
            break;  // Go back to the main menu
          }

          gates_tool(choice);

          cout << "Do you want to continue? (Y/N): ";
          char continueChoice;
          cin >> continueChoice;
          if (continueChoice != 'Y' && continueChoice != 'y') {
            Sleep(700);
            break;
          }
        }
        break;
      case 3:  // Complement Function
        complement_tool();
        break;
      case 4:  // Exit Program
        flag = true;
        break;
      default:
        cout << "Invalid choice! Please try again." << '\n';
        break;
    }
  }
}