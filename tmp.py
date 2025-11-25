"""Demonstrate comparing strings using bitmaps (bitsets).

This file shows a simple, clear approach for lowercase a-z strings:
- build a 26-bit integer where bit 0 = 'a', bit 1 = 'b', ...
- use bitwise AND/OR to test containment, common letters, equality of sets

This is about membership (which characters appear), not counts or order.
"""

needle = "abc"
haystack = "aab"

def bitmap_lower(s: str) -> int:
	"""Return a 26-bit mask for lowercase letters a..z present in s.

	Raises ValueError if s contains characters outside a-z.
	"""
	mask = 0
	for c in set(s):
		if 'a' <= c <= 'z':
			mask |= 1 << (ord(c) - ord('a'))
		else:
			raise ValueError("bitmap_lower only supports lowercase a-z")
	return mask

def letters_from_mask(mask: int) -> list:
	"""Return list of letters represented by the mask (a..z)."""
	return [chr(i + ord('a')) for i in range(26) if mask & (1 << i)]

def contains_all(hay_mask: int, needle_mask: int) -> bool:
	"""Return True if hay_mask contains all bits set in needle_mask."""
	return (hay_mask & needle_mask) == needle_mask

def has_common(hay_mask: int, needle_mask: int) -> bool:
	"""Return True if hay_mask and needle_mask share any bit."""
	return (hay_mask & needle_mask) != 0

def equal_sets(a_mask: int, b_mask: int) -> bool:
	return a_mask == b_mask


if __name__ == '__main__':
	n_mask = bitmap_lower(needle)
	h_mask = bitmap_lower(haystack)

	print(f"needle = {needle!r}")
	print(f"haystack = {haystack!r}\n")

	print("needle mask:", n_mask, bin(n_mask), letters_from_mask(n_mask))
	print("haystack mask:", h_mask, bin(h_mask), letters_from_mask(h_mask))

	print()
	print("hay contains all needle?", contains_all(h_mask, n_mask))
	print("have common letters?", has_common(h_mask, n_mask))
	print("sets equal?", equal_sets(h_mask, n_mask))

