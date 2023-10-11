#include <bits/stdc++.h>
using namespace std;
int main()
{
    int o,w;
    cout<<"Enter the no of coins: ";
    cin>>o;
    cout<<"Enter the Amount: ";
    cin>>w;
    int h[o+1][w+1],l[o];
    for (int i=0;i<o;i++)
    {
        cout<<endl<<"Coin "<<i+1<<":"<<endl;
        cout<<"Value of coin "<<i+1<<":";
        cin>>l[i];
    }
    cout<<endl<<"Table"<<endl;
    for (int i=0;i<o+1;i++)
    {
        for (int j=0;j<w+1;j++)
        {
            if (i==0 || j==0)
                h[i][j]=0;
            else
            {
                int y=l[i-1];
                if (i==1)
                    h[i][j]=h[i][j-y]+1;
                else if (j<y)
                    h[i][j]=h[i-1][j];
                else
                    h[i][j]=min(h[i-1][j],1+h[i][j-y]);
            }
            cout<<h[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"Minimum "<<h[o][w]<<" coin for change";
    return 0;
}
