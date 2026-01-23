#include <bits/stdc++.h>
using namespace std;

// Given a string word, return the sum of the number of vowels ('a', 'e', 'i', 'o', and 'u') in every substring of word.
// A substring is a contiguous (non-empty) sequence of characters within a string.

int check(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    }
    return 0;
}

long long countVowels(string word) {
    int n = word.size();
    long long res = 0;
    long long ans;
    
    for(int i = 0; i < n; ++i) {
        // Với mỗi i là một nguyên âm ta tính xem i đóng góp vào bao nhiêu substrings
        // Có i + 1 cách chọn điểm bắt đầu substring chứa i (từ 0 đến i)
        // Có n - i cách chọn điểm kết thúc substring chứa i (từ i đến n - 1)
        if(check(word[i])) {
            long long a = i + 1;
            long long b = n - i;
            res += (i + 1) * (n - i);
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << countVowels(s) << endl;
}