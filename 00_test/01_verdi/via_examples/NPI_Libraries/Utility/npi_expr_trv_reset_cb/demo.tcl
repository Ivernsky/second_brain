proc expr_cb { hdl cbData } {
  upvar $cbData cnt
  if { [ npi_get_str -property npiType -object $hdl] != "npiOperation" } {
    return 0
  }
  if { [ npi_get_str -property npiOpType -object $hdl] == "npiAddOp" } {
    incr cnt
  }
  return 1
}

source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set varHdl [ npi_handle_by_name -name "top.a" -scope "" ]
set exprHdl [ npi_handle -type "npiExpr" -refHandle $varHdl ]

set addOpCnt 0
::npi_L1::npi_expr_trv_register_cb "expr_cb" "addOpCnt"
::npi_L1::npi_expr_trv $exprHdl
puts "Add op cnt = $addOpCnt"

set addOpCnt 0
::npi_L1::npi_expr_trv_reset_cb
::npi_L1::npi_expr_trv $exprHdl
puts "Add op cnt = $addOpCnt"


debExit
