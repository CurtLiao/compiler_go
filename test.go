/* Sigma.go
 *
 * Compute sum = 1 + 2 + ... + n
 */

// variables
const n = 10
var sum int = 0
var index int = 0
  
// main function
func void main ( ) {
  

	for (index = 0; index <= n; index = index + 1 ) {

    	sum = sum + index
	}
	// sum = 0
	// index = 0
	for (index <= 10; index = index + 1 ) {

		sum = sum + index
	}
	for (index = 0; index <= 10) {
	
		sum = sum + index
		index = index + 1
	}  
	sum = 0
	for (index = 0; index <= n + 6; index = index + 1) {
		sum = sum + index

	} 
  print "The sum is "
  println sum
}


