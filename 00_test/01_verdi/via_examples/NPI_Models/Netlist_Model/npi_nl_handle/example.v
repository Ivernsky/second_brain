module tb;
  wire clk, rst;
  wire [31:0] out;
  test t1 (clk, rst, out);
endmodule

module test ( clk, rst, out );
  input clk, rst;
  output out;
  reg [31:0] out;

  always @(posedge clk or posedge rst) begin
    if (rst)  out <= 0;
    else       out <= out + 1;
  end

endmodule
