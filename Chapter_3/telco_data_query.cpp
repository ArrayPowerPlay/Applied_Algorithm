#include <bits/stdc++.h>
using namespace std;

// check if the phone is valid
bool check_valid_phone(string phone) {
    if(phone.size() != 10) return false;
    for(char c : phone) {
        if(isdigit(c) == 0) return false;
    }

    return true;
}

// total second from start time to end time
int cnt_time(string s_time, string e_time) {
    int start_sec = stoi(s_time.substr(0, 2)) * 3600 + stoi(s_time.substr(3, 2)) * 60
                    + stoi(s_time.substr(6, 2));
    int end_sec = stoi(e_time.substr(0, 2)) * 3600 + stoi(e_time.substr(3, 2)) * 60
                    + stoi(e_time.substr(6, 2));
    
    return end_sec - start_sec;
}

int main() {
    string s;
    cin >> s;
    // check all phone number (if they are valid or not)
    int check_phone = 1;
    // total number of phone calls
    int cnt_calls = 0;
    // number of phone calls from a phone number
    map<string, int> num_calls;
    // total number of time for calling from a phone number
    map<string, int> cnt_time_calls;

    while(s != "#") {
        // start phone/time, end phone/time
        string s_phone, e_phone, date, s_time, e_time;
        cin >> s_phone >> e_phone >> date >> s_time >> e_time;

        cnt_calls++;

        if(!check_valid_phone(s_phone) || !check_valid_phone(e_phone)) {
            check_phone = 0;
        }

        num_calls[s_phone]++;
        cnt_time_calls[s_phone] += cnt_time(s_time, e_time);

        cin >> s;
    }

    cin >> s;
    
    while(s != "#") {
        if(s == "?check_phone_number") {
            cout << check_phone << endl;
        }

        if(s == "?number_calls_from") {
            string phone;
            cin >> phone;
            cout << num_calls[phone] << endl;
        }

        if(s == "?number_total_calls") {
            cout << cnt_calls << endl;
        }

        if(s == "?count_time_calls_from") {
            string phone;
            cin >> phone;
            cout << cnt_time_calls[phone] << endl;
        }

        cin >> s;
    }
    
    return 0;
}