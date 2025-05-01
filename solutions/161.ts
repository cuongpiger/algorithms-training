function countLargestGroup(n: number): number {
  const bucket: { [key: number]: number } = {};

  for (let i = 1; i <= n; i++) {
    const key = i
      .toString()
      .split("")
      .map(Number)
      .reduce((a, b) => a + b, 0);

    bucket[key] = (bucket[key] || 0) + 1;
  }

  const values = Object.values(bucket);
  const maxValue = Math.max(...values);
  const count = values.filter((v) => v === maxValue).length;

  return count;
}
