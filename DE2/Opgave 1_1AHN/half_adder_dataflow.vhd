library ieee;

use ieee.std_logic_1164.all;

entity half_adder_dataflow is
	port (a,b : in std_logic;
		sum, carry_out: out std_logic);
end half_adder_dataflow;

architecture dataflow2 of half_adder_dataflow is
	begin
	sum <= a xor b;
	carry_out <= a and b;
end dataflow2;