#include <iostream>
#include <vector>

using namespace std;

vector<int> findIntersecrion(vector<int> a, vector<int> b){
    cout << a[0] << " " << a[1] << endl;
    return {1,1};
}
vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    if(firstList.size() == 0 || secondList.size() == 0){
        return {};
    }

    vector<vector<int>> result;

    int i = 0;
    int j = 0;

    while (i < firstList.size()){
        while(j < secondList.size()){
            if (secondList[j][0] > firstList[i][1]) {
                i++;
            }
            if(secondList[j][1] < firstList[i][0]){
                j++;
            }
            findIntersecrion(firstList[i], secondList[j]);
            i++;
        }


        
        //i++;
        //j++;
    }
    return result;
}

int main()
{
    vector<vector<int>> firstList = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> secondList = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> result = intervalIntersection(firstList, secondList);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> firstList2 = {{1,3},{5,9}};
    vector<vector<int>> secondList2 = {{}};
    vector<vector<int>> result2 = intervalIntersection(firstList2, secondList2);
    for (int i = 0; i < result2.size(); i++) {
        for (int j = 0; j < result2[i].size(); j++) {
            cout << result2[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> firstList3 = {};
    vector<vector<int>> secondList3 = {{4,8},{10,12}};
    vector<vector<int>> result3 = intervalIntersection(firstList3, secondList3);
    for (int i = 0; i < result3.size(); i++) {
        for (int j = 0; j < result3[i].size(); j++) {
            cout << result3[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> firstList4 = {{1,7}};
    vector<vector<int>> secondList4 = {{3,10}};
    vector<vector<int>> result4 = intervalIntersection(firstList4, secondList4);
    for (int i = 0; i < result4.size(); i++) {
        for (int j = 0; j < result4[i].size(); j++) {
            cout << result4[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> firstList5 = {{3,10}};
    vector<vector<int>> secondList5 = {{5,10}};
    vector<vector<int>> result5 = intervalIntersection(firstList5, secondList5);
    for (int i = 0; i < result5.size(); i++) {
        for (int j = 0; j < result5[i].size(); j++) {
            cout << result5[i][j] << " ";
        }
        cout << endl;
    }   
    return 0;
}
