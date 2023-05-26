#ifndef FUNCTIONS
#define FUNCTIONS

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class nsc {
 public:
  // convert decimal numbers with fractional parts into binary
  string decToBin(string dec) {
    double decimal = stod(dec);
    string bin = "";
    int integral = int(decimal);
    double fractional = decimal - integral;

    while (integral != 0) {
      bin = to_string(integral % 2) + bin;
      integral = integral / 2;
    }

    bin += ".";

    int counter = 0;
    while (fractional != 0 and counter < 10) {
      fractional = fractional * 2;
      int bit = int(fractional);
      bin += to_string(bit);
      fractional -= bit;
      counter++;
    }

    if (bin[bin.size() - 1] == '.')
      bin = bin.substr(0, bin.size() - 1);
    return bin;
  }

  // convert binary numbers with a fractional part into decimal
  string binToDec(string bin) {
    double dec = 0, base = 1;

    int dec_point = bin.find('.');
    if (dec_point == string::npos)
      dec_point = bin.size();

    for (int i = dec_point - 1; i >= 0; i--) {
      dec = dec + (bin[i] - '0') * base;
      base = base * 2;
    }

    base = 2;
    for (int i = dec_point + 1; i < bin.size(); i++) {
      dec = dec + (bin[i] - '0') / base;
      base *= 2;
    }
    if (dec == int(dec))
      return to_string(int(dec));
    return to_string(dec);
  }

  // convert a decimal number with a fraction to hexadecimal
  string decToHex(string dec) {
    double decimal = stod(dec);
    string hex = "";
    ll integral = ll(decimal);
    double fractional = decimal - integral;

    while (integral) {
      int rem = integral % 16;
      if (rem < 10)
        hex = to_string(rem) + hex;
      else
        hex = char('A' + rem - 10) + hex;
      integral = integral / 16;
    }

    if (fractional == 0)
      return hex;

    hex += '.';
    for (int i = 0; i < 10; i++) {
      fractional *= 16;
      int rem = int(fractional);
      fractional -= rem;
      if (rem < 10)
        hex = hex + to_string(rem);
      else
        hex = hex + string(1, 'A' + rem - 10);
    }

    return hex;
  }

  string hexToDec(string hex) {
    double dec = 0, base = 1;

    ll dec_point = hex.find('.');
    if (dec_point == string::npos)
      dec_point = hex.size();

    for (int i = dec_point - 1; i >= 0; i--) {
      if (hex[i] >= '0' and hex[i] <= '9')
        dec = dec + (hex[i] - '0') * base;
      else
        dec = dec + (hex[i] - 'A' + 10) * base;
      base *= 16;
    }

    base = 16;
    for (int i = dec_point + 1; i < hex.size(); i++) {
      dec += (hex[i] >= '0' and hex[i] <= '9') ? (hex[i] - '0') / base : (hex[i] - 'A' + 10) / base;
      base *= 16;
    }

    return to_string(dec);
  }

  // Convert decimal to octal
  string decToOct(string dec) {
    double decimal = stod(dec);
    string oct = "";
    int integral = int(decimal);
    double fractional = decimal - integral;

    while (integral) {
      oct = to_string(integral % 8) + oct;
      integral /= 8;
    }

    oct += ".";

    int counter = 0;
    while (fractional != 0 and counter < 10) {
      fractional *= 8;
      int bit = int(fractional);
      oct += to_string(bit);
      fractional -= bit;
      counter++;
    }

    if (oct[oct.size() - 1] == '.')
      oct = oct.substr(0, oct.size() - 1);
    return oct;
  }

  // Convert octal to decimal
  string octToDec(string oct) {
    double dec = 0, base = 1;

    int dec_point = oct.find('.');
    if (dec_point == string::npos)
      dec_point = oct.size();

    for (int i = dec_point - 1; i >= 0; i--) {
      dec += (oct[i] - '0') * base;
      base *= 8;
    }

    base = 8;
    for (int i = dec_point + 1; i < oct.size(); i++) {
      dec += (oct[i] - '0') / base;
      base *= 8;
    }

    return to_string(dec);
  }

  // Convert binary to octal
  string binToOct(string binary) {
    string octal = "";
    int point = binary.find('.');
    if (point == -1) point = binary.size();
    string intpart = binary.substr(0, point), decpart = binary.substr(point + 1);
    while (intpart.size() % 3) intpart = '0' + intpart;
    while (decpart.size() % 3) decpart += '0';
    ///////////////
    auto bin = [](string sub) {
      int num = 0;
      if (sub[0] == '1') num += 4;
      if (sub[1] == '1') num += 2;
      if (sub[2] == '1') num += 1;
      return to_string(num);
    };
    //////////////////////////
    for (int i = 0; i < intpart.size(); i += 3) {
      octal += bin(intpart.substr(i, 3));
    }
    octal += '.';
    for (int i = 0; i < decpart.size(); i += 3) {
      octal += bin(decpart.substr(i, 3));
    }
    if (octal.back() == '.') octal += '0';
    return octal;
  }

  string binToHex(string binary) {
    string hexadecimal = "";
    int point = binary.find('.');
    if (point == -1) point = binary.size();
    string intpart = binary.substr(0, point), decpart = binary.substr(point + 1);
    while (intpart.size() % 4) intpart = '0' + intpart;
    while (decpart.size() % 4) decpart += '0';
    ///////////////
    auto bin = [](string sub) {
      int num = 0;
      if (sub[0] == '1') num += 8;
      if (sub[1] == '1') num += 4;
      if (sub[2] == '1') num += 2;
      if (sub[3] == '1') num += 1;
      if (num < 10) return to_string(num);
      string hex = "";
      hex += (num - 10 + 'A');
      return hex;
    };
    //////////////////////////
    for (int i = 0; i < intpart.size(); i += 4) {
      hexadecimal += bin(intpart.substr(i, 4));
    }
    hexadecimal += '.';
    for (int i = 0; i < decpart.size(); i += 4) {
      hexadecimal += bin(decpart.substr(i, 4));
    }
    if (hexadecimal.back() == '.') hexadecimal += '0';
    return hexadecimal;
  }

  string octToBin(string octal) {
    string binary = "";
    auto bin = [](int bit) {
      string subbinary = "";
      while (bit) {
        subbinary += (bit % 2 + '0');
        bit /= 2;
      }
      while (subbinary.size() < 3) subbinary += '0';
      reverse(subbinary.begin(), subbinary.end());
      return subbinary;
    };
    for (int i = 0; i < octal.size(); i++) {
      if (octal[i] == '.')
        binary += '.';
      else
        binary += bin(octal[i] - '0');
    }
    return binary;
  }

  string hexToBin(string hexadecimal) {
    string binary = "";
    auto bin = [](int bit) {
      string subbinary = "";
      while (bit) {
        subbinary += (bit % 2 + '0');
        bit /= 2;
      }
      while (subbinary.size() < 4) subbinary += '0';
      reverse(subbinary.begin(), subbinary.end());
      return subbinary;
    };
    for (int i = 0; i < hexadecimal.size(); i++) {
      if (hexadecimal[i] == '.')
        binary += '.';
      else if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9')
        binary += bin(hexadecimal[i] - '0');
      else
        binary += bin(hexadecimal[i] - 'A' + 10);
    }
    return binary;
  }

  string hexToOct(string hexadecimal) {
    string octal = "";
    int point = hexadecimal.find('.');
    if (point == -1) point = hexadecimal.size();
    string intpart = hexadecimal.substr(0, point), decpart = hexadecimal.substr(point + 1);
    intpart = hexToBin(intpart);
    decpart = hexToBin(decpart);
    octal = binToOct(intpart + '.' + decpart);
    return octal;
  }
  string octToHex(string octal) {
    string hexadecimal = "";
    int point = octal.find('.');
    if (point == -1) point = octal.size();
    string intpart = octal.substr(0, point), decpart = octal.substr(point + 1);
    intpart = octToBin(intpart);
    decpart = octToBin(decpart);
    hexadecimal = binToHex(intpart + '.' + decpart);
    return hexadecimal;
  }
};

class gates {
 public:
  // AND gate
  bool _and(bool a, bool b) { return a and b; }

  // OR gate
  bool _or(bool a, bool b) { return a or b; }

  // NOT gate
  bool _not(bool a) { return !a; }

  // XOR gate
  bool _xor(bool a, bool b) { return a != b; }

  // NAND gate
  bool _nand(bool a, bool b) { return !_and(a, b); }

  // NOR gate
  bool _nor(bool a, bool b) { return !_or(a, b); }

  // XNOR gate
  bool _xnor(bool a, bool b) { return !_xor(a, b); }

  // Implication gate
  bool _imp(bool a, bool b) { return !a or b; }

  // Physics part 4

  // half adder
  // return {sum, carry}
  pair<bool, bool> _halfAdder(bool a, bool b) {
    return {_xor(a, b), _and(a, b)};
  }
  // full adder
  // take 2 bits and carry in
  // return {sum, carry_out}
  pair<bool, bool> _fullAdder(bool a, bool b, bool c) {
    return {_xor(_xor(a, b), c), _or(_and(_xor(a, b), c), _and(a, b))};
  }
  // half subtractor
  // take 2 bits
  // return {difference, borrow}
  pair<bool, bool> _halfSubtractor(bool a, bool b) {
    return {_xor(a, b), _and(_not(a), b)};
  }
  // full subtractor
  // take 3 bits
  // return {difference, borrow}
  pair<bool, bool> _fullSubtractor(bool a, bool b, bool c) {
    return {_xor(_xor(a, b), c), _or(_and(_xor(a, b), c), _and(_not(a), b))};
  }
};

class Complementer {
 public:
  int priority(char operant) {
    if (operant == '+' || operant == '-')
      return 1;
    else if (operant == '*' || operant == '/')
      return 2;
    else if (operant == '^')
      return 3;
    else
      return 0;
  }

  string InfixToPostfix(string expression) {
    string postfix = "";
    stack<char> s;
    for (int i = 0; i < expression.size(); i++) {
      if (expression[i] == ' ')
        continue;
      if (expression[i] == ')') {
        while (s.top() != '(') {
          postfix += s.top();
          s.pop();
        }
        s.pop();
      } else if (expression[i] == '(') {
        s.push(expression[i]);
      } else if (isdigit(expression[i]) || isalpha(expression[i]) || expression[i] == '\'') {
        postfix += expression[i];
      } else {
        if (s.empty())
          s.push(expression[i]);
        else if (s.top() == '(')
          s.push(expression[i]);
        else {
          while (!s.empty() && priority(s.top()) >= priority(expression[i])) {
            postfix += s.top();
            s.pop();
          }
          s.push(expression[i]);
        }
      }
    }
    while (!s.empty()) {
      postfix += s.top();
      s.pop();
    }
    return postfix;
  }

  string PostfixToInfix(string expression) {
    stack<string> s;
    for (int i = 0; i < expression.size(); i++) {
      if (expression[i] == ' ')
        continue;
      if (isdigit(expression[i]) || isalpha(expression[i])) {
        string op(1, expression[i]);
        if (expression[i + 1] == '\'') {
          op += '\'';
          s.push(op);
          i++;
        } else {
          s.push(op);
        }
      } else {
        string op1 = s.top();
        if (op1.back() == '\'')
          op1.pop_back();
        else if (op1.back() != ')')
          op1 += '\'';
        s.pop();
        string op2 = s.top();
        if (op2.back() == '\'')
          op2.pop_back();
        else if (op2.back() != ')')
          op2 += '\'';
        s.pop();
        if (expression[i] == '+')
          expression[i] = '*';
        else
          expression[i] = '+';
        s.push("(" + op2 + expression[i] + op1 + ")");
      }
    }
    return s.top();
  }

  string complement(string exp) {
    string converted;

    for (int i = 0; i <= exp.find('='); i++) {
      if (isalpha(exp[i]) && exp[i + 1] == '\'') {
        converted += exp[i];
        converted += exp[i + 1];
        converted += ' ';

        i++;
      } else if (isalpha(exp[i])) {
        converted += exp[i];
        converted += '\'';
        converted += ' ';
      } else
        converted += exp[i];
    }
    converted += ' ';

    exp = exp.substr(exp.find('=') + 1, exp.size());

    string a = InfixToPostfix(exp);
    string b = PostfixToInfix(a);

    for (int i = 0; i < b.size(); i++) {
      if (isalpha(b[i]) && b[i + 1] == '\'') {
        converted += b[i];
        converted += b[i + 1];
        converted += ' ';

        i++;
      } else if (isalpha(b[i])) {
        converted += b[i];
        converted += '\'';
        converted += ' ';
      } else
        converted += b[i];
    }
    return converted;
  }
};

#endif  // FUNCTIONS
