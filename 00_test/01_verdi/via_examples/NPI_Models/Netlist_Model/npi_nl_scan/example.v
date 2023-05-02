module test ( clk, rst, out );
  input clk, rst;
  output out;
  reg [31:0] out;

  always @(posedge clk or posedge rst) begin
    if (rst)  out <= 0;
    else       out <= out + 1;
  end

endmodule

