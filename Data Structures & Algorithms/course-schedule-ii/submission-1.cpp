class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adjacencyList[1001];
        vector<int> indegree(n,0);
        queue<int> qt;

        for(auto x : prerequisites){
            adjacencyList[x[1]].push_back(x[0]);
            indegree[x[0]] ++;
        }

        for(int i=0;i<n;i++){
            if(indegree[i] == 0) qt.push(i);
        }

        vector<int> orderOfTraversal;

        while(!qt.empty()){

            int currCourse = qt.front();
            qt.pop();
            orderOfTraversal.push_back(currCourse);
            n --;

            for(auto x : adjacencyList[currCourse]){

                indegree[x] --;
                if(indegree[x] == 0) qt.push(x);

            }

        }

        if(n > 0) orderOfTraversal.clear();
        
        return orderOfTraversal;
    }
};
