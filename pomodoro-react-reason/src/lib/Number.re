let padDecimalNumber = (number) => {
  if (int_of_string(number) < 10) {
    "0" ++ number;
  } else {
    number;
  }
}