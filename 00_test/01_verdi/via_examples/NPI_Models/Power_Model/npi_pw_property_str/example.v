module ModDest ();
  //empty module
endmodule

module ModTar (O, inA, inB, ioPort);
  output O;
  input [1:0] inA;
  input [1:0] inB;
  inout [3:0] ioPort;

  wire tx;
  wire ty;

  and ux (tx, inA[0], inB[0]);
  and uy (ty, inA[1], inB[1]);
  and uz (O, tx, ty);
endmodule

module ModSrcB (data_out, data_inA, data_inB);
  output data_out;
  input  [1:0] data_inA;
  input  [1:0] data_inB;

  wire tempIa;
  wire [1:0] tempIb;
  wire [7:2] tmpWire;
  reg  [5:0] tmpReg;

  assign tempIa   = ~data_inB[0];
  assign tempIb   = ~data_inB;

  ModTar Tar(data_out, 2'b10, {tempIb[0], tempIa}, {tmpWire[4:2], tmpReg[5]});

endmodule

module ModSrcA (data_out, data_inA, data_inB);
  output data_out;
  input  [1:0] data_inA;
  input  [1:0] data_inB;
  wire   [2:0] tmpWire;

  ModSrcB SrcB (data_out, data_inA, data_inB);
endmodule

module tb;
  wire data_out;
  reg [1:0] data_inA;
  reg [1:0] data_inB;

  ModSrcA SrcA  (data_out, data_inA, data_inB);
  ModDest Dest ();
endmodule
