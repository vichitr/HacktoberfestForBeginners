class Solution{
	public:
		int minJumps(vector<int>& arr){
			if(arr.size()<=1) return 0;
			if(arr[0]==arr[arr.size()-1]) return 1;
			vector<bool> visited(arr.size(), false);
			unordered_map<int, vector<int>>val_tlb;
			for(int i=0;i<arr.size();i++){
				val_tlb[arr[i]].push_back(i);
			}
			queue<int> q;
			visited[0]=true;
			q.push(0);
			int lv=1;
			while(!q.empty()){
				for(int j=q.size();j>0;j--){
					int temp=q.front();
					q.pop();
					if(temp==arr.size()-1) return lv;
					for(int k=val_tlb[arr[temp]].size()-1;k>=0;k--){
                    	int n=val_tlb[arr[temp]][k];
						if(n==arr.size()-1) return lv;
						if(!visited[n]){
							visited[n]=true;
							q.push(n);
						}
					}if(temp>1 && !visited[temp-1]){
						visited[temp-1]=true;
						q.push(temp-1);
					}if(temp==arr.size()-2) return lv;
					if(temp<arr.size()-1 && !visited[temp+1]){
						visited[temp+1]=true;
						q.push(temp+1);
					}
				}
				lv++;
			}
			return 0;
		}
};
