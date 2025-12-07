/**
 * Definition for isBadVersion()
 * 
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        let left = 1, right = n, res = 1;
        while (left <= right) {
            const mid = left + Math.floor((right - left) / 2);
            const is_bad = isBadVersion(mid);

            if (is_bad) {
                right = mid - 1;
                res = mid;
            } else {
                left = mid + 1;
            }
        }

        return res;
    };
};
