int solve(int n, vector<int> &days, vector<int>& cost, int index){

    if(index>=n) return 0;



    int option1 = cost[0]+ solve(n, days,cost,index+1);

    int i;


    for(i = index; i<n && days[i]<days[index]+7;i++);

     int option2 = cost[1] + solve(n , days, cost, i);


     for(i=index;i<n && days[i]<days[index]+30; i++);


     int option3 = cost[2]+solve(n, days, cost, i);



     return min(option1 , min(option2, option3));

}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    return solve(n, days, cost, 0);
}













int solve(int n, vector<int> &days, vector<int>& cost, int index, vector<int> & dp){

    if(index>=n) return 0;


    if(dp[index]!=-1) return dp[index];


    int option1 = cost[0]+ solve(n, days,cost,index+1, dp);

    int i;


    for(i = index; i<n && days[i]<days[index]+7;i++);

     int option2 = cost[1] + solve(n , days, cost, i, dp);


     for(i=index;i<n && days[i]<days[index]+30; i++);


     int option3 = cost[2]+solve(n, days, cost, i, dp);



     dp[index] =  min(option1 , min(option2, option3));


     return dp[index];

}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int> dp(n+1 , -1);
    return solve(n, days, cost, 0, dp);
}










int solveTab(int n, vector<int> & days, vector<int> & cost){
    vector<int> dp(n+1, INT_MAX);

    dp[n]=0;



    for(int k=n-1;k>=0;k--){

    int option1 = cost[0]+ dp[k+1];



    int i;


    for(i = k; i<n && days[i]<days[k]+7;i++);

     int option2 = cost[1] + dp[i];


     for(i=k;i<n && days[i]<days[k]+30; i++);


     int option3 = cost[2]+dp[i];



     dp[k] =  min(option1 , min(option2, option3));


     

    }
    

        
    return dp[0];


}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    // vector<int> dp(n+1 , -1);
    return solveTab(n, days, cost);
}











//01

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    int ans=0;

    queue<pair<int, int>>month;
    queue<pair<int, int>>week;
    
    for(int day:days){
        while(!month.empty()  && month.front().first+30<=day)
            month.pop();

        while(!week.empty() && week.front().first+7<=day)
            week.pop();

        week.push(make_pair(day, ans+cost[1]));
        month.push(make_pair(day, ans+cost[2]));


        ans=min(ans+cost[0], min(week.front().second, month.front().second));
    }

    return ans;
}