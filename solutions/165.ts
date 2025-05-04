function numEquivDominoPairs(dominoes: number[][]): number {
  const normalized: number[] = dominoes.map(([a, b]) =>
    a >= b ? a * 10 + b : b * 10 + a
  );

  const cache: Record<number, number> = {};
  let res = 0;

  for (const d of normalized) {
    const value = cache[d] || 0;
    res += value;
    cache[d] = value + 1;
  }

  return res;
}
