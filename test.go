/* fib.sc
 *
 * This test program computes the Nth Fibonacci number
 */

// variables
const Fn = 1
var n int  = 8
var FNminus1 int = 1
var temp int

// compute the nth Fibonacci number
func void main( ) {

	var a int = 5
	var b int 
	var c int = 6
	if(a > b)
		temp = Fn
	else
		temp = Fn

	if(a > b)
		temp = Fn
	if(a > b)
		temp = Fn
	else
		temp = Fn

	for (n = 1; n > 2; n = n - 1) {
		{}
		temp = Fn
		Fn = Fn + FNminus1
		FNminus1 = temp
		for (n = 1; n > 2; n = n - 1) {
			{}
			temp = Fn
			Fn = Fn + FNminus1
			FNminus1 = temp
			
		}		
	}
	for (n > 2; n = n - 1) {
		temp = Fn
		Fn = Fn + FNminus1
		FNminus1 = temp
	}
	if(a > 5)
		temp = Fn
	if(!true)
		temp = Fn
	if(!(a == b))
		a = b
	var d_flag bool = false
	if(d_flag | !(false))
		a = b
	if(d_flag | !(d_flag))
		a = b
	if(!(a > b) | !(a == b))
		a = b
	if(!(a > b) | (c > b) & (a > b) | !(a == b))
		temp = Fn

	/* print result */
	print "Result of computation: "
	println n
	print 7 * 10
	println 2 - 7 * 10
	read a
	return a

	var d real 
	//next line will be report crash bca a is integer, d is real
	// if(!(a > b) | (c > b) & (a > d) | !(a == b))
	// 	temp = Fn

}
