module MOD(.p1({a, b}), .p2(c) );
  input a;
  input b;
  output c;
endmodule

module TOP;
  wire [1:0] w1;
  wire w2;
  MOD inst(w1, w2);
endmodule


