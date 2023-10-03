class Solution {
public:
	bool isPossible(vector<int>& weights, int mid, int days){
		int sum=0;
		int d=1;
		for(int num:weights){
			sum+=num;
			if(sum>mid){
				d++;
				sum=num;
			}
		}
		return d <= days;
	}
	int shipWithinDays(vector<int>& weights, int days) {
		// Your code goes here
		int sum =0; 
		int mx =0;
		for(int num:weights){
			sum+=num;
			mx= max(mx,num);
		}

		int lo=mx;
		int high=sum;
		int ans=0;
		while(lo<=high){
			int mid = lo+(high-lo)/2;

			if(isPossible(weights,mid,days)){
				ans=mid;
				high=mid-1;
			} else{
				lo=mid+1;
			}
		}
		return ans;
	}
};