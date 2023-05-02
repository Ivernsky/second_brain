module MOD (a, b);
  input [3:0] a;
  output b;
endmodule

module TOP;
  wire [3:0] w1;
  logic w2;
  MOD inst(w1|w2, ~|w2);
endmodule 
