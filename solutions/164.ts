function minDominoRotations(tops: number[], bottoms: number[]): number {
  const n = tops.length;
  const X = tops[0];
  const Y = bottoms[0];

  let hasX = true;
  let hasY = true;

  let swapXB = 0,
    swapXT = 0;
  let swapYB = 0,
    swapYT = 0;

  for (let i = 0; i < n; i++) {
    // Check for value X
    if (hasX) {
      if (tops[i] !== X && bottoms[i] !== X) {
        hasX = false;
      } else {
        if (tops[i] !== X) {
          swapXT++;
        }

        if (bottoms[i] !== X) {
          swapXB++;
        }
      }
    }

    // Check for value Y
    if (hasY) {
      if (tops[i] !== Y && bottoms[i] !== Y) {
        hasY = false;
      } else {
        if (tops[i] !== Y) {
          swapYT++;
        }

        if (bottoms[i] !== Y) {
          swapYB++;
        }
      }
    }

    if (!hasX && !hasY) {
      return -1;
    }
  }

  let ans = Number.MAX_SAFE_INTEGER;
  if (hasX) {
    ans = Math.min(ans, swapXT, swapXB);
  }

  if (hasY) {
    ans = Math.min(ans, swapYT, swapYB);
  }

  return ans;
}
