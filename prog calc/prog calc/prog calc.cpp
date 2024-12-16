#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
enum enchoose { binary = 1, deci= 2, hexadecimal = 3, binary_operators = 4, hexadecimal_operators = 5 };


struct stbinary {
    string from_deci;
    string from_hexa;
};
struct stdeci {
    int from_binary = 0;
    int from_hexa = 0;
};
struct sthexa {
    string from_binary;
    string from_deci;
};
struct stoutput {
    sthexa hexa;
    stbinary binary;
    stdeci deci;
};
struct stinput {
    string hexa;
    string binary;
    int deci = 0;
    string hexa1;
    string binary1;
    int deci1 = 0;
    string hexa2;
    string binary2;
    int deci2 = 0;
};
static void myname();
static void menue();
void binarymenue();
void decimenue();
string binaryvalid(string binary);
string hexavalid(string hexa);
void hexamenue();
string binarydiff(string binary1, string binary2);
static enchoose readchoice(int& c);
int binarytodecimal(string binary);
string decitohexa(int deci);
string binarytohexa(string binary);
int hexatodeci(string hexadecimal);
string decimaltobinary(int decimal);
string hexatobinary(string hexa);
string binarysum(string binary1, string binary2);
string hexasum(string hexa1, string hexa2);
string hexadiff(string hexa1, string hexa2);
void procedure(enchoose choice);
int main() {
    stinput input;
        char answer;
    myname();
    do {
        system("cls");
        menue();
        int c;
        procedure(readchoice(c));
        answer = 'y';
        cout << "back to menue ? (Y/n) ";
        cin >> answer;
            bool isvalid = true;





    } while (answer == 'Y' || answer == 'y');
    cin.get();
    //cin.ignore();
    return 0;
}

static void myname() {
    string space;
    cout << "\n\n\n***------------------------- programmer calculator developed by ABODA Ayman -------------------------***";
    cout << "\n\n\n\npress any button + enter to continue....\n";
    cin >> space;
    system("cls");
}

static void menue() {
    cout << "\n\n\n\n------------------------ we need from you to choose which number system you will enter ------------------------ \n\n\n";
    cout << "   (1) ==>> binary\n" << endl;
    cout << "   (2) ==>> decimal\n" << endl;
    cout << "   (3) ==>> hexadeciamel\n" << endl;
    cout << "   (4) ==>> binary (+,-) binary \n" << endl;
    cout << "   (5) ==>> hexadeciamel (+,-) hexadecimal\n" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------\n\n\n";
}
void binarymenue() {
    cout << "---------------------------------------\n";
    cout << "   (1) ==>> to hexadecimal\n";
    cout << "---------------------------------------\n";
    cout << "   (2) ==>> to decimal\n";
    cout << "---------------------------------------\n";
}
void decimenue() {
    cout << "---------------------------------------\n";
    cout << "   (1) ==>> to hexadecimal\n";
    cout << "---------------------------------------\n";
    cout << "   (2) ==>> to binary\n";
    cout << "---------------------------------------\n";
}
void hexamenue() {
    cout << "---------------------------------------\n";
    cout << "   (1) ==>> to binary\n";
    cout << "---------------------------------------\n";
    cout << "   (2) ==>> to decimal\n";
    cout << "---------------------------------------\n";
}

static enchoose readchoice(int& c) {
    enchoose choice;
    cout << "   your choice :\n";
    cin >> c;
    while (c != 1 && c != 2 && c != 3 && c != 4 && c != 5) {
        cout << "   invalid choice, pls enter number from 1 to 5\n";
        cin >> c;
    }
    choice = enchoose(c);
    return choice;
}

int hexatodeci(string hexadecimal) {
    int deci = 0;
    int length = hexadecimal.length();
    for (int i = 0; i < length; i++) {
        int position = length - i - 1;
        int digitvalue;

        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            digitvalue = hexadecimal[i] - '0';
            deci += pow(16, position) * digitvalue;
        }

        else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            digitvalue = hexadecimal[i] - 'A' + 10;
            deci += pow(16, position) * digitvalue;
        }

        else if
            (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
            digitvalue = hexadecimal[i] - 'a' + 10;
            deci += pow(16, position) * digitvalue;
        }
    }
        return  deci;
}

string decimaltobinary(int decimal) {
    string binary = "";

    if (decimal == 0) {
        binary = '0';
    }
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary += to_string(remainder);
        decimal /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

string hexatobinary(string hexa) {
    int deci;
    string binary;
    binary = decimaltobinary(hexatodeci(hexa));
    return binary;
}

int binarytodecimal(string binary) {
    int decimal = 0;
    int length = binary.length();

 

    for (int i = 0; i < binary.length(); i++) {
        if (binary[i] == '1' || binary[i] == '0') {
            int digitvalue = binary[i] - '0';
            int position = length - i - 1;
            decimal += pow(2, position) * digitvalue;
        }
    }
    return decimal;
}


string decitohexa(int deci) {

    string hexa = "";

    if (deci == 0) {
        return "0";
    }
    while (deci > 0) {
        int remainder = deci % 16;
        if (remainder >= 0 && remainder <= 9) {
            hexa += char(remainder + '0');
        }
        else if (remainder >= 10 && remainder <= 15) {
            hexa += char(remainder + 'A' - 10);
        }
        deci /= 16;
    }
        reverse(hexa.begin(), hexa.end());
        return hexa;
}
string decitohexa1(int deci) {


    string hexa = "";
    int remainder = deci % 16;

    while (remainder > 0) {
        if (remainder >= 0 && remainder <= 9) {
            int hexadigit = remainder + '0';
            hexa += char(hexadigit);
        }
        else if (remainder >= 10 && remainder <= 15) {
            int hexadigit = remainder + 'A' - 10;
            hexa += char(hexadigit);
        }
        deci /= 16;
    }
        reverse(hexa.begin(), hexa.end());
        return hexa;
}



string binarytohexa(string binary) {
    
    int decimal = 0;
    int length = binary.length();
    string hexa = "";
     for (int i = 0; i < length; i++) {
        if (binary[i] == '1' || binary[i] == '0') {
            int digitvalue = binary[i] - '0';
            int position = length - i - 1;
            decimal += pow(2, position) * digitvalue;
        }
    }

    int remainder = decimal % 16;
    while (decimal > 0) {
        if (remainder >= 0 && remainder <= 9) {
            int hexadigit = remainder + '0';
            hexa += char(hexadigit);
            decimal /= 16;
        }
        else if (remainder >= 10 && remainder <= 15) {
            int hexadigit = remainder + 'A' - 10;
            hexa += char(hexadigit);
            decimal /= 16;
        }
    }
        reverse(hexa.begin(), hexa.end());
        return hexa;
 }

    string binarysum(string binary1, string binary2){
        int deci1, deci2, sum;
        bool valid = true;
        string tbinary;
        do {
            for (char c : binary1, binary2) {
                if (!(c == '1' || c == '0')) {
                    valid = false;
                    break;
                }
                else {
                    valid = true;
                }
            }
            if (valid == false) {
                cout << "invalid binary, try again\n";
                cin >> binary1 >> binary2;
            }
        } while (valid == false);

        deci1 = binarytodecimal(binary1);
        deci2 = binarytodecimal(binary2);
        sum = deci1 + deci2;
        tbinary = decimaltobinary(sum);
        return tbinary;
}
    string binarydiff(string binary1, string binary2){
        int deci1, deci2, diff;
        string tbinary;
        deci1 = binarytodecimal(binary1);
        deci2 = binarytodecimal(binary2);
        diff = abs(deci1 - deci2);
        tbinary = decimaltobinary(diff);
        return tbinary;
}

string hexasum(string hexa1,string hexa2) {
    
    int deci1, deci2, sum;
    bool valid = true;
    do {
        valid = true;
        for (char c : hexa1, hexa2) {
            if (!(c >= '0' && c <= '9' || c >= 'A' && c <= 'F' || c >= 'a' && c <= 'f')) {
                valid = false;
                break;
            }
            else {
                valid = true;
            }
        }
        if (valid == false) {
            cout << "   invalid hexadecimal, try again\n";
            cin >> hexa1 >> hexa2;
        }
    } while (valid == false);
    
    string tsum;
    deci1 = hexatodeci(hexa1);
    deci2 = hexatodeci(hexa2);
    sum = deci1 + deci2;
    tsum = decitohexa(sum);
    return tsum;
}

string hexadiff(string hexa1,string hexa2) {
    int deci1, deci2, diff;
    string tdiff;
    deci1 = hexatodeci(hexa1);
    deci2 = hexatodeci(hexa2);
    diff = abs(deci1 - deci2);
    tdiff = decitohexa(diff);
    return tdiff;
}


void procedure(enchoose choice)
{
    stinput input;
    stoutput output;

    if (choice == enchoose::binary) {
        string validedbinary;
        cout << "   enter binary number\n";
        validedbinary = binaryvalid(input.binary);
        cout << validedbinary;
            system("cls");
            binarymenue();
            int answer1;
            cin >> answer1;
            if (answer1 == 1) {
                system("cls");
                cout << "   ------------------------------------------------------------ \n";
                cout << "   | the hexadecimal of your binary is " << binarytohexa(validedbinary) << endl;
                cout << "   ------------------------------------------------------------ \n";
            }
            else if (answer1 == 2) {
                system("cls");
                cout << "   -----------------------------------------------------------\n";
                cout << "   | the decimal of your binary is " << binarytodecimal(validedbinary) << endl;
                cout << "   ------------------------------------------------------------ \n";

            }
    }

    else if (choice == enchoose::deci) {
        cout << "   enter a decimal number \n";
        cin >> input.deci;
        decimenue();
        int answer2;
        cin >> answer2;
            if (answer2 == 1) {
            output.deci.from_binary = binarytodecimal(input.binary);
            cout << "   ------------------------------------------------------------ \n";
            cout << "   | the hexadecimal of your decimal is " << decitohexa(input.deci) << endl;
            cout << "   ------------------------------------------------------------ \n";

            }
            else if (answer2 == 2) {

            cout << "   -----------------------------------------------------------\n";
            cout << "   | the binary of your decimal is " << decimaltobinary(input.deci) << endl;
            cout << "   ------------------------------------------------------------ \n";
            }
    }
    
    else if (choice == enchoose::hexadecimal) {
        string newhexa;
        cout << "   enter a hexadecimal number \n";
        cin >> input.hexa;
        system("cls");
        newhexa = hexavalid(input.hexa);
        cout << newhexa;
        system("cls");
        hexamenue();
        int answer3;
        cin >> answer3;
        if (answer3 == 1) {
            cout << "\n   ------------------------------------------------------------ \n";
            cout << "   | the binary of your hexadecimal is " << hexatobinary(newhexa) << endl;
            cout << "   ------------------------------------------------------------ \n";

        }
        else if (answer3 == 2) {

            cout << "   -----------------------------------------------------------\n";
            cout << "   | the decimal of your hexadecimal is " << hexatodeci(newhexa) << endl;
            cout << "   ------------------------------------------------------------ \n";
        }
    }
    else if (choice == enchoose::binary_operators) {
        string binary1, binary2;
        cout << "   enter binary number 1 then 2\n";
        cin >> binary1 >> binary2;
        string binarysumition = binarysum(binary1, binary2);
        string binarydiffs = binarydiff(binary1, binary2);
        cout << "\n   ------------------------------------------------------------ \n";
        cout << "   | the sum of your binary numbers is " << binarysumition << endl;
        cout << "   ------------------------------------------------------------ \n";
        cout << "   | the difference of your binary numbers is " << binarydiffs << endl;
        cout << "   ------------------------------------------------------------ \n";
        }

    else if (choice == enchoose::hexadecimal_operators) {
        string hexa1, hexa2, sum, diff;
        cout << "   enter hexadecimal numer 1 then 2\n";
        cin >> hexa1 >> hexa2;
        sum = hexasum(hexa1, hexa2);
        diff = hexadiff(hexa1, hexa2);
        cout << "\n   ------------------------------------------------------------ \n";
        cout << "   | the sum of your binary numbers is " << sum << endl;
        cout << "   ------------------------------------------------------------ \n";
        cout << "   | the difference of your binary numbers is " << diff << endl;
        cout << "   ------------------------------------------------------------ \n";
  
    }
}
string binaryvalid(string binary) {
    bool valid = true;
    cin >> binary;
    do {
        for (char c : binary) {
            if (!(c == '1' || c == '0')) {
                valid = false;
                break;
            }
            else {
                valid = true;
            }
        }
        if (valid == false) {
            cout << "   invalid binary, try again\n";
            cin >> binary;
        }
    }
    while (valid == false);
    
    return binary;
}

string hexavalid(string hexa) {
    bool valid = true;
    do {
        valid = true;
        for (char c : hexa) {
            if (!(c >= '0' && c <= '9' || c >= 'A' && c <= 'F' || c >= 'a' && c <= 'f')) {
                valid = false;
                break;
            }
            else {
                valid = true;
            }
        }
        if (valid == false) {
            cout << "   invalid hexadecimal, try again\n";
            cin >> hexa;

        }
    }
    while (valid == false);

    return hexa;
}