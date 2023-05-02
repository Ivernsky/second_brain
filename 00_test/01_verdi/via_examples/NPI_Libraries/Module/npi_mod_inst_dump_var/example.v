typedef struct { 
  struct { 
    struct { 
      reg [1:0] Inc; 
    } Ctr [3:0];
  } t [3:0]; 
} SS;

module MOD;
  real real_var = 1.23;
  logic array_var [15:0][0:7];
  SS s1;
endmodule

module TOP;
  MOD inst();
endmodule
