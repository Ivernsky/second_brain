module MOD;
  parameter PARAM1 = 3;
  parameter real PARAM_REAL = 123.123;
  localparam byte LPRAM = PARAM1 + 3;
endmodule

module TOP;
  MOD #(123) inst();
endmodule
