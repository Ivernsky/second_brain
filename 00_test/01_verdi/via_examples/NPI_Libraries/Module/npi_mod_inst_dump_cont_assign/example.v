module MOD;
  wire w1;
  wire #10 w2;
  wire #12 w3;

  assign #(2+2) w1 = 1;
  assign {w2, w3} = 2'b01;
endmodule

module TOP;
  MOD inst();
endmodule
