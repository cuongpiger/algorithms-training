function findEvenNumbers(digits: number[]): number[] {
  const res = new Set<number>();
  const n = digits.length;

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      for (let k = 0; k < n; k++) {
        if (
          i !== j &&
          j !== k &&
          k !== i &&
          digits[i] !== 0 &&
          digits[k] % 2 === 0
        ) {
          const num = digits[i] * 100 + digits[j] * 10 + digits[k];
          res.add(num);
        }
      }
    }
  }

  return Array.from(res).sort((a, b) => a - b);
}
