module TOP;
  reg clk = 0;
  always #3 clk = ~clk;
endmodule
