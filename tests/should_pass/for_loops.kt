fun foo(): Int {
  return 3
}

fun for_loops(foo: Int) {
  var cond: Int = 1

  for (i in 1..3) {
    print("Hello, World!\n")
  }
  for (i in 1..foo()) {
    print("Hello, World!\n")
  }
  
  while(cond < 2) {
    print("Hello, World!\n")
    cond += 1
  }
}

