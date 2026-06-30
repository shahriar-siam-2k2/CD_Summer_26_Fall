#include <iostream>
using namespace std;

void numCheck (string text) {
    int n = text.length();
    bool numeric = true;
    for (int i=0 ; i<n ; i++) {
        int asciiVal = text[i];

        if(asciiVal < 48 || asciiVal > 58 ) {
            numeric = false;
            break;
        }
    }
    if (numeric) {
        cout << "Numeric Constant." << endl;
    }
    else {
        cout << "Not Numeric." << endl;
    }

}

int isOperator (string text) {
    int c = 0;
    for (int i=0 ; i<text.length() ; i++) {

        if(text[i] == '+' || text[i] == '-' || text[i] == '*' || text[i] == '/' || text[i] == '%' || text[i] == '=' ) {
            c++;
            cout << endl << "Operator" << c << ": " << text[i] << endl;
        }
    }
    cout << endl;
    return c;
}

void isComment(string text) {
    int n = text.length();

    if(n >= 2 && text[0] == '/' && text[1] == '/') {
        cout << endl << "Single line comment." << endl;
    }
    else if(n >= 4 && text[0] == '/' && text[1] == '*' && text[n-2] == '*' && text[n-1] == '/') {
        cout << endl << "Multi line comment." << endl;
    }
    else {
        cout << endl << "No comment detected!" << endl;
    }
}

bool isValidIdentifier(string text) {
    if (text.length() == 0) {
        return false;
    }

    int firstAscii = text[0];
    if (!((firstAscii >= 97 && firstAscii <= 122) || (firstAscii >= 65 && firstAscii <= 90) || firstAscii == 95)) {
        return false;
    }

    for (int i = 1; i < text.length(); i++) {
        int chAscii = text[i];
        if (!((chAscii >= 97 && chAscii <= 122) || (chAscii >= 65 && chAscii <= 90) || (chAscii >= 48 && chAscii <= 57) || chAscii == 95)) {
            return false;
        }
    }

    return true;
}

double getAverage(int arr[], int n) {
    if (n == 0) {
        return 0.0;
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum / n;
}

void findMinMax(int arr[], int n) {
    if (n == 0) {
        return;
    }

    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    cout << endl << "Minimum Value: " << minVal;
    cout << endl << "Maximum Value: " << maxVal << endl;
}

string getFullName(string firstName, string lastName) {
    return firstName + " " + lastName;
}

int main () {
    string text = "";
    int op;

    while(true) {
        cout << endl << "1. Numeric Check." << endl
            << "2. Operator Check." << endl
            << "3. Comment Check." << endl
            << "4. Identifier Check." << endl
            << "5. Find Average value from array." << endl
            << "6. Find Min-Max value from array." << endl
            << "7. Concatenate Name." << endl
            << "0. Exit" << endl;

        cout << endl << "Choose Operation: ";
        cin >> op;
        cout << endl;

        if(op == 1) {
            cout << "Enter text: ";
            cin >> text;

            numCheck(text);
        }
        else if(op == 2) {
            cout << "Enter text: ";
            cin >> text;

            if(isOperator(text) < 0) {
                cout << endl << "No Operator(s) detected!" << endl;
            }
        }
        else if(op == 3) {
            string line;
            cout << "Enter string (Type 'STOP' on a new line to finish):" << endl;

            while(getline(cin, line)) {
                if(line == "STOP") {
                    break;
                }
                text += line;
            }

            isComment(text);
        }
        else if(op == 4) {
            cout << "Enter text: ";
            cin >> text;

            if(isValidIdentifier(text)) {
                cout << endl << "Given input is Identifier." << endl;
            }
            else {
                cout << endl << "Given input is Not Identifier." << endl;
            }
        }
        else if(op == 5) {
            int n;
            cout << "Enter the size of the array: ";
            cin >> n;

            int arr[n];
            cout << "Enter the values: ";
            for(int i=0; i<n; i++) {
                cin >> arr[i];
            }

            cout << endl << "Average: " << getAverage(arr, n) << endl;
        }
        else if(op == 6) {
            int n;
            cout << "Enter the size of the array: ";
            cin >> n;

            int arr[n];
            cout << "Enter the values: ";
            for(int i=0; i<n; i++) {
                cin >> arr[i];
            }

            findMinMax(arr, n);
        }
        else if(op == 7) {
            string firstName, secondName;

            cout << "Enter First Name: ";
            cin >> firstName;

            cout << "Enter Second Name: ";
            cin >> secondName;

            cout << endl << "Full Name: " << getFullName(firstName, secondName) << endl;
        }
        else if(op == 0) {
            return 0;
        }
        else {
            cout << endl << "INVALID INPUT!" << endl;
        }
    }
}
