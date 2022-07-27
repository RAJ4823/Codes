#include <bits/stdc++.h>
#define ll long long
using namespace std;


void swap(vector<int> &v, int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void heapify(vector<int> &v, int i) {
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;

    if(l <= v.size() && v[l] > v[largest])
        largest = l;
    if(r <= v.size() && v[r] > v[largest])
        largest = r;
    if(largest != i) {
        swap(v, i , largest);
        heapify(v, largest);
    }
}

int main()
{
    vector<int> v = {10,20,30,40,50,60,70,80};
    // vector<int> v = {10,30,50,20,35,15};
    int n = v.size();
    cout << "Before Heapify" << endl;
    for(int i=0; i<n; i++)
        cout << v[i] << " ";

    for(int i=n/2; i>=0; i--)
        heapify(v, i);


    cout << "\nAfter Heapify : " << endl;
    for(int i=0; i<n; i++) {
        cout << v[i] << " ";
    }
    
    return 0;
}