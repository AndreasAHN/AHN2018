library ieee;
use ieee.std_logic_1164.all;

--------- Half adder -------
entity half_adder is
	port (a,b : in std_logic;
		sum, carry_out: out std_logic);
end half_adder;

architecture dataflow of half_adder is
	begin
	sum <= a xor b;
	carry_out <= a and b;
end dataflow;



----------- OR gate ----------
library ieee;
use ieee.std_logic_1164.all;

entity or_2 is
port 
	(a,b : in std_logic;
	or_out : out std_logic);
end;

architecture dataflow of or_2 is
begin
	or_out <= a or b;
end dataflow;


--------- Full adder ------------
library ieee;
use ieee.std_logic_1164.all;

entity full_adder is
	port(a,b, carry_in :in std_logic;
	sum, carry_out: out std_logic);
end full_adder;


architecture structure of full_adder is

	signal s1, c1, c2 : std_logic;

begin
	ha1: entity work.half_adder port map(a => a, b=> b, sum => s1, carry_out => c1);
	ha2: entity work.half_adder port map(a => s1, b => carry_in, sum => sum, carry_out => c2);
	or1: entity work.or_2 port map      (a=>c2, b=>c1,or_out=>carry_out);
end structure;

