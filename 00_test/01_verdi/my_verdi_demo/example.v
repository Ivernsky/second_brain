module MOD(a, b);
input a;
output b;
endmodule
module TOP;
wire w1, w2;
MOD inst(w1, w2);
endmodule
