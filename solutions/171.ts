function lengthAfterTransformations(s: string, t: number): number {
  const mod = 10 ** 9 + 7;
  let cnt: number[] = new Array(26).fill(0);

  for (const ch of s) {
    cnt[ch.charCodeAt(0) - "a".charCodeAt(0)]++;
  }

  for (let round = 0; round < t; round++) {
    const nxt: number[] = new Array(26).fill(0);
    nxt[0] = cnt[25];
    nxt[1] = (cnt[25] + cnt[0]) % mod;

    for (let i = 2; i < 26; i++) {
      nxt[i] = cnt[i - 1];
    }

    cnt = nxt;
  }

  const ans = cnt.reduce((acc, val) => (acc + val) % mod, 0);
  return ans;
}
