function countInterestingSubarrays(
  nums: number[],
  modulo: number,
  k: number
): number {
  let n = nums.length;
  let cnt = new Map<number, number>();
  let res = 0;
  let prefix = 0;

  cnt.set(0, 1);

  for (let i = 0; i < n; i++) {
    prefix += nums[i] % modulo === k ? 1 : 0;
    res += cnt.get((prefix - k + modulo) % modulo) || 0;
    cnt.set(prefix % modulo, (cnt.get(prefix % modulo) || 0) + 1);
  }

  return res;
}
