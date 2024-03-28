#define all(x) (x).begin(),(x).end()
#define vvi vector<vector<int>>
#define vi vector<int>
#define pb push_back

//inserting all strings (reverse) in trie
void insert(vvi &tri,vi &idx,vi &sz,string &s,int id){
    int t=0;
    for(int i=0 ; i<s.size() ; i++){
        int b=(s[i]-'a');
        if(tri[t][b]==-1) {
            tri[t][b]=tri.size();
            tri.push_back(vector<int>(26,-1));
            idx.push_back(1e9);
            sz.push_back(1e9);
        }
        t=tri[t][b];
        if(sz[t]>s.size()){
            sz[t]=s.size();
            idx[t]=id;
        }
        else if(sz[t]==s.size()){
            idx[t]=min(idx[t],id);
        }
    }   
}

//checking index of string with longest common suffix with the query string
int suffix(vvi &tri,vi &idx,vi &sz,string &s){
    int ans=1e9;
    int t=0;
    for(int i=0 ; i<s.size() ; i++){
        int b=(s[i]-'a');
        if(tri[t][b]==-1) {
            ans=idx[t];
            break;
        }
        t=tri[t][b];
        ans=idx[t];
    }  
    return ans;
}


class Solution {
public:
    vector<int> stringIndices(vector<string>& words, vector<string>& Query) {
        vvi tri;
        vi idx;
        vi sz;
        tri.pb(vi(26,-1));
        idx.pb(1e9);
        sz.pb(1e9);
        int id=0;
        int mini=1e9;
        int x=1e9;
        for(auto &e : words){
            reverse(all(e));
            insert(tri,idx,sz,e,id);
            if(e.size()<x){
                x=e.size();
                mini=id;
            }
            id++;
        }
        vector<int> ans;
        for(auto &q : Query){
            reverse(all(q));
            int anss=suffix(tri,idx,sz,q);
            ans.push_back((anss==1e9 ? mini : anss));
        }
        return ans;
    }
};