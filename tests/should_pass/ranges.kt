fun ranges_inclusive() {
  for (i in 1..3) {
    println("Hello, World!")
  }
}

fun ranges_exclusive() {
  for (i in 1..<3) {
    print("Hello, World!")
  }
  for (i in 1 ..< 3 ) {
    print("Hello, World!")
  }

  for (i in 1..< 3 ) {
    print("Hello, World!")
  }

}
