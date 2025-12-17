class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        chunks = []
        chunk = ""

        for x in s[::-1]:
            if x == "-":
                continue

            chunk = f"{chunk}{x}"
            if len(chunk) == k:
                chunks.append(chunk.upper())
                chunk = ""

        if len(chunk) > 0:
            chunks.append(chunk.upper())

        return "-".join(chunks)[::-1]


