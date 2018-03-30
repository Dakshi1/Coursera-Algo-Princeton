#include <iostream>

using namespace std;
int root(int x, int arr[])
{
    while(x != arr[x])
    {
        x=arr[x];
    }
    return x;
}
void unionx(int st, int en, int arr[], int sz[], int n)
{
    int st_root=root(st, arr);
    int en_root=root(en, arr);

    if(sz[st_root] >= sz[en_root])
    {
        cout << sz[st_root] << " st " << sz[en_root] << endl;
        arr[en_root]=arr[st_root];
        sz[st_root]+=sz[en_root];
    }
    else
    {
        cout << sz[en_root] << " en " << sz[st_root] << endl;
        arr[st_root]=arr[en_root];
        sz[en_root]+=sz[st_root];
    }
}
int main()
{
    int n,x=1;
    int st, en;
    cin >> n;
    int arr[n+1];

    // improvising quick_union by adding weights array, can be converted to normal quick_union by its removal
    int sz[n+1];

    for(int i=0;i<=n;i++)
    {
        arr[i]=i;
        sz[i]=1;
    }
    cout << "Make the unions between nodes:" << endl;
    while(x>0)
    {
        cin >> st >> en;
        cout << endl;
        unionx(st, en, arr, sz, n);
        cout << "want to add more bonds?";
        cin >> x;
        cout << endl;
    }
    x=1;
    cout << "Check for the existing bonds " << endl;
    while(x > 0)
    {
        cin >> st >> en;
        if(root(st, arr) == root(en, arr))
        {
            cout << "There exists a bond " << endl;
        }
        else{
            cout << root(st, arr) << "  " << root(en, arr) << endl;
        }
        cout << "want to check more bonds?";
        cin >> x;
        cout << endl;
    }
    return 0;
}
