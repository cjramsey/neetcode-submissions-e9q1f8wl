class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for word in strs:
            res += str(len(word));
            res += "_" + word;
        return res;

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        n = len(s)
        while i < n:
            j = i
            while j < n and s[j] != '_':
                j += 1
            length = int(s[i:j])
            j += 1
            res.append(s[j: j + length])
            i = j + length
        return res
