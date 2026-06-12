public class Solution {

    public string Encode(IList<string> strs) {
        StringBuilder sb = new StringBuilder();
        foreach (var word in strs) {
            int n = word.Length;
            sb.Append(n.ToString());
            sb.Append("_");
            sb.Append(word);
        }
        return sb.ToString();
    }

    public List<string> Decode(string s) {
        List<string> res = new();
        int n = s.Length;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] != '_') {
                ++j;
            }
            string digit = s.Substring(i, j - i);
            ++j;
            int length = int.Parse(digit);
            res.Add(s.Substring(j, length));
            i = j + length;
        }
        return res;
   }
}
