module MOD;
  wire [3:0]a;
  logic array_var [15:0][0:7];
  wor w1 [3:0];
endmodule

module TOP;
  MOD inst();
  MOD inst2 [3:0] ();
endmodule
