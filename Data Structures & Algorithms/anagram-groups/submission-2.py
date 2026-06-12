class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mapping = defaultdict(list)
        for s in strs:
            counter = [0 for _ in range(26)]
            for c in s:
                counter[ord(c) - ord('a')] += 1
            mapping[tuple(counter)].append(s)
        return list(mapping.values())
