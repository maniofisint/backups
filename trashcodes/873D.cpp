#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k =0;
void merge(vector<int> &nums,int p,int q, int r){
	vector<int> le;
	vector<int> ri;
	int oe = (r-p)%2;
	int s1 = !oe ?  q-p:q-p+1;
	int s2 = !oe ?  r-q:r-q-1;
	le.reserve(s1);
	ri.reserve(s2);
	for(int i=0;i<s1;i++){
		le[i] = nums[p+i];
	}
	for(int i=0;i<s2;i++){
		int  ind = !oe ? q+i:q+i+1;
		ri[i] = nums[ind];
	}
	int i=0,j=0,k=p;
	for(k=p;k<r;k++){
		if(j<s2){
			nums[k] = ri[j];
			j++;
		}
		else{
			nums[k]=le[i];
			i++;
		}
	}
	
	
}

void un(vector<int> &nums,int p,int r){
	
 	if(p<r-1){

		int q = (p+r)/2;
		merge(nums,p,q,r);
		k-=2;
			
		if(k>0&&(q-1)!=p)
			un(nums,p,q);
		if(k>0&&q!=r-1)
			un(nums,q,r);
	}
}

int main(){
	vector<int> nums;
	int n,k;
	cin >> n >> k;
	
	if(k%2==0||k>n*2-1){
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		nums.push_back(i);

	}
	if(k==2*n-1){
		for(int i=n-1;i>=0;i--){
			cout<<nums[i]<<' ';
		}
		return 0;
	
	}

	k--;
	if(k>0){
		un(nums,0,n);
	}
	for(int i=0;i<n;i++){
		cout<<nums[i]<<' ';
	if(i==n/2)cout<<endl<<endl;
	}
	return 0;
}

