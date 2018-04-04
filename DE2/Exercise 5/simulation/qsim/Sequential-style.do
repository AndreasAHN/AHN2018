onerror {quit -f}
vlib work
vlog -work work Sequential-style.vo
vlog -work work Sequential-style.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.nand_8_tester_vlg_vec_tst
vcd file -direction Sequential-style.msim.vcd
vcd add -internal nand_8_tester_vlg_vec_tst/*
vcd add -internal nand_8_tester_vlg_vec_tst/i1/*
add wave /*
run -all
