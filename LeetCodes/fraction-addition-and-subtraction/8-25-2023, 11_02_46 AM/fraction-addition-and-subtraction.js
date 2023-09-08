// Link: https://leetcode.com/problems/fraction-addition-and-subtraction

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: fraction-addition-and-subtraction
 *  RUNTIME: 41 ms
 *  MEMORY: 42.4 MB
 *  DATE: 8-25-2023, 11:02:46 AM
 *
 */

// Solution:

const _gcd = (a, b) => {
    if(b == 0) return a;
    return _gcd(b, a % b);
}

const _lcm = (arr) => {
    return arr.reduce((sum, fract) => {
        const denominator = fract.split('/')[1];
        const partial_lcm = (sum * denominator) / _gcd(sum, denominator);
        return partial_lcm;
    }, 1);
}

var fractionAddition = function(exp) {
	const fractions = exp.split(/[+-]/).filter(Boolean);
	const operator = exp.split(/[0-9/]/).filter(Boolean);
	exp[0] !== '-' && operator.unshift('+');

	const lcm = _lcm(fractions);

	const molecularSum = fractions.reduce((total, fraction, index) => {
		const [molecular, denominator] = fraction.split('/');
        const sign = (operator[index] === '+' ? 1 : -1);
		const multiple = sign * (lcm / denominator);
		return total + molecular * multiple;
	}, 0);

	const resultGcd = _gcd(Math.abs(molecularSum), lcm);
	return `${molecularSum / resultGcd}/${lcm / resultGcd}`;
};
