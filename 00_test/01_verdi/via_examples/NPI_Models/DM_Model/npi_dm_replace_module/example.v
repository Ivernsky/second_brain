module TOP;
  wire w1, w2;
  MOD1 i0(w1, w2);
endmodule

module MOD1(a, b);
  input a;
  output b;
endmodule

module MOD2(a, b);
  input a;
  output b;
endmodule

