/*
 * hi, let's test
 *
 * =======================
 *
 * date:20170525
 * author:xiaosean 
 *
 */

// variables
var a int = 5
var c int

// function declaration
// func int add(a int, b int, c real) {
func void vadd_void() {
}
func int add_void() {
  return 5
}
func int add_(a int) {
  return a
}
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
	c = add_(a)
	c = add_(5)
	c = add_(5)
	c = add(a, 20320)
	c = add(a, add(5, 3))
	c = add_void()
	go vadd_void()
	//next line will type error
	// c = vadd_void()
	//next line will type error
	// c = add_(vadd_void())
	//next line will type error
	// c = add_void(5)
	//next line will type error
	// c = add(a, add(5, 3.456))
	//next line will type error
	// c = add(a, 203203.244)
	//next line will type error
	// c = add(1.244, 10, "WAd")
	c = sub(1.32424e21, add_void(), "sdad")
	c = sub(1.32424e21, 323, "sdad")
	c = mul(a, 10, "WAd")
	// next line will type error
	// c = mul(1.244, "x", "WAd")
  if (c > 10) {
    print -c
  }
  else {
    print c
  }
  println "Hello World"
}

