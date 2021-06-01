// problem link:- https://leetcode.com/problems/number-of-islands/

class Solution
{
    int dfsHelp(int i, int j, vector<vector<int>> &graph)
    {
        if(i>=0 && i<graph.size() && j>=0 && j<graph[0].size() && graph[i][j]==1)
        {
            graph[i][j]=0; //as a visited array
            return 1+dfsHelp(i+1,j,graph)+dfsHelp(i-1,j,graph)+dfsHelp(i,j+1,graph)+dfsHelp(i,j-1,graph);
            //all possible areas are taken
        }
        return 0;
    }
    
    public:
    int maxAreaOfIsland(vector<vector<int>>& graph) 
    {
        int maxArea=0;
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[0].size();j++)
            {
                if(graph[i][j]==1)
                {
                    maxArea=max(maxArea, dfsHelp(i,j,graph)); //max is taken for diffrent islands
                }
            }
        }
        return maxArea;
    }
};
