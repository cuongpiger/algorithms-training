class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s_key_chain = []
        for x in s:
            if x == "#" and len(s_key_chain) > 0:
                s_key_chain.pop()
            elif x != "#":
                s_key_chain.append(x)

        t_key_chain = []
        for x in t:
            if x == "#" and len(t_key_chain) > 0:
                t_key_chain.pop()
            elif x != "#":
                t_key_chain.append(x)

        return "".join(s_key_chain) == "".join(t_key_chain)
