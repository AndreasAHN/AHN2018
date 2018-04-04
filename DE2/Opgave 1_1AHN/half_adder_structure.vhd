library ieee;
use ieee.std_logic_1164.all;

entity xor_2 is	
	port (i1, i2 : in std_logic;
	o1: out std_logic);
end xor_2;

architecture dataflow of xor_2 is
begin	
	o1<=i1 xor i2;
end dataflow;

library ieee;
use ieee.std_logic_1164.all;

entity and_2 is
	port(i1,i2:in std_logic;
	o1:out std_logic);
end and_2;

architecture dataflow of and_2 is
begin
	o1 <= i1 and i2;
end dataflow;

library ieee;
use ieee.std_logic_1164.all;

entity half_adder_structure is
	port(a,b :in std_logic;
	sum, carry_out: out std_logic);
end half_adder_structure;

architecture structure of half_adder_structure is
begin
	u1: entity work.xor_2 port map (i1 => a, i2 => b, o1 => sum);
	u2: entity work.and_2 port map (i1 => a, i2 => b, o1 => carry_out);
end structure;