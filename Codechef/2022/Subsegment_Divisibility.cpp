#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define x 99999

int random(int arr[], int index) {
    int randomNumber = rand() % x;
    for (int j = 0; j < index; j++)
    {
        if (randomNumber == arr[j])
        {
            randomNumber = rand() % x;
            j = 0;
        }
    }
    return randomNumber;
}

int add(int arr[], int index)
{
    int sum = random(arr,index);
    int ans = sum;
    int i = index;
    while (i--)
    {
        sum += arr[i];
        if (sum % (index - i + 2) == 0)
        {
            i = index;
            sum = random(arr,index);
        }
    }
    return ans;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        int arr[n];
        arr[0] = rand() % x;
        arr[1] = arr[0] + 1;
        for (int i = 2; i < n; i++)
        {
            arr[i] = add(arr, i - 1);
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << arr[n - 1] << endl;
        cout << endl;
        int sum = 0;
        for(int i=n; i >= 0; i--) {
            sum += arr[i];
            cout << (n-i+2) << " - > " << sum%(n-i+2) << endl;;
        }
    }
    return 0;
}