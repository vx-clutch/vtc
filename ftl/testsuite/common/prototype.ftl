#use <io.def>

&main: void {
  printfn("Hello, World!");
  let mut out;
  out = add(34, 35);
  printfn("%d", out);
  return 0;
} int;

&add: (int x, int y) {
  return x y +;
} int;
