const UPPER_BOUNDARIES = 10 ** 6;

function checkEvenDigits(
  numb: number,
  basedNumber: number,
  result: boolean
): boolean {
  if (basedNumber > UPPER_BOUNDARIES) {
    return false;
  }

  if (numb < basedNumber) {
    return result;
  }

  return checkEvenDigits(numb, basedNumber * 10, !result);
}

function findNumbers(nums: number[]): number {
  let res = 0;
  for (const num of nums) {
    if (checkEvenDigits(num, 10, false)) {
      res += 1;
    }
  }

  return res;
}
