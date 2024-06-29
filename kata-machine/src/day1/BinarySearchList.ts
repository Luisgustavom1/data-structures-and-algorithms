// [__________,F] = N
// [____M_____,F] = N/2
//     [______,F]
// [______M___,F] = N/4
//       [_M__,F]
// [_________M,F] = N/8
// 	    [M,F]
//
// N..N/2..N/4..N/8..N/16..N/32
// 4096..2048..1024..512..256..128..64..32..16..8..4..2..1 = log(4096) = 12 = O(log(N))
// log N = X
//    2
// 2^X = N
// 2^12 = 4096
// ------------
// N/2^k => N = 2ˆk => log N = X
// 

export default function bs_list(haystack: number[], needle: number): boolean {
	let s = 0;
	let e = haystack.length;

	while (s < e) {
		const m = Math.floor(s + (e - s)/2);
		if (haystack[m] === needle) return true;		
		if (haystack[m] < needle) s = m + 1;
		else e = m;
	}

	return false;
}
