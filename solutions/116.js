/**
 * @param {number[][]} nums1
 * @param {number[][]} nums2
 * @return {number[][]}
 */
var mergeArrays = function (nums1, nums2) {
  let res = [];
  let i = 0,
    j = 0;

  while (i < nums1.length && j < nums2.length) {
    if (nums1[i][0] === nums2[j][0]) {
      res.push([nums1[i][0], nums1[i][1] + nums2[j][1]]);
      i++;
      j++;
    } else if (nums1[i][0] < nums2[j][0]) {
      res.push(nums1[i]);
      i++;
    } else {
      res.push(nums2[j]);
      j++;
    }
  }

  // Append remaining elements from nums1
  while (i < nums1.length) {
    res.push(nums1[i]);
    i++;
  }

  // Append remaining elements from nums2
  while (j < nums2.length) {
    res.push(nums2[j]);
    j++;
  }

  return res;
};
