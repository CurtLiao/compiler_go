/*
 * hi, let's test
 *
 * =======================
 *
 * date:20170525
 * author:xiaosean 
 *
 */

var int_a int = 5
var int_b int = 21
const const_a = 5
var b string = "asdaw""""wd"


func void main( ) {
	int_a = int_b

	// next line will compiler error
	// int_a = b

	var arr_s[5] string
	// arr_s[0] = "wadwada"

	// next line will compiler error
	// arr_s[0] = 1223213
	int_b = 3 * 5
	int_b = int_a
	int_b = 3 * int_a 
	var arr_i[3 * const_a] int
	arr_i[0] = 4 
	// todo: i will crash
	// var arr_ii[arr_i[0]] real
	var arr_ii[3] real
	arr_ii[0] = 1.4353525
	var arr_b[3 + 6] bool
	arr_b[0] = true

}
