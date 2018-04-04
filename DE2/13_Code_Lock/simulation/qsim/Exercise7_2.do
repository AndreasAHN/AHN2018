onerror {quit -f}
vlib work
vlog -work work Exercise7_2.vo
vlog -work work Exercise7_2.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.Code_lock_vlg_vec_tst
vcd file -direction Exercise7_2.msim.vcd
vcd add -internal Code_lock_vlg_vec_tst/*
vcd add -internal Code_lock_vlg_vec_tst/i1/*
add wave /*
run -all
