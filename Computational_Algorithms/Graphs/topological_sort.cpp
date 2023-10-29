#include<bits/stdc++.h>
using namespace std;
//B22147 Yash Sehgal
//class for implementaion of Graphs
class Graph{
    unordered_map<int,list<int>> map;
    int num_nodes;

    public:
    // s number of nodes
    //constructor
    Graph(int s){
       this->num_nodes=s;
    }
    //adding the edges between the nodes
    void addedge(int u,int v,bool  dir){
        map[u].push_back(v);
        if(dir==0){
            map[v].push_back(u);
        }
    }
    void print_graph(){
        for(auto i :map){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
    private:
    //The DFS traversal 
    void dfs(int node,int* visited,stack<int> &result){
        visited[node]=1;
     
        for(auto i :map[node]){
            if(!visited[i]){
             dfs(i,visited,result);
            }
        }
           result.push(node);
    }
    public:
    //the topological sort
    void topological_sort(){
        int visited[num_nodes]={0};
        stack<int>s;
        for(int i=0;i<num_nodes;i++){
            if(!visited[i]){
                dfs(i,visited,s);
            }
        }
        vector<int>result;
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        //the final result array is printed
        for(auto i:result){
            cout<<i<<" ";
        }
    }
};

int main(){
    int n,m;
    cout<<"enter the number of nodes and edges : ";
    cin>>n>>m;
    cout<<"Enter the edges : "<<endl;
   Graph g1(n);
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g1.addedge(u,v,1);
   }
   g1.print_graph();
    cout<<endl;
   cout<<"The topological  sort : "<<endl;
   g1.topological_sort();
return 0;
}
