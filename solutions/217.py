class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        visited_s = {}
        visited_t = {}
        for i in range(len(s)):
            s_ch = s[i]
            t_ch = t[i]

            vs = visited_s.get(s_ch, None)
            vt = visited_t.get(t_ch, None)

            if vs == vt == None:
                visited_s[s_ch] = t_ch
                visited_t[t_ch] = s_ch
            elif not ((vs or vt) is None) and vs == t_ch and vt == s_ch:
                continue
            else:
                return False

        return True
