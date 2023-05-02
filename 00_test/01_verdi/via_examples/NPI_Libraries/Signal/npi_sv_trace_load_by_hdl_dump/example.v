module mod(input mi, output mo);
  not n0(mo, mi);
endmodule

module top;
  wire a, b, c, d, e, f;

  assign b = a + c;
  mod  m0(b, f);
  nand nd(b, d, e);
endmodule
