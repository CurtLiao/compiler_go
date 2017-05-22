/*
 * Example with Functions
 */

// variables
var a int = 5
var c int

// function declaration
// func int add(a int, b int, c real) {
func int add(a int, b int) {
  return a+b
}
func int sub(a real, b int, c string) {
  return 5+b
}

func int mul(a int, b int, c string) {
  return 5+b
}

func void main( ) {
	c = add(a, 10)
	// c = add(1.244, 10, "WAd")
	// c = mul(a, 10, "WAd")
	//next line will type error
	// c = add(1.244, 10, "WAd")
  // if (c > 10) {
    // print -c
  // }
  // else {
    // print c
  // }
  // println "Hello World"
}

