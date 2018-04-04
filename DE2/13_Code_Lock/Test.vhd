-------- tester --------
library ieee;
use ieee.std_logic_1164.all;

entity tester is
	port(
			KEY : in std_logic_vector(2 downto 1); 
			SW : in std_logic_vector(3 downto 0);
			LEDG : out std_logic_vector(0 downto 0),
			CLOCK_50 : in std_logic
			);			
end tester;

architecture structure of tester is	
 signal	LYS   :	std_logic_vector(0 downto 0);
begin

		mee_moo_tester: entity work.MEE_MOO port map(
			code => SW(3 downto 0),
			clk => CLOCK_50,
			reset => key(2),
			enter = > key(3),
			lock	 => LYS(0)
															);
		LEDG <= LYS;
end structure; 




