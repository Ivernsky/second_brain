module Add(a, b, c);
  input a;
  input b;
  output c;
  assign c = a+b;
endmodule

module TOP (i1, i2, o1);
  input i1, i2;
  output o1;
  wire w1, w2, w3, w4;
  assign w1 = i1;
  assign w2 = i2;
  assign w3 = w4;
  assign o1 = w3;
  Add inst(w1, w2, w4);
endmodule
