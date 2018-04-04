onerror {quit -f}
vlib work
vlog -work work MEE-MOO.vo
vlog -work work MEE-MOO.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.MEE_MOO_vlg_vec_tst
vcd file -direction MEE-MOO.msim.vcd
vcd add -internal MEE_MOO_vlg_vec_tst/*
vcd add -internal MEE_MOO_vlg_vec_tst/i1/*
add wave /*
run -all
