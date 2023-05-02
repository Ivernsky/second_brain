module Add(a, b, c);
  input a;
  input b;
  output c;
  assign c = a+b;
endmodule

module TOP;
  wire  w1;
  wire  w2;
  wire  w3;
  wire  w4 = w1;
  Add inst(w4, w2, w3);
endmodule
