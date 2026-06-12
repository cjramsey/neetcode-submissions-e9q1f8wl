public class Solution {
    public List<List<string>> GroupAnagrams(string[] strs) {
        var groups = new Dictionary<string, List<string>>();
        foreach (string s in strs) {
            int[] freq = new int[26];
            foreach (char c in s) {
                ++freq[c - 'a'];
            }
            string key = "";
            foreach (int n in freq) {
                key += '#' + n.ToString();
            }
            if (!groups.ContainsKey(key)) {
                groups[key] = new List<string>();
            }
            groups[key].Add(s);
        }
        var res = new List<List<string>>();
        foreach (var (_, group) in groups) {
            res.Add(group);
        } 
        return res;
    }
}
