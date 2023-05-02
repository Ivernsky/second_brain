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
  wire  w4;
  assign w3 = w4;
  Add inst(w1, w2, w4);
endmodule
