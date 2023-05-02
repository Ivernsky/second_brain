module Add(a, b, c);
  input a;
  input b;
  output c;
  assign c = a+b;
endmodule

module Add2(a2,b2,c2);
  input a2;
  input b2;
  output c2;
  Add inst2(a2,b2,c2);
endmodule

module TOP;
  wire w1;
  wire w2;
  wire w3;
  wire w4 = w3;
  Add2 inst(w1, w2, w3);
endmodule
