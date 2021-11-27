#include<bits/stdc++.h>
using namespace std;

void subset_of_sum(vector<int> nums, int target, vector<int> subset, unordered_map<int,int> &c, int max){
    if (subset.size() > max) return;

    int s = accumulate(subset.begin(), subset.end(), 0);
    if (s == target) c[subset.size()]++;
    else if (s > target) return;

    for (int i = 0; i < nums.size(); i++){
        int n = *(nums.begin()+i);

        vector<int> r;
        for (auto it = nums.begin()+i+1; it != nums.end(); it++){
            r.push_back(*it);
        }

        vector new_subset(subset);
        int new_s = s;
        while (new_s<target){
            new_subset.push_back(n);
            new_s += n;
            subset_of_sum(r, target, new_subset, c, max);
        }
    }
}

int total(unordered_map<int, int> c, int remaining_n, int remaining_p){
    if (remaining_p == 0) return 1;
    if (remaining_p == 1) return c[remaining_n];
    int sum = 0;
    for (int i = 1 ;i <= (remaining_n - remaining_p)+1; i++){
        sum += c[i] * total(c, remaining_n-i, remaining_p-1);
    }
    return sum;
}

int main(){
    int p, i, n, w;
    cin >> p >> i >> n >> w;

    unordered_map<int, int> c;
    
    vector<int> nums;
    for (int j = 1; j <= i; j++){
        nums.push_back(j);
    }
    
    subset_of_sum(nums, w, vector<int> {}, c, (n-p)+1);
    cout << total(c, n, p);

    return 0;
}