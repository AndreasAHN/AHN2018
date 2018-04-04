library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity process_with_loop is
port(
	a 		:	in		std_logic_vector(7 downto 0);
	ones 	:	out	std_logic_vector(3 downto 0)
);
end process_with_loop;


architecture combinational of process_with_loop is
begin
	pwl: process(a)
	variable result : integer;
	begin
		result := 0;
		for index in 7 downto 0 loop
			if a(index) = '1' then
				result := result + 1;
			else
				result := result;
			end if;
		end loop;
		ones <= std_logic_vector(to_unsigned(result, 4));
	end process pwl;
end combinational;
		