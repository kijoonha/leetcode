class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        


    map<string, vector<string>> myMap;  //myMap 원소는 {"eat","ate"}
    vector<vector<string>> results;   // {{"eat","ate"},{"no","on"}}
    
    for (int i=0; i<strs.size(); i++){
        string sorted = strs[i];
        sort(sorted.begin(),sorted.end());
        //myMap.insert(pair<string,string>(sorted,strs[i]));
        if (myMap.count(sorted) ==0){
            myMap.insert(pair<string, vector<string>> (sorted, {strs[i]}));
        } 
        else {
            myMap[sorted].push_back(strs[i]);
        }
        }  
    for (auto it=myMap.begin(); it!=myMap.end();it++){
        results.push_back(it->second);
    }
        
 

    return results;
}    
};