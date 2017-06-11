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
  for (index <= n; index = index + 1 ) {
    sum = sum + index
    // index = index + 1
  } 
  print "The sum is "
  println sum
}


