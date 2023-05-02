module TOP;
  wire w1, w2;
  MOD1 i0(w1, w2);
endmodule

module MOD1(a, b);
  input a;
  output b;

  MOD2 i1(a, b);
endmodule

module MOD2(a, b);
  input a;
  output b;
endmodule

