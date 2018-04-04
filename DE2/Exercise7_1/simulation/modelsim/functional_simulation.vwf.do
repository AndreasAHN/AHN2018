vlog -work work D:/Dropbox/AarhusUNI/DSD/Exercise7_1/simulation/modelsim/functional_simulation.vwf.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.MEE_MOO_vlg_vec_tst
onerror {resume}
add wave {MEE_MOO_vlg_vec_tst/i1/a}
add wave {MEE_MOO_vlg_vec_tst/i1/b}
add wave {MEE_MOO_vlg_vec_tst/i1/clk}
add wave {MEE_MOO_vlg_vec_tst/i1/mee_out}
add wave {MEE_MOO_vlg_vec_tst/i1/moo_out}
add wave {MEE_MOO_vlg_vec_tst/i1/reset}
add wave {MEE_MOO_vlg_vec_tst/i1/present_state}
run -all
