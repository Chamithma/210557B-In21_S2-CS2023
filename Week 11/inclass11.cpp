#include <iostream>
#include <vector>

using namespace std;

void dijkstra(vector<vector<int>> arr,int source){
    vector<int> minimum_time(arr.size(),INT_MAX);
    vector<bool> visited(arr.size(),false);
    minimum_time[source]=0;
    for(int i=0;i<arr.size();i++){
        int min=INT_MAX;
        int min_index=-1;
        for(int j=0;j<arr.size();j++){
            if(visited[j]==false && minimum_time[j]<=min){
                min=minimum_time[j];
                min_index=j;
            }
        }
        visited[min_index]=true;
        for(int j=0;j<arr.size();j++){
            if(visited[j]==false && arr[min_index][j]!=0 && minimum_time[min_index]!=INT_MAX && minimum_time[min_index]+arr[min_index][j]<minimum_time[j]){
                minimum_time[j]=minimum_time[min_index]+arr[min_index][j];
            }
        }
    }

        float sum = 0;
        float count = 5;
        for (int j = 0; j < minimum_time.size(); j++) {
            sum += minimum_time[j];
                
            
        }
        cout << "Average time taken to travel from city " << source <<" -> "<< sum / count;
        cout << endl;
    
}




int main(){
    vector<vector<int>> arr = 
    {
        {0,10,0,0,15,5},
        {10,0,10,30,0,0},
        {0,10,0,12,5,0},
        {0,30,12,0,0,20},
        {15,0,5,0,0,0},
        {5,0,0,20,0,0} 
    };

    cout << "Average time taken to travel other cities from each city";
    cout << endl;

    dijkstra(arr,0);
    dijkstra(arr,1);
    dijkstra(arr,2);
    dijkstra(arr,3);
    dijkstra(arr,4);
    dijkstra(arr,5);

    
    return 0;  

}