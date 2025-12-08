/**
 Do not return anything, modify s in-place instead.
 */
function reverseString(s: string[]): void {
    const n = s.length;
    for (let i = 0; i < Math.floor(n/2); i++) {
        const j = n - i - 1;
        [s[i], s[j]] = [s[j], s[i]]; // swap
    }
};
