// Sam Cook
// Programming 1
// 10/23/20
// Day of the week
// This program allows the user to enter a valid date and will return the day of the week for that date.

#include <iostream>
#include <string>
#include <regex>
using namespace std;

string day_of_the_week(int, int, int);

int main() {

    // get user input
    string input;
    bool invalid_date;
    int month, day, year;

    do {
        invalid_date = false;

        cout << "Enter a date in the format mm/dd/yyyy: ";
        cin >> input;

        int slash_count = 0;
        // check to make sure user followed instructions
        for (int i = 0; i < input.length()-1; i++) {
            if (input[i] == '/') {
                slash_count++;
            }
        }

        regex reg([0-9]);
        cout << "regex: " << (regex_match(input, reg)) << endl;
        if (regex_match(input, reg)) {
            cout << "Regex did something" << endl;
        }


        if (  slash_count == 2 && (input.substr(input.find("/")+1, input.length()-1)).find("/") < (input.substr(input.find("/")+1, input.length()-1)).length())  {

        (input.find("/")) ? month = stoi(input.substr(0,input.find("/"))) : invalid_date = true;
        input = input.substr(input.find("/")+1, input.length()-1);
        (input.find("/")) ? day = stoi(input.substr(0,input.find("/"))) : invalid_date = true;
        (input.find("/")+1 < input.length()) ? year = stoi(input.substr(input.find("/")+1, input.length()-1)) : invalid_date = true;

        if (!invalid_date) {
            bool leap_year = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);

            // validate user input to be an actual date
            if (month < 1 || month > 12 || day < 1 || day > 31) {
                invalid_date = true;
            } else {
                switch(month) {
                    case 2: invalid_date = ((day > 28 && !leap_year) || day > 29) ? true : false; break;
                    case 4: invalid_date = (day > 30) ? true : false; break;
                    case 6: invalid_date =  (day > 30) ? true : false; break;
                    case 9: invalid_date = (day > 30) ? true : false; break;
                    case 11: invalid_date = (day > 30) ? true : false; break;
                    default: invalid_date = false;
                }
            }
        }

        if (invalid_date) {
            cout << "Invalid input please try again." << endl;
            cin.ignore();
            cin.clear();
        }
        } else {
            invalid_date = true;
        }

    } while (invalid_date);

    cout << day_of_the_week(month, day, year);


}

string day_of_the_week(int month, int day, int year) {

    // assign the correct number for calculating the day to month
    if (month == 4 || month == 7) {
        month = 0;
    } else if (month == 1 || month == 10) {
        month = 1;
    } else if (month == 5) {
        month = 2;
    } else if (month == 8) {
        month = 3;
    } else if (month == 2 || month == 3 || month == 11) {
        month = 4;
    } else if (month == 6) {
        month = 5;
    } else if (month == 9 || month == 12) {
        month = 6;
    } else {
        return "Something went wrong.";
    }

    // assign the proper number to year
    year = year % 4 == 0 && year % 100 != 0 || year % 400 == 0 ? 3 : 2;

    string days[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    // do the calculation and return the answer.
    return days[(month + day + year) % 7];



}
