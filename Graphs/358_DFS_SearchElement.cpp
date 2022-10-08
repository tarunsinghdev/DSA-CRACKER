#include<vector>
#include<iostream>
using namespace std;

int v[100],dis[100];
vector<int> arr[100];
void dfs(int n,int d){
    v[n]=1;
    dis[n]=d;
    for(int a:arr[n]){
        if(v[a]==0){
            v[a]=1;
            dis[a]=dis[a]+1;
            dfs(a,dis[a]+1);
        }
    }

}
int main()
{
    int s;

    arr[0].push_back(1);
    arr[0].push_back(9);
    arr[1].push_back(2);
    arr[2].push_back(0);
    arr[2].push_back(3);
    arr[9].push_back(3);



    dfs(0,0);//1st parameter is starting node and 2nd parameter is distance of starting node i.e. 0

    s=9;    //element to be searched i.e.9
    if(v[s]==1)
        cout<<"\nElements "<<s<<" is present in the tree or graph"<<endl;
    else
        cout<<"\nElements "<<s<<" is not present in the tree or graph"<<endl;

    cout<<"\nDistance using dfs is from source to "<<s<<" is:"<<dis[s]<<endl;
    return 0;
}
/*
Output:
Elements 9 is present in the tree or graph

Distance using dfs is from source to 9 is:2
*/
