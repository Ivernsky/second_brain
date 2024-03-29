primitive udp_mux2 (out, in0, in1, sel);
output out;
input  in0, in1, sel;

table
// in0 in1  sel :  out
1  ?   0  :  1 ;
0  ?   0  :  0 ;
?  1   1  :  1 ;
?  0   1  :  0 ;
0  0   x  :  0 ;
1  1   x  :  1 ;
endtable
endprimitive // udp_mux2

module top;
wire a, b, s, z;
udp_mux2 mux (z, a, b, s);
endmodule
