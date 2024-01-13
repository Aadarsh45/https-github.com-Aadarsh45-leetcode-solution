class Solution {
public:

    vector<int> mapping(string s)
    {
        vector<int> v(26, 0);
        for (int i = 0; i < s.size(); i++)
            v[s[i] - 'a']++;
        return v;
    }

    int minSteps(string s, string t) {

    vector<int> mapping1 = mapping(s);
    vector<int> mapping2 = mapping(t);
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        int diff = 0;
        if (mapping1[i] != 0)
            if (mapping1[i] > mapping2[i])
                diff = mapping1[i] - mapping2[i];
        count += diff;
    }
    return count;
        
    }
};