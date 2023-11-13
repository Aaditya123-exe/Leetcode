class Solution
{
public:
    string sortVowels(string s)
    {
        vector<int> v(s.size());
        vector<char> vec;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] == 'A') || (s[i] == 'E') || (s[i] == 'I') || (s[i] == 'O') || (s[i] == 'U') || (s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u'))
            {
                vec.push_back(s[i]);
                v[i] = 1;
            }
        }
        sort(vec.begin(), vec.end());
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (v[i] == 1)
            {
                s[i] = vec[j++];
            }
        }
        return s;
    }
};