module MOD;
  function [1:0] cpy (input [1:0] data, inout real success);
    cpy = data;
    success = 1.0;
  endfunction
endmodule

module TOP;
  MOD inst();
endmodule
