source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set varHdl [ npi_handle_by_name -name "top.a" -scope "" ]
set exprHdl [ npi_handle -type "npiExpr" -refHandle $varHdl ]

puts [ ::npi_L1::npi_expr_decompile $exprHdl ]

debExit
