class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjacencyList[numCourses];
        vector<int> indegree(numCourses,0);

        for(auto x : prerequisites){
            adjacencyList[x[1]].push_back(x[0]);
            indegree[x[0]] ++;
        }

        queue<int> qt;

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) qt.push(i);
        }

        while(!qt.empty()){
            int currCourse = qt.front();
            qt.pop();
            numCourses --;
            for(auto x : adjacencyList[currCourse]){

                indegree[x] -- ;
                if(indegree[x] == 0) qt.push(x);

            }
        }

        return numCourses == 0;
    }
};
