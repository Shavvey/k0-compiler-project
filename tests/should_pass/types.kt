fun types() {
  var s: String = "string\ts"
  var c: Char = 'f'
  var i: Int = 1
  var _v: Int = 1_2_3_4
  var f: Double = 0.13
  var f1: Float = 13f // using f or F postfix makes it a REALLITERAL
  var e1: Double = 1E0__1 // sci-notation is allow, but with only int exponents
  var e2: Double = 1E-0__1
  var e3: Double = 1E+0_0_4
  var E2: Double = 0.3E1
  var _11111: Int = 1
  var l: Int = 10L // ints may have the L notation, but is ignored
  var binary: Int = 0b10001
  var b1: Int = 0b1_000_1
  var hex: Int = 0x1F
  var s1: String = "NULL"
  var d2: Double = .13 // this should also be a valid double/float
}
