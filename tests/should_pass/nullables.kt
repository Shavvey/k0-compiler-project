fun nullables() {
  val a: Int? = null
  var b: Int = a ?: 3

  var c: Int = 10
  var b: Int = c ?: 4
}
