/* Approach : DFS 
   refer : https://cp-algorithms.com/graph/topological-sort.html

  Time Complexity : O(V + E)
  Space Complexity : O(V)
  
*/

vector<int> res;
vector<bool> visited;

void dfs(vector<int> adj[], int i){
    if(visited[i])   return;
    visited[i] = true;
    for(int u : adj[i]){
        if(!visited[u])
           dfs(adj,u);
    }
    res.push_back(i);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    visited.assign(V,false);
    res.clear();
    for(int i=0;i <  V; i++){
        if(!visited[i])
          dfs(adj,i);
    }
    reverse(res.begin(),res.end());
    return res;
}

/* Approach : Kahn's Algorithm : There is atleast a vertex with indegree 0 in the graph. Push the vertex
                                 with indegree 0 to the queue and remove the outgoing edges from that
				 vertex. In doing so subtract the indegree of the child vertex and if
				 its indegree becomes zero push it into the queue. Store all the 
				 vertex with indegree 0 to your res vector which will be your answer.

   refer : https://www.youtube.com/watch?v=bS62tit40m8&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=30

 Time Complexity: O(V + E)
 Space Complexity : O(V)

*/

        int in[10001];
	vector<int> res;
	
	void kahn(int n, vector<int> adj[]){
	    queue<int> q;
	    
	    for(int i = 0; i < n; i++){
	        if(in[i] == 0)
	           q.push(i);
	    }
	    
	    while(!q.empty()){
	        int v = q.front();
	        q.pop();
	        res.push_back(v);
	        for(int u: adj[v]){
	            in[u]--;
	            if(in[u] == 0)
	                q.push(u);
	        }
	    }
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
	    
	 
	    for(int i = 0; i < V; i++){
	        for(int j = 0; j < adj[i].size(); j++){
	            in[adj[i][j]]++;
	        }
	    }
	    
	    kahn(V, adj);
	    
	   return res;
	}
