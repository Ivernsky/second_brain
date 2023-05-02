module TOP;
  wire wq, wa;
  wire data, clock;

  nand #(3, 4) nand1(wa, data, clock);
  cmos cmArr[1:0] (wq, wa, clock, ~clock);
endmodule
