/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function (pattern, s) {
  const bow = new Map(); // word -> char
  const boc = new Map(); // char -> word
  const chunks = s.split(" ");

  if (chunks.length !== pattern.length) {
    return false;
  }

  for (let i = 0; i < chunks.length; i++) {
    const ch = pattern[i];
    const chunk = chunks[i];

    const digit = bow.has(chunk) ? bow.get(chunk) : "";
    const word = boc.has(ch) ? boc.get(ch) : "";

    if (word + digit === "") {
      bow.set(chunk, ch);
      boc.set(ch, chunk);
    } else if (word !== chunk || digit !== ch) {
      return false;
    }
  }

  return true;
};
