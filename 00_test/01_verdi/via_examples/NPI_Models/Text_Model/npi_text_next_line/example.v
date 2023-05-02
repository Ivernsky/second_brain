
`define AAA 
`include "example_inc.vh"
`undef AAA

`define BBB 
`include "example_inc.vh"
`undef BBB

`include "example_inc.vh"


module TOP;

wire ai, ao;
wire bi, bo;
wire ci, co;

AAA u_AAA (ai, ao);
BBB u_BBB (bi, bo);
CCC u_CCC (ci, co);

endmodule

