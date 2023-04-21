#include <bits/stdc++.h> 
int ks(vector<int> weight, vector<int> value, int index, int maxWeight){
  if (index == 0) {
    if (weight[0] <= maxWeight)
      return value[0];
    else
      return 0;
  }

        int include=0;

		if(weight[index]<maxWeight)
			 include=value[index]+ks(weight, value, index-1, maxWeight-weight[index]);
		int exclude = 0 + ks(weight, value, index-1, maxWeight);

		return max(include, exclude);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return ks(weight, value, n-1, maxWeight);
}








#include <bits/stdc++.h> 
int ks(vector<int> weight, vector<int> value, int index, int maxWeight, vector<vector<int>> &dp){
  if (index == 0) {
    if (weight[0] <= maxWeight)
      return value[0];
    else
      return 0;
  }

  if(dp[index][maxWeight]!=-1) return dp[index][maxWeight];

    int include=0;

		if(weight[index]<=maxWeight)
			 include=value[index]+ks(weight, value, index-1, maxWeight-weight[index], dp);
		int exclude = 0 + ks(weight, value, index-1, maxWeight,dp);

		dp[index][maxWeight]=max(include, exclude);
		return dp[index][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n, vector<int>(maxWeight+1,-1));
	return ks(weight, value, n-1, maxWeight,dp);
}






int kstab(vector<int> weight, vector<int> value, int n, int maxWeight){
  vector<vector<int>> dp(n, vector<int>(maxWeight+1,0));

  for(int w=weight[0];w<=maxWeight;w++){
    if (weight[0] <= maxWeight)
      dp[0][w]=value[0];
    else
      dp[0][w]=0;
  }


  for(int index=1;index<n;index++){
    for (int w = 0; w <= maxWeight; w++) {
      int include = 0;

      if (weight[index] <= w) {
      
      include = value[index] + dp[index - 1][w - weight[index]];
    }
      int exclude = 0 + dp[index - 1][w];
      dp[index][w] = max(exclude, include);
    }
  }
  return dp[n-1][maxWeight];
}







 int optimal(int weight[],int value[], int n, int maxWeight){
    vector<int> prev(maxWeight+1, 0);
    vector<int> curr(maxWeight+1, 0);

    for(int w=weight[0];w<=maxWeight;w++){
    if (weight[0] <= maxWeight)
      prev[w]=value[0];
    else
      prev[w]=0;
  }


  for(int index=1;index<n;index++){
    for (int w = 0; w <= maxWeight; w++) {
      int include = 0;

      if (weight[index] <= w) {
      
      include = value[index] + prev[w - weight[index]];
    }
      int exclude = 0 + prev[w];
      curr[w] = max(exclude, include);
    }
    
    prev=curr;
  }
  return prev[maxWeight];
    }
