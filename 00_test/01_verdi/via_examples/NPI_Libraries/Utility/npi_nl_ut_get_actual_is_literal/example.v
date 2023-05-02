module top;
wire [2:0] a;
wire [7:0] b;
wire [2:0] c;

assign b = {2'b01, 3'b011, a};
assign c = 3'bx01;

endmodule
