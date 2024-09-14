class TreeAncestor {
public:
    int lgmax=20; 
    vector<vector<int>> power;
    TreeAncestor(int n, vector<int>& parent) {
        	power.resize(lgmax, vector<int>(n, -1));

        for(int i=0;i<n;i++){
            power[0][i]=parent[i];
        }
                cout<<"Sf";

        for (int i = 1; i < lgmax; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (power[i - 1][j] != -1)
			{
				power[i][j] = power[i - 1][power[i - 1][j]];
			}
		}
	}
        cout<<"Sf";
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=lgmax;i>=0;i--){
            if(k&(1<<i)){
                node = power[i][node];
                k-=(1<<i);
                if(node==-1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */