/**
 * @param {number[]} colors
 * @param {number} k
 * @return {number}
 */
var numberOfAlternatingGroups = function(colors, k) {
  for (let i = 0; i < k - 1; i++) {
      colors.push(colors[i]);
  }

  let result = 0;
  let left = 0;
  let right = 1;

  while (right < colors.length) {
      if (colors[right] === colors[right - 1]){
          left = right;
          right++;
          continue;
      }

      right++;
      if (right - left < k) {
          continue;
      }

      result++;
      left++;
  }

  return result;
};