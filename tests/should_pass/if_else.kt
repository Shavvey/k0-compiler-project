fun ifelse() {
  // NOTE: from https://kotlinlang.org/docs/control-flow.html#when-expressions-and-statements
  if (heightAlice > 0) {
    print("Whatever\n")
  }

  if (heightAlice > heightBob) {
      print("Choose Alice\t Now")
  } else if (heightAlice == 0) {
      print("Choose Bob\n Now")
  } else {
      print("Something else")
  }

}
