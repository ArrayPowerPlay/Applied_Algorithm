#include <bits/stdc++.h>
using namespace std;

/*Given an array arr[] and an integer k, where arr[i] denotes the number of pages of a book
and k denotes total number of students. All the books need to be allocated to k students in 
contiguous manner, with each student getting at least one book. The task is to minimize the 
maximum number of pages allocated to a student. 

If it is not possible to allocate books to all students, return -1.*/

// Thử chia k sinh viên số sách nằm trong mảng arr với số lượng trang tối đa mỗi sinh viên được
// nhận không vượt quá limit
bool canAllocate(vector<int> &arr, int k, int limit) {
    const int n = arr.size();
    if(k > n) return -1;

    // Thử chia 'page' trang sách cho sinh viên thứ i
    int students = 1;
    int pages = 0;

    for(int num : arr) {
        if(num > limit) return false;
        // Nếu vượt limit thì cần phia chia sách này cho sinh viên khác
        if(pages + num > limit) {
            pages = num;
            ++students;
            if(students > k) return false;
        } else {
            pages += num;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    vector<int> arr;

    while(ss >> x) arr.push_back(x);

    int k;
    cin >> k;

    if(k > arr.size()) {
        cout << -1 << endl;
        return 0;
    }

    int L = *max_element(arr.begin(), arr.end());
    int R = accumulate(arr.begin(), arr.end(), 0);

    int ans = -1;
    // Tìm kiếm nhị phân số trang nhỏ nhất thỏa mãn
    while(L < R) {
        int mid = (L + R) / 2;
        if(canAllocate(arr, k, mid)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}