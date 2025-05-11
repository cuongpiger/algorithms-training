function threeConsecutiveOdds(arr: number[]): boolean {
  let oddCount = 0;

  for (const x of arr) {
    if (x % 2 == 1) {
      oddCount += 1;

      if (oddCount > 2) {
        return true;
      }
    } else {
      oddCount = 0;
    }
  }

  return false;
}
