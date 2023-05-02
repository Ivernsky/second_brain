module top;
 
  typedef struct packed {
    bit   [2:0] sa;
    integer     sb;
    logic [1:0] sc;
  } ps;
 
  typedef struct packed {
    bit   [1:0] a;
    logic       b;
    ps          c;
  } st;
 
  reg [3:0] regArr [1:0];
  const integer idx0 = 0;
  parameter p0 = 0;
  st st1;
 
  initial begin: init_blk
    parameter p1 = 1;
    // -- left and right overlap ----------------
    // left contains right
    regArr[0][1:0] = regArr[0][0];
    regArr[0][1:p0] = regArr[0][idx0];
    // partial left is equal to partial right
    regArr[0][3:1] = regArr[0][2:0];
    st1.a = st1[38];
    st1.b = st1[38:35];
    // -- left and right do not overlap ---------
    regArr[1][1:0] = regArr[0][1:0];
    st1[20:10] = st1[9:0];
  end
 
endmodule
