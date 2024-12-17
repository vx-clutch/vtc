fn main (): int {
  x;
  loop: 5 {
    ;; This prints the values of $x five times.
    println: $x;
    $x++;
  }
  return 1;
}
