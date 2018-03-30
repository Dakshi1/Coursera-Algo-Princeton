#include <iostream>

using namespace std;
void unionx(int a, int b, int arr[], int n)
{
    int var=arr[a];
    int res=arr[b];

    //int n=sizeof(arr)/sizeof(arr[0]);

    cout << "var and res have the following values " << var << "  " << res << "  " << n << endl;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==var)
        {
            arr[i]=arr[b];
            //*(arr + i)=res;
        }
    }

}
int main()
{
    int n,x=1;
    int st, en;
    cin >> n;
    int arr[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=i;
    }
    cout << "Make the unions between nodes:" << endl;
    while(x>0)
    {
        cin >> st >> en;
        cout << endl;
        unionx(st, en, arr, n);
        cout << "want to add more bonds?";
        cin >> x;
        cout << endl;
    }
    x=1;
    cout << endl;
    cout << "Check for the existing bonds " << endl;
    while(x > 0)
    {
        cin >> st >> en;
        if(arr[st] == arr[en])
        {
            cout << "There exists a bond " << endl;
        }
        else{
            cout << arr[st] << "  " << arr[en] << endl;
        }
        cout << "want to check more bonds?";
        cin >> x;
        cout << endl;
    }
    return 0;
}
