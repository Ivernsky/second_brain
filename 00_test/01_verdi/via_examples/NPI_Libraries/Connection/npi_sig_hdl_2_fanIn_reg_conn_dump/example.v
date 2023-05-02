module TOP(clk, win, wout);
  input  clk, win;
  output reg wout;
  reg wtmp;
  
  always@(posedge clk) begin
    wtmp<=win;
  end
  
  always@(posedge clk) begin
    wout<=wtmp;
  end

endmodule
