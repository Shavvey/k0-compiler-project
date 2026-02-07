fun ifelse() {
  // NOTE: from https://kotlinlang.org/docs/control-flow.html#when-expressions-and-statements
  val heightAlice = 160
  val heightBob = 175

  if (heightAlice > heightBob) {
      print("Choose Alice\t Now")
  } else {
      print("Choose Bob\n Now")
  }
  
  if (heightAlice == 5 || heightBob == 5) {
    print("One person is very short\n")
  }

  if (heightAlice == 5 && heightBob == 5) {
    print("Both people are very short\n")
  } else {
    print("Both people are not short\n")
  }
  val taller = (heightAlice > heightBob) ? heightAlice : heightBob 
  print("Taller is: $taller")
}
