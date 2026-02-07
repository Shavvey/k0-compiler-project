fun boolops() {
  var a: Int = 0b0_111_0
  var b: Int = 0b1_000_1
  if (a && b == 0b0) {
    println("Conjunction (&&) statement")
  } 
  if (a || b ==  0b1_111_1) {
    println("Disjunction (||) statement")
  }
}
