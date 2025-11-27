function singleNumber(nums: number[]): number {
  let res = 0;
  for (const x of nums) {
    res ^= x; // xor
  }
  return res;
}
