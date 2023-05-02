module TOP;
  reg clk;
  
  initial begin: INIT_BLK
    clk = ~clk;
  end
endmodule
